#pragma once

#include <vector>
#include "command.h"
#include <string>
#include "emoji.h"

namespace mdcore{
    class SubcommandListener
    {
        public:
            SubcommandListener()
            {
                commands = {};
            };
            SubcommandListener(int indexIn){
                commands = {};
                index = indexIn;
            };
            SubcommandListener(std::vector<Command*> c)
            {
                commands = c;
            };
            SubcommandListener(int indexIn, std::vector<Command*> c)
            {
                commands = c;
                index = indexIn;
            };
            ~SubcommandListener();
            void onMessage(SleepyDiscord::DiscordClient* c, SleepyDiscord::Message m, std::vector<std::string> args)
            {
                if(args[index] == "help" && !m.author.bot)
                {
                    SleepyDiscord::Channel dm_channel = c->createDirectMessageChannel(m.author.ID.string()).cast();
                    std::string help_message = "";
                    help_message += c->getCurrentUser().cast().username + " Help:\n\n";
                    help_message += "help - Displays this help message\n";
                    for(auto command : commands){
                        help_message += command->getName() + " - " + command->getHelp() + "\n";
                    }
                    c->sendMessage(dm_channel.ID, help_message);
                    c->addReaction(m.channelID, m.ID, emojicpp::EMOJIS[":white_check_mark:"]);
                }
                for(auto command : commands)
                {
                    if(args[index] == command->getName() && !m.author.bot)
                    {
                        command->execute(c, m, args);
                        return;
                    }
                    for(auto altName : command->getAltNames())
                    {
                        if(args[index] ==  command->getName() && !m.author.bot){
                            command->execute(c, m, args);
                            return;
                        }
                    }
                }
            }
            void registerCommand(mdcore::Command* c)
            {
                commands.push_back(c);
            }
        private:
            std::vector<mdcore::Command*> commands;
            int index = 1;
    };
}