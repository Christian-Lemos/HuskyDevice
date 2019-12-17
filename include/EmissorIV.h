#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <IRac.h>
#include <functional>

namespace husky
{
	#pragma once
	class EmissorIV
	{
		private:
			short unsigned int m_gpio;
			void Iniciar(int, decode_type_t, stdAc::opmode_t);
		public:
			IRac ac;
			explicit EmissorIV(unsigned int, unsigned int, decode_type_t, stdAc::opmode_t);
			explicit EmissorIV(unsigned int, unsigned int, unsigned int, stdAc::opmode_t);
			explicit EmissorIV(unsigned int, unsigned int, decode_type_t, int);
			explicit EmissorIV(unsigned int, unsigned int, unsigned int, int);
			~EmissorIV(){}

			unsigned int getGPIO() const { return this->m_gpio; };
	};
}


