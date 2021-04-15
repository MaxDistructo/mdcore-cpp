#include "include/mdcore/command_listener.h"

mdcore::CommandListener::CommandListener(std::vector<mdcore::Command*> commands, std::string prefix)
{
    this->commands = commands;
    this->name = "CommandListener";
    this->prefix = prefix;
}
mdcore::CommandListener::~CommandListener(){};
mdcore::CommandListener::CommandListener()
{
    commands = {};
    this->name = "CommandListener";
};
void mdcore::CommandListener::registerCommand(mdcore::Command* command)
{
    this->commands.push_back(command);
}