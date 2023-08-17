/*

enviroment dikdörtgen şeklinde bir bahçe
bahçenin içinde çeşitli yerlerde fıskiyeler var , konumları var ve fix 0-10 derece arasını ıslatıyor, sonra 10-20 derece arasını ıslatıyor, bu şekilde dönerek hareket ediyor.

bahçede birkaç tane kaplumbağa var, herbirinin ilk konumu var, belli hız ve doğrultuda gidiyorlar. 

100 milisaniyelik adımlar attığımızı varsayalım, ilk 100 milisaniyede 0-10 derece , 100-200 arası 10-20 derece arasını tarıyor gibi düşünülebilir.

An be an hangi fıskiye hangi kaplumbağayı ıslattı
kaplumbağalar belli bir süre sonra duvara çarpacaklar, çarptığı an hangi duvara çarptığını, çarptığı anda ölecek, ölüm anlarını yazdıracak şekilde yazılacak.

metre, metre/ sn, derece , milisaniye gibi birimler kullanılacak.

fıskiyelerin kordinatları, su ıslatma menzilleri, açıları, kaplumbağaların ilk konumları, hızları, doğrultu açıları verilecek. 

kaplumbağaların ölüm anları, duvarlara çarptıkları anlar, ıslanma anları yazdırılacak, kaplumbağalar aynı anda birden fazla fıskiye tarafından ıslanabilir,, tümü yazdırılacak.

online GDB ile çalıştırılabilir.


*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.14159265;

class Fountain {
public:
    double x, y;
    double range1, range2;
    double angle;

    Fountain(double x, double y, double range1, double range2, double angle)
        : x(x), y(y), range1(range1), range2(range2), angle(angle) {}
};

class Turtle {
public:
    double x, y;
    double speed;
    double angle;
    double deathTime;

    Turtle(double x, double y, double speed, double angle)
        : x(x), y(y), speed(speed), angle(angle), deathTime(-1) {}
};

int main() {
    // Bahçe boyutları
    const double gardenWidth = 100;
    const double gardenHeight = 100;

    // Fıskiye ve kaplumbağa listeleri
    vector<Fountain> fountains = {
        Fountain(30, 40, 0, 10, 0),
        Fountain(70, 20, 10, 20, 45)
    };

    vector<Turtle> turtles = {
        Turtle(10, 80, 1, 30),
        Turtle(90, 60, 0.8, 200)
    };

    // Simülasyon adım aralığı ve süresi
    double timeStep = 0.1;
    double simulationTime = 60.0;

    // Simülasyon döngüsü
    for (double currentTime = 0; currentTime < simulationTime; currentTime += timeStep) {
        for (Fountain &fountain : fountains) {
            fountain.angle += timeStep * 10.0;
            if (fountain.angle >= 360) {
                fountain.angle -= 360;
            }

            for (Turtle &turtle : turtles) {
                if (turtle.deathTime != -1) {
                    continue; // Kaplumbağa ölmüşse devam et
                }

                turtle.x += turtle.speed * cos(turtle.angle * PI / 180.0) * timeStep;
                turtle.y += turtle.speed * sin(turtle.angle * PI / 180.0) * timeStep;

                double angleToTurtle = atan2(turtle.y - fountain.y, turtle.x - fountain.x) * 180.0 / PI;
                if (angleToTurtle < 0) {
                    angleToTurtle += 360;
                }

                if (angleToTurtle >= fountain.range1 && angleToTurtle <= fountain.range2) {
                    double distanceToTurtle = sqrt(pow(turtle.x - fountain.x, 2) + pow(turtle.y - fountain.y, 2));

                    if (distanceToTurtle <= 1) { // Eğer 1 birim veya daha yakınındaysa
                        cout << "Turtle at (" << turtle.x << ", " << turtle.y << ") got wet by fountain at (" << fountain.x << ", " << fountain.y << ") at time " << currentTime << endl;
                    }
                }

                if (turtle.x <= 0 || turtle.x >= gardenWidth || turtle.y <= 0 || turtle.y >= gardenHeight) {
                    cout << "Turtle at (" << turtle.x << ", " << turtle.y << ") hit a wall at time " << currentTime << endl;
                    turtle.deathTime = currentTime;
                }
            }
        }
    }

    for (const Turtle &turtle : turtles) {
        if (turtle.deathTime != -1) {
            cout << "Turtle at (" << turtle.x << ", " << turtle.y << ") died at time " << turtle.deathTime << endl;
        }
    }

    return 0;
}
