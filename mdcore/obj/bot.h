#ifndef _mdcore_Bot_h
#define _mdcore_Bot_h
#include <string>
#include <vector>
#include "listener.h"
#include "dispatcher.h"
#include "command.h"
#include "sleepy_discord/sleepy_discord.h"

namespace mdcore
{
        class Bot{
            public:
                Bot();
                ~Bot();
                Bot(std::string token);
                Bot(std::string token, std::string ownerId);
                Bot(std::string token, std::string prefix, std::string ownerId);
                void registerListener(mdcore::Listener listener);
                void init();
                void registerCommand(mdcore::Command c);
                void setOwnerId(std::string id);
                void useCommandListener();
                mdcore::Dispatcher dispatcher;
            private:
                std::vector<mdcore::Listener> listeners;
                std::vector<mdcore::Command> commands;
                std::vector<std::string> coOwners;
                std::string name;
                std::string ownerId;
                std::string token;
                std::string prefix;
                bool commandListenerEnabled;
                mdcore::Listener commandListener;
        };
}
#endif