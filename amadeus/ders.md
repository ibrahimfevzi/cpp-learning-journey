//a^16'yı kaç adımda hesaplar?
//a^16 = a^8 _ a^8
//a^8 = a^4 _ a^4
//a^4 = a^2 _ a^2
//a^2 = a _ a
//a^1 = a
//a^0 = 1
//sorunun cevabı: 5 adımda hesaplar

b=27 olursa nasıl yaparız?
b^27 = b^13 _ b^13 _ b
b^13 = b^6 _ b^6 _ b
b^6 = b^3 _ b^3
b^3 = b^1 _ b^1 \* b
b^1 = b
b^0 = 1

b=27 sayısının ikilik düzende yazılışı
27 = 11011
27 = 2^4 + 2^3 + 2^1 + 2^0
27 = 16 + 8 + 2 + 1
27 = 11011

b=27 sayısının ikilik düzende yazılışı dikkate alarak kaç adımda hesaplanır
b^27 = b^16 _ b^8 _ b^2 _ b^1
b^16 = b^8 _ b^8
b^8 = b^4 _ b^4
b^4 = b^2 _ b^2
b^2 = b^1 \* b^1
b^1 = b
b^0 = 1
sorunun cevabı: 7 adımda hesaplanır

A, B, C, D, E isimli şehirlerden verilen iki şehir arasındaki doğrudan ve dolaylı uçuşları bulan programı python ile yaz
PYTHON:

# Komşuluk matrisi

adjacency_matrix = [ # A B C D E
[0, 0, 1, 0, 1], # A
[1, 0, 0, 0, 1], # B
[0, 0, 0, 1, 1], # C
[0, 1, 0, 0, 1], # D
[1, 1, 1, 1, 0] # E
]

# Şehir isimlerini tutan liste

cities = ['A', 'B', 'C', 'D', 'E']

# Doğrudan uçuşları bulan fonksiyon

def find_direct_flights(origin):
index = cities.index(origin)
direct_flights = [cities[i] for i in range(len(cities)) if adjacency_matrix[index][i] == 1]
return direct_flights

# Dolaylı uçuşları bulan yardımcı fonksiyon

def find_indirect_flights_helper(current_city, destination, visited, flight_path, flights):
if current_city == destination:
flights.append(flight_path)
return

    visited.add(current_city)

    for i in range(len(cities)):
        if adjacency_matrix[cities.index(current_city)][i] == 1 and cities[i] not in visited:
            find_indirect_flights_helper(cities[i], destination, visited.copy(), flight_path + [cities[i]], flights)

# Dolaylı uçuşları bulan fonksiyon

def find_indirect_flights(origin, destination):
flights = []
find_indirect_flights_helper(origin, destination, set(), [origin], flights)
return flights

# Kullanıcıdan giriş alıp doğrudan ve dolaylı uçuşları bulan bölüm

def main():
origin = input("Başlangıç şehri girin: ")
destination = input("Varış şehri girin: ")

    # Doğrudan uçuşları bul ve ekrana yazdır
    direct_flights_result = find_direct_flights(origin)
    if direct_flights_result:
        print(f"Doğrudan uçuşlar: {direct_flights_result}")
    else:
        print(f"{origin} şehrinden doğrudan uçuş bulunmamaktadır.")

    # Dolaylı uçuşları bul ve ekrana yazdır
    indirect_flights_result = find_indirect_flights(origin, destination)
    if indirect_flights_result:
        print("Dolaylı uçuşlar:")
        for flight in indirect_flights_result:
            print(" -> ".join(flight))

if **name** == "**main**":
main()

Ülkelerin ithalat ve ihracat verilerini içeren matrisler ile ülkelerin isimlerini içeren bir liste verilmiştir. Bu veriler ile anlamlı nasıl fonksiyonlar yazarak karşılaştırmalar yapılabilir. 10 farklı fonksiyonu anlatınız

Toplam İthalat ve İhracat Hacmi Hesaplama:
Bu fonksiyon, her ülkenin toplam ithalat ve ihracat hacmini hesaplar ve geri döndürür. Matrislerdeki değerler toplam alınarak hesaplama yapılır.

En Büyük İthalat ve İhracat Yapan Ülke Bulma:
Bu fonksiyon, en yüksek ithalat ve ihracat hacmine sahip ülkeleri bulur ve geri döndürür. İlgili satırlar üzerinde maksimum değerleri bulma işlemi yapılır.

En Küçük İthalat ve İhracat Yapan Ülke Bulma:
Bu fonksiyon, en düşük ithalat ve ihracat hacmine sahip ülkeleri bulur ve geri döndürür. İlgili satırlar üzerinde minimum değerleri bulma işlemi yapılır.

En Dengeli Ticaret Yapan Ülke Bulma:
Bu fonksiyon, ithalat ve ihracat arasındaki farkı en düşük olan ülkeyi bulur ve geri döndürür.

Belirli Bir Ülkenin İthalat ve İhracat Hacmi Hesaplama:
Kullanıcıdan alınan ülke adına göre, o ülkenin ithalat ve ihracat hacmini hesaplar ve ekrana yazdırır.

İthalat ve İhracat Hacimlerini Karşılaştırma:
Bu fonksiyon, her iki matrisi karşılaştırarak, hangi ülkelerin ithalat veya ihracat hacminin daha yüksek olduğunu belirler.

Ticaret Dengesizliği Hesaplama:
Bu fonksiyon, her ülkenin ithalat ve ihracat dengesizliğini (ticaret fazlası veya açığı) hesaplar ve geri döndürür.

Ortalama İthalat ve İhracat Hacmi Hesaplama:
Bu fonksiyon, her ülkenin ortalama ithalat ve ihracat hacmini hesaplar ve geri döndürür.

İthalat ve İhracat Verilerini Sıralama:
Bu fonksiyon, her ülkenin ithalat ve ihracat verilerini sıralar ve geri döndürür.

İki Ülkenin İthalat ve İhracat Verilerini Karşılaştırma:
Kullanıcıdan alınan iki ülke adına göre, bu iki ülkenin ithalat ve ihracat verilerini karşılaştırır ve hangi ülkenin daha yüksek veya daha düşük olduğunu belirler.
