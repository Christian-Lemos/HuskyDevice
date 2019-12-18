
#include "Sensor.h"
// Classe
#pragma once
class LDR : public husky::Sensor {
	private:
		husky::MensagemMqtt* mensagemLDR;
	public:
		virtual void lerSensor();
		LDR(int);
};

