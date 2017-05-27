#include <iostream>
#include <string.h>
#include "urzadzenia.h"
#include <vector>
#include <queue>
using namespace std;
class Menu
{
private:
int obiekt;
typedef Bramka* BR;
vector<BR> wyjsciowy;
vector <przycisk*> przyciski;
vector <string> nazwa_przyciski;
vector <generator*> generatory;
vector <string> nazwa_generatory;
vector <BR> bramki;
vector <string> nazwa_bramki;
vector <dioda*> diody;
vector<string> nazwa_diody;
vector<oscyloskop*> oscyloskopy;
vector<string> nazwa_oscyloskopy;
vector<wyswietlacz*> wyswietlacze;
vector<string> nazwa_wyswietlacze;
public:
Menu():obiekt(0){}
~Menu()
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
}
int menu();
void wyswietl_menu();
void tworz_bramke(BR a);
void tworz_przycisk();
void tworz_generator();
BR tworz_AND();
BR tworz_OR();
BR tworz_NAND();
BR tworz_NOR();
BR tworz_XOR();
BR tworz_NOT();
void tworz_dioda();
void tworz_oscyloskop();
void tworz_wyswietlacz();
void podlacz();
void ustaw_przelacznik();
void ustaw_generator();
void buduj();
void symulacja(int x);
int przeszukaj(string tmp);
void connect(int ob1,int rodz1,int ob2,int rodz2);
void wyswietl_obiekty();
void resetuj_uklad();
};
