#include "networkAdapter.hpp"

using namespace jFramework;

#define X(typeID, name) name,
const char *_NetworkToString[]{
    J_NETWORK_STATE};
#undef X

networkAdapter::networkAdapter(const char *name)
    : jObject(name), _netif(nullptr), _state(J_NETWORK_UNINITIALIZED)
{
}

j_err networkAdapter::start()
{
    if (createNetif() == J_OK)
    {
        J_LOGI("Create Network Interface Success");
    }
    else
    {
        J_LOGI("Create Network Interface Fail");
    }

    J_LOGI("Starting networkAdapter");
    j_err erg = _start();
    if (erg == J_OK)
    {
        J_LOGI("Adapter Start Success");
    }

    return erg;
}

esp_netif_t *networkAdapter::getNetIF()
{
    return _netif;
}

g_network_state jFramework::networkAdapter::getState()
{
    return _state;
}

const char *jFramework::networkAdapter::getStateName()
{
    return _NetworkToString[_state];
}
