
// 4 basamaklı ve rakamları birbirinden farklı kaç tam sayı olduğunu bulma ve ekrana yazdırma


#include <iostream>
using namespace std;

int main() {
  


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

    cout << "4 basamaklı ve rakamları birbirinden farklı " << sayac << " tane tam sayı vardır." << endl;


    return 0;
}

