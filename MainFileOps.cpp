#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // ofstream file; dosya yazma

    // fstream file;
    // file.open("test.text", ios::out | ios::app | ios::binary);

    // if (file.is_open())
    // {
    //    string isim = "İbrahim Kaya";
    //    file << isim << endl;
    //     file.close();
    // }
    // else
    // {
    //     string hata = "Dosya acilamadi.";
    //     cout << hata << endl;
    // }

    // cout <<  endl;

    // return 0;


    // ifstream file; dosya okuma

    fstream file;
    file.open("test.text", ios::in | ios::binary);

    if (file.is_open())
    {
        string isim;
        while (getline(file, isim))
        {
            cout << isim << endl;
        }
        file.close();
    }
    else
    {
        string hata = "Dosya acilamadi.";
        cout << hata << endl;
    }
}


// text dosyaları dışında binary modda dosya açmak için ios::binary kullanılır.
// binary mod ile dosya açıldığında dosyaya yazılan verilerin okunması zorlaşır.
// text dışında kullanma gerekçesi, dosyaya yazılan verilerin okunmasını zorlaştırarak, dosyaya yazılan verilerin değiştirilmesini engellemektir.
