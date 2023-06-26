// 20 ile 40 arasındaki sayıların tüm bölenlerini bulan ve ekrana yazdıran bir program yazınız.

#include <iostream>
using namespace std;

int main() {

    for (int i = 20; i <= 40; i++) {
        cout << i << " sayisinin tum bolenleri: ";
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
   





    return 0;
}

