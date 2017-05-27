//
// Created by Krzysztof on 23/05/2017.
//


#include <vector>
#include <fstream>
#include "Bramki.h"

class przycisk//pelni role przycisku generujacego sygnal
        :public wyjscie
{
public:
    przycisk(bool a = false) :wyjscie()
    {
         Setoutputval(a);
    };
    friend std::ostream & operator<<(std::ostream & wyj,const przycisk &s);
    void fun();
    void set_signal(bool a);
};

class generator//pelni role generatora sygnalu
        :public wyjscie
{
private:
    int cal, akt;
    bool *syg;
    bool stan;
public:
    generator(std::string n) :wyjscie(),akt(0)
    {
        cal = n.size();
        syg = new bool[cal]();
        insert_signal(n);
    };
    friend std::ostream & operator<<(std::ostream & wyj,const generator &s);
    void set_generator(bool a);
    void change_signal();
    void insert_signal(std:: string n);
};

class dioda//moze pelnic role diody
        :public wejscie
{
public:
    dioda()
    {
        Setobiekt(NULL);
    };
    friend std::ostream & operator<<(std::ostream & wyj,const dioda &s);
};

class oscyloskop
        :public dioda
{
private:
    std::vector<bool>zaw;
public:
    void sprawdz();
    void zapisz();
};

class wyswietlacz
{
private:
    std::vector<wyjscie*>wsk;
    int x;
    bool *zaw;
public:
    wyswietlacz(int a = 2)
    {
        x = a;
        zaw = new bool[x]();
        for(int i = 0; i<x; i++)
        {
            wsk.push_back(NULL);
        }
    }
    void operator+(wyjscie& b);
    void operator-(wyjscie& b);
    void sprawdz();
    friend std::ostream & operator<<(std::ostream & wyj,const wyswietlacz &s);
};

