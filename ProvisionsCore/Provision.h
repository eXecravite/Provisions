#include "Itf/ProvisionItf.h"

namespace ProvisionsCore
{
    class Provision: public ProvisionItf
    {
    public:
        [[nodiscard]]
        const std::optional<std::chrono::year_month_day> GetDateOfExpiration() override;
        void SetDateOfExpiration(std::chrono::year_month_day dateOfExpiration) override;
    private:
        std::optional<std::chrono::year_month_day> m_dateOfExpiration = {};
    }; 
}