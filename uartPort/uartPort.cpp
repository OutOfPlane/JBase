#include "uartPort.hpp"
#include "driver/uart.h"
#include "driver/gpio.h"
#include <cstring>

using namespace jFramework;

uartPort::uartPort(const char *name, uartPortNumber portNumber, uint32_t baud)
    : jObject(name), _port(portNumber)
{
}

j_err jFramework::uartPort::write(char *data)
{
    return w((uint8_t *)data, strlen(data));
}

j_err jFramework::uartPort::w8(uint8_t data)
{
    uint16_t len = 1;
    return w(&data, len);
}

j_err jFramework::uartPort::w8r8(uint8_t address, uint8_t data)
{
    std::memcpy(buf, &address, sizeof(address));
    std::memcpy(buf + sizeof(address), &data, sizeof(data));
    return w(buf, sizeof(address) + sizeof(data));
}

j_err jFramework::uartPort::w8r16(uint16_t address, uint8_t data)
{
    std::memcpy(buf, &address, sizeof(address));
    std::memcpy(buf + sizeof(address), &data, sizeof(data));
    return w(buf, sizeof(address) + sizeof(data));
}

j_err jFramework::uartPort::w8r32(uint32_t address, uint8_t data)
{
    std::memcpy(buf, &address, sizeof(address));
    std::memcpy(buf + sizeof(address), &data, sizeof(data));
    return w(buf, sizeof(address) + sizeof(data));
}

j_err jFramework::uartPort::w16r8(uint8_t address, uint16_t data)
{
    std::memcpy(buf, &address, sizeof(address));
    std::memcpy(buf + sizeof(address), &data, sizeof(data));
    return w(buf, sizeof(address) + sizeof(data));
}

j_err jFramework::uartPort::w16r16(uint16_t address, uint16_t data)
{
    std::memcpy(buf, &address, sizeof(address));
    std::memcpy(buf + sizeof(address), &data, sizeof(data));
    return w(buf, sizeof(address) + sizeof(data));
}

j_err jFramework::uartPort::w16r32(uint32_t address, uint16_t data)
{
    std::memcpy(buf, &address, sizeof(address));
    std::memcpy(buf + sizeof(address), &data, sizeof(data));
    return w(buf, sizeof(address) + sizeof(data));
}

j_err jFramework::uartPort::w32r8(uint8_t address, uint32_t data)
{
    std::memcpy(buf, &address, sizeof(address));
    std::memcpy(buf + sizeof(address), &data, sizeof(data));
    return w(buf, sizeof(address) + sizeof(data));
}

j_err jFramework::uartPort::w32r16(uint16_t address, uint32_t data)
{
    std::memcpy(buf, &address, sizeof(address));
    std::memcpy(buf + sizeof(address), &data, sizeof(data));
    return w(buf, sizeof(address) + sizeof(data));
}

j_err jFramework::uartPort::w32r32(uint32_t address, uint32_t data)
{
    std::memcpy(buf, &address, sizeof(address));
    std::memcpy(buf + sizeof(address), &data, sizeof(data));
    return w(buf, sizeof(address) + sizeof(data));
}

j_err jFramework::uartPort::read(char *data, uint16_t &maxBufSize, uint32_t timeout_ms)
{
    assert(data);
    if (maxBufSize == 0)
        return J_ERR_INVALID_ARGS;

    maxBufSize--;
    j_err erg = r((uint8_t *)data, maxBufSize, timeout_ms);
    if ((erg == J_ERR_TIMEOUT) || (erg == J_OK))
    {
        data[maxBufSize] = '\0';
    }
    return erg;
}

j_err jFramework::uartPort::readUntil(char *data, uint16_t &maxBufSize, uint32_t timeout_ms, char trigger)
{
    assert(data);
    if (maxBufSize == 0)
        return J_ERR_INVALID_ARGS;

    uint16_t idx = 0;
    uint8_t tmp = 0;
    while ((r8(tmp, timeout_ms) == J_OK) &&
           (idx < (maxBufSize - 1)) &&
           (tmp != trigger))
    {
        data[idx] = tmp;
        idx++;
    }
    data[idx] = '\0';
    maxBufSize = idx;
    return J_OK;
}

j_err jFramework::uartPort::r8(uint8_t &data, uint32_t timeout_ms)
{
    uint16_t len = 1;
    return r(&data, len, timeout_ms);
}

j_err jFramework::uartPort::r8r8(uint8_t address, uint8_t &data, uint32_t timeout_ms)
{
    uint16_t len = sizeof(data);
    j_err erg = w((uint8_t *)&address, len);
    if (erg)
    {
        return erg;
    }
    return r((uint8_t *)&data, len, timeout_ms);
}

j_err jFramework::uartPort::r8r16(uint16_t address, uint8_t &data, uint32_t timeout_ms)
{
    uint16_t len = sizeof(data);
    j_err erg = w((uint8_t *)&address, len);
    if (erg)
    {
        return erg;
    }
    return r((uint8_t *)&data, len, timeout_ms);
}

j_err jFramework::uartPort::r8r32(uint32_t address, uint8_t &data, uint32_t timeout_ms)
{
    uint16_t len = sizeof(data);
    j_err erg = w((uint8_t *)&address, len);
    if (erg)
    {
        return erg;
    }
    return r((uint8_t *)&data, len, timeout_ms);
}

j_err jFramework::uartPort::r16r8(uint8_t address, uint16_t &data, uint32_t timeout_ms)
{
    uint16_t len = sizeof(data);
    j_err erg = w((uint8_t *)&address, len);
    if (erg)
    {
        return erg;
    }
    return r((uint8_t *)&data, len, timeout_ms);
}

j_err jFramework::uartPort::r16r16(uint16_t address, uint16_t &data, uint32_t timeout_ms)
{
    uint16_t len = sizeof(data);
    j_err erg = w((uint8_t *)&address, len);
    if (erg)
    {
        return erg;
    }
    return r((uint8_t *)&data, len, timeout_ms);
}

j_err jFramework::uartPort::r16r32(uint32_t address, uint16_t &data, uint32_t timeout_ms)
{
    uint16_t len = sizeof(data);
    j_err erg = w((uint8_t *)&address, len);
    if (erg)
    {
        return erg;
    }
    return r((uint8_t *)&data, len, timeout_ms);
}

j_err jFramework::uartPort::r32r8(uint8_t address, uint32_t &data, uint32_t timeout_ms)
{
    uint16_t len = sizeof(data);
    j_err erg = w((uint8_t *)&address, len);
    if (erg)
    {
        return erg;
    }
    return r((uint8_t *)&data, len, timeout_ms);
}

j_err jFramework::uartPort::r32r16(uint16_t address, uint32_t &data, uint32_t timeout_ms)
{
    uint16_t len = sizeof(data);
    j_err erg = w((uint8_t *)&address, len);
    if (erg)
    {
        return erg;
    }
    return r((uint8_t *)&data, len, timeout_ms);
}

j_err jFramework::uartPort::r32r32(uint32_t address, uint32_t &data, uint32_t timeout_ms)
{
    uint16_t len = sizeof(data);
    j_err erg = w((uint8_t *)&address, len);
    if (erg)
    {
        return erg;
    }
    return r((uint8_t *)&data, len, timeout_ms);
}
