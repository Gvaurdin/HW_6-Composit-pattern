#include <vector>
#include "Tourist_service.h"
#include "Tourist_ticket.h"
#include "Money_Adapter.h"

ostream& operator << (ostream& os, Tourist_ticket& ticket)
{
    cout << "Destination: " << ticket.destination << endl;
    cout << "Start Date: " << ticket.begin_date << endl;
    cout << "Duration: " << ticket.duration << " days" << endl;
    cout << "Price: " << ticket.price << " (" << "RUB" << ")" << endl;
    return os;
}

int SelectCurrency()
{
    char action{}; int mode{};
    cout << "Select currency\n" <<
        "Enter 1 to select currency USD\n" <<
        "Enter 2 to select currency Euro\n" <<
        "Enter 3 to select currency RUB\n" <<
        "Your action : "; cin >> action;
    while (action != '1' && action != '2' &&
        action != '3' && !action)
    {
        cout << "Error input currency\n" <<
            "Try enter comand again : ";
        cin >> action;
    }
    if (action == '1')
    {
        mode = 1;
        cout << "Your currnecy = USD\n";
    }
    else if (action == '2')
    {
        mode = 2;
        cout << "Your currnecy = EUR\n";
    }
    else
    {
        mode = 3;
        cout << "Your currnecy = RUB\n";
        system("pause");
    }
    return mode;
}

CurrencyConverter* Get_Mode(int& mode)
{
    try
    {
        if (mode < 1 || mode > 3 || !mode)
        {
            throw range_error("Error type mode");
        }
        if (mode == 1)
        {
            CurrencyConverter* conv = new CurrencyAdapter(new USDConverter);
            return conv;
        }
        if (mode == 2)
        {
            CurrencyConverter* conv = new CurrencyAdapter(new EuroConverter);
            return conv;
        }
        if (mode == 3)
        {
            return 0;
        }
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
}

void menu()
{
    vector <Tourist_ticket> vec_ticket;
    vec_ticket.push_back(Tourist_ticket("Paris, France", "2023-09-01", 7, 100000.0));
    vec_ticket.push_back(Tourist_ticket("Kair, Egipet", "2023-11-12", 7, 150000.0));
    bool flag = false; char action{}; int mode{};
    mode = SelectCurrency();
    while (flag == false)
    {
        system("cls");
        cout << "Tourist Company\n" <<
            "Enter 1 to show tourist tickets and price\n" <<
            "Enter 2 to exit\n" <<
            "You action : ";
        cin >> action;
        while (action != '1' && action != '2' && !action)
        {
            cout << "Error input currency\n" <<
                "Try enter comand again : ";
            cin >> action;
        }
        switch (action)
        {
        case '1':
        {
            system("cls");
            CurrencyConverter* conv = Get_Mode(mode);
            Tour_ticket tour_Kaliningrad = Create_Tour_Kaliningrad();
            Tour_ticket tour_Kazan = Create_Tour_Kazan();
            cout << "\n====================================Foreign tours==================================\n";
            for (Tourist_ticket& ticket : vec_ticket)
            {
                ticket.ShowInfo(conv);
            }
            delete conv;
            cout << "\n====================================Russian tours==================================\n";
            tour_Kaliningrad.displayInfo();
            tour_Kazan.displayInfo();
            system("pause");
        }
        break;
        case '2':
        {
            system("cls");
            cout << "Exit.....\n";
            system("pause");
            flag = true;
        }
        break;
        }
    }
}


void Tourist_ticket::ShowInfo(const CurrencyConverter* converter)
{
    cout << "Destination: " << destination << endl;
    cout << "Start Date: " << begin_date << endl;
    cout << "Duration: " << duration << " days" << endl;
    if (converter != nullptr)
    {
        cout << "Price: " << converter->convert(price) << " (" << converter->getCurrencyName() << ")" << endl;
    }
    else
    {
        cout << "Price: " << price << " (" << "RUB" << ")" << endl;
    }
    cout << "\n================================================================\n";
}
