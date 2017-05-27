//
// Created by Krzysztof on 21/05/2017.
//
#include "urzadzenia.h"

using namespace std;

void przycisk::set_signal(bool a)
{
        wyjscie::Setoutputval(a);
}
void przycisk::fun()
{
    Setoutputval(outputval);
}
std::ostream & operator<<(std::ostream & wyj,const przycisk &s) //wyswietla wszystkie dane w buforze
{
    wyj<<"Aktualny sygnal: ";
    wyj<<"\n";
    return wyj;
}

