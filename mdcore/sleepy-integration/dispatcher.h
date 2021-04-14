#ifndef _mdcore_Dispatcher_h
#define _mdcore_Dispatcher_h
#include "sleepy_discord/sleepy_discord.h"
#include "listener.h"
#include "../logger.h"
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

namespace mdcore{
        class Dispatcher : public SleepyDiscord::DiscordClient{
            public:
                Dispatcher(std::string token, SleepyDiscord::Mode mode) : SleepyDiscord::DiscordClient(token, mode){};
                ~Dispatcher();
                using SleepyDiscord::DiscordClient::DiscordClient;
                void onMessage(SleepyDiscord::Message message) override{
                    //TODO: Input logging messages here for each event
                    SleepyDiscord::Server server;;
                    try{server = getServer(message.serverID).cast();}
                    catch(...){};
                    SleepyDiscord::Channel channel;
                    try{channel = getChannel(message.channelID).cast();}
                    catch(...){};
                    mdcore::Logger::Logger logger(&bot_name[0]);
                    if(!(channel.type == SleepyDiscord::Channel::ChannelType::DM || channel.type == SleepyDiscord::Channel::ChannelType::GROUP_DM)){
                        SleepyDiscord::ServerMember author = getMember(message.serverID, message.author.ID);
                        if(author.nick != ""){
                            logger.info((std::string)"[" + server.name + "] [#" + channel.name + "] [" + author.nick + "#" + message.author.discriminator +"] " + message.content);
                        }
                        else
                        {
                            logger.info((std::string)"[" + server.name + "] [#" + channel.name + "] [" + message.author.username + "#" + message.author.discriminator +"] " + message.content);
                        }

                    }
                    else
                    {
                        logger.info((std::string)"[DM] [@" + message.author.username + "#" + message.author.discriminator +"] " + message.content);
                    }
                    for(mdcore::Listener* listener : this->listeners)
                    {
                        //logger.debug("Running Listener: " + listener->getName());
                        listener->onMessage(this, message);
                    }
                };
                void onServer(SleepyDiscord::Server server) override{
                    mdcore::Logger::Logger logger(&bot_name[0]);
                    logger.info("[" + server.name + "] has been added!");
                }
                void onChannel(SleepyDiscord::Channel channel) override{
                    mdcore::Logger::Logger logger(&bot_name[0]);
                    if(channel.name != ""){ //This prevents stray log messages from DMs
                        logger.info("[#" + channel.name + "] has been added!");
                    }
                }
                void onHeartbeat() override{
                    if(bot_name == "")
                    {
                        bot_name = getCurrentUser().cast().username;
                    }
                    mdcore::Logger::Logger logger(&bot_name[0]);
                    logger.debug("Discord Heartbeat");
                }
                void setListeners(std::vector<mdcore::Listener*> listeners);
                void registerListener(mdcore::Listener* listener);
            private:
                std::vector<mdcore::Listener*> listeners;
                std::string bot_name = "";
        };
}
#endif