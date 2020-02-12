#pragma once 

#include <SD.h>
#undef max
#undef min
#include "data_storage.hpp"
#include "msg_serializer_deserializer.hpp"


class ArduinoMemoryCard : public DataStorage
{
	public:
		ArduinoMemoryCard(int, MsgSerializerDeserializer*);
		void deleteFile(std::string);
		void saveData(DataMessage*, std::string);
		DataMessage* loadData(std::string);
	
	protected:

		SerialDataMsg* m_serial_data;
		DataMessage* m_msg;

		MsgSerializerDeserializer* m_handler;

		void writeSDCard(std::string, uint8_t t_data[], int);
		int readSDCard(std::string, std::list<uint8_t>*);
};