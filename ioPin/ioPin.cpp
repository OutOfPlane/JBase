#include "ioPin.hpp"

using namespace jFramework;

ioPin::ioPin(const char *name, uint8_t pinNumber)
    : jObject(name), _pinNumber(pinNumber)
{
    _connected = false;
}

uint8_t ioPin::getNumber()
{
    return _pinNumber;
}

bool jFramework::ioPin::isConnected()
{
    return _connected;
}

ioPin* ioPin::_dummyPin = nullptr;

ioPin *ioPin::dummyPin()
{
    if(!_dummyPin)
        _dummyPin = new ioPinDummy("IO_DUMMY");
    return _dummyPin;
}

ioPinDummy::ioPinDummy(const char *name)
: ioPin(name, 0)
{
}

jFramework::ioPinDummy::~ioPinDummy()
{
}

j_err jFramework::ioPinDummy::mode(pinDirection dir)
{
    return J_OK;
}

j_err jFramework::ioPinDummy::set(uint8_t value)
{
    return J_OK;
}

j_err jFramework::ioPinDummy::get(uint8_t &value)
{
    value = 1;
    return J_OK;
}

bool jFramework::ioPinDummy::canSet()
{
    return true;
}

bool jFramework::ioPinDummy::canGet()
{
    return true;
}
