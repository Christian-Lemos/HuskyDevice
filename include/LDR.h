#pragma once
#include "Sensor.h"
// Classe
class LDR : public husky::Sensor {
	private:
		husky::MensagemMqtt* mensagemLDR;
	public:
		virtual std::vector<husky::MensagemMqtt> executar();
		LDR(int);
};

