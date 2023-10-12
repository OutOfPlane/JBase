#ifndef J_CONFIG_STORAGE_H
#define J_CONFIG_STORAGE_H

#include "jObject.hpp"

namespace jFramework
{

    class configStorage : public jObject
    {
    public:
        configStorage(const char *name);
        virtual ~configStorage() {}

    protected:
    private:
    };
} // namespace jFramework

#endif