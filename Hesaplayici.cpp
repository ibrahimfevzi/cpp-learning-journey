#include <iostream>
#include "Ogrenci.h"

using namespace std;

class Hesaplayici {
    public:
        void ortalamaHesapla(Ogrenci ogrenci){
            int ortalama =(ogrenci.not1 + ogrenci.not2) / 2;
            cout << ogrenci.ad << " adlı öğrencinin ortalaması: " << ortalama << endl;

        }
};


int main () {
    Ogrenci ogrenci1("Ahmet", 80, 90);
    Ogrenci ogrenci2("Mehmet", 70, 60);
    Hesaplayici hesaplayici;
    hesaplayici.ortalamaHesapla(ogrenci1);
    hesaplayici.ortalamaHesapla(ogrenci2);
}