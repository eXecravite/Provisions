#include <chrono>
#include <optional>

#pragma once

namespace ProvisionsCoreItf
{
    class ProvisionsGetterItf
    {
    public:
        [[nodiscard]]
        virtual const std::optional<std::chrono::year_month_day> GetEarliestDateOfExpiration() = 0;
    }; 
}