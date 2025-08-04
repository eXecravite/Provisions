#include "Provisions.h"

#include <algorithm>

#include "ExpirationDateHelper.h"

namespace ProvisionsCore
{
    const std::optional<std::chrono::year_month_day> Provisions::GetEarliestDateOfExpiration()
    {
        if (!m_dateOfExpirationCache.has_value())
        {
            m_dateOfExpirationCache = RetrieveEarliestExpirationDate(m_provisions);
        }
        return m_dateOfExpirationCache;
    }

    void Provisions::AddProvision(std::shared_ptr<ProvisionsCoreItf::ProvisionGetterItf> provision)
    {
        m_provisions.push_back(provision);
    }
}