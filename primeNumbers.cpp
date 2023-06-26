//ASAL SAYILARI BULMA


#include <iostream>
using namespace std;

int main() {
    int sayi;
    cout << "Lutfen sayi giriniz: ";
    cin >> sayi;

    for (int i = 2; i <= sayi; i++) {
        bool asalMi = true;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                asalMi = false;
                break;
            }
        }
        if (asalMi) {
            cout << i << " ";
        }
    }

    return 0;
}

