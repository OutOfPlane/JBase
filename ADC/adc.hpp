#ifndef J_ADC_H
#define J_ADC_H

#include "jObject.hpp"
#include "ioPin.hpp"

namespace jFramework
{
    class ADC : public jObject
    {
    public:
        ADC(const char *name, uint16_t numChannels);
        virtual ~ADC() {}
        virtual j_err selectChannel(uint16_t channel) { return J_ERR_NO_IMPLEMENTATION; }
        virtual j_err read(int32_t &value_mV) { return J_ERR_NO_IMPLEMENTATION; }

    protected:
        uint16_t _numChannels = 0;

    private:
    };

    class adcPin : public ioPin
    {
    public:
        adcPin(const char *name, uint8_t pinNumber, ADC *adc, float scale);
        j_err getVoltage(int32_t &voltage_mV);

    protected:
        int32_t _fastScale;
        ADC *_adc;

    private:
    };

} // namespace jFramework

#endif