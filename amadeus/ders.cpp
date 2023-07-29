
/*
the triangle program accepts three integers, a,b and c as input, which are taken to be sides of triangle 

the output of the program is the type of triangle, if any, that can be formed with the given sides
equilateral, isosceles, scalene or no triangle at all

sometimes, this problem is extended to include right triangles as fifth type
*/

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter the three sides of the triangle: ";
    cin >> a >> b >> c;

    if (a + b > c && b + c > a && c + a > b) {
        if (a == b && b == c) {
            cout << "Equilateral triangle" << endl;
        }
        else if (a == b || b == c || c == a) {
            cout << "Isosceles triangle" << endl;
        }
        else {
            cout << "Scalene triangle" << endl;
        }
    }
    else {
        cout << "No triangle" << endl;
    }

    return 0;
}

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
        if (a == b && b == c) {
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

/* üçgen noktalarının koordinatlarının verilmesi durumunda çözüm


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cout << "Enter the coordinates of the three points of the triangle: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

    if (a + b > c && b + c > a && c + a > b) {
        if (a == b && b == c) {
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

*/


/*

biçimsiz bir poligon bir şekil ve bir nokta var. verilen nokta şeklin içinde mi dışında mı olduğunu sorgulayan program

#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter the number of vertices of the polygon: ";
    cin >> n;

    int x[n], y[n];
    cout << "Enter the coordinates of the vertices of the polygon: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int px, py;
    cout << "Enter the coordinates of the point: ";
    cin >> px >> py;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if ((y[i] > py) != (y[j] > py)) {
            double atX = (x[j] - x[i]) * (py - y[i]) / (y[j] - y[i]) + x[i];
            if (px < atX) {
                count++;
            }
        }
    }

    if (count % 2 == 0) {
        cout << "Outside" << endl;
    }
    else {
        cout << "Inside" << endl;
    }

    return 0;
}

Kullanıcıdan, poligonun köşe sayısını (n) girmesini istiyoruz.

Daha sonra, poligonun her köşesinin koordinatlarını (x ve y) almak üzere, n adet x ve y değişkenini tanımlıyoruz ve kullanıcıdan bu koordinatları girmesini istiyoruz.

Kullanıcıdan, sorgulamak istediğimiz noktanın koordinatlarını (px ve py) alıyoruz.

Şimdi, noktanın poligonun içinde mi dışında mı olduğunu kontrol etmek için bir sayacı (count) başlatıyoruz.

Bir döngü içinde, her iki köşe arasında bir doğru çiziyoruz ve bu doğru ile nokta arasındaki kesişimi kontrol ediyoruz.

Eğer çizdiğimiz doğru, noktanın y koordinatı (py) ile bir köşenin y koordinatları arasında kesişiyorsa (y[i] > py ve y[j] > py veya y[i] < py ve y[j] < py), bu bize bir kesişme bilgisi vermez ve devam ederiz.

Ancak, çizdiğimiz doğru, noktanın y koordinatı (py) ile bir köşenin y koordinatları arasında geçiyorsa, bu durumda bir kesişme var demektir. Bu kesişme durumunda, noktanın x koordinatı (px) çizdiğimiz doğrunun üzerinde mi altında mı olduğunu kontrol ederiz. Eğer noktanın x koordinatı, doğrunun üzerinde ise, bir kesişme sayarız ve sayacı artırırız (count++). Bu adım, köşe sayısına göre çizdiğimiz doğruların noktayı kaç kez kestiğini sayar.

Sonuç olarak, eğer sayacın değeri çift ise, nokta poligonun dışında kabul edilir (Outside), çünkü poligon köşeleri arasında çift sayıda kesilmiştir. Eğer sayacın değeri tek ise, nokta poligonun içinde kabul edilir (Inside), çünkü poligon köşeleri arasında tek sayıda kesilmiştir.

Son olarak, sonucu ekrana yazdırıyoruz.

Bu şekilde, kullanıcıdan alınan poligonun köşe koordinatları ve bir noktanın koordinatları ile, noktanın poligonun içinde mi dışında mı olduğunu sorgulayan bir program oluşturmuş oluyoruz.


// 



*/

2. yöntem

#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

bool isInsidePolygon(Point polygon[], int n, Point point) {
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x))
        {
            inside = !inside;
        }
    }
    return inside;
}

int main() {
    int n;
    cout << "Enter the number of vertices of the polygon: ";
    cin >> n;

    Point polygon[n];
    cout << "Enter the coordinates of the vertices of the polygon: ";
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    Point point;
    cout << "Enter the coordinates of the point: ";
    cin >> point.x >> point.y;

    if (isInsidePolygon(polygon, n, point)) {
        cout << "Inside" << endl;
    } else {
        cout << "Outside" << endl;
    }

    return 0;
}



// iç içe verilen poligonda poligonların birbirini kesip kesmediğini bulan program

#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

bool isInsidePolygon(Point polygon[], int n, Point point) {
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x))
        {
            inside = !inside;
        }
    }
    return inside;
}

bool isIntersecting(Point polygon1[], int n1, Point polygon2[], int n2) {
    for (int i = 0; i < n1; i++) {
        if (isInsidePolygon(polygon2, n2, polygon1[i])) {
            return true;
        }
    }
    for (int i = 0; i < n2; i++) {
        if (isInsidePolygon(polygon1, n1, polygon2[i])) {
            return true;
        }
    }
    return false;
}

int main() {
    int n1;
    cout << "Enter the number of vertices of the first polygon: ";
    cin >> n1;

    Point polygon1[n1];
    cout << "Enter the coordinates of the vertices of the first polygon: ";
    for (int i = 0; i < n1; i++) {
        cin >> polygon1[i].x >> polygon1[i].y;
    }

    int n2;
    cout << "Enter the number of vertices of the second polygon: ";
    cin >> n2;

    Point polygon2[n2];
    cout << "Enter the coordinates of the vertices of the second polygon: ";
    for (int i = 0; i < n2; i++) {
        cin >> polygon2[i].x >> polygon2[i].y;
    }

    if (isIntersecting(polygon1, n1, polygon2, n2)) {
        cout << "Intersecting" << endl;
    } else {
        cout << "Not intersecting" << endl;
    }

    return 0;
}

//algoritma karmaşıklığı O(n1 * n2) olan bir program yazdık. Bu program, iki poligonun birbirini kesip kesmediğini kontrol ediyor.