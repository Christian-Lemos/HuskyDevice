#include "EmissorIV.h";

husky::EmissorIV::EmissorIV(unsigned int modelo, unsigned int gpio, decode_type_t protocolo, stdAc::opmode_t modo): m_gpio(gpio), ac(gpio)
{
	this->Iniciar(modelo, protocolo, modo);
}


husky::EmissorIV::EmissorIV(unsigned int modelo, unsigned int gpio, unsigned int protocolo, stdAc::opmode_t modo): m_gpio(gpio), ac(gpio)
{
	this->Iniciar(modelo, static_cast<decode_type_t>(protocolo), modo);  // Set a protocol to use.
}

husky::EmissorIV::EmissorIV(unsigned int modelo, unsigned int gpio, decode_type_t protocolo, int modo): m_gpio(gpio), ac(gpio)
{
	this->Iniciar(modelo, protocolo, static_cast<stdAc::opmode_t>(modo));
}


husky::EmissorIV::EmissorIV(unsigned int modelo, unsigned int gpio, unsigned int protocolo, int modo): m_gpio(gpio), ac(gpio)
{
	this->Iniciar(modelo, static_cast<decode_type_t>(protocolo), static_cast<stdAc::opmode_t>(modo));  // Set a protocol to use.
}

void husky::EmissorIV::Iniciar(int modelo, decode_type_t protocolo, stdAc::opmode_t modo)
{
	ac.next.protocol = protocolo;  // Set a protocol to use.
	ac.next.model = modelo;  // Some A/Cs have different models. Try just the first.
	ac.next.mode = modo;  // Run in cool mode initially.
	ac.next.celsius = true;  // Use Celsius for temp units. False = Fahrenheit
	ac.next.degrees = 25;  // 25 degrees.
	ac.next.fanspeed = stdAc::fanspeed_t::kMedium;  // Start the fan at medium.
	ac.next.swingv = stdAc::swingv_t::kOff;  // Don't swing the fan up or down.
	ac.next.swingh = stdAc::swingh_t::kOff;  // Don't swing the fan left or right.
	ac.next.light = false;  // Turn off any LED/Lights/Display that we can.
	ac.next.beep = false;  // Turn off any beep from the A/C if we can.
	ac.next.econo = false;  // Turn off any economy modes if we can.
	ac.next.filter = false;  // Turn off any Ion/Mold/Health filters if we can.
	ac.next.turbo = false;  // Don't use any turbo/powerful/etc modes.
	ac.next.quiet = false;  // Don't use any quiet/silent/etc modes.
	ac.next.sleep = -1;  // Don't set any sleep time or modes.
	ac.next.clean = false;  // Turn off any Cleaning options if we can.
	ac.next.clock = -1;  // Don't set any current time if we can avoid it.
	ac.next.power = false;  // Initially start with the unit off.
}


