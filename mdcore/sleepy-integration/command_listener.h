#ifndef __mdcore_CommandListener_h
#define __mdcore_CommandListener_h
#include <vector>
#include "command.h"
#include "listener.h"
#include "core.h"

namespace mdcore
{
    class CommandListener : public Listener{
        public:
            CommandListener();
            ~CommandListener();
            CommandListener(std::vector<mdcore::Command> commands);
            void onMessage(SleepyDiscord::DiscordClient* client, SleepyDiscord::Message message){
                std::vector<std::string> args;
                std::istringstream iss(message.content);
                std::copy(std::istream_iterator<std::string>(iss),
                          std::istream_iterator<std::string>(),
                          std::back_inserter(args)
                        );
                for(auto command : commands)
                {
                    if(message.startsWith(core_prefix + command.getName()))
                    {
                        command.execute(client, message, args);
                        return;
                    }
                    for(auto altName : command.getAltNames())
                    {
                        if(message.startsWith(core_prefix + command.getName())){
                            command.execute(client, message, args);
                            return;
                        }
                    }
                }
            }
        private:
            std::vector<mdcore::Command> commands;
    };
}
#endif