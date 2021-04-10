#include "logger.h"

using namespace mdcore::Logger;
const TerminalColor COLOR;
Logger::Logger(char* name)
{
    this->logger_name = name;
};
Logger::~Logger(){};
void Logger::info(std::string message)
{
    printf("%s", COLOR.WHITE);
    printf("%s", ((std::string)"[INFO] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", COLOR.RESET);
    printf("%s", "\n");
};
void Logger::debug(std::string message)
{
    printf("%s", COLOR.YELLOW);
    printf("%s", ((std::string)"[DEBUG] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", COLOR.RESET);
    printf("%s", "\n");
};
void Logger::warning(std::string message)
{
    printf("%s", COLOR.BOLD_YELLOW);
    printf("%s", ((std::string)"[WARNING] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", COLOR.RESET);
    printf("%s", "\n");
};
void Logger::error(std::string message)
{
    printf("%s", COLOR.RED);
    printf("%s", ((std::string)"[ERROR] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", COLOR.RESET);
    printf("%s", "\n");
};
void Logger::fatal(std::string message)
{
    printf("%s", COLOR.BOLD_RED);
    printf("%s", ((std::string)"[FATAL] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", COLOR.RESET);
    printf("%s", "\n");
};