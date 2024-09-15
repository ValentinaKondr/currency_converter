#pragma once

#include "IObserver.h"
#include "common.h"
#include "Balances.h"
#include "ExchangeRates.h"


#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iomanip>
#include <iostream>

class ExchangeTerminal {
private:
    Balances user;
    Balances terminal;
    ExchangeRates& rates;

public:
    ExchangeTerminal(ExchangeRates& rates)
        : user("User", {{Currency::RUB, 1000000.00}}),
        terminal("Terminal", {{Currency::RUB, 10000.00},
                                {Currency::USD, 1000.00},
                                {Currency::EUR, 1000.00},
                                {Currency::USDT,1000.00},
                                {Currency::BTC, 1.5}}),
        rates(rates)
    {
        terminal.addObserver(&rates);
    }

    ~ExchangeTerminal() {
        terminal.removeObserver(&rates);
    }

    void displayBalances() {
        user.displayBalances();
        std::cout << "\n";
        terminal.displayBalances();
    }

    void displayRates() const {
        rates.displayRates();
    }

    bool performExchange(const Currency& from, const Currency& to, double amount) {
        const auto rate{rates.getRate(from, to)};
        if (rate == -1) {
            std::cout << "Ошибка: Недопустимая валютная пара!\n";
            return false;
        }

        if (user.addAmount(from, - amount)) {
            terminal.addAmount(to, amount);
            return true;
        } else {
            std::cout << "Ошибка: Недостаточно средств!\n";
            return false;
        }

        return false;
    }
};
