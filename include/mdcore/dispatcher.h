#pragma once

#include "sleepy_discord/sleepy_discord.h"
#include "listener.h"
#include "mdcore/logger.h"
#include <vector>
#include <chrono>

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
                    Logger logger(&bot_name[0]);
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
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(Listener* listener : this->listeners)
                    {
                        //logger.debug("Running Listener: " + listener->getName());
                        listener->onMessage(this, message);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onMessage()");
                };
                void onServer(SleepyDiscord::Server server) override{
                    Logger logger(&bot_name[0]);
                    logger.info("[" + server.name + "] has been added!");
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                        listener->onServer(this, server);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onServer()");
                }
                void onChannel(SleepyDiscord::Channel channel) override{
                    Logger logger(&bot_name[0]);
                    if(channel.name != ""){ //This prevents stray log messages from DMs
                        logger.info("[#" + channel.name + "] has been added!");
                    }
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                        listener->onChannel(this, channel);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onChannel()");
                }
                void onHeartbeat() override{
                    if(bot_name == "")
                    {
                        bot_name = getCurrentUser().cast().username;
                    }
                    Logger logger(&bot_name[0]);
                    logger.debug("Discord Heartbeat");

                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                         listener->onHeartbeat();
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onHeartbeat()");
                }
                void onBan(SleepyDiscord::Snowflake<SleepyDiscord::Server> serverID, SleepyDiscord::User user) override
                {
                    Logger logger(&bot_name[0]);
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                         listener->onBan(this, serverID, user);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onBan()");
                };
                void onUnban(SleepyDiscord::Snowflake<SleepyDiscord::Server> serverID, SleepyDiscord::User user) override{
                    Logger logger(&bot_name[0]);
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                         listener->onUnban(this, serverID, user);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onUnban()");
                };
                void onEditChannel(SleepyDiscord::Channel channel) override{
                    Logger logger(&bot_name[0]);
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                         listener->onEditChannel(this, channel);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onEditChannel()");
                };  
                void onDeleteChannel(SleepyDiscord::Channel channel) override {
                    Logger logger(&bot_name[0]);
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                         listener->onEditChannel(this, channel);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onDeleteChannel()");
                };
                void onEditMember(SleepyDiscord::Snowflake<SleepyDiscord::Server> serverID, SleepyDiscord::User user, std::vector<SleepyDiscord::Snowflake<SleepyDiscord::Role>> roles, std::string nick) override{
                    Logger logger(&bot_name[0]);
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                         listener->onEditMember(this, serverID, user, roles, nick);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onEditMember()");
                };
                void onEditServer(SleepyDiscord::Server server) override {
                    Logger logger(&bot_name[0]);
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                         listener->onEditServer(this, server);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onEditServer()");
                };
                void onReaction(SleepyDiscord::Snowflake<SleepyDiscord::User> userID, SleepyDiscord::Snowflake<SleepyDiscord::Channel> channelID, SleepyDiscord::Snowflake<SleepyDiscord::Message> messageID, SleepyDiscord::Emoji emoji) override{
                    Logger logger(&bot_name[0]);
                    auto t1 = std::chrono::high_resolution_clock::now();
                    for(auto listener : listeners)
                    {
                         listener->onReaction(this, userID, channelID, messageID, emoji);
                    }
                    auto t2 = std::chrono::high_resolution_clock::now();

                    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

                    logger.debug("Took " + std::to_string(ms_int.count()) + " ms to run onReaction()");
                };
                void setListeners(std::vector<Listener*> listeners);
                void registerListener(Listener* listener);
            private:
                std::vector<Listener*> listeners;
                std::string bot_name = "";
        };
}