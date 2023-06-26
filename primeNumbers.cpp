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

// 4 basamaklı ve rakamları birbirinden farklı kaç tam sayı olduğunu bulma ve ekrana yazdırma

    int sayac = 0;
    for (int i = 1000; i <= 9999; i++) {
        int binler = i / 1000;
        int yuzler = (i / 100) % 10;
        int onlar = (i / 10) % 10;
        int birler = i % 10;

        if (binler != yuzler && binler != onlar && binler != birler && yuzler != onlar && yuzler != birler && onlar != birler) {
            sayac++;
        }
    }



    return 0;
}

