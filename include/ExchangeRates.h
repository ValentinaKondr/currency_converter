#pragma once

#include "IObserver.h"
#include "common.h"

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iomanip>
#include <iostream>

template <>
struct std::hash<std::pair<Currency, Currency>>
{
    std::size_t operator()(std::pair<Currency, Currency> pair) const
    {
        return int(pair.first) * 10 + int(pair.second);
    }
};

class ExchangeRates : public IObserver {
private:
    std::unordered_map<std::pair<Currency, Currency>, double> rates;

    float updateValueRandomly(float value)
    {
        return value * (1 + (rand() % 1000 - 500) / 10000.0);
    }

public:
    ExchangeRates() {
        // initial values
        rates[{Currency::RUB, Currency::USD}] = 90;
        rates[{Currency::RUB, Currency::EUR}] = 95;
        rates[{Currency::USD, Currency::EUR}] = 1.05;
        rates[{Currency::USD, Currency::USDT}] = 1.00;
        rates[{Currency::USD, Currency::BTC}] = 0.00003;

        rates[{Currency::USD, Currency::RUB}] = 1 / rates[{Currency::RUB, Currency::USD}];
        rates[{Currency::EUR, Currency::RUB}] = 1 / rates[{Currency::RUB, Currency::EUR}];
        rates[{Currency::EUR, Currency::USD}] = 1 / rates[{Currency::USD, Currency::EUR}];
        rates[{Currency::USDT, Currency::USD}] = 1 / rates[{Currency::USD, Currency::USDT}];
        rates[{Currency::BTC, Currency::USD}] = 1 / rates[{Currency::USD, Currency::BTC}];
    }

    void displayRates() const {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "Текущие курсы:\n";
        for (const auto& rate : rates) {
            //std::cout << CURRENCY_NAMES[rate.first.first] << " -> " << CURRENCY_NAMES[rate.first.second] << ": " << rate.second << "\n";
        }
    }

    double getRate(const Currency& from, const Currency& to) const;
    void update() override;
};
