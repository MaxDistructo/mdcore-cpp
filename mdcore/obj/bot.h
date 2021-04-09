#include <string>
#include <vector>
#include "mdcore/obj/listener.h"
#include "mdcore/obj/command.h"
#include "sleepy_discord/sleepy_discord.h"

namespace mdcore
{
    namespace obj{
        class Bot{
            public:
                Bot();
                ~Bot();
                Bot(std::string token);
                Bot(std::string token, std::string ownerId);
                Bot(std::string token, std::string prefix, std::string ownerId);
                void registerListener(Listener listener);
                void init();
                void registerCommand(Command c);
                void setOwnerId(std::string id);
                SleepyDiscord::DiscordClient getClient();
                void useCommandListener(bool b);
            private:
                std::vector<Listener> listeners;
                std::vector<Command> commands;
                std::vector<std::string> coOwners;
                std::string name;
                SleepyDiscord::DiscordClient client;
                bool commandListenerEnabled;
                Listener commandListener;
        };
    }

}