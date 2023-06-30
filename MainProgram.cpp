#include <iostream>
#include "Otomobil.h"
#include "Hayvan.h"
#include "Kedi.h"



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

    // Otomobil otomobil1("siyah", "Mercedes", 200);
    // Otomobil otomobil2("beyaz", "BMW", 150);



    // otomobil1.ruhsatBilgileriGoster();
    // cout << endl << endl;  
    // otomobil2.ruhsatBilgileriGoster();

    // return 0;

    // Hayvan h("karabas");
    // h.beslen();
    // h.uyu();

    // cout << endl << endl;
    // return 0;

    Kedi tekir("Tekir");
    tekir.beslen();
    tekir.uyu(); 
    tekir.fareYakala();

    cout << endl << endl;
    return 0;
}