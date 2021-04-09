#include <vector>
#include "command.h"

namespace mdcore
{
    class CommandListener{
        public:
            CommandListener();
            ~CommandListener();
            CommandListener(std::vector<mdcore::Command> commands)
        private:
            std::vector<mdcore::Command> commands;
    }
}