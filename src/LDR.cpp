#include "LDR.h"
// Implementação da classe
std::vector<husky::MensagemMqtt> LDR::executar() 
{
	int ldrValor = analogRead(GPIO);
	char strValor[5];

	strValor[0] = '\0';
	itoa(ldrValor, strValor, 10); // converte int em string 
	
	this->mensagemLDR->payload.assign(strValor); // é mesma coisa que usar =

	return retornoExecucao; //retorna a mensagem 
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
