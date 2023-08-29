#pragma once
#include "Tourist_ticket.h"

class CurrencyConverter 
{
public:
    virtual double convert(double amount) const  = 0;
    virtual string getCurrencyName() const  = 0;
    virtual ~CurrencyConverter() {}
};

class USDConverter : public CurrencyConverter 
{
public:
    double convert(double amount) const override 
    {
        return amount / 95.43;
    }
    string getCurrencyName() const override {
        return "USD";
    }
};

class EuroConverter : public CurrencyConverter 
{
public:
    double convert(double amount) const override 
    {
        return amount / 103.17;
    }
    string getCurrencyName() const override {
        return "Euro";
    }
};

class CurrencyAdapter : public CurrencyConverter
{
private:
    CurrencyConverter* converter;

public:
    CurrencyAdapter(CurrencyConverter* conv) : converter(conv) {}

    double convert(double amount) const override
    {
        return converter->convert(amount);
    }
    string getCurrencyName() const override 
    {
        return converter->getCurrencyName();
    }
};