#ifndef JBASE_OBJECT_H
#define JBASE_OBJECT_H

#include <stdint.h>
#include <stdio.h>
#include <cstring>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include "jError.h"

#define J_LOGV(format, ...) esp_log_write(ESP_LOG_VERBOSE, _name, LOG_FORMAT(V, format), esp_log_timestamp(), _name, ##__VA_ARGS__)
#define J_LOGD(format, ...) esp_log_write(ESP_LOG_DEBUG, _name, LOG_FORMAT(D, format), esp_log_timestamp(), _name, ##__VA_ARGS__)
#define J_LOGI(format, ...) esp_log_write(ESP_LOG_INFO, _name, LOG_FORMAT(I, format), esp_log_timestamp(), _name, ##__VA_ARGS__)
#define J_LOGE(format, ...) esp_log_write(ESP_LOG_ERROR, _name, LOG_FORMAT(E, format), esp_log_timestamp(), _name, ##__VA_ARGS__)

#define J_ERROR_DECODE(x)                                                      \
    do                                                                          \
    {                                                                           \
        J_LOGE("[%s] on %s:%d", j_errToString[x], __FILE__, __LINE__); \
    } while (0)

namespace jFramework
{
#define X(typeID, name) typeID,
    enum j_err : size_t
    {
        J_ERROR_CODES
    };
#undef X

    extern const char *j_errToString[];

    j_err j_err_translate(esp_err_t e);
    class jObject
    {
    public:
        jObject(const char *name);
        bool lock(jObject &lockedBy, uint32_t timeout_ms = 0);
        void unlock();
        const char *lockedBy();
        const char *getName();

    protected:
        const char *_name;
        const char *_lockedBy = nullptr;
        bool _locked = false;

    private:
        SemaphoreHandle_t _mutex = NULL;
    };

} // namespace jFramework

#endif