//
// Created by Krzysztof on 22/05/2017.
//

#include "urzadzenia.h"

using namespace std;

void generator::insert_signal(string n)
{
    std::string::iterator it;
    for (it = n.begin(); it != n.end(); it++)//zapisuje znaki ze stringa do tablicy charow
    {
        if(*it == '1') syg[akt] = true;
        else syg[akt] = false;
        akt++;
    }
    akt = 0;
}

void generator::set_generator(bool a)
{
    if (a == 0)
    {
        wyjscie::Setoutputval(a);
        akt = 0;
        stan = false;
    }
    else if(a == 1)
    {
        akt = 0;
        wyjscie::Setoutputval(syg[akt]);
        stan = true;
    }
}

void generator:: change_signal()
{
    akt++;
    if(stan)
    {
        if (akt < cal)
            wyjscie::Setoutputval(syg[akt]);
        else {
            akt = 0;
            wyjscie::Setoutputval(syg[akt]);
        }
    }
};

std::ostream & operator<<(std::ostream & wyj,const generator &s) //wyswietla wszystkie dane w buforze
{
    wyj<<"Aktualny sygnal generowany: ";
    wyj<<s.syg[s.akt]<<"\n";
    return wyj;
}
