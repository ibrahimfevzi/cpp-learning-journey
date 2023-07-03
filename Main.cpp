#include <iostream>

using namespace std;

//Base class 
class Hayvan{
    public:
       virtual void sesCikar() {
              cout << "Hayvan sınıfı ses çıkarıyor !" << endl;
       }
       void yazdir() {
              cout << "Hayvan sınıfı yazdırıyor !" << endl;
       }
};

//Child class
class Kedi : public Hayvan{
    public:
       void sesCikar() {
              cout << "Kedi sınıfı ses çıkarıyor !" << endl;
       }
       void yazdir() {
              cout << "Kedi sınıfı yazdırıyor !" << endl;
       }
};


int main() {
    Hayvan *phayvan;
    Kedi tekir;
    phayvan = &tekir;
    phayvan->sesCikar();
    phayvan->yazdir();
    return 0;
} 