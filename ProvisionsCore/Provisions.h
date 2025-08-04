#include <vector>

#include "Itf/ProvisionsGetterItf.h"
#include "Itf/ProvisionsSetterItf.h"

namespace ProvisionsCore
{
    class Provisions: public ProvisionsCoreItf::ProvisionsGetterItf, ProvisionsCoreItf::ProvisionsSetterItf
    {
    public:
        [[nodiscard]]
        const std::optional<std::chrono::year_month_day> GetEarliestDateOfExpiration() override;
        void AddProvision(std::shared_ptr<ProvisionsCoreItf::ProvisionGetterItf> provision) override;
    private:
        std::optional<std::chrono::year_month_day> m_dateOfExpirationCache = {};
        std::vector<std::shared_ptr<ProvisionsCoreItf::ProvisionGetterItf>> m_provisions;
    }; 
}