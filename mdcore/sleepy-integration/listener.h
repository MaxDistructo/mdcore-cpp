#ifndef _mdcore_Listener_h
#define _mdcore_Listener_h
#include "sleepy_discord/sleepy_discord.h"
#include "member.h"

namespace mdcore{
    class Listener{
        public: 
            virtual void onMessage(SleepyDiscord::DiscordClient* client, SleepyDiscord::Message message);
            void onChannel(SleepyDiscord::Channel channel);
            void onBan(mdcore::Member member);
            void onUnban(mdcore::Member member);
            void onEditChannel(SleepyDiscord::Channel channel);
            void onDeleteChannel(SleepyDiscord::Channel channel);
            void onServer(SleepyDiscord::Server server);
            void onEditMember(SleepyDiscord::ServerMember member);
            void onEditServer(SleepyDiscord::Server server);
            void onReaction(SleepyDiscord::Message message);
            void onDeleteServer(SleepyDiscord::Server server);
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