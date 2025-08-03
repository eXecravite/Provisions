#include "Provision.h"

namespace ProvisionsCore
{
    const std::optional<std::chrono::year_month_day> Provision::GetDateOfExpiration()
    {
        return m_dateOfExpiration;
    }

    void Provision::SetDateOfExpiration(std::chrono::year_month_day dateOfExpiration)
    {
        m_dateOfExpiration = dateOfExpiration;
    }
}