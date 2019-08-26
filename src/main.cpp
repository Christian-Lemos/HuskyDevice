#include <Arduino.h>
#include "Sensor.h"
#include "utils.h"
#include "SensorFactory.h"
#include "HuskyDevice.h"
#include "patch.h"
#include <memory>

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
}

void loop()
{
	dispositivo.Loop();
}