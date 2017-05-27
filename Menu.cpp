#include "Menu.h"
typedef Bramka* BR;
typedef wyjscie* wy;
typedef wejscie* we;
int Menu::menu()
{
    wyswietl_menu();
    int menu=1;
    while (menu!=0)
    {
      cin>>menu;
      switch(menu)
      {
        case 0:
          break;
        case 1:
          tworz_przycisk();
          break;
        case 2:
          tworz_bramke(tworz_AND());
          break;
        case 3:
          tworz_bramke(tworz_OR());
          break;
        case 4:
          tworz_bramke(tworz_NAND());
          break;
        case 5:
          tworz_bramke(tworz_NOR());
          break;
        case 6:
          tworz_bramke(tworz_XOR());
          break;
        case 7:
          tworz_bramke(tworz_NOT());
          break;
        case 8:
          tworz_generator();
          break;
        case 9:
          tworz_dioda();
          break;
        case 10:
          tworz_oscyloskop();
          break;
        case 11:
          tworz_wyswietlacz();
          break;
        case 12:
          podlacz();
          break;
        case 13:
          ustaw_przelacznik();
          break;
        case 14:
          ustaw_generator();
          break;
        case 15:
          symulacja(20);
          break;
        case 16:
          wyswietl_menu();
          break;
        case 17:
          wyswietl_obiekty();
          break;
        case 18:
          resetuj_uklad();
          break;
      }
    }
    #if DEBUG
    for(int n=0;n<nazwa_przyciski.size();n++)
    {
        cout<<nazwa_przyciski[n];
        cout<<*przyciski[n];
    }
    for(int n=0;n<nazwa_generatory.size();n++)
    {
        cout<<nazwa_generatory[n];
        cout<<*generatory[n];
    }
    for(int n=0;n<nazwa_bramki.size();n++)
    {
        cout<<nazwa_bramki[n];
        cout<<*bramki[n];
    }
    for(int n=0;n<nazwa_diody.size();n++)
    {
        cout<<nazwa_diody[n];
        cout<<*diody[n];
    }
    for(int n=0;n<nazwa_oscyloskopy.size();n++)
    {
        cout<<nazwa_oscyloskopy[n];
        cout<<*oscyloskopy[n];
    }
     for(int n=0;n<nazwa_wyswietlacze.size();n++)
    {
        cout<<nazwa_wyswietlacze[n];
        cout<<*wyswietlacze[n];
    }
    #endif
    return 0;
}
void  Menu::wyswietl_menu()
{
    cout<<"Wprowadz aby utworzyc nastepujace elementy\n";
    cout<<"1 Przycisk\n";
    cout<<"2 AND\n";
    cout<<"3 OR\n";
    cout<<"4 NAND\n";
    cout<<"5 NOR\n";
    cout<<"6 XOR\n";
    cout<<"7 NOT\n";
    cout<<"8 Generetor\n";
    cout<<"9 Dioda\n";
    cout<<"10 Oscyloskop\n";
    cout<<"11 Wyswietlacz\n";
    cout<<"\n";
    cout<<"Wprowadz aby:\n";
    cout<<"12 Polaczyc bramki\n";
    cout<<"13 Ustawic przycisk\n";
    cout<<"14 Ustawic Generator\n";
    cout<<"\n";
    cout<<"15 uruchamia symulacje\n";
    cout<<"16 wyswietla menu\n";
    cout<<"17 wyswietla wszystkie obiekty\n";
    cout<<"18 resetuje uklad\n";
    cout<<"\n0 konczy program";
    cout<<endl;
}
void Menu::tworz_przycisk()
{
  string tym;
  cout<<"Podaj nazwe urzadzenia\n";
  cin>>tym;
  nazwa_przyciski.push_back(tym);
  przyciski.push_back(new przycisk());
}
void Menu::tworz_generator()
{
  string tym;
  cout<<"Podaj nazwe urzadzenia\n";
  cin>>tym;
  nazwa_generatory.push_back(tym);
  generatory.push_back(new generator("000"));
}
void Menu::tworz_bramke(BR a)
{
  string tym;
  cout<<"Podaj nazwe Bramki\n";
  cin>>tym;
  nazwa_bramki.push_back(tym);
  bramki.push_back(a);
}
void Menu::tworz_dioda()
{
  string tym;
  cout<<"Podaj nazwe urzadzenia\n";
  cin>>tym;
  nazwa_diody.push_back(tym);
  diody.push_back(new dioda());
}
void Menu::tworz_oscyloskop()
{
  string tym;
  cout<<"Podaj nazwe urzadzenia\n";
  cin>>tym;
  nazwa_oscyloskopy.push_back(tym);
  oscyloskopy.push_back(new oscyloskop());
}
void Menu::tworz_wyswietlacz()
{
  string tym;
  cout<<"Podaj nazwe urzadzenia\n";
  cin>>tym;
  nazwa_wyswietlacze.push_back(tym);
  wyswietlacze.push_back(new wyswietlacz());
}
BR Menu::tworz_AND()
{
  BR x=new AND();
  return x;
}
BR Menu::tworz_OR()
{
  BR x=new OR();
  return x;
}
BR Menu::tworz_NAND()
{
  BR x=new NAND();
  return x;
}
BR Menu::tworz_NOR()
{
  BR x=new NOR();
  return x;
}
BR Menu::tworz_XOR()
{
  BR x=new XOR();
  return x;
}
BR Menu::tworz_NOT()
{
  BR x=new NOT();
  return x;
}
void Menu::podlacz()
{
  int obiekt1=0;
  int obiekt2=0;
  int r1=0;
  int r2=0;
  string tmp;
  cout<<"Podaj nazwe 1 obiektu"<<endl;
  cin>>tmp;
  r1=przeszukaj(tmp);
  if(r1!=0)
    obiekt1=obiekt;
  else
    return;
  cout<<"podaj nazwe 2 obiektu"<<endl;
  cin>>tmp;
  r2=przeszukaj(tmp);
  if(r2!=0)
    obiekt2=obiekt;
  else
    return;
  if(r2!=0&&r1!=0)
  connect(obiekt1,r1,obiekt2,r2);
}
int Menu::przeszukaj(string tmp)
{
  int spr=0;
  for(int n=0;n<nazwa_przyciski.size();n++)
  {
    if(tmp.compare(nazwa_przyciski[n])==0)
    {
      obiekt=n;
      spr=1;
    }
  }
  for(int n=0;n<nazwa_generatory.size();n++)
  {
    if(tmp.compare(nazwa_generatory[n])==0)
    {
      obiekt=n;
      spr=2;
    }
  }
  for(int n=0;n<nazwa_bramki.size();n++)
  {
    if(tmp.compare(nazwa_bramki[n])==0)
     {
      obiekt=n;
      spr=3;
    }
  }
  for(int n=0;n<nazwa_diody.size();n++)
  {
    if(tmp.compare(nazwa_diody[n])==0)
     {
      obiekt=n;
      spr=4;
    }
  }
  for(int n=0;n<nazwa_oscyloskopy.size();n++)
  {
    if(tmp.compare(nazwa_oscyloskopy[n])==0)
    {
      obiekt=n;
      spr=5;
    }
  }
  for(int n=0;n<nazwa_wyswietlacze.size();n++)
  {
    if(tmp.compare(nazwa_wyswietlacze[n])==0)
    {
      obiekt=n;
      spr=6;
    }
  }
  if(spr==0)
  {
    cout<<"Nie ma takiego obiektu, sprobuj jeszcze raz";
  }
  return spr;
}
void Menu::connect(int ob1,int rodz1,int ob2,int rodz2)
{
    switch(rodz1)
    {
    case 1:
      switch(rodz2)
        {
            case 1:
              cout<<"blad\n";
            break;
            case 2:
              cout<<"blad\n";
            break;
            case 3:
                if(bramki[ob2]->w1.zwrocid())
                {
                if(bramki[ob2]->w2.zwrocid()==0)
                   *przyciski[ob1]+bramki[ob2]->w2;
                }
                else
                *przyciski[ob1]+bramki[ob2]->w1;
            break;
            case 4:
                *przyciski[ob1]+*diody[ob2];
            break;
            case 5:
                *przyciski[ob1]+*oscyloskopy[ob2];
            break;
            case 6:
                *wyswietlacze[ob2]+*przyciski[ob1];
            break;
        }
    break;
    case 2:
      switch(rodz2)
        {
            case 1:
              cout<<"blad\n";
            break;
            case 2:
              cout<<"blad\n";
            break;
            case 3:
                if(bramki[ob2]->w1.zwrocid())
                {
                if(bramki[ob2]->w2.zwrocid()==0)
                *generatory[ob1]+bramki[ob2]->w2;
                }
                else
                *generatory[ob1]+bramki[ob2]->w1;
            break;
            case 4:
                *generatory[ob1]+*diody[ob2];
            break;
            case 5:
                *generatory[ob1]+*oscyloskopy[ob2];
            break;
            case 6:
                *wyswietlacze[ob2]+*generatory[ob1];
            break;
        }
    break;

    case 3:
        switch(rodz2)
        {
            case 1:
              cout<<"blad";
            break;
            case 2:
              cout<<"blad";
            break;
            case 3:
                if(bramki[ob2]->w1.zwrocid())
                {
                if(bramki[ob2]->w2.zwrocid()==0)
                bramki[ob1]->w+bramki[ob2]->w2;
                }
                else
                bramki[ob1]->w+bramki[ob2]->w1;
            break;
            case 4:
                bramki[ob1]->w+*diody[ob2];
            break;
            case 5:
                bramki[ob1]->w+*oscyloskopy[ob2];
            break;
            case 6:
                *wyswietlacze[ob2]+bramki[ob1]->w;
            break;
        }
    break;
    case 4:
    cout<<"blad";
    break;
    case 5:
    cout<<"blad";
    break;
    case 6:
    cout<<"blad";
    break;
    }
}
void  Menu::ustaw_przelacznik()
{
    string tmp;
    cout<<"Podaj nazwe przycisku"<<endl;
    cin>>tmp;
    if(przeszukaj(tmp)==1)
    {
        if(przyciski[obiekt]->zwroc())
        przyciski[obiekt]->set_signal(0);
        else
        przyciski[obiekt]->set_signal(1);
    }
}
void  Menu::ustaw_generator()
{
    string tmp;
    cout<<"Podaj nazwe generatora"<<endl;
    cin>>tmp;
    if(przeszukaj(tmp)==2)
    {
        generatory[obiekt]->set_generator(1);
        cout<<"Podaj generowany sygnal"<<endl;
        cin>>tmp;
        generatory[obiekt]->insert_signal(tmp);
    }
}
void Menu::buduj()
{
    wyjsciowy.clear();
    void* x;
    vector<BR> temp1;
    vector<BR> temp2;
    for(int n=0;n<przyciski.size();n++)
    {
        for(int o=0;o<przyciski[n]->zwroclpod();o++)
        {
          x=przyciski[n]->zwrocoutput(o)->obiekt;
          if(x!=NULL)
          {
            wyjsciowy.push_back((BR)x);
            temp1.push_back((BR)x);
          }
        }
    }
    for(int n=0;n<generatory.size();n++)
    {
        for(int o=0;o<generatory[n]->zwroclpod();o++)
        {
          x=generatory[n]->zwrocoutput(o)->obiekt;
          if(x!=NULL)
          {
            wyjsciowy.push_back((BR)x);
            temp1.push_back((BR)x);
          }
        }
    }
    while(temp1.size()>=1)
    {
      for(unsigned int n=0;n<temp1.size();n++)
      {
        for(int o=0;o<temp1[n]->w.zwroclpod();o++)
        {
          x=temp1[n]->w.zwrocoutput(o)->obiekt;
          if(x!=NULL)
          {
            wyjsciowy.push_back((BR)x);
            temp2.push_back((BR)x);
          }
        }
      }
      temp1.clear();
      for(unsigned int n=0;n<temp2.size();n++)
       temp1.push_back(temp2[n]);
      temp2.clear();
    }

}
void Menu::symulacja(int x)
{
    buduj();
    for(int n=0;n<x;n++)
    {
        cout<<"----------------"<<endl;
        cout<<"Iteracja "<<n<<endl;
        for(int o=0;o<przyciski.size();o++)
         przyciski[o]->fun();
        for(int o=0;o<generatory.size();o++)
         generatory[o]->change_signal();
        for(int o=0;o<wyjsciowy.size();o++)
         wyjsciowy[o]->fun();
        cout<<"Diody:"<<endl;
        for(int o=0;o<diody.size();o++)
         cout<<nazwa_diody[o]<<" "<<*diody[o]<<endl;
        for(int o=0;o<oscyloskopy.size();o++)
         oscyloskopy[o]->sprawdz();
        cout<<"Wyswietlacze:"<<endl;
        for(int o=0;o<wyswietlacze.size();o++)
        {
         wyswietlacze[o]->sprawdz();
         cout<<*wyswietlacze[o]<<endl;
        }
    }
    for(int o;0<oscyloskopy.size();o++)
         oscyloskopy[o]->zapisz();
    wyjsciowy.clear();

}
void Menu::wyswietl_obiekty()
{
    cout<<"Przyciski: ";
    for(int n=0;n<nazwa_przyciski.size();n++)
      cout<<nazwa_przyciski[n]<<" ";
    cout<<"Generatory: ";
    for(int n=0;n<nazwa_generatory.size();n++)
      cout<<nazwa_generatory[n]<<" ";
    cout<<"Bramki: ";
    for(int n=0;n<nazwa_bramki.size();n++)
      cout<<nazwa_bramki[n]<<" ";
    cout<<"Diody: ";
    for(int n=0;n<nazwa_diody.size();n++)
      cout<<nazwa_diody[n]<<" ";
    cout<<"Oscyloskopy: ";
    for(int n=0;n<nazwa_oscyloskopy.size();n++)
      cout<<nazwa_oscyloskopy[n]<<" ";
    cout<<"Wyswietlacze: ";
    for(int n=0;n<nazwa_wyswietlacze.size();n++)
      cout<<nazwa_wyswietlacze[n]<<" ";
}
void Menu::resetuj_uklad()
{
    for(int n=0;n<przyciski.size();n++)
        delete przyciski[n];
    for(int n=0;n<generatory.size();n++)
        delete generatory[n];
    for(int n=0;n<bramki.size();n++)
        delete bramki[n];
    for(int n=0;n<diody.size();n++)
        delete diody[n];
    for(int n=0;n<oscyloskopy.size();n++)
        delete oscyloskopy[n];
    for(int n=0;n<wyswietlacze.size();n++)
        delete wyswietlacze[n];
    przyciski.clear();
    generatory.clear();
    bramki.clear();
    diody.clear();
    oscyloskopy.clear();
    wyswietlacze.clear();
    nazwa_przyciski.clear();
    nazwa_generatory.clear();
    nazwa_bramki.clear();
    nazwa_diody.clear();
    nazwa_oscyloskopy.clear();
    nazwa_wyswietlacze.clear();
}
