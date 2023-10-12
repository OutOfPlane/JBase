#ifndef J_NETWORK_ADAPTER_H
#define J_NETWORK_ADAPTER_H

#include "jObject.hpp"
#include "esp_netif.h"

#define J_NETWORK_STATE                         \
    X(J_NETWORK_UNINITIALIZED, "uninitialized") \
    X(J_NETWORK_NO_IF, "no interface present")  \
    X(J_NETWORK_CONNECTING, "connecting")       \
    X(J_NETWORK_RECONNECTING, "reconnecting")       \
    X(J_NETWORK_CONNECTED, "connected")         \
    X(J_NETWORK_DISCONNECTED, "disconnected")

namespace jFramework
{

#define X(typeID, name) typeID,
    enum g_network_state : size_t
    {
        J_NETWORK_STATE
    };
#undef X

    class networkAdapter : public jObject
    {
    public:
        networkAdapter(const char *name);
        virtual ~networkAdapter() {}

        j_err start();
        esp_netif_t *getNetIF();
        g_network_state getState();
        const char *getStateName();

    protected:
        virtual j_err _start() { return J_ERR_NO_IMPLEMENTATION; }
        virtual j_err createNetif() { return J_ERR_NO_IMPLEMENTATION; }
        esp_netif_t *_netif;
        g_network_state _state;
        esp_netif_config_t _netifCfg;
        

    private:
    };

} // namespace jFramework

#endif