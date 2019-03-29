#include <Arduino.h>
#include "HuskDevice.h"
#include "Sensor.h"
#include "utils.h"
#include "SensorFactory.h"
#include "patch.h"
#include <memory>

husky::TipoUpload tipo = husky::NODE_MCU;
//TipoUpload tipo = SONOFF_BASIC;
//TipoUpload tipo = SONOFF_POW;

std::unique_ptr<HuskDevice> dispositivo;

void setup()
{
	Serial.begin(115200);
	delay(2000);

	dispositivo = std::unique_ptr<HuskDevice>(patch::make_unique<HuskDevice>(tipo));
	HuskDevice* pointerHuskerDevice = dispositivo.get();
	
	pointerHuskerDevice->Conectar("LAB207", "poli@lab207#", "200.132.36.147", 1883, "usuario", "senha"); //ssid, senha, broker, porta, mqttusuario, mqttsenha
	Serial.println("Conectado");
	if (tipo == husky::SONOFF_POW)
	{
		std::unique_ptr<husky::Sensor> shlw = SensorFactory::CriarSensor("hlw8012", 5); //O 5 n�o importa. 
		pointerHuskerDevice->AdicionarSensor(std::move(shlw));
	}
}

void loop()
{
	dispositivo.get()->Loop();
}