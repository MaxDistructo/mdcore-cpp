#ifndef _mdcore_Member_h
#define _mdcore_Member_h
#include "sleepy_discord/sleepy_discord.h"

namespace mdcore{
    class Member{
        public:
            Member();
            ~Member();
            Member(SleepyDiscord::Snowflake<SleepyDiscord::Server> serverId, SleepyDiscord::User user);
            SleepyDiscord::Server getServer();
            SleepyDiscord::User getUser();
        private:
            SleepyDiscord::User user;
            SleepyDiscord::Server server;
    };
}
#endif