#include <iostream>
#include "wejscie.h"

class wyjscie
{
  protected:
  bool outputval;
  wejscie* *output;
  int i;
  int lpodlaczen;
  public:
  wyjscie(wejscie* x=NULL,int lpod=4):outputval(false),i(0)
  {
    lpodlaczen=lpod;
    output=new wejscie*[lpodlaczen];
    Setoutput(x);
  }
  ~wyjscie(){}
  bool zwroc();
  wejscie* zwrocoutput(int x);
  int zwroclpod();
  void Setoutput(wejscie* x);
  void Setoutputval(bool x);
  void operator+(wejscie& b);
  void operator-(wejscie& b);
  friend std::ostream & operator<<(std::ostream & wyj,wyjscie &s);
};

