#pragma once
#include "Sensor.h"
class Microondas : public husky::Sensor
{
	private:
		husky::MensagemMqtt* mensagemMicroondas;
	public:
		virtual void lerSensor();
		Microondas(int);
};


