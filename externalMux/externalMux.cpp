#include "externalMux.hpp"

using namespace jFramework;

jFramework::externalMux::externalMux(const char *name, uint16_t numChannels, ioPin *bit0, ioPin *bit1, ioPin *bit2, ioPin *bit3)
    : jObject(name), _numChannels(numChannels)
{
    _numBits = 0;
    if (bit0)
    {
        _numBits++;
        if (bit1)
        {
            _numBits++;
            if (bit2)
            {
                _numBits++;
                if (bit3)
                {
                    _numBits++;
                }
            }
        }
    }

    _pinList = new ioPin *[_numBits];
    for (size_t i = 0; i < _numBits; i++)
    {
        if(i == 0)
        {
            _pinList[i] = bit0;
        }
        if(i == 1)
        {
            _pinList[i] = bit1;
        }
        if(i == 2)
        {
            _pinList[i] = bit2;
        }
        if(i == 3)
        {
            _pinList[i] = bit3;
        }
    }
    
}

jFramework::externalMux::~externalMux()
{
    delete[] _pinList;
}

j_err jFramework::externalMux::selectChannel(uint16_t channel)
{
    if (channel >= _numChannels)
        return J_ERR_INVALID_ARGS;

    for (size_t i = 0; i < _numBits; i++)
    {
        _pinList[i]->set((channel >> i) & 0x1);
    }
    return J_OK;
}
