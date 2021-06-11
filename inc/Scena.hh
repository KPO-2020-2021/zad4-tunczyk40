#ifndef SCENA_HH
#define SCENA_HH
#include <iostream>
#include <iomanip>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "Bloczek.hh"

#define N 2

class Scena
{
 PzG::LaczeDoGNUPlota Lacze;
 Bloczek *tab[N];
 public:
 Scena();
 void rysuj();
 bool interfejs();
~Scena();
};



#endif
