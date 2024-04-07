#include "Circuit.h"
#include<iostream>
using namespace std;
void Circuit::SetLength(int dist) {
	this->length = dist;
}
void Circuit::SetWeather(Weather vreme){
	this ->vreme = vreme;
}
void Circuit::AddCar(CAR* car) {
   // cars = new CAR* [this->nr_masini];
	cars[this->nr_masini++] = car;

}
void Circuit::Race()
{
    unsigned int i;

    for (i = 0; i < (int) this->nr_masini ;i++)
    {
        if (cars[i]->getDistance() >= this->length)
            cout << cars[i]->name << " termina in " << cars[i]->getRace_time(length,this->vreme) << " ore\n";
    }
}
void Circuit::ShowFinalRanks()
{
   
    int time[11];
    CAR** aux;
    aux = cars;

    for (int i = 0; i < nr_masini; i++)
    {
        if (cars[i]->getDistance() >= this->length)
        {
            time[i] = cars[i]->getRace_time(length, vreme);
        }
        else time[i] = 9999;
    }
    for (int i = 0; i < nr_masini - 1; i++)
        for (int j = i + 1; j < nr_masini; j++)
            if (time[i] > time[j])
            {
                std::swap(aux[i], aux[j]);
                std::swap(time[i], time[j]);
            }

    std::cout << "\nRankings:\n";
    for (int i = 0; i < nr_masini; i++)
        std::cout << aux[i]->name << '\n';
}

void Circuit::ShowWhoDidNotFinish()
{
    unsigned int i, k = 0;
    bool ok = 0;
    CAR* DNF[11];

    for (i = 0; i < nr_masini; i++)
    {
        if (cars[i]->getDistance() < this->length)
        {
            DNF[k++] = cars[i];
            ok = 1;
        }
    }
    if (ok)
        std::cout << "\nDNF:\n";
    for (int i = 0; i < k; i++)
    {
        std::cout << DNF[i]->name << " nu termina cursa\n";
    }
}