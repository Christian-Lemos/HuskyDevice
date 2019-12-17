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
			 // 
			void virtual lerSensor() = 0;
		public:
			std::vector<husky::MensagemMqtt> retornoExecucao;
			virtual bool executar() //Se true então pode enviar os dados
			{
				if ((millis() - this->ultimoIntervalo) >= this->intervalo)
				{
					this->ultimoIntervalo = millis();
					this->lerSensor();
					return true;
				}
				return false;
			};
			unsigned int intervalo; //Intervalo de envio de dados para o ucmr
			unsigned long ultimoIntervalo = 10000;
			int getGPIO() const; // nao deixa alterar qualquer atributo da classe 
			void setGPIO(int);
			explicit Sensor(int);
	};

}


