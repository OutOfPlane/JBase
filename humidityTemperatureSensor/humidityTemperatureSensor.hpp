#ifndef J_HUMIDITY_TEMPERATURE_H
#define J_HUMIDITY_TEMPERATURE_H

#include "jObject.hpp"

namespace jFramework
{
    class humidityTemperatureSensor : public jObject
    {
    public:
        humidityTemperatureSensor(const char *name);
        virtual ~humidityTemperatureSensor() {}
        virtual j_err getHumidity(int32_t &relhumidity_promill) { return J_ERR_NO_IMPLEMENTATION; }
        virtual j_err getTemperature(int32_t &temperature_dezideg) { return J_ERR_NO_IMPLEMENTATION; }

    protected:
    private:
    };
} // namespace jFramework

#endif