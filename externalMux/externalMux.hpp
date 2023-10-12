#ifndef J_EXTERNAL_MUX_H
#define J_EXTERNAL_MUX_H

#include "jObject.hpp"
#include "ioPin.hpp"

namespace jFramework
{
    class externalMux : public jObject
    {
    public:
        externalMux(const char *name, uint16_t numChannels, ioPin *bit0 = nullptr, ioPin *bit1 = nullptr, ioPin *bit2 = nullptr, ioPin *bit3 = nullptr);
        virtual ~externalMux();
        virtual j_err selectChannel(uint16_t channel);

    protected:
        uint16_t _numChannels = 0;
        uint16_t _numBits = 0;

    private:
        ioPin **_pinList;
    };

} // namespace jFramework

#endif