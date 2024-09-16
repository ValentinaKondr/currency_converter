#include "Balances.h"


void Balances::notifyObservers() {
    for (IObserver* obs : observers) {
        obs->update();
    }
}

bool Balances::canWithdraw(Currency currency, double amount)
{
    return balance[currency] - amount > 0;
}

void Balances::addAmount(Currency currency, double amount)
{
    balance[currency] += amount;
}

void Balances::withdrawAmount(Currency currency, double amount)
{
    if (canWithdraw(currency, amount))
    {
        balance[currency] -= amount;
    }
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
