#include "wejscie.h"
bool wejscie::zwroc()
{
    return inputval;
}
int wejscie::zwrocid()
{
    return id;
}
void wejscie::Setid(int x)
{
    id=x;
}
void wejscie::Setobiekt(void* b)
{
    obiekt=b;
}
void wejscie::Setinputval(bool x)
{
    inputval=x;
}
std::ostream & operator<<(std::ostream & wyj,wejscie &s) //wyswietla wszystkie dane w buforze
{
    wyj<<"inputval ";
    wyj<<s.inputval<<"\n";
    wyj<<"id "<<s.id<<"\n";
    wyj<<"obiekt\n"<<s.obiekt;
    return wyj;
}
