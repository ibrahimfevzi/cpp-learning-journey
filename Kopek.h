#pragma once
#include "Hayvan.h"

class Kopek : public Hayvan{

public:
    Kopek(string ad);
    ~Kopek();
    void havla();
    static int getKopekSayisi(){ return kopekSayisi;}

};

private:
    static int kopekSayisi;
};


