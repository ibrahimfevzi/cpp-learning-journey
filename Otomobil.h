#pragma once 
#include "iostream"

using namespace std;

class Otomobil
{
 public:
     string renk;
     string model;
     int beygirGucu;

     void ruhsatBilgileriGoster();
     Otomobil(string _renk, string _model, int _beygirGucu);
};