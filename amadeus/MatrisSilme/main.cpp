#include <iostream>
#include <vector>

/*
Fonksiyon Girdileri: 
n satır ve n sütunlu matris (Denklemin solundaki katsayı matrisi: A)
n satır ve 1 sütunlu matris (Denklemin sağındaki kaynak matrisi: b)
k (Silinecek satır-sütuna dair indis)
xk değeri (Değerini öğrendiğimiz ve denklemlerde yerine koyduğumuz değer; yani önceki slaytlardaki x2 değeri gibi)
Fonksiyon Çıktıları:
Uygun şekilde güncellenerek n-1 satır ve n-1 sütunlu hale getirilmiş A matrisi
Uygun şekilde güncellenerek n-1 satır ve 1 sütunlu hale getirilmiş b matrisi

*/

void eliminateRowAndColumn(std::vector<std::vector<double>>& A, std::vector<double>& b, int k) {
    int n = A.size();

    A.erase(A.begin() + k - 1);
    for (int i = 0; i < n - 1; ++i) {
        A[i].erase(A[i].begin() + k - 1);
    }
    b.erase(b.begin() + k - 1);

    double xk = b[k - 1];
    for (int i = k - 1; i < n - 1; ++i) {
        b[i] = b[i + 1];
    }
    b.pop_back();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = k - 1; j < n - 1; ++j) {
            A[i][j] = A[i][j + 1];
        }
        A[i].pop_back();
    }
}

int main() {
    int n;
    std::cout << "Matris boyutunu girin: ";
    std::cin >> n;

    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    std::vector<double> b(n);

    std::cout << "Matris A'yi girin:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Matris b'yi girin:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    int k;
    std::cout << "Silinecek satır ve sütunu girin: ";
    std::cin >> k;

    std::cout << "Girdi Matris A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "| " << b[i] << std::endl;
    }

    eliminateRowAndColumn(A, b, k);

    std::cout << "Çıktı Matris A':" << std::endl;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "| " << b[i] << std::endl;
    }

    return 0;
}
