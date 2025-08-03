#include <chrono>
#include <optional>
namespace ProvisionsCore
{
    class ProvisionItf
    {
    public:
        [[nodiscard]]
        virtual const std::optional<std::chrono::year_month_day> GetDateOfExpiration() = 0;
        virtual void SetDateOfExpiration(std::chrono::year_month_day dateOfExpiration) = 0;
    private:
        std::chrono::year_month_day m_dateOfExpiration;
    }; 
}