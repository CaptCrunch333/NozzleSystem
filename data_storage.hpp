#pragma once 

#include <string>
#include <list>
#include "DataMessage.hpp"

class DataStorage
{
	public:

		virtual void deleteFile(std::string) = 0;
		virtual void saveData(DataMessage*, std::string) = 0;
		virtual DataMessage* loadData(std::string) = 0;
};