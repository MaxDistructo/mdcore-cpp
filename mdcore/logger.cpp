#include "logger.h"

using namespace mdcore::Logger;
Logger::Logger(std::string name)
{
    this->logger_name = name;
};
Logger::~Logger(){};
void Logger::info(std::string message)
{
    printf("%s", color.WHITE);
    printf("%s", ((std::string)"[INFO] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", color.RESET);
    printf("%s", "\n");
};
void Logger::debug(std::string message)
{
    printf("%s", color.YELLOW);
    printf("%s", ((std::string)"[DEBUG] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", color.RESET);
    printf("%s", "\n");
};
void Logger::warning(std::string message)
{
    printf("%s", color.BOLD_YELLOW);
    printf("%s", ((std::string)"[WARNING] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", color.RESET);
    printf("%s", "\n");
};
void Logger::error(std::string message)
{
    printf("%s", color.RED);
    printf("%s", ((std::string)"[ERROR] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", color.RESET);
    printf("%s", "\n");
};
void Logger::fatal(std::string message)
{
    printf("%s", color.BOLD_RED);
    printf("%s", ((std::string)"[FATAL] [" + this->logger_name + "] " + message).c_str());    
    printf("%s", color.RESET);
    printf("%s", "\n");
};