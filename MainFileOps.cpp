#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    fstream file;
    file.open("test.text", ios::out | ios::app | ios::binary);

    if (file.is_open())
    {
       string isim = "İbrahim Kaya";
       file << isim << endl;
        file.close();
    }
    else
    {
        string hata = "Dosya acilamadi.";
        cout << hata << endl;
    }

    cout <<  endl;

    return 0;
}