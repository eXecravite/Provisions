#include <chrono>
#include <optional>

#pragma once

namespace ProvisionsCoreItf
{
    class ProvisionSetterItf
    {
    public:
        virtual void SetDateOfExpiration(std::chrono::year_month_day dateOfExpiration) = 0;
    }; 
}