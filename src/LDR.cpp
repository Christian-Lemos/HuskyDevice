#include "LDR.h"
// Implementação da classe
void LDR::lerSensor() 
{
	int ldrValor = analogRead(GPIO);
	int lux = 5.2053*pow(EULER,(0.0058*ldrValor));

	char strValor[5];
	strValor[0] = '\0';
	itoa(lux, strValor, 10); // converte int em string 
	
	this->mensagemLDR->payload.assign(strValor); // é mesma coisa que usar =
}

LDR::LDR(int gpio) : Sensor(gpio) // Construtor da classe - Sensor (gpio) = construtor da classe super no java
{
	this->retornoExecucao.reserve(1);

	this->retornoExecucao.emplace_back("ldr", ""); // Ldr tópico - Payload ainda vazio. É o mesmo que fazer oque tem na linha comentada abaixo
	//this->retornoExecucao.emplace_back(new husky::MensagemMqtt("topico", "payload"));
	
	this->mensagemLDR = &this->retornoExecucao.at(0);
	pinMode(gpio, OUTPUT);
	intervalo = 30000;
}
