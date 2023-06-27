#include <iostream> 
using namespace std; 
 
int main() 
{ 
    int arr[5] = {10, 20, 30, 40, 50}; 
    int* ptr1 = arr; 
    int* ptr2 = arr + 3; 
 
    cout << "ptr2'nin tuttuğu değer: " << *ptr2 << endl; 
 
    ptr1++;
    ptr2--; 
 
    cout << "ptr1'in tuttuğu değer: " << *ptr1 << endl; 
    cout << "ptr2'nin tuttuğu değer: " << *ptr2 << endl; 
    return 0; 
} 


/*Sonuç:
ptr2'nin tuttuğu değer: 40
ptr1'in tuttuğu değer: 20
ptr2'nin tuttuğu değer: 30
*/

// ptr1 ve ptr2 isimli iki adet pointer tanımladık. ptr1 dizinin ilk elemanını, ptr2 dizinin 3. elemanını gösteriyor. ptr1'in tuttuğu değer: 10, ptr2'nin tuttuğu değer: 40
// ptr1'i bir arttırdık, ptr2'yi bir azalttık. ptr1 dizinin 2. elemanını, ptr2 dizinin 2. elemanını gösteriyor.
// ptr1'in tuttuğu değer: 20
// ptr2'nin tuttuğu değer: 30
