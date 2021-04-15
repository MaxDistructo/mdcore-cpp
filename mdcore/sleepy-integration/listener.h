#ifndef _mdcore_Listener_h
#define _mdcore_Listener_h
#include "sleepy_discord/sleepy_discord.h"
#include "member.h"

namespace mdcore{
    class Listener{
        public: 
            virtual void onMessage(SleepyDiscord::DiscordClient* client, SleepyDiscord::Message message);
            virtual void onChannel(SleepyDiscord::DiscordClient* client, SleepyDiscord::Channel channel){};
            virtual void onBan(SleepyDiscord::DiscordClient* client, SleepyDiscord::Snowflake<SleepyDiscord::Server> serverID, SleepyDiscord::User user){};
            virtual void onUnban(SleepyDiscord::DiscordClient* client, SleepyDiscord::Snowflake<SleepyDiscord::Server> serverID, SleepyDiscord::User user){};
            virtual void onEditChannel(SleepyDiscord::DiscordClient* client, SleepyDiscord::Channel channel){};
            virtual void onDeleteChannel(SleepyDiscord::DiscordClient* client, SleepyDiscord::Channel channel){};
            virtual void onServer(SleepyDiscord::DiscordClient* client, SleepyDiscord::Server server){};
            virtual void onEditMember(SleepyDiscord::DiscordClient* client, SleepyDiscord::Snowflake<SleepyDiscord::Server> serverID, SleepyDiscord::User user, std::vector<SleepyDiscord::Snowflake<SleepyDiscord::Role>> roles, std::string nick){};
            virtual void onEditServer(SleepyDiscord::DiscordClient* client, SleepyDiscord::Server server){};
            virtual void onReaction(SleepyDiscord::DiscordClient* client, SleepyDiscord::Snowflake<SleepyDiscord::User> userID, SleepyDiscord::Snowflake<SleepyDiscord::Channel> channelID, SleepyDiscord::Snowflake<SleepyDiscord::Message> messageID, SleepyDiscord::Emoji emoji){};
            virtual void onHeartbeat(){};
            Listener* operator*()
            {
                return this;
            }
            std::string getName()
            {
                return this->name;
            }
        protected:
            std::string name;
    };
}
#endif