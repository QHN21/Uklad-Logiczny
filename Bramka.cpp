#include "Bramki.h"
void Bramka::Setpropagacja(int x)
{
    for(int i=0;i<x;i++)
      propagacja.push(NULL);
}
bool Bramka::MOVEsignal(bool x)
{
    bool last;
    propagacja.push(x);
    last=propagacja.front();
    propagacja.pop();
    return last;
}
void Bramka::operator+(wejscie& b)
{
    w+b;
}
void Bramka::operator-(wejscie& b)
{
    w-b;
}
std::ostream & operator<<(std::ostream & wyj,Bramka &s)
{
    wyj<<"\nBramka\n";
    wyj<<"wejscie 1 \n"<<s.w1<<"\n";
    wyj<<"wejscie 2 \n"<<s.w2<<"\n";
    wyj<<"wyjscie \n"<<s.w<<"\n";
    return wyj;
}

