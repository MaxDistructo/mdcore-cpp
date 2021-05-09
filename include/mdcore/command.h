#pragma once

#include <string>
#include <vector>
#include "sleepy_discord/sleepy_discord.h"
#include <ostream>

namespace mdcore{
        class Command{
            public:
                Command();
                ~Command();
                virtual void execute(SleepyDiscord::DiscordClient* client, SleepyDiscord::Message event, std::vector<std::string> args) {};
                std::string getName();
                std::vector<std::string> getAltNames();
                std::string getHelp();

                void setName(std::string nameIn);
                void setAltNames(std::vector<std::string> altNames);
                void setHelp(std::string help);
                Command* operator*()
                {
                    return this;
                }
                friend std::ostream& operator<<(std::ostream& stream, Command& command)
                {
                    stream << "mdcore::Command(Name: " << command.name << ", Help: " << command.help << ")" << std::endl;
                    return stream;
                }
            protected:
                std::string name;
                std::vector<std::string> altNames;
                bool guildOnly = false;
                bool adminOnly = false;
                std::string help;
        };
}