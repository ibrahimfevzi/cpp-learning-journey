#pragma once
#include <iostream>

using namespace std;

class Ogrenci{
    
    private:
        int not1;
        int not2;
        string ad;

    public:
        Ogrenci(string _ad, int n_ot1, int _not2);
        ~Ogrenci();
        friend class Hesaplayici;
};