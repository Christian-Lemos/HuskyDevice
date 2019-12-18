#include <Arduino.h>
#include "Sensor.h"
#include "utils.h"
#include "SensorFactory.h"
#include "HuskyDevice.h"
#include "patch.h"
#include <memory>
#include "EmissorIV.h"


husky::TipoUpload tipo = husky::NODE_MCU;

HuskyDevice dispositivo(tipo);

void setup()
{
	Serial.begin(115200);
	delay(2000);

	dispositivo.Conectar("LAB207", "poli@lab207#", "200.132.36.147", 1883, "usuario", "senha"); //ssid, senha, broker, porta, mqttusuario, mqttsenha
	Serial.println("Conectado");
	if (tipo == husky::SONOFF_POW)
	{
		std::unique_ptr<husky::Sensor> shlw = SensorFactory::CriarSensor("hlw8012", 5); //O 5 n�o importa. 
		dispositivo.AdicionarSensor(std::move(shlw));
	}

	if(tipo == husky::NODE_MCU)
	{
		dispositivo.AdicionarSensor(SensorFactory::CriarSensor("statepir", 3)); // sensor factory parametro string e um gpio
		dispositivo.AdicionarSensor(SensorFactory::CriarSensor("dht22", 5));

		dispositivo.emissorIV = new husky::EmissorIV(1, 13, 14, 1); //EmissorIV(modelo, gpio, protocolo, i modo)
	}
	

	
}

void loop()
{
	dispositivo.Loop();
}