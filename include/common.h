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

inline std::string getCurrecyNameByEnum(Currency curr) {
    switch(curr) {
    case Currency::RUB:
        return "Rub";
    case Currency::USD:
        return "Usd";
    case Currency::EUR:
        return "Euro";
    case Currency::USDT:
        return "USDT";
    case Currency::BTC:
        return "BTC";
    default:
        return "Error";
    }
}
