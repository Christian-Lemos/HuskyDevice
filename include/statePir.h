#include "Sensor.h"
#include "StateSensor.h"

#pragma once
class StatePIR : public husky::StateSensor {

	private:
		husky::MensagemMqtt* mensagemPIR;
	protected:
		virtual bool DeveEnviar();
	public:
		virtual void lerSensor();
		StatePIR(int);
};

