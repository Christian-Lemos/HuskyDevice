#include "DHT.h"
#include "DHT11Sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Arduino.h>

#define DHTTYPE DHT11

std::vector<husky::MensagemMqtt> DHT11Sensor::executar()
{	
	float humidade = dht.readHumidity();
	float temperatura = dht.readTemperature();

	char hSTR[7];
	char tSTR[7];
	snprintf(hSTR, sizeof(hSTR), "%.0f", humidade); // converte float para string
	snprintf(tSTR, sizeof(tSTR), "%.0f", temperatura);// converte float para string
	
	this->mensagemHumidade->payload.assign(hSTR);
	this->mensagemTemperatura->payload.assign(tSTR);
	return retornoExecucao;
}

DHT11Sensor::DHT11Sensor(int gpio) : husky::Sensor(gpio)
{
	this->retornoExecucao.reserve(2);
	this->retornoExecucao.emplace_back("humidade", ""); //começa com payload vazio e completa nessa linha 
	this->retornoExecucao.emplace_back("temperatura", "");

	this->mensagemHumidade = &this->retornoExecucao.at(0); // a mensagem umidade é um ponteiro que aponta para a primeira posição do vetor 
	this->mensagemTemperatura = &this->retornoExecucao.at(1);

	this->intervalo = 60000;

	dht = DHT(gpio, DHTTYPE);
	dht.begin();	
}