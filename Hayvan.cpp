#include "Hayvan.h"


// Hayvan constructor
Hayvan::Hayvan(string ad){
    Hayvan::isim = ad;
}

void Hayvan::beslen(){
    cout << Hayvan::isim << " besleniyor." << endl;

}

void Hayvan::uyu(){
    cout << Hayvan::isim << " uyuyor." << endl;
}

void Hayvan::setIsim(string ad){
    Hayvan::isim = ad;
}

string Hayvan::getIsim(){
    return Hayvan::isim;
}
