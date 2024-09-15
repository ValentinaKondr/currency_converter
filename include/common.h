#pragma once

#include <cstdint>
#include <map>
#include <string>

enum class Currency : uint8_t
{
    RUB,
    USD,
    EUR,
    USDT,
    BTC
};

const std::map<Currency, std::string> CURRENCY_NAMES {
    {Currency::RUB, std::string{"RUB"}},
    {Currency::USD, std::string{"USD"}},
    {Currency::EUR, std::string{"EUR"}},
    {Currency::USDT, std::string{"USDT"}},
    {Currency::BTC, std::string{"BTC"}},
};
