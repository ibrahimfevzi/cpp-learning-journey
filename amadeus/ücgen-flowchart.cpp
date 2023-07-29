/*
the triangle program accepts three integers, a,b and c as input, which are taken to be sides of triangle 

the output of the program is the type of triangle, if any, that can be formed with the given sides
equilateral, isosceles, scalene or no triangle at all

sometimes, this problem is extended to include right triangles as fifth type

aynı zamanda dik üçgen olup olmadıpını da kontrol ediyoruz
*/

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter the three sides of the triangle: ";
    cin >> a >> b >> c;

    if (a + b > c && b + c > a && c + a > b) {
        if (a == b && b == c ||a == b && c == a || b == c && c == a) {
            cout << "Equilateral triangle" << endl;
        }
        else if (a == b || b == c || c == a) {
            cout << "Isosceles triangle" << endl;
        }
        else {
            cout << "Scalene triangle" << endl;
        }

        if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) {
            cout << "Right triangle" << endl;
        }
    }
    else {
        cout << "No triangle" << endl;
    }

    return 0;
}


