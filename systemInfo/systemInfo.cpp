#include <systemInfo.hpp>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "buildnumber.hpp"

using namespace jFramework;

char firmwareShort[32] = {0};
char firmwareLong[64] = {0};


sysInfo_t jFramework::identifySystem()
{
    sysInfo_t info;

    // Identify the Software
    info.software.IDFVer = IDF_VER;
    info.software.firmware.buildDate = __DATE__;
    info.software.firmware.buildTime = __TIME__;
    info.software.firmware.major = J_CODE_MAJOR;
    info.software.firmware.minor = J_CODE_MINOR;
    info.software.firmware.patch = J_CODE_PATCH;
    info.software.firmware.build = J_CODE_BUILD;

    info.hardware.hardwareID = nullptr;

    getFirmwareStringShort();
    getFirmwareStringLong();

    uint8_t mac[8];
    esp_read_mac(mac, ESP_MAC_WIFI_STA);

    // Identify the Hardware
    info.hardware.PCBRev = PCB_Revision_2_0;
    

    return info;
}

const char *jFramework::getFirmwareStringShort()
{
    if (!firmwareShort[0])
        sprintf(firmwareShort, "%d.%d.%d", J_CODE_MAJOR, J_CODE_MINOR, J_CODE_PATCH);
    return firmwareShort;
}

const char *jFramework::getFirmwareStringLong()
{
    if (!firmwareLong[0])
        sprintf(firmwareLong, "%d.%d.%d:%05d", J_CODE_MAJOR, J_CODE_MINOR, J_CODE_PATCH, J_CODE_BUILD);
    return firmwareLong;
}

const char *jFramework::getPCBRevisionString(PCBRevision rev)
{
    switch (rev)
    {
    case PCB_Revision_2_0:
        return "Rev 2.0";

    case PCB_Revision_Unknown:
    default:
        return "Unknown";
    }
}
