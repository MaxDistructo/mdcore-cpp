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
        Command::Command()
        {
            this->name = "";
            this->altNames = {""};
            this->help = "";
        }
}