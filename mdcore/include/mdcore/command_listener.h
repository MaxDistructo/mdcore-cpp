#ifndef __mdcore_CommandListener_h
#define __mdcore_CommandListener_h
#include <vector>
#include "command.h"
#include "listener.h"
#include "logger.h"
#include "../../../lib/emoji.h"

namespace mdcore
{
    class CommandListener : public Listener{
        public:
            CommandListener();
            ~CommandListener();
            CommandListener(std::vector<mdcore::Command*> commands, std::string prefix);
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
                    if(message.startsWith(prefix + command->getName()) && !message.author.bot)
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
#endif