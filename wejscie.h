#include <iostream>
class wejscie
{
  protected:
  int id;
  bool inputval;
  public:
  wejscie(bool a=false,void *b=NULL):id(0),inputval(a){}
  void* obiekt;
  void Setobiekt(void* b);
  bool zwroc();
  int zwrocid();
  void Setid(int x);
  void Setinputval(bool x);
  friend std::ostream & operator<<(std::ostream & wyj,wejscie &s);
};

