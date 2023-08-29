#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TourComponent
{
public:
    virtual double calculatePrice() = 0;
    virtual void displayInfo() = 0;
};

class Excursion : public TourComponent
{
private:
    string name;
    double price;

public:
    Excursion(const string& n, double p) : name(n), price(p) {}

    double calculatePrice() override { return price; }

    void displayInfo() override;
};

class Hotel : public TourComponent
{
private:
    string hotelname;
    int number_days;
    double price_day;

public:
    Hotel(const string& name, int nights, double price)
        : hotelname(name), number_days(nights), price_day(price) {}

    double calculatePrice() override { return number_days * price_day;}

    void displayInfo() override;
};

class TransportService : public TourComponent 
{
private:
    string mode;
    double price;

public:
    TransportService(const string& m, double p) : mode(m), price(p) {}

    double calculatePrice() override 
    {
        return price;
    }

    void displayInfo() override;
};

class Tour_ticket : public TourComponent 
{
private:
    string ticket_name;
    vector<TourComponent*> components;

public:
    Tour_ticket(const string& name) : ticket_name(name) {}
   
    ~Tour_ticket();

    void addComponent(TourComponent* component) {components.push_back(component);}

    void removeComponent(TourComponent* component);

    double calculatePrice() override;

    void displayInfo() override;
};

Tour_ticket Create_Tour_Kaliningrad();

Tour_ticket Create_Tour_Kazan();


