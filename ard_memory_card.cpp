#include "ard_memory_card.hpp"

ArduinoMemoryCard::ArduinoMemoryCard(int t_pin, MsgSerializerDeserializer* t_handler)
{
	m_handler = t_handler;
	if(!SD.begin(SD_CHIP_SELECT_PIN))
	{
		//TODO: add warning
	}
}

void ArduinoMemoryCard::deleteFile(std::string t_name)
{
	SD.remove(t_name.c_str());
	//TODO: add "remove" check
	// if(!SD.exists(t_name.c_str()))
	// 	return true;
	// else
	// 	return false;
}

void ArduinoMemoryCard::saveData(DataMessage* t_msg, std::string t_name)
{
	m_serial_data = m_handler->serialize(t_msg);
	writeSDCard(t_name, m_serial_data->data, m_serial_data->len);
	//TODO: add a message "write" check to make sure all data is wrote
}

DataMessage* ArduinoMemoryCard::loadData(std::string t_name)
{
	std::list<uint8_t> buffer;
	int t_msg_len = readSDCard(t_name, &buffer);
	m_msg = m_handler->deserialize(&buffer);
	// TODO: add a len chack here to make sure all data is read
	return m_msg;
}


void ArduinoMemoryCard::writeSDCard(std::string t_name, uint8_t t_data[], int t_len)
{
	File temp;
	temp = SD.open(t_name.c_str(),FILE_WRITE);
	temp.write(t_data,t_len);
	temp.close();
}

int ArduinoMemoryCard::readSDCard(std::string t_name, std::list<uint8_t>* t_data)
{
	File temp;
	temp = SD.open(t_name.c_str());
	while(temp.available())
	{
		t_data->push_back(temp.read());
	}
	temp.close();
}