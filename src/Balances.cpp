#include "Balances.h"


void Balances::notifyObservers() {
    for (IObserver* obs : observers) {
        obs->update();
    }
}

bool Balances::addAmount(Currency currency, double amount)
{
    bool isOk{ false };
    if (balance[currency] + amount > 0)
    {
        balance[currency] += amount;
        isOk = true;
    }

    notifyObservers();
    return isOk;
}

void Balances::displayBalances() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << owner << ":\n";
    std::cout << "RUB: " << balance[Currency::RUB] << "\n";
    std::cout << "USD: " << balance[Currency::USD] << "\n";
    std::cout << "EUR: " << balance[Currency::EUR] << "\n";
    std::cout << "USDT: " << balance[Currency::USDT] << "\n";
    std::cout << "BTC: " << balance[Currency::BTC] << "\n";
}

void Balances::addObserver(IObserver* obs) {
    observers.push_back(obs);
}

void Balances::removeObserver(IObserver* obs) {
    observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
}
