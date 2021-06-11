#include "Scena.hh"


 Scena::Scena()
 {

        Lacze.ZmienTrybRys(PzG::TR_3D);

       Lacze.UstawZakresY(-300, 300);
       Lacze.UstawZakresX(-300, 300);
       Lacze.UstawZakresZ(-300, 300);

       double tab_wym[3]={600,600,0};
       Wektor3D wym_dna(tab_wym);
       for(int i=0;i<N; i++)
       {
           double pozycja[3]={(double)(rand()%440-220),(double)(rand()%440-220),25};
       tab[i]=new Bloczek(i,Lacze,Wektor3D(pozycja));
       tab[i]->zapisz();
       }

       Lacze.Rysuj();
 }
 void  Scena::rysuj()
 { 
  Lacze.Rysuj();
 }
 bool  Scena::interfejs()
 {
    cout<<"Podaj nr kostki 0,1 lub wpisz 2 aby skonczyc dzialanie programu:"<<endl;
    int nr;
    cin>>nr;
    if(nr<N)
    {
        tab[nr]->sterowanie();
    }
    else
    {
        return false;
    }
  return true;
 }

 Scena::~Scena()
 {
    for(int i=0; i<N; i++)
    delete tab[i];
 }