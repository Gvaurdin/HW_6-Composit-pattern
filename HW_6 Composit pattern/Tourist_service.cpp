#include "Tourist_service.h"

void Excursion::displayInfo()
{
	cout << "Excursion: " << name << " ( " << price << " RUB )" << endl;
}

void Hotel::displayInfo()
{
	cout << "Hotel: " << hotelname << ", " << number_days << " ( " << calculatePrice() << " RUB )" << endl;
}

void TransportService::displayInfo()
{
	cout << "Transport: " << mode << " ( " << price << " RUB )" << endl;
}

Tour_ticket::~Tour_ticket()
{
	for (TourComponent* component : components) {
		delete component;
	}
}

void Tour_ticket::removeComponent(TourComponent* component)
{
	auto it = find(components.begin(), components.end(), component);
	if (it != components.end())
	{
		components.erase(it);
	}
}

double Tour_ticket::calculatePrice()
{
	double total = 0.0;
	for (TourComponent* component : components)
	{
		total += component->calculatePrice();
	}
	return total;
}

void Tour_ticket::displayInfo()
{
	cout << "Tour ticket: " << ticket_name << endl;
	for (TourComponent* component : components)
	{
		component->displayInfo();
	}
	cout << "Total ticket price: (RUB)" << calculatePrice() <<
		"\n================================================================\n";
}



Tour_ticket Create_Tour_Kaliningrad()
{
	Tour_ticket tour_Kaliningrad = Tour_ticket("Travel to Kaliningrad");
	TourComponent* excursion = new Excursion("Curonian Spit", 1300);
	TourComponent* hotel = new Hotel("Luxury Hotel", 7, 5000);
	TourComponent* transportService = new TransportService("Plane (round trip)", 10345);
	tour_Kaliningrad.addComponent(excursion);
	tour_Kaliningrad.addComponent(hotel);
	tour_Kaliningrad.addComponent(transportService);
	return tour_Kaliningrad;
}

Tour_ticket Create_Tour_Kazan()
{
	Tour_ticket tour_kazan = Tour_ticket("Travel to Kazan");
	TourComponent* excursion = new Excursion("Bauman Street Tour", 1340);
	TourComponent* hotel = new Hotel("Medium Hotel", 10, 2500);
	TourComponent* transportService = new TransportService("Plane (round trip)", 9489);
	tour_kazan.addComponent(excursion);
	tour_kazan.addComponent(hotel);
	tour_kazan.addComponent(transportService);
	return tour_kazan;
}


