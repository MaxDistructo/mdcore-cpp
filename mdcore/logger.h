#ifndef __mdcore_Logger_h
#define __mdcore_Logger_h

#include <string>

namespace mdcore{
        class Logger
        {
            public:
                Logger(char* name);
                ~Logger();
                void info(std::string message);
                void debug(std::string message);
                void warning(std::string message);
                void error(std::string message);
                void fatal(std::string message);
            private:
                char* logger_name;
        };
        class TerminalColor
        {
            public:
                const char* BLACK = "\033[0;30m";
                const char* RED = "\033[0;31m";
                const char* GREEN = "\033[0;32m";
                const char* YELLOW = "\033[0;33m";
                const char* BLUE = "\033[0;34m";
                const char* PURPLE = "\033[0;35m";
                const char* CYAN = "\033[0;36m";
                const char* WHITE = "\033[0;37m";
                const char* BOLD_BLACK = "\033[1;30m";
                const char* BOLD_RED = "\033[1;31m";
                const char* BOLD_GREEN = "\033[1;32m";
                const char* BOLD_YELLOW = "\033[1;33m";
                const char* BOLD_BLUE = "\033[1;34m";
                const char* BOLD_PURPLE = "\033[1;35m";
                const char* BOLD_CYAN = "\033[1;36m";
                const char* BOLD_WHITE = "\033[1;37m";
                const char* RESET = "\033[0m";
        };
        TerminalColor color;
}

#endif