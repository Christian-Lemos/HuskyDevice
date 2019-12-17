#pragma once
#include "Sensor.h"
// Classe
class LDR : public husky::Sensor {
	private:
		husky::MensagemMqtt* mensagemLDR;
	public:
		virtual void lerSensor();
		LDR(int);
};

