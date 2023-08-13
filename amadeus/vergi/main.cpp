#include <iostream>
#include "TaxBrackets.h"

double calculateIncomeTax(double annualIncome) {
    double totalTax = 0.0;
    double remainingIncome = annualIncome;

    if (remainingIncome > Bracket1) {
        totalTax += (Bracket1 * 0.15);
        remainingIncome -= Bracket1;
    } else {
        totalTax += (remainingIncome * 0.15);
        remainingIncome = 0;
    }

    if (remainingIncome > 0) {
        double bracket2Income = std::min(remainingIncome, static_cast<double>(Bracket2 - Bracket1));
        totalTax += (bracket2Income * 0.20);
        remainingIncome -= bracket2Income;
    }

    if (remainingIncome > 0) {
        double bracket3Income = std::min(remainingIncome, static_cast<double>(Bracket3 - Bracket2));
        totalTax += (bracket3Income * 0.27);
        remainingIncome -= bracket3Income;
    }

    if (remainingIncome > 0) {
        double bracket4Income = std::min(remainingIncome, static_cast<double>(Bracket4 - Bracket3));
        totalTax += (bracket4Income * 0.35);
        remainingIncome -= bracket4Income;
    }

    if (remainingIncome > 0) {
        totalTax += (remainingIncome * 0.40);
    }

    return totalTax;
}

int main() {
    double annualIncome;
    
    while (true) {
        std::cout << "Yillik geliri giriniz (TL): ";
        std::cin >> annualIncome;
        
        if (annualIncome < 0) {
            std::cout << "Gecersiz giris! Gelir negatif olamaz." << std::endl;
        } else {
            break;
        }
    }

    double taxAmount = calculateIncomeTax(annualIncome);
    
    std::cout << "Odemeniz gereken gelir vergisi: " << taxAmount << " TL" << std::endl;

    return 0;
}
