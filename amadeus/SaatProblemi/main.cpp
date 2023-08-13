/*Saat Problemi

seven segment saati 7 segmente ayırıp her bir segmenti a,b,c,d,e,f,g olarak isimlendirelim.
Bu segmentlerin her biri 1 veya 0 değerini alabilir. 1 değerini aldığında yanıyor 0 değerini aldığında yanmıyor.
Bu segmentlerin her biri bir sayıyı temsil ediyor. Örneğin 0 sayısını temsil eden segmentler a,b,c,d,e,f yanıyor.
1 sayısını temsil eden segmentler c,f yanıyor. 2 sayısını temsil eden segmentler a,c,d,e,g yanıyor.
3 sayısını temsil eden segmentler a,c,d,f,g yanıyor. 4 sayısını temsil eden segmentler b,d,c,f yanıyor.
5 sayısını temsil eden segmentler a,b,d,f,g yanıyor. 6 sayısını temsil eden segmentler a,b,d,e,f,g yanıyor.
7 sayısını temsil eden segmentler a,c,f yanıyor. 8 sayısını temsil eden segmentler a,b,c,d,e,f,g yanıyor.
9 sayısını temsil eden segmentler a,b,c,d,f,g yanıyor.

İnput olarak gece yarısından sonra kaç saniye geçtiğini vereceğiz, saati output olarak yazdıracağız ve 4 byte çıktı üretecek şekilde yazacağız, 4 farklı digit için bu segmentlerin binary cinsinden karşılıklarını yazacak şekilde yazacağız.
Saati ve dakikayı temsil edecek, saniyeye gerek yok.

Örnek input: 3600
Örnek output: 01:00:00
Binary output: 00000001 00000000 00000000 00000000



Binary olarak input vereceğiz ve output olarak da saat yazdıracağız.

Örnek input: 0000000
Örnek output: 00:00:00

Örnek input: 0000001
Örnek output: 00:00:01

Örnek input: 0000010
Örnek output: 00:00:02

Örnek input: 0000011
Örnek output: 00:00:03






*/

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

std::vector<std::string> sevenSegmentEncoding;

void initializeSevenSegmentEncoding() {
    sevenSegmentEncoding.push_back("11101110"); // 0
    sevenSegmentEncoding.push_back("00100100"); // 1
    sevenSegmentEncoding.push_back("10111010"); // 2
    sevenSegmentEncoding.push_back("10110110"); // 3
    sevenSegmentEncoding.push_back("01110100"); // 4
    sevenSegmentEncoding.push_back("11010110"); // 5
    sevenSegmentEncoding.push_back("11011110"); // 6
    sevenSegmentEncoding.push_back("10100100"); // 7
    sevenSegmentEncoding.push_back("11111110"); // 8
    sevenSegmentEncoding.push_back("11110110"); // 9
}


// Function to display a single digit using seven-segment display
void displayDigit(int digit) {
    if (digit < 0 || digit > 9) {
        std::cout << "Invalid digit: " << digit << std::endl;
        return;
    }

    std::string encoding = sevenSegmentEncoding[digit];
    std::cout << encoding << "   " << digit << "  ";
      
    std::cout << std::endl;
}

// Function to display time on seven-segment display
void displayTime() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* timeInfo = std::localtime(&currentTime);

    int hours = timeInfo->tm_hour;
    int minutes = timeInfo->tm_min;
    int seconds = timeInfo->tm_sec;

    std::cout << "     Clock     " << std::endl;
    std::cout << "===============" << std::endl;
    displayDigit(hours / 10);
    displayDigit(hours % 10);
    std::cout << "       " << std::endl;
    displayDigit(minutes / 10);
    displayDigit(minutes % 10);
    std::cout << "       " << std::endl;
    displayDigit(seconds / 10);
    displayDigit(seconds % 10);
}

int main() {
    initializeSevenSegmentEncoding();

    while (true) {
        displayTime();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // Clear the console (works on some systems)
        std::cout << "\033[2J\033[1;1H";
    }

    return 0;
}