#ifndef J_UART_PORT_H
#define J_UART_PORT_H

#include "jObject.hpp"

namespace jFramework
{
    enum uartPortNumber
    {
        uart0 = 0,
        uart1 = 1,
        uart2 = 2,
        uartOther = 100
    };

    enum uartNewline{
        NEWLINE_CRLF,
        NEWLINE_CR,
        NEWLINE_LF
    };

    class uartPort : public jObject
    {
    public:
        uartPort(const char *name, uartPortNumber portNumber, uint32_t baud);

        // writing
        virtual j_err w(uint8_t *data, uint16_t len){return J_ERR_NO_IMPLEMENTATION;}
        
        //convenience Functions for writing
        j_err write(char *data);
        
        j_err w8(uint8_t data);
        j_err w8r8(uint8_t address, uint8_t data);
        j_err w8r16(uint16_t address, uint8_t data);
        j_err w8r32(uint32_t address, uint8_t data);
        j_err w16r8(uint8_t address, uint16_t data);
        j_err w16r16(uint16_t address, uint16_t data);
        j_err w16r32(uint32_t address, uint16_t data);
        j_err w32r8(uint8_t address, uint32_t data);
        j_err w32r16(uint16_t address, uint32_t data);
        j_err w32r32(uint32_t address, uint32_t data);

        // reading
        virtual j_err r(uint8_t *data, uint16_t &len, uint32_t timeout_ms){return J_ERR_NO_IMPLEMENTATION;}

        //convenience Functions for reading
        j_err read(char *data, uint16_t &maxBufSize, uint32_t timeout_ms);
        j_err readUntil(char *data, uint16_t &maxBufSize, uint32_t timeout_ms, char trigger = '\n');
        
        j_err r8(uint8_t &data, uint32_t timeout_ms);
        j_err r8r8(uint8_t address, uint8_t &data, uint32_t timeout_ms);
        j_err r8r16(uint16_t address, uint8_t &data, uint32_t timeout_ms);
        j_err r8r32(uint32_t address, uint8_t &data, uint32_t timeout_ms);
        j_err r16r8(uint8_t address, uint16_t &data, uint32_t timeout_ms);
        j_err r16r16(uint16_t address, uint16_t &data, uint32_t timeout_ms);
        j_err r16r32(uint32_t address, uint16_t &data, uint32_t timeout_ms);
        j_err r32r8(uint8_t address, uint32_t &data, uint32_t timeout_ms);
        j_err r32r16(uint16_t address, uint32_t &data, uint32_t timeout_ms);
        j_err r32r32(uint32_t address, uint32_t &data, uint32_t timeout_ms);

        //status
        virtual j_err present(bool &isPresent){return J_ERR_NO_IMPLEMENTATION;}

    protected:
        uartPortNumber _port;
    private:
        
        uint8_t buf[8];
    };

} // namespace jFramework

#endif