#include "Bramki.h"
void AND::fun()
{
    if(w1.zwroc()&&w2.zwroc())
      w.Setoutputval(MOVEsignal(true));
    else
      w.Setoutputval(MOVEsignal(false));
    return;
}

void NAND::fun()
{
    if(w1.zwroc()&&w2.zwroc())
      w.Setoutputval(MOVEsignal(false));
    else
      w.Setoutputval(MOVEsignal(true));
    return;
}

void OR::fun()
{
    if(w1.zwroc()||w2.zwroc())
      w.Setoutputval(MOVEsignal(true));
    else
      w.Setoutputval(MOVEsignal(false));
    return;
}

void NOR::fun()
{
    if(w1.zwroc()||w2.zwroc())
      w.Setoutputval(MOVEsignal(false));
    else
      w.Setoutputval(MOVEsignal(true));
    return;
}

void NOT::fun()
{
    if(w1.zwroc())
      w.Setoutputval(MOVEsignal(false));
    else
      w.Setoutputval(MOVEsignal(true));
    return;
}

void XOR::fun()
{
    if(w1.zwroc()!=w2.zwroc())
      w.Setoutputval(MOVEsignal(true));
    else
      w.Setoutputval(MOVEsignal(false));
    return;
}




