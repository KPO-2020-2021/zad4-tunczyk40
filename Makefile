#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: obroty_3D
	./obroty_3D

obroty_3D: obj obj/main.o obj/Macierz3x3.o obj/Wektor3D.o obj/Bryla.o obj/Prostopadloscian.o  obj/Bloczek.o obj/Scena.o obj/Plaszczyzna.o\
           obj/lacze_do_gnuplota.o
	g++ -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor3D.o obj/Bryla.o obj/Prostopadloscian.o  obj/Bloczek.o obj/Scena.o obj/Plaszczyzna.o\
                        obj/Macierz3x3.o obj/lacze_do_gnuplota.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Macierz3x3.hh inc/Macierz.hh\
           inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh inc/Macierz.hh inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/Bryla.o: src/Bryla.cpp inc/Bryla.hh inc/Bryla.hh
	g++ -c ${CXXFLAGS} -o obj/Bryla.o src/Bryla.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh inc/Prostopadloscian.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Bloczek.o: src/Bloczek.cpp inc/Bloczek.hh inc/Bloczek.hh
	g++ -c ${CXXFLAGS} -o obj/Bloczek.o src/Bloczek.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Plaszczyzna.o: src/Plaszczyzna.cpp inc/Plaszczyzna.hh inc/Plaszczyzna.hh
	g++ -c ${CXXFLAGS} -o obj/Plaszczyzna.o src/Plaszczyzna.cpp

clean:
	rm -f obj/*.o obroty_3D
