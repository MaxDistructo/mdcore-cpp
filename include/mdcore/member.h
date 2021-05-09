#pragma once
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