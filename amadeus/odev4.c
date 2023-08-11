#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int mYear;
    int mMonth;
    int mDay;
} CDate;

bool IsValidDate(int year, int month, int day) {
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0)
            daysInMonth[2] = 29;
    }

    if (day > daysInMonth[month])
        return false;

    return true;
}

bool IsLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0)
            return true;
    }
    return false;
}

CDate ComputeNextDate(CDate date) {
    CDate nextDate = date;

    nextDate.mDay++;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(nextDate.mYear))
        daysInMonth[2] = 29;

    if (nextDate.mDay > daysInMonth[nextDate.mMonth]) {
        nextDate.mDay = 1;
        nextDate.mMonth++;

        if (nextDate.mMonth > 12) {
            nextDate.mMonth = 1;
            nextDate.mYear++;
        }
    }

    return nextDate;
}

CDate ComputePreviousDate(CDate date) {
    CDate previousDate = date;

    previousDate.mDay--;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(previousDate.mYear))
        daysInMonth[2] = 29;

    if (previousDate.mDay == 0) {
        previousDate.mMonth--;

        if (previousDate.mMonth == 0) {
            previousDate.mMonth = 12;
            previousDate.mYear--;
        }

        previousDate.mDay = daysInMonth[previousDate.mMonth];
    }

    return previousDate;
}

int main() {
    CDate date;

    printf("Yili giriniz: ");
    scanf("%d", &date.mYear);
    printf("Ayi giriniz: ");
    scanf("%d", &date.mMonth);
    printf("Gunu giriniz: ");
    scanf("%d", &date.mDay);

    if (IsValidDate(date.mYear, date.mMonth, date.mDay)) {
        CDate nextDate = ComputeNextDate(date);
        CDate prevDate = ComputePreviousDate(date);

        printf("Girilen Tarih: %d-%02d-%02d\n",  date.mDay, date.mMonth, date.mYear);
        printf("Sonraki Tarih: %d-%02d-%02d\n", nextDate.mDay, nextDate.mMonth, nextDate.mYear );
        printf("Onceki Tarih: %d-%02d-%02d\n", prevDate.mDay, prevDate.mMonth, prevDate.mYear);
    } else {
        printf("Hatali Tarih!\n");
    }

    return 0;
}
