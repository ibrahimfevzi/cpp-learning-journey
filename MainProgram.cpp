#include <iostream>
#include "Otomobil.h"



using namespace std;

int main()
{

    // string isim = "Ali Kaya";
    // int yas = 20;

    // cout << "Merhaba" << endl
    //      << endl
    //      << "Ogrenci Adi - Soyadi : "
    //      << isim << endl;
    // cout <<"Ogrenci Yasi : " <<  yas << endl;

    // return 0;

    Otomobil otomobil1, otomobil2;

    otomobil1.renk = "siyah";
    otomobil1.model = "Mercedes";
    otomobil1.beygirGucu = 200;
    
    otomobil2.renk = "beyaz";
    otomobil2.model = "BMW";
    otomobil2.beygirGucu = 150;


    otomobil1.ruhsatBilgileriGoster();
    cout << endl << endl;  
    otomobil2.ruhsatBilgileriGoster();


    
    ;
}