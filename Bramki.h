#include "wyjscie.h"
#include <queue>
class Bramka
{
std::queue < bool > propagacja;
public:
Bramka(const wejscie& a=NULL,const wejscie& b=NULL,const wyjscie& c=NULL,int prop=5):w1(a),w2(b),w(c)
{
   w1.Setobiekt(this);
   w2.Setobiekt(NULL);
}
virtual ~Bramka(){}
    virtual void fun()=0;
    void Setpropagacja(int x);
    bool MOVEsignal(bool x);
    wejscie w1,w2;
    wyjscie w;
    void operator+(wejscie& b);
    void operator-(wejscie& b);
    friend std::ostream & operator<<(std::ostream & wyj,Bramka &s);
};
class AND:public Bramka
{
public:
AND(){Setpropagacja(2);}
void fun();
};

class OR: public Bramka
{
public:
OR(){Setpropagacja(2);}
void fun();
};

class NAND:public Bramka
{
    public:
NAND(){Setpropagacja(2);}
void fun();
};

class NOR:public Bramka
{
public:
NOR(){Setpropagacja(2);}
void fun();
};
class XOR:public Bramka
{
public:
XOR(){Setpropagacja(3);}
void fun();
};
class NOT:public Bramka
{
public:
NOT(){Setpropagacja(1);}
void fun();
};
