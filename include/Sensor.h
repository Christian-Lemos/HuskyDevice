#include <string>
#include <Arduino.h>
#include <vector>
#include "utils.h"
#pragma once

namespace husky
{
	class Sensor
	{
		protected:
			std::string nome;
			int GPIO; // pino do sensor
			std::vector<husky::MensagemMqtt> retornoExecucao; // 
		public:
			virtual std::vector<husky::MensagemMqtt> executar() = 0;
			int intervalo; //Intervalo de envio de dados para o ucmr
			unsigned long ultimoIntervalo = 10000;
			int getGPIO() const; // nao deixa alterar qualquer atributo da classe 
			void setGPIO(int);
			explicit Sensor(int);
	};

}


