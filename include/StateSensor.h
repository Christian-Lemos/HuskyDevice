#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <functional>
#include <Sensor.h>




namespace husky
{
	#pragma once
	class StateSensor: public Sensor // equivalente ao extends 
	{
		protected:
			virtual bool deveEnviar() = 0;//True para enviar os dados
			virtual bool executar(){
				this->lerSensor(); 
				return this->deveEnviar();
			}
		public:
			explicit StateSensor(unsigned int);
			~StateSensor();
	};
}


