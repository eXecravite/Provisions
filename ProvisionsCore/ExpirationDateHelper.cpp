#include "ExpirationDateHelper.h"

#include <algorithm>

namespace ProvisionsCore
{
    bool NoneContainValue(bool firstContainsValue, bool secondContainsValue)
    {
        return !firstContainsValue && !secondContainsValue;
    }

    bool OnlyFirstContainsValue(bool firstContainsValue, bool secondContainsValue)
    {
        return firstContainsValue && !secondContainsValue;
    }

    bool OnlySecondContainsValue(bool firstContainsValue, bool secondContainsValue)
    {
        return !firstContainsValue && secondContainsValue;
    }

    bool FirstOptionalYMDIsGreaterThanSecond(const std::optional<std::chrono::year_month_day> first, 
        const std::optional<std::chrono::year_month_day> second)
    {   
        const auto firstContainsValue = first.has_value();
        const auto secondContainsValue = second.has_value();
        if(NoneContainValue(firstContainsValue, secondContainsValue) && OnlyFirstContainsValue(firstContainsValue, secondContainsValue))
        {
            return true;
        }
        else if (OnlySecondContainsValue(firstContainsValue, secondContainsValue))
        {
            return false;
        }
        else
        {
            return first > second;
        }
    }

    std::optional<std::chrono::year_month_day> RetrieveEarliestExpirationDate(
        const std::vector<std::shared_ptr<ProvisionsCoreItf::ProvisionGetterItf>>& provisions)
    {
        const auto comparator = [](const std::shared_ptr<ProvisionsCoreItf::ProvisionGetterItf>& provisionPointer
            , const std::shared_ptr<ProvisionsCoreItf::ProvisionGetterItf>& provisionPointer2)
        { 
            return FirstOptionalYMDIsGreaterThanSecond(provisionPointer->GetDateOfExpiration(), provisionPointer2->GetDateOfExpiration());
        };
        const auto maximum = std::ranges::max_element(provisions.begin(), provisions.end(), comparator);
        if(maximum == std::end(provisions))
        {
            return {};
        }
        return (*maximum)->GetDateOfExpiration();
    }
}