#include <stdio.h>
#include <math.h>

int main()
{
    double taban, kuvvet, sonuc;

    // kullanıcıdan iki sayi al 
    printf("Taban: ");
    scanf("%lf", &taban);

    printf("Kuvvet: ");
    scanf("%lf", &kuvvet);

    // taban üzeri kuvveti hesapla
    sonuc = pow(taban, kuvvet);

    printf("%.2lf ^ %.2lf = %.2lf", taban, kuvvet, sonuc);

    return 0;
}
