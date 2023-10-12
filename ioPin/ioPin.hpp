#ifndef J_IO_PIN_H
#define J_IO_PIN_H

#include "jObject.hpp"

namespace jFramework
{
    enum pinDirection
    {
        PIN_UNSET,
        PIN_INPUT,
        PIN_INPUT_PULLUP,
        PIN_INPUT_PULLDOWN,
        PIN_OUTPUT,
        PIN_OUTPUT_OPEN_DRAIN,
        PIN_OUTPUT_PWM
    };

    class ioPin : public jObject
    {
    public:
        ioPin(const char *name, uint8_t pinNumber);
        virtual ~ioPin() {}
        uint8_t getNumber();
        bool isConnected();
        virtual j_err mode(pinDirection dir) { return J_ERR_NO_IMPLEMENTATION; }
        virtual j_err set(uint8_t value) { return J_ERR_NO_IMPLEMENTATION; }
        virtual j_err get(uint8_t &value) { return J_ERR_NO_IMPLEMENTATION; }
        virtual bool canSet() { return false; }
        virtual bool canGet() { return false; }
        virtual j_err setVoltage(int32_t voltage_mV) { return J_ERR_NO_IMPLEMENTATION; }
        virtual j_err getVoltage(int32_t &voltage_mV) { return J_ERR_NO_IMPLEMENTATION; }
        static ioPin *dummyPin();

    protected:
        uint8_t _pinNumber;
        bool _connected;

    private:
        static ioPin *_dummyPin;
    };

    class ioPinDummy : public ioPin
    {
    public:
        ioPinDummy(const char *name);
        ~ioPinDummy();
        j_err mode(pinDirection dir);
        j_err set(uint8_t value);
        j_err get(uint8_t &value);
        bool canSet();
        bool canGet();

    protected:
        uint8_t _pinNumber;

    private:
        static ioPin *_dummyPin;
    };

} // namespace jFramework

#endif