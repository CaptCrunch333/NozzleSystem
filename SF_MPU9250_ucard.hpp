#pragma once 

#include "data_storage.hpp"

class MemoryCard : public DataStorage
{
	public:

		virtual void setFileName(std::string) = 0;
		virtual void saveData(std::list<uint8_t>*, std::string) = 0;
		virtual DataMessage* loadData(std::string) = 0;
		virtual void deleteData(std::string) = 0;
};