#include <iostream> 
using namespace std; 
 
int main() 
{

    int a[5], *p, z;

    for (int i = 0; i < 5; i++){
        a[i] = i * i;

    p = a;
    z = *(p + 1) + *(a + 2);
    cout << z << endl;
    }

        return 0; 
} 


//sonuç: 5

// 1. for döngüsü ile a dizisine 0, 1, 4, 9, 16 değerleri atandı.
// p pointer'ı a dizisinin ilk elemanını gösteriyor.
// z değişkenine p pointer'ının gösterdiği değerin bir sonraki elemanı ile a dizisinin 2. elemanının toplamı atandı.
// p pointer'ı a dizisinin 2. elemanını gösteriyor.
// z değişkeni ekrana yazdırıldı.

// a dizisi
// 0 1 4 9 16

// p pointer'ı
// 0 1 4 9 16

// z değişkeni
// 5 5 5 5 5
