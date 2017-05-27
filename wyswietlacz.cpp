//
// Created by Krzysztof on 24/05/2017.
//
#include "urzadzenia.h"

void wyswietlacz:: operator+(wyjscie& b)
{
    for(int i = 0; i<x; i++)
    {
        if(wsk[i] == NULL)
        {
            wsk[i] = &b;
            break;
        }

    }
};

void wyswietlacz:: operator-(wyjscie& b)
{
    for(int i = 0; i<x; i++)
    {
        if(&b == wsk[i])
        {
            wsk[i] = NULL;
            break;
        }
    }
};

void wyswietlacz::sprawdz()
{
    for(int i = 0; i<x; i++)
    {
        if(wsk[i] != NULL)
        {
            zaw[i] = wsk[i]->zwroc();
        }
        else
            zaw[i] = NULL;
    }
}

std::ostream & operator<<(std::ostream & wyj,const wyswietlacz &s)
{
    wyj<<"Wyswietlacz: ";
    for(int i = 0; i<s.x; i++)
    {
        if(s.wsk[i] != NULL)
            wyj<<s.zaw[i]<<" ";
        else
            wyj<<"- ";
    }
    wyj<<"\n";
    return wyj;
}
