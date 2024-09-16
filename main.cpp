#include "ExchangeRates.h"
#include "ExchangeTerminal.h"

#include <iostream>

using namespace std;
bool checkCurrency(int i) {
    return i >= 0 && i <= int(Currency::BTC);
}

int main()
{
    srand(time(0));

    ExchangeRates rates;
    ExchangeTerminal terminal(rates);
    int currency{-1};
    Currency from, to;
    double amount;
    int action = 1;
    cout << "Выберите действие:" << endl
         << "0. Выход" << endl
         << "1. Показать балансы" << endl
         << "2. Обменять" << endl
         << "3. Вывести курсы" << endl;

    cin >> action;
    while (action)
    {
        switch (action)
        {
        case 0:
            break;
        case 1:
            terminal.displayBalances();
            break;
        case 2:
            std::cout << "Выберите валюту для обмена: \n";
            std::cout << "0. RUB\n1. USD\n2. EUR\n3. USDT\n4. BTC\n5. Exit\n";
            std::cin >> currency;


            if (!cin.good() || !checkCurrency(currency)) {
                std::cout << "Некорректный ввод\n";
                break;
            }
            from = Currency(currency);
            std::cout << "Выберите, на какую валюту хотите обменять: \n";
            std::cout << "0. RUB\n1. USD\n2. EUR\n3. USDT\n4. BTC\n5. Exit\n";
            std::cin >> currency;

            if (!cin.good() || !checkCurrency(currency)) {
                std::cout << "Некорректный ввод\n";
                break;
            }

            to = Currency(currency);
            std::cout << "Введите количество: ";
            std::cin >> amount;
            if (amount < 0) {
                std::cout << "Некорректный ввод\n";
                break;
            }
            terminal.performExchange(from, to, amount);
            break;
        case 3:
            rates.displayRates();
            break;
        default:
            std::cout << " Некорректный ввод\n";
            break;
        }
        std::cout << "Введите операцию:\n";
        std::cin >> action;

    }
    return 0;
}
