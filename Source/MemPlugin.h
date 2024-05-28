//
// Created by Noah Thompson on 5/27/2024.
//

#pragma once

#include <StreamDeckSDK/ESDPlugin.h>
#include <StreamDeckSDK/ESDLogger.h>
#include <StreamDeckSDK/ESDConnectionManager.h>
#include <set>
#include <string>
#include "IRamUsage.h"

namespace nthompson {
    class Timer {
    public:
        void Start(int32_t interval, const std::function<void()>& func);
        void Stop();
    private:
        std::thread thread_;
        std::mutex mutex_;
        std::atomic<bool> running_ = false;
    };


    class MemPlugin : public ESDBasePlugin {
    public:
        MemPlugin();

        void Update();

        void WillAppearForAction(const std::string& inAction,
                                 const std::string& inContext,
                                 const nlohmann::json& inPayload,
                                 const std::string& inDeviceID) override;

        void WillDisappearForAction(
                const std::string& inAction,
                const std::string& inContext,
                const nlohmann::json& inPayload,
                const std::string& inDeviceID) override;

        ~MemPlugin() override;
    private:
        std::unique_ptr<IRamUsage> usage_;
        std::unique_ptr<Timer> timer_;
        std::mutex mutex_;
        std::set<std::string> contexts_;
    };

}

