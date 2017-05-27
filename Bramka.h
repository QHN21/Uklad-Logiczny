
class Bramka
{
    typedef Bramka* w;
    void Setinput(w in,int nr);
    void Setout(w out);
    public:
    Bramka(w in1=NULL,w in2=NULL, w out=NULL)
    {
        Setinput(in1,1);
        Setinput(in2,2);
        Setout(out);
    }
    w wej1;
    w wej2;
    w wyj;
    int input1=0;
    int input2=0;
    int output=0;
    int Showinput(int x);
    void Setinputval();
    virtual void Setoutput(){}
    void Podlacz(w in,int nr);
    void Odlacz(int nr);
    void operator+(Bramka &P);
    friend std::ostream & operator<<(std::ostream & wyjscie,Bramka &s);
};
void Bramka::Setout(w out)
{
    wyj=out;
}
void Bramka::Setinput(w in, int nr)
{
  if(in!=NULL)
  {
    if(nr==1)
    {
      wej1=in;
      input1=in->output;
    }
    else
    {
      wej2=in;
      input2=in->output;
    }
  }
  else
  {
    if(nr==1)
      wej1=NULL;
    else
      wej2=NULL;
  }
  Setoutput();
}
int Bramka::Showinput(int x)
{
    if(x==1)
        return input1;
    else
        return input2;
}
void Bramka::Setinputval()
{
    if(wej1!=NULL)
        input1=wej1->output;
    if(wej2!=NULL)
        input2=wej2->output;
}
void Bramka::operator+(Bramka& P)  //sumuje dwa bufory (zwraca liczbe zaszyfrowanych w nich obu znakow)
  {
    if(wej1==NULL)
    Setinput(&P,1);
    else
    Setinput(&P,2);
  }
//-------------------------------------
std::ostream & operator<<(std::ostream & wyjscie,Bramka &s) //wyswietla wszystkie dane w buforze
{
   wyjscie<<"wej1 ";
    wyjscie<<s.wej1<<" ";
    wyjscie<<s.input1<<" ";
    wyjscie<<"\n"<<"wej2 "<<s.wej2<<" "<<s.input2;
    wyjscie<<"\nwyjscie "<<s.output<<"\n";
    return wyjscie;
}
