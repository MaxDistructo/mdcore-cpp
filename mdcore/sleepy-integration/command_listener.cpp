#include "command_listener.h"

mdcore::CommandListener::CommandListener(std::vector<mdcore::Command> commands)
{
    this->commands = commands;
}