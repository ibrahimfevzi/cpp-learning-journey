#include "Kopek.h"

int Kopek::kopekSayisi = 0;

// Köpek constructor
Kopek::Kopek(string ad) : Hayvan(ad){

// Ek özellikler burada tanımlanabilir.
    kopekSayisi++;
};

// Kopek destructor 
Kopek::~Kopek(){
    kopekSayisi--;
};

void Kopek::havla(){
    cout << Hayvan::getIsim << "Köpek havlıyor !" << endl;
}