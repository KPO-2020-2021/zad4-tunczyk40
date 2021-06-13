#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>
#include "Macierz.hh"


typedef Macierz<3>  Macierz3x3;


Macierz3x3 macierz_obrotu_x(double kat);
Macierz3x3 macierz_obrotu_y(double kat);
Macierz3x3 macierz_obrotu_z(double kat);

#endif
