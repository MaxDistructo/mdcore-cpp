#include "command.h"

namespace mdcore{
        std::string Command::getName()
        {
            return this->name;
        }
        std::vector<std::string> Command::getAltNames()
        {
            return this->altNames;
        }
        std::string Command::getHelp()
        {
            return this->help;
        }
        Command::Command()
        {
            this->name = "";
            this->altNames = {""};
            this->help = "";
        }
        void Command::setName(std::string name)
        {
            this->name = name;
        }
        void Command::setAltNames(std::vector<std::string> altNames)
        {
            this->altNames = altNames;
        }
        void Command::setHelp(std::string help)
        {
            this->help = help;
        }
}