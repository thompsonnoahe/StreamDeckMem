//
// Created by Noah Thompson on 5/27/2024.
//

#include "MemPlugin.h"
#include "Windows/WindowsRamUsage.h"

namespace nthompson {
    void Timer::Start(int32_t interval, const std::function<void()> &func) {
        if (running_) return;
        running_ = true;
        thread_ = std::thread([this, &interval, func]() {
            while (running_) {
                std::scoped_lock<std::mutex> lock(mutex_);
                func();
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
            }
        });
    }

    void Timer::Stop() {
        running_ = false;
        if (thread_.joinable()) {
            thread_.join();
        }
    }


    MemPlugin::MemPlugin() {
        timer_ = std::make_unique<Timer>();

#ifdef _WIN32
        usage_ = std::make_unique<WindowsRamUsage>();
#endif

        if (!usage_) {
            ESDLog("Unsupported platform or failed to alloc memory for usage calculation");
            return;
        }

        timer_->Start(1000, [this](){
            Update();
        });
    }


    void MemPlugin::WillDisappearForAction(const std::string &inAction, const std::string &inContext,
                                           const nlohmann::json &inPayload, const std::string &inDeviceID) {
        std::scoped_lock<std::mutex> lock(mutex_);
        contexts_.erase(inContext);
    }

    void MemPlugin::WillAppearForAction(const std::string &inAction, const std::string &inContext,
                                        const nlohmann::json &inPayload, const std::string &inDeviceID) {
        std::scoped_lock<std::mutex> lock(mutex_);

        contexts_.insert(inContext);
    }

    void MemPlugin::Update() {
        if (mConnectionManager == nullptr) return;
        std::scoped_lock<std::mutex> lock(mutex_);
        uint32_t utilization = usage_->GetRamUsage();
        for (const std::string& context : contexts_) {
            mConnectionManager->SetTitle(std::to_string(utilization) + "%", context, kESDSDKTarget_HardwareAndSoftware);
        }
    }

    MemPlugin::~MemPlugin() {
        timer_->Stop();
    }
}


