#ifndef J_PORTEXPANDER_H
#define J_PORTEXPANDER_H

#include "ioPin.hpp"

namespace jFramework
{
    class portExpander : public jObject
    {
    public:
        portExpander(const char *name);
        virtual ~portExpander() {}
        virtual j_err setPinDirection(uint8_t pin, pinDirection dir) { return J_ERR_NO_IMPLEMENTATION; }
        virtual bool pinDirectionSupported(uint8_t pin, pinDirection dir) { return false; }
        virtual j_err setPin(uint8_t pin, uint8_t val) { return J_ERR_NO_IMPLEMENTATION; }
        virtual j_err getPin(uint8_t pin, uint8_t &val) { return J_ERR_NO_IMPLEMENTATION; }
        virtual bool canSetPin(uint8_t pin) { return false; }
        virtual bool canGetPin(uint8_t pin) { return false; }
        virtual ioPin *getIOPin(uint8_t pin) { return nullptr; }

    protected:
    private:
    };

    class portExpanderPin : public ioPin
    {
    public:
        portExpanderPin(const char *name, uint8_t pinNumber, portExpander *port);
        ~portExpanderPin();
        j_err mode(pinDirection dir);
        j_err set(uint8_t value);
        j_err get(uint8_t &value);
        bool canSet();
        bool canGet();
    protected:
        portExpander* _port;

    };
} // namespace jFramework

#endif