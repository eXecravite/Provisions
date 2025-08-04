#include <chrono>
#include <optional>

#pragma once

namespace ProvisionsCoreItf
{
    class ProvisionGetterItf
    {
    public:
        [[nodiscard]]
        virtual const std::optional<std::chrono::year_month_day> GetDateOfExpiration() = 0;
    }; 
}