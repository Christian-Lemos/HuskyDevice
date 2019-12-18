#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <functional>
#include <Sensor.h>

namespace husky
{
	#pragma once
	class StateSensor: public husky::Sensor // equivalente ao extends 
	{
		protected:
			virtual bool deveEnviar() = 0;//True para enviar os dados
			virtual void lerSensor() = 0;
		public:
			virtual bool executar(){
				this->lerSensor(); 
				return this->deveEnviar();
			}
			explicit StateSensor(unsigned int);
			~StateSensor();
	};
}


