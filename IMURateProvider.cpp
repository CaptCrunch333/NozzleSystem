#include "IMURateProvider.hpp"

IMURateProvider::IMURateProvider(BodyRateProvider* t_rate_prov, block_frequency t_freq) : TimedBlock(t_freq)
{
    m_rate_prov = t_rate_prov;
}

void IMURateProvider::loopInternal(void)
{
    m_data.data = this->getBodyRate();
    //SerialUSB.println("sending imu data: " + String(m_data.data.x) + " " + String(m_data.data.y) + " " + String(m_data.data.z));
    this->emit_message((DataMessage*) &m_data);
}

Vector3D<float> IMURateProvider::getBodyRate(void)
{
    return m_rate_prov->getBodyRate();
}