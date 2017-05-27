//
// Created by Krzysztof on 23/05/2017.
//
#include "urzadzenia.h"

std::ostream & operator<<(std::ostream & wyj,const dioda &s)
{
    wyj<<"Aktualna wartosc na wyjsciu: ";
    wyj<<s.inputval;
    wyj<<std::endl;
    return wyj;
}
