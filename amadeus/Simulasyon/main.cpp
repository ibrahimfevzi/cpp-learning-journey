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
    double range;
    double angle;

    Fountain(double x, double y, double range, double angle)
        : x(x), y(y), range(range), angle(angle) {}
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

class Garden {
public:
    double corner1_x, corner1_y;
    double corner2_x, corner2_y;

    Garden(double x1, double y1, double x2, double y2)
        : corner1_x(x1), corner1_y(y1), corner2_x(x2), corner2_y(y2) {}
};

int main() {
    // Bahçe boyutları
    Garden garden(0, 0, 100, 100);
    // Fıskiye ve kablumbağa konumlarını  ve menzillerini kullanıcı tarafından girilmesi zaman aldığı için vektör olarak tuttuk.
    // Fıskiye ve kaplumbağa listeleri
    vector<Fountain> fountains = {
        Fountain(30, 40, 10, 0),
        Fountain(70, 20, 10, 45),
        Fountain(60, 30, 10, 270),
        Fountain(50, 10, 10, 90)
    };

    vector<Turtle> turtles = {
        Turtle(10, 80, 1, 30),
        Turtle(90, 60, 0.8, 200),
        Turtle(60, 60, 0.8, 180),
        Turtle(30, 60, 0.8, 90)
    };

    // Simülasyon adım aralığı ve süresi
    double timeStep = 0.1;
    double simulationTime = 18000.0;

    // Simülasyon döngüsü
    for (double currentTime = 0; currentTime < simulationTime; currentTime += timeStep) {
        for (Fountain &fountain : fountains) {
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

                if (angleToTurtle >= fountain.angle - fountain.range / 2 && angleToTurtle <= fountain.angle + fountain.range / 2) {
                    double distanceToTurtle = sqrt(pow(turtle.x - fountain.x, 2) + pow(turtle.y - fountain.y, 2));

                    if (distanceToTurtle <= fountain.range) { // Eğer menzil içerisine girerse
                        cout << "Turtle at (" << turtle.x << ", " << turtle.y << ") got wet by fountain at (" << fountain.x << ", " << fountain.y << ") at time " << currentTime << endl;
                    }
                }

                if (turtle.x <= garden.corner1_x || turtle.x >= garden.corner2_x ||
                    turtle.y <= garden.corner1_y || turtle.y >= garden.corner2_y) {
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
