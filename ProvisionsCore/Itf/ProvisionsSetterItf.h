#include <memory>

#include "ProvisionGetterItf.h"

#pragma once

namespace ProvisionsCoreItf
{
    class ProvisionsSetterItf
    {
    public:
        virtual void AddProvision(std::shared_ptr<ProvisionGetterItf> provision) = 0;
    }; 
}