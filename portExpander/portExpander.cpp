#include "portExpander.hpp"

using namespace jFramework;

jFramework::portExpander::portExpander(const char *name)
: jObject(name)
{
}

portExpanderPin::portExpanderPin(const char *name, uint8_t pinNumber, portExpander *port)
:ioPin(name, pinNumber), _port(port)
{
    _connected = true;
}

portExpanderPin::~portExpanderPin()
{
}

j_err jFramework::portExpanderPin::mode(pinDirection dir)
{
    return _port->setPinDirection(_pinNumber, dir);
}

j_err jFramework::portExpanderPin::set(uint8_t value)
{
    return _port->setPin(_pinNumber, value);
}

j_err jFramework::portExpanderPin::get(uint8_t &value)
{
    return _port->getPin(_pinNumber, value);
}

bool jFramework::portExpanderPin::canSet()
{
    return _port->canGetPin(_pinNumber);
}

bool jFramework::portExpanderPin::canGet()
{
    return _port->canGetPin(_pinNumber);
}


