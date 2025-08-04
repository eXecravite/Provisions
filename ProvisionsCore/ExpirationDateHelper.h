#include <vector>
#include <memory>

#include "Itf/ProvisionGetterItf.h"

namespace ProvisionsCore
{
    std::optional<std::chrono::year_month_day> RetrieveEarliestExpirationDate(
        const std::vector<std::shared_ptr<ProvisionsCoreItf::ProvisionGetterItf>>& provisions);
}