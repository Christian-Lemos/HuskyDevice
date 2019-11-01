#include "Sensor.h"
#include "DHT.h"
#pragma once
class DHT22Sensor : public husky::Sensor
{
	private:
		DHT dht;
		husky::MensagemMqtt* mensagemHumidade;
		husky::MensagemMqtt* mensagemTemperatura;
	public:
		virtual std::vector<husky::MensagemMqtt> executar();
		DHT22Sensor(int);
};
