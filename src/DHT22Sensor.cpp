#include "DHT.h"
#include "DHT22Sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Arduino.h>

#define DHTTYPE DHT22

void DHT22Sensor::lerSensor()
{	
	float humidade = dht.readHumidity();
	float temperatura = dht.readTemperature();

	char hSTR[7];
	char tSTR[7];
	snprintf(hSTR, sizeof(hSTR), "%.0f", humidade);
	snprintf(tSTR, sizeof(tSTR), "%.0f", temperatura);
	
	this->mensagemHumidade->payload.assign(hSTR);
	this->mensagemTemperatura->payload.assign(tSTR);
}

DHT22Sensor::DHT22Sensor(int gpio) : husky::Sensor(gpio)
{
	this->retornoExecucao.reserve(2);
	this->retornoExecucao.emplace_back("humidade", "");
	this->retornoExecucao.emplace_back("temperatura", "");

	this->mensagemHumidade = &this->retornoExecucao.at(0);
	this->mensagemTemperatura = &this->retornoExecucao.at(1);

	this->intervalo = 60000;

	dht = DHT(gpio, DHTTYPE);
	dht.begin();	
}