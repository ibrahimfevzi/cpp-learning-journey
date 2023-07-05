#include "Otomobil.h"

// Otomobil constructor
Otomobil:: Otomobil(string _renk, string _model, int _beygirGucu){
    renk = _renk;
    model = _model;
    beygirGucu = _beygirGucu;
}

void Otomobil::ruhsatBilgileriGoster()
{
    cout << "Model : " << model << endl;
    cout << "Renk : " << renk << endl;
    cout << "Beygir Gucu : " << beygirGucu << endl;
}

//

