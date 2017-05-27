#include "wyjscie.h"
void wyjscie::Setoutput(wejscie* x)
{
  if(x!=NULL)
  {
    x->Setid(1);
    if(i<lpodlaczen)
    {
      output[i++]=x;
    }
    else
    {
      wejscie* *temp;
      temp=output;
      output=new wejscie*[lpodlaczen=lpodlaczen+4];
      for(int k=0;k<i;k++)
      output[k]=temp[k];
      output[i++]=x;
      delete []temp;
    }
  }
}
bool wyjscie::zwroc()
{
    return outputval;
}
wejscie* wyjscie::zwrocoutput(int x)
{
    if (x<i)
    return output[x];
    return NULL;
}
int wyjscie::zwroclpod()
{
    return i;
}
void wyjscie::Setoutputval(bool x)
{
    outputval=x;
    if(output[0]!=NULL)
    {
      for(int k=0;k<i;k++)
      output[k]->Setinputval(x);
    }
}
void wyjscie::operator+(wejscie& b)
{
    Setoutput(&b);
}
void wyjscie::operator-(wejscie& b)
{
    if(i!=0)
    {
      for(int k=0;k<i;k++)
        {
          if(output[k]==&b)
            {
               if(k==i-1)
               {
                   i--;
                   output[i]=NULL;
               }
               else
               {
                  i--;
                  output[k]=output[i];
                  output[i]=NULL;
               }
            }
        }
    }
}
std::ostream & operator<<(std::ostream & wyj,wyjscie &s) //wyswietla wszystkie dane w buforze
{
    wyj<<"outputval ";
    wyj<<s.outputval<<"\n";
    wyj<<"outputs \n";
    for(int k=0;k<s.i;k++)
    wyj<<s.output[k]<<"\n";
    return wyj;
}
