#include <catch2/catch_test_macros.hpp>
#include "../Provision.h"

namespace ProvisionsCoreTest
{
    TEST_CASE( "Provision returns empty optional by default") {
        ProvisionsCore::Provision provision{};
        const auto expirationDate = provision.GetDateOfExpiration();
        REQUIRE(expirationDate.has_value() == false ); //NOLINT(cppcoreguidelines-avoid-do-while)
    }

    TEST_CASE( "Provision returns set value") {
        ProvisionsCore::Provision provision{};
        const auto now = std::chrono::system_clock::now();
        const auto ymd = std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(now));

        provision.SetDateOfExpiration(ymd);
        const auto expirationDate = provision.GetDateOfExpiration();

        REQUIRE(expirationDate.has_value() == true ); //NOLINT(cppcoreguidelines-avoid-do-while)
        REQUIRE(expirationDate.value() == ymd ); //NOLINT(cppcoreguidelines-avoid-do-while, bugprone-unchecked-optional-access)
    }
}