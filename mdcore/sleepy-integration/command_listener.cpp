#include "command_listener.h"

mdcore::CommandListener::CommandListener(std::vector<mdcore::Command> commands)
{
    this->commands = commands;
}
mdcore::CommandListener::~CommandListener()
{};
mdcore::CommandListener::CommandListener()
{
    commands = {};
};