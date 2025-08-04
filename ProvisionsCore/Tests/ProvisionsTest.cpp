#include <catch2/catch_test_macros.hpp>
#include "../Provision.h"
#include "../Provisions.h"

namespace ProvisionsCoreTest
{
    TEST_CASE( "Provisions returns empty optional expiration date by default") {
        ProvisionsCore::Provisions provisions{};
        const auto expirationDate = provisions.GetEarliestDateOfExpiration();
        REQUIRE(expirationDate.has_value() == false ); //NOLINT(cppcoreguidelines-avoid-do-while)
    }

    TEST_CASE( "Provisions returns empty optional expiration date by with empty provision") {
        ProvisionsCore::Provisions provisions{};
        const auto provision = std::make_shared<ProvisionsCore::Provision>();

        provisions.AddProvision(provision);
        const auto expirationDate = provisions.GetEarliestDateOfExpiration();
        
        REQUIRE(expirationDate.has_value() == false ); //NOLINT(cppcoreguidelines-avoid-do-while)
    }

    TEST_CASE( "Provisions returns empty optional expiration date by with two empty provisions") {
        ProvisionsCore::Provisions provisions{};
        const auto provision = std::make_shared<ProvisionsCore::Provision>();
        const auto provision2 = std::make_shared<ProvisionsCore::Provision>();

        provisions.AddProvision(provision);
        provisions.AddProvision(provision2);
        const auto expirationDate = provisions.GetEarliestDateOfExpiration();
        
        REQUIRE(expirationDate.has_value() == false ); //NOLINT(cppcoreguidelines-avoid-do-while)
    }

    TEST_CASE( "Provisions returns correct date when comparing empty expiration date with a filled one") {
        ProvisionsCore::Provisions provisions{};
        const auto provision = std::make_shared<ProvisionsCore::Provision>();
        const auto provision2 = std::make_shared<ProvisionsCore::Provision>();
        const auto now = std::chrono::system_clock::now();
        const auto ymd = std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(now));

        provision->SetDateOfExpiration(ymd);
        provisions.AddProvision(provision);
        provisions.AddProvision(provision2);
        const auto expirationDate = provisions.GetEarliestDateOfExpiration();
        
        REQUIRE(expirationDate.has_value() == false ); //NOLINT(cppcoreguidelines-avoid-do-while)
    }

    TEST_CASE( "Provisions returns correct date when comparing filled ones") {
        using namespace std::chrono_literals;

        ProvisionsCore::Provisions provisions{};
        const auto provision = std::make_shared<ProvisionsCore::Provision>();
        const auto provision2 = std::make_shared<ProvisionsCore::Provision>();
        const auto provision3 = std::make_shared<ProvisionsCore::Provision>();
        const auto provision4 = std::make_shared<ProvisionsCore::Provision>();
        const auto provision5 = std::make_shared<ProvisionsCore::Provision>();
        
        constexpr auto ymd = std::chrono::year_month_day{2020y, std::chrono::January, 2d};
        constexpr auto ymd2 = std::chrono::year_month_day{2019y, std::chrono::June, 21d};
        constexpr auto ymd3 = std::chrono::year_month_day{2023y, std::chrono::February, 10d};
        constexpr auto ymd4 = std::chrono::year_month_day{2019y, std::chrono::March, 1d};
        constexpr auto ymd5 = std::chrono::year_month_day{2020y, std::chrono::January, 2d};

        provision->SetDateOfExpiration(ymd);
        provision2->SetDateOfExpiration(ymd2);
        provision3->SetDateOfExpiration(ymd3);
        provision4->SetDateOfExpiration(ymd4);
        provision5->SetDateOfExpiration(ymd5);

        provisions.AddProvision(provision);
        provisions.AddProvision(provision2);
        provisions.AddProvision(provision3);
        provisions.AddProvision(provision4);
        provisions.AddProvision(provision5);

        const auto expirationDate = provisions.GetEarliestDateOfExpiration();
        
        REQUIRE(expirationDate.has_value() == true ); //NOLINT(cppcoreguidelines-avoid-do-while)
        REQUIRE(expirationDate.value() == ymd4 ); //NOLINT(cppcoreguidelines-avoid-do-while, bugprone-unchecked-optional-access)
    }
}