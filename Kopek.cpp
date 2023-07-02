#include "Kopek.h"

// Kedi constructor
Kopek::Kopek(string ad) : Hayvan(ad){

    // Ek özellikler burada tanımlanabilir.
};

void Kopek::havla(){
    cout << Hayvan::getIsim << "Köpek havlıyor !" << endl;
}