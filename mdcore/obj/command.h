#ifndef __mdcore_Command_h
#define __mdcore_Command_h
#include <string>
#include <vector>
#include "sleepy_discord/sleepy_discord.h"

namespace mdcore{
        class Command{
            public:
                Command();
                ~Command();
                void execute(SleepyDiscord::Message event, std::vector<std::string> args);
                std::string getName();
                std::vector<std::string> getAltNames();
            protected:
                std::string name;
                std::vector<std::string> altNames;
                bool guildOnly = false;
                bool adminOnly = false;
                std::string help;
        };
}
#endif