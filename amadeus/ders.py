# Komşuluk matrisi
adjacency_matrix = [
    # A  B  C  D  E
    [0, 0, 1, 0, 1],  # A
    [1, 0, 0, 0, 1],  # B
    [0, 0, 0, 1, 1],  # C
    [0, 1, 0, 0, 1],  # D
    [1, 1, 1, 1, 0]   # E
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

if __name__ == "__main__":
    main()
  