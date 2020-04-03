//Egy szekvenciális inputfájlban vadászok adott napi vadászatain elejtett zsákmányait (fajtanév és súly párok formájában) vadászok szerint rendezetten tároljuk. Igaz-e, hogy minden vadász valamelyik vadászatán lőtt medvét?
//Üres a felsoroló osztály, viszont adottak a fájl és a felsorolandó adatok szerkezetét leíró struktúrák, és azokhoz az estelgesen szükséges beolvasó és kiíró operátorok. Feladat továbbá a main elkészítése: Igaz-e, hogy minden vadász valamelyik vadászatán lőtt medvét?

#include <iostream>
#include "vadaszEnor.h"

using namespace std;

int main(){
	
	VadaszEnor t("infile.txt");
	bool mindenszorcs = true;
	t.first();
	while( mindenszorcs && !t.end() ) {
		mindenszorcs = t.current().vanMedve;
		t.next();
	}
	
	if( mindenszorcs ) {
		cout << "Mindenki lott medvet, nyertes nyertes medve vacsora!!" << endl;
	} else {
		cout << "Nem mindenki lott medvet, haha noob" << endl;
	}
		
	return 0;
}
