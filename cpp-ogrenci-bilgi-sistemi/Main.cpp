
#include <iostream>
#include "Ogrenci.h"
#include <list> // list STL kütüphanesi

using namespace std;


void menuyuGoster(){

    cout << " * * * * * * * * * * *";
    cout << " *                   *";
    cout << " *       MENU        *";
    cout << " *                   *";
    cout << " * * * * * * * * * * *";
    cout << "1. Ogrenci ekle" << endl;
    cout << "2. Tüm Listeyi Goster" << endl;
    cout << "3. Ogrenci sil" << endl;
    cout << "4. Ogrenci ara" << endl;
    cout << "5. Cikis" << endl;
    

}

void ogrenciEkle( list<Ogrenci> * lst){

    int id;
    string ad;
    int sinavNot;

    cout << "Ogrenci id: ";
    cin >> id;
    cout << "Ogrenci ad: ";
    cin >> ad;
    cout << "Ogrenci sinav not: ";
    cin >> sinavNot;

    Ogrenci ogr(id, ad, sinavNot);
    lst->push_back(ogr);

  
}

void showList(list<Ogrenci> * lst){

    list<Ogrenci>::iterator it;

    for (it = lst->begin(); it != lst->end(); it++)
    {
        it->bilgileriYaz();
    }

    cout << endl;

}

void ogrenciSil(list<Ogrenci> * lst){

    int id;
    cout << "Silinecek ogrenci id: ";
    cin >> id;

    list<Ogrenci>::iterator it;

    for (it = lst->begin(); it != lst->end(); it++)
    {
        if (it->getId() == id)
        {
            lst->erase(it);
            break;
        }
    }




}

void ogrenciAra(list<Ogrenci> * lst){

    int id;
    cout << "Aranacak ogrenci id: ";
    cin >> id;

    list<Ogrenci>::iterator it;

    for (it = lst->begin(); it != lst->end(); it++)
    {
        if (it->getId() == id)
        {
            it->bilgileriYaz();
            break;
        }
    }

}



int main() {

    list<Ogrenci> *ogrenciList = new list<Ogrenci>();





    int secim = 0;
    do {
        menuyuGoster();
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim)
        {
        case 1:
            ogrenciEkle(ogrenciList);
            break;
        case 2:
            showList(ogrenciList);
            break;
        case 3:
            ogrenciSil(ogrenciList);
            break;
        case 4:
            ogrenciAra(ogrenciList);
            break;
        case 5:
            cout << "Cikis yapiliyor..." << endl;
            break;
        default:
            cout << "Hatali secim!" << endl;
            break;
        }
    } while (secim != 5);


        

    return 0;
}

