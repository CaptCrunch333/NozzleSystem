#pragma once

#include "logger.hpp"
#include "Arduino.h"
#undef max
#undef min

class ArduinoLogger : public Logger
{
    private:
    LoggerLevel file_logger_level=LoggerLevel::Info;
	void printLogLevel(LoggerLevel);
    public:
    void log(const char*,LoggerLevel);
    void log(const char*,float,LoggerLevel);
    void log(const char*,float,float,LoggerLevel);
    void log(const char*,float,float,float,LoggerLevel);
    void enableFileLog(LoggerLevel);// Example: if LoggerLevel::Warning is passed only LoggerLevel::Warning and LoggerLevel::Error will be written to file
    void disableFileLog();
};