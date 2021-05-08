#include "../include/mdcore/command_listener.h"
/**
 * @brief Construct a new mdcore::Command Listener::Command Listener object
 * 
 * The preferred constructor for this object, construct using a command array
 * and a specified prefix. 
 *
 * @param commands - The vector of commands for this listener
 * @param prefix - The prefix for this listener
 */
mdcore::CommandListener::CommandListener(std::vector<mdcore::Command*> commands, std::string prefix)
{
    this->commands = commands;
    this->name = "CommandListener";
    this->prefix = prefix;
}
/**
 * @brief Destroy the mdcore::Command Listener::Command Listener object
 * 
 * We don't do anything on destruction as everything done in this object 
 * is not dynamically allocated.
 *
 * @author MaxDistructo
 */
mdcore::CommandListener::~CommandListener(){};
/**
 * @brief Construct a new mdcore::Command Listener::Command Listener object
 * 
 */
mdcore::CommandListener::CommandListener()
{
    commands = {};
    this->name = "CommandListener";
};
/**
 * @brief Register a command for use with this command listener
 * 
 * @param command 
 */
void mdcore::CommandListener::registerCommand(mdcore::Command* command)
{
    this->commands.push_back(command);
}