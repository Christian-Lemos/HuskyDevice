#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <functional>
#include <Sensor.h>

typedef std::function<void(const std::vector<husky::MensagemMqtt>)> callback_signature;


namespace husky
{
	#pragma once
	class StateSensor: public Sensor
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


