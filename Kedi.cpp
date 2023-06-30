#include "Kedi.h"

// Kedi constructor
Kedi::Kedi(string ad) : Hayvan(ad){

    // Ek özellikler burada tanımlanabilir.
};

void Kedi::fareYakala(){
    cout << Hayvan::getIsim << "Fare yakalıyor !" << endl;
}