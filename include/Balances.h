#pragma once

#include "ISubject.h"
#include "IObserver.h"
#include "common.h"

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iomanip>
#include <iostream>

class Balances : public ISubject {
public:
    Balances(const std::string& owner, const std::unordered_map<Currency, double>& balance)
        : owner(owner)
        , balance(balance)
    {

    }

    void displayBalances();

    void addObserver(IObserver* obs) override;
    void removeObserver(IObserver* obs) override;
    void notifyObservers() override;

    bool addAmount(Currency currency, double amount);

private:
    std::string owner;
    std::vector<IObserver*> observers;
    std::unordered_map<Currency, double> balance;
};
