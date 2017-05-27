//
// Created by Krzysztof on 21/05/2017.
//
#include "urzadzenia.h"

using namespace std;

void urz_wejscia::insert_signal(string n)
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

void urz_wejscia::set_signal(bool a)
{
    if (a == 0)
    {
        wyjscie::Setoutputval(a);
        akt = 0;
    }
    else if(a == 1)
    {
        akt = 0;
        wyjscie::Setoutputval(a);
    }
}

void urz_wejscia:: change_signal()
{
    akt++;
    if(akt<cal)
        wyjscie::Setoutputval(syg[akt]);
    else
    {
        akt = 0;
        wyjscie::Setoutputval(syg[akt]);
    }
};

std::ostream & operator<<(std::ostream & wyj,const urz_wejscia &s) //wyswietla wszystkie dane w buforze
{
    wyj<<"aktualny sygnal ";
    wyj<<s.syg[s.akt]<<"\n";
    wyj<<s.syg<<"\n";
    return wyj;
}

