#include "ioPin.hpp"
#include "adc.hpp"

using namespace jFramework;

jFramework::ADC::ADC(const char *name, uint16_t numChannels)
: jObject(name), _numChannels(numChannels)
{
}

jFramework::adcPin::adcPin(const char *name, uint8_t pinNumber, ADC *adc, float scale)
: ioPin(name, pinNumber), _adc(adc)
{
    _fastScale = scale * 1000;
}

j_err jFramework::adcPin::getVoltage(int32_t &voltage_mV)
{
    if(_adc->lock(*this, 100))
    {
        j_err erg = J_OK;
        if((erg = _adc->selectChannel(_pinNumber)) == J_OK)
            erg = _adc->read(voltage_mV);
        _adc->unlock();

        voltage_mV *= _fastScale;
        voltage_mV /= 1000;

        return erg;
    }
    return J_ERR_OBJECT_LOCKED;
}
