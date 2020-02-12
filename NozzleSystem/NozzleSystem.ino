#undef max
#undef min

#include "arduino_serial_comm_device.hpp"
#include "BaseCommunication.hpp"
#include "common_types.hpp"
#include "IMURateProvider.hpp"
#include "SF_MPU9250_sensor.hpp"
#include "Arduserv.hpp"
#include "NozzleActuation.hpp"
#include "looper.hpp"
#include "CommChecker.hpp"
#include "ArduinoLogger.hpp"
#include "PumpActuation.hpp"
#include "ArduPump.hpp"

// NECESSaRY TO ADD IN ORDER TO PASS VECTORS!!!! /////////////////////////////
// namespace std {
// void __throw_bad_alloc() {
//   // Serial.println("Unable to allocate memory");
//   while (true) {}
//   }
// }
//////////////////////////////////////////////////////////////////////////////

ArduinoSerialCommDevice* dev1;
BaseCommunication* com_stack1;
CommChecker* main_checker;

SFMPU9250_sensor* main_imu;

IMURateProvider* main_rate_prov;

Actuator* pitch_motor;
Actuator* yaw_motor;
Actuator* water_pump;
std::vector<Actuator*> actuators;
ActuationSystem* main_Actuation_System;
ActuationSystem* main_Pump_System;

Looper* main_looper;

void setup()
{
  delay(2000);
  // ************************************ LOGGER ************************************
  //Logger::assignLogger(new ArduinoLogger());
  //Logger::getAssignedLogger()->log("start of logger ",LoggerLevel::Warning);
  // ********************************************************************************
  // ***************************** COMMUNICATION DEVICE *****************************
  dev1 = new ArduinoSerialCommDevice(block_frequency::hz100);
  com_stack1 = new BaseCommunication((CommDevice*)dev1);
  int x = 500000;
  dev1->attach_hardware_sender((void*) &(x));
  main_checker = new CommChecker(dev1, (void*) &x, block_frequency::hz10);
  // ********************************************************************************
  // ************************************* IMU **************************************
  main_imu = new SFMPU9250_sensor();
  main_imu->setSettings(ACCELEROMETER, FSR, 16);
  main_imu->setSettings(GYROSCOPE, FSR, 2000);
  main_imu->setSettings(GYROSCOPE, LPF, 42);
  main_imu->setSettings(GYROSCOPE, SAMPLERATE, 1000);
  main_imu->setSettings(MAGNETOMETER, SAMPLERATE, 100);
  // ********************************************************************************
  // ****************************** IMU RATE PROVIDER *******************************
  main_rate_prov = new IMURateProvider((BodyRateProvider*) main_imu->getGyro(), block_frequency::hz100);
  // ********************************************************************************
  // ************************* ACTUATORS & ACTUATION SYSTEM *************************
  pitch_motor = new Arduserv(13, true, -90); //ugv: pitch: 80 true
  yaw_motor = new Arduserv(12, true, -60); //ugv: yaw: 60 false
  actuators.push_back(pitch_motor);
  actuators.push_back(yaw_motor);
  main_Actuation_System = new NozzleActuation(pitch_motor, yaw_motor);
  ((NozzleActuation*)main_Actuation_System)->setRange(-30, 30);
  // ********************************************************************************
  // ******************************* PUMP CONTROLLER ********************************
  water_pump = new ArduPump(11, RelayType::NO);
  main_Pump_System = new PumpActuation(water_pump);
  // ********************************************************************************
  main_looper = new Looper();
  main_looper->addTimedBlock((TimedBlock*) main_rate_prov);
  main_looper->addTimedBlock((TimedBlock*) dev1);
  main_looper->addTimedBlock((TimedBlock*) main_checker);
  // **************************** SYSTEM CONNECTIONS ******************************
  com_stack1->add_callback_msg_receiver((msg_receiver*) main_checker);
  main_checker->add_callback_msg_receiver((msg_receiver*) com_stack1);
  main_rate_prov->add_callback_msg_receiver((msg_receiver*) com_stack1);
  com_stack1->add_callback_msg_receiver((msg_receiver*) main_Actuation_System);
  com_stack1->add_callback_msg_receiver((msg_receiver*) main_Pump_System);
  // ********************************************************************************
}

void loop()
{
  main_looper->Loop();
}
