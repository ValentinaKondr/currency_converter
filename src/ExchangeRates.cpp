#include "ExchangeRates.h"

double ExchangeRates::getRate(const Currency& from, const Currency& to) const {
    auto it = rates.find({from, to});
    if (it != rates.end()) {
        return it->second;
    }
    return -1;
}

void ExchangeRates::update() {
    rates[{Currency::RUB, Currency::USD}] = updateValueRandomly(rates[{Currency::RUB, Currency::USD}]);
    rates[{Currency::RUB, Currency::EUR}] = updateValueRandomly(rates[{Currency::RUB, Currency::EUR}]);
    rates[{Currency::USD, Currency::EUR}] = updateValueRandomly(rates[{Currency::USD, Currency::EUR}]);
    rates[{Currency::USD, Currency::USDT}] = updateValueRandomly(rates[{Currency::USD, Currency::USDT}]);
    rates[{Currency::USD, Currency::BTC}] = updateValueRandomly(rates[{Currency::USD, Currency::BTC}]);

    // Обратные курсы
    rates[{Currency::USD, Currency::RUB}] = 1 / rates[{Currency::RUB, Currency::USD}];
    rates[{Currency::EUR, Currency::RUB}] = 1 / rates[{Currency::RUB, Currency::EUR}];
    rates[{Currency::EUR, Currency::USD}] = 1 / rates[{Currency::USD, Currency::EUR}];
    rates[{Currency::USDT, Currency::USD}] = 1 / rates[{Currency::USD, Currency::USDT}];
    rates[{Currency::BTC, Currency::USD}] = 1 / rates[{Currency::USD, Currency::BTC}];
}
