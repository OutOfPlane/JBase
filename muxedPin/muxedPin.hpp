#ifndef J_MUXED_PIN_H
#define J_MUXED_PIN_H

#include "jObject.hpp"
#include "ioPin.hpp"
#include "externalMux.hpp"

namespace jFramework
{
    class muxedPin : public ioPin
    {
    public:
        muxedPin(const char *name, ioPin *sharedPin, externalMux *pinMux, uint8_t pinNumber);
        j_err getVoltage(int32_t &voltage_mV);

    private:
        ioPin *_sharedPin;
        externalMux *_pinMux;
    };

} // namespace jFramework

#endif