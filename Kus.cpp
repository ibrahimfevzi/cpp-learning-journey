#include "Kus.h"

// Kuş constructor
Kus::Kus(string ad) : Hayvan(ad){

    // Ek özellikler burada tanımlanabilir.
};

void Kus::uc(){
    cout << Hayvan::getIsim << "Kuş Uçuyor !" << endl;
}