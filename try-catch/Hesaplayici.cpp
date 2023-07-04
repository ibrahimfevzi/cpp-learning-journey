#include <iostream>

using namespace std;

int main() {

try
{
    int yas;
    cout << "Yaşınızı giriniz: ";
    cin >> yas;
    if (yas >= 18)
    {
        cout << "Mekana hoşgeldiniz !" << endl;
    }
    else{
        throw (yas);
        
    }
}
catch(int hataNo)
{
    cout << "Mekana giremezsiniz ! Yaşınız 18'den küçük" << endl;
    cout << "Yaşınız: " << hataNo << endl;
}

    return 0;
}

//Notlar




    