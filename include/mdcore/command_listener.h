#pragma once

#include <vector>
#include "command.h"
#include "listener.h"
#include "mdcore/logger.h"
#include "../../../lib/emoji.h"

namespace mdcore
{
    class CommandListener : public Listener{
        public:
            CommandListener();
            ~CommandListener();
            CommandListener(std::vector<mdcore::Command*> commands, std::string prefix);
            /**
             * @brief The Primary dispatching function for commands. Upon receiving a message,
             * we check to see if it is a command based on the registered commands or help.
             *
             * The help command is hard coded into this method and not registered like all other
             * commands.
             * 
             * @param client - A pointer to the client
             * @param message - The message that we have received
             */
            void onMessage(SleepyDiscord::DiscordClient* client, SleepyDiscord::Message message) override{
                //mdcore::Logger::Logger logger("CommandListener");
                //logger.debug("Running CommandListener::onMessage(client, message)");
                std::vector<std::string> args;
                std::istringstream iss(message.content);
                std::copy(std::istream_iterator<std::string>(iss),
                          std::istream_iterator<std::string>(),
                          std::back_inserter(args)
                        );
                //Hard coded help command, loops over all registered commands and builds a help message
                if(message.startsWith(prefix + "help") && !message.author.bot)
                {
                    SleepyDiscord::Channel dm_channel = client->createDirectMessageChannel(message.author.ID.string()).cast();
                    std::string help_message = "";
                    help_message += client->getCurrentUser().cast().username + " Help:\n\n";
                    help_message += "help - Displays this help message\n";
                    for(auto command : commands){
                        help_message += command->getName() + " - " + command->getHelp() + "\n";
                    }
                    client->sendMessage(dm_channel.ID, help_message);
                    client->addReaction(message.channelID, message.ID, emojicpp::EMOJIS[":white_check_mark:"]);
                }
                for(auto command : commands)
                {
                    //It would appear this not-a-bot check doesn't work? We'll just need to replace it.
                    //if(message.startsWith(prefix + command->getName()) && !message.author.bot)
                    //Yes, we are forcibly killing Carl from this. For some reason all the bot checks fail and Carl can still trigger us. Same with ourselves
                    if(message.startsWith(prefix + command->getName()) && (message.author.flags != SleepyDiscord::User::Flags::Verified_Bot) && (message.author.publieFlags != SleepyDiscord::User::Flags::Verified_Bot) && message.author.ID != 235148962103951360 && message.author.ID != 266731788594970635)
                    {
                        command->execute(client, message, args);
                        return;
                    }
                    for(auto altName : command->getAltNames())
                    {
                        if(message.startsWith(prefix + command->getName())){
                            command->execute(client, message, args);
                            return;
                        }
                    }
                }
            }
            void registerCommand(mdcore::Command* command);
        private:
            std::vector<mdcore::Command*> commands;
            std::string prefix;
    };
}