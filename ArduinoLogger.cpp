#include "ArduinoLogger.hpp"

void ArduinoLogger::log(const char* t_log,LoggerLevel t_log_level)
{
    printLogLevel(t_log_level);
    SerialUSB.println(t_log);
}

void ArduinoLogger::log(const char* t_log,float t_para_1,LoggerLevel t_log_level)
{
    printLogLevel(t_log_level);
    SerialUSB.println(t_log + String(t_para_1));
}

void ArduinoLogger::log(const char* t_log,float t_para_1,float t_para_2,LoggerLevel t_log_level)
{
    printLogLevel(t_log_level);
    SerialUSB.println(t_log + String(t_para_1) + String(t_para_2));
}

void ArduinoLogger::log(const char* t_log,float t_para_1 ,float t_para_2,float t_para_3,LoggerLevel t_log_level)
{
    printLogLevel(t_log_level);
	SerialUSB.println(t_log + String(t_para_1) + String(t_para_2) + String(t_para_3));
}

void ArduinoLogger::enableFileLog(LoggerLevel)
{
    //TODO: Implement
}

void ArduinoLogger::disableFileLog()
{
    //TODO: Implement
}

void ArduinoLogger::printLogLevel(LoggerLevel t_log_level)
{
    switch (t_log_level)
    {
        case LoggerLevel::Info:
        {
			SerialUSB.print("Info: ");
            break;
        }
        case LoggerLevel::Warning:
        {
			SerialUSB.print("Warn: ");
            break;
        }
        case LoggerLevel::Error:
        {
			SerialUSB.print("Error: ");
            break;
        }
    }
}