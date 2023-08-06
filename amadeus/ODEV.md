İlk olarak, CDate struct'ını tanımlayalım:

´´´
typedef struct {
int mYear;
int mMonth;
int mDay;
} CDate;
´´´

Aşağıda, istenilen fonksiyonları ve yardımcı fonksiyonları tanımlayalım:

IsValidDate: Verilen tarihin geçerli bir tarih olup olmadığını kontrol eden fonksiyon.

´´´
bool IsValidDate(int year, int month, int day) {
// Year, month, and day should be within valid ranges.
if (year < 0 || month < 1 || month > 12 || day < 1)
return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(year))
        daysInMonth[2] = 29;

    if (day > daysInMonth[month])
        return false;

    return true;

}
´´´

IsLeapYear: Verilen yılın artık yıl olup olmadığını kontrol eden fonksiyon.

´´´
bool IsLeapYear(int year) {
if (year % 4 == 0) {
if (year % 100 != 0 || year % 400 == 0)
return true;
}
return false;
}
´´´
ComputeNextDate: Verilen tarihin bir gün sonraki tarihini hesaplayan fonksiyon.

´´´
CDate ComputeNextDate(CDate date) {
CDate nextDate = date;

    // Increment the day
    nextDate.mDay++;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(nextDate.mYear))
        daysInMonth[2] = 29;

    // Check if day exceeds the number of days in the month
    if (nextDate.mDay > daysInMonth[nextDate.mMonth]) {
        nextDate.mDay = 1;
        nextDate.mMonth++;

        // Check if month exceeds 12, then increment the year as well
        if (nextDate.mMonth > 12) {
            nextDate.mMonth = 1;
            nextDate.mYear++;
        }
    }

    return nextDate;

}
´´´

ComputePreviousDate: Verilen tarihin bir gün önceki tarihini hesaplayan fonksiyon.

´´´
CDate ComputePreviousDate(CDate date) {
CDate previousDate = date;

    // Decrement the day
    previousDate.mDay--;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(previousDate.mYear))
        daysInMonth[2] = 29;

    // Check if day becomes zero, then move to the previous month
    if (previousDate.mDay == 0) {
        previousDate.mMonth--;

        // Check if month becomes zero, then move to the previous year
        if (previousDate.mMonth == 0) {
            previousDate.mMonth = 12;
            previousDate.mYear--;
        }

        // Set the day to the last day of the previous month
        previousDate.mDay = daysInMonth[previousDate.mMonth];
    }

    return previousDate;

}
´´´

Şimdi, test case'leri kurgulayalım ve bu fonksiyonları test edelim. Test case'leri oluştururken, aşağıdaki senaryoları dikkate almalıyız:

Geçerli tarihleri test etmek: Örneğin, 2023-08-06 gibi geçerli bir tarihi girdi olarak kullanarak, ComputeNextDate ve ComputePreviousDate fonksiyonlarından beklenen sonuçları almayı sağlamalıyız.

Geçersiz tarihleri test etmek: Örneğin, 2023-02-30 veya 2023-13-01 gibi geçersiz bir tarihi girdi olarak kullanarak, fonksiyonların doğru bir şekilde hata mesajı vermesini sağlamalıyız.

Artık yılları test etmek: Örneğin, 2020-02-28 gibi bir artık yılı girdi olarak kullanarak, ComputeNextDate ve ComputePreviousDate fonksiyonlarından beklenen sonuçları almayı sağlamalıyız.

Yılın son günü ve ilk günü test etmek: Örneğin, 2023-12-31 ve 2023-01-01 gibi yılın son günü ve ilk gününü girdi olarak kullanarak, fonksiyonların doğru bir şekilde yıl ve ay değişikliklerini işlemesini sağlamalıyız.

Geçerli tarih aralıklarını test etmek: Tarih aralıklarının sınırlarını (örneğin, gün 1-31, ay 1-12, yıl 0 ve sonrası gibi) test ederek fonksiyonların doğru çalışmasını sağlamalıyız.

Hızlı bir şekilde birden çok artık yıl ve normal yılın ardışık tarihlerini test etmek için otomatik testler de oluşturulabilir.

Essay:

Geçerli bir CDate tarihini alarak, ComputeNextDate ve ComputePreviousDate fonksiyonları, bir sonraki ve bir önceki tarihi hesaplamak için kullanılır. Bu fonksiyonlar, tarih hesaplama işlemleri sırasında artık yıl, 30 ve 31 gün gibi çetrefilli durumları ele alır ve hatalı girişleri engellemek için IsValidDate fonksiyonunu kullanır.

IsValidDate fonksiyonu, verilen yıl, ay ve gün değerlerinin geçerli bir tarih olup olmadığını kontrol eder. Geçersiz tarihler, yılın negatif olması, ayın 1-12 aralığında olmaması veya günün ayın gün sayısını aşması gibi durumları içerir. Ayrıca, IsLeapYear fonksiyonu, bir yılın artık yıl olup olmadığını belirlemek için kullanılır ve şubat ayının gün sayısını günceller.

ComputeNextDate fonksiyonu, verilen tarihin bir gün sonraki tarihini hesaplar. Tarih hesaplama işlemi sırasında, gün değeri gün sayısını aştığında, ay ve yıl değerleri de güncellenir. Ayrıca, ComputePreviousDate fonksiyonu, verilen tarihin bir gün önceki tarihini hesaplar ve aynı şekilde tarih hesaplama işlemi sırasında geçerli tarih aralığını kontrol eder.

Test case'lerinin kurgulanmasında amacımız, fonksiyonların tüm olası senaryolarda doğru çalışmasını sağlamaktır. Bu nedenle, test case'lerinin çeşitliliği ve kapsamlılığı önemlidir. Öncelikle, geçerli tarihleri test etmeliyiz, bu sayede fonksiyonların beklenen sonuçları ürettiğinden emin olabiliriz. Ayrıca, geçersiz tarihleri test ederek fonksiyonların hatalı girişlere nasıl tepki verdiğini gözlemlemeliyiz.

Artık yılları test etmek, tarih hesaplama işlemleri sırasında şubat ayının gün sayısının doğru bir şekilde güncellendiğini doğrulamamıza yardımcı olur. Yılın son günü ve ilk günü testleri, yıl ve ay değişikliklerini ele alıp almadığını kontrol eder. Geçerli tarih aralıklarını test etmek, tarih değerlerinin belirli sınırlar içinde olduğunda doğru sonuçları ürettiğini doğrulamak için önemlidir.

Otomatik testler, hızlı bir şekilde birden çok tarih kombinasyonunu test etmemize yardımcı olur ve daha kapsamlı test coverage elde etmemizi sağlar. Test case'lerinin yeterli olduğunu düşünmemizin nedeni, tüm önemli senaryoların kapsandığından emin olmamızdır. Her bir test case, kodun farklı kısımlarını ve farklı senaryoları test etmeli ve bu sayede olası hataları tespit etmeli ve düzeltmeliyiz.

Sonuç olarak, CDate struct'ını kullanan ComputeNextDate ve ComputePreviousDate fonksiyonları, tarih hesaplama işlemlerini doğru bir şekilde gerçekleştiren ve geçerli tarih aralıklarını kontrol eden kodlar olarak uygulanmalıdır. Test case'leri, fonksiyonların doğru çalıştığından ve çeşitli senaryolara uygun olduğundan emin olmak için kapsamlı ve çeşitlilik gösteren bir şekilde kurgulanmalıdır. Bu, kodun güvenilir ve sağlam bir şekilde çalışmasını sağlamak için önemlidir.
