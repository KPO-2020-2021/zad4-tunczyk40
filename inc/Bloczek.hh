#ifndef BLOCZEK_HH
#define BLOCZEK_HH

#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#include <unistd.h> // biblioteka dla usleep
#define CZAS 20000

class Bloczek
{
    std::vector<Wektor3D> droga_drona;
    PzG::LaczeDoGNUPlota &Lacze;
    Prostopadloscian oryginal;
    Prostopadloscian kopia;
    Macierz3x3 obr;
    Wektor3D droga;
    double kat;
    int id; 
public:

  
  Bloczek(int id,PzG::LaczeDoGNUPlota &Lacze,Wektor3D pozycja);
  void ruch(double droga);
  void obrot_x(double kat); // kat podajemy w stopniach
  void obrot_z(double kat);
  void obrot_y(double kat);
  void zapisz();
  void sterowanie();
  void okresl_droge(double droga);
};

#endif
