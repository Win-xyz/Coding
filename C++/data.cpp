#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    system("clear");
    
    int data_count;
    cout << "Masukkan jumlah data array : ";
    cin >> data_count;
    
    cout << endl;
    
    int numbers[data_count];
    for (int i = 1; i <= data_count; i ++) {
        cout << "Masukkan data ke-" << i << " : ";
        cin >> numbers[i];
    }
    
    int length = sizeof(numbers) / sizeof(int);
    int count = 0, average = 0, min = 2147483647, max = 0;
    
    cout << endl;
    
    for (int i = 1; i <= length; i++) {
        cout << "Data ke-" << i << " = " << numbers[i] << endl;
        
        // ----- COUNT ----- //
        count = count + numbers[i];
        
        // ----- AVERAGE ----- //
        average = average + numbers[i];
        
        // ----- MIN ----- //
        if (numbers[i] < min) {
            min = numbers[i];
        }
        
        // ----- MAX ----- //
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    cout << endl;
    
    // ----- SORTING ----- //
    int temp;
    
    for (int i = 1; i <= length; i++) {
        for (int j = 1; j <= length - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    
    for (int i = 1; i <= length; i++) {
        cout << "Sorting data ke-" << i << " = " << numbers[i] << endl;
    }
    
    cout << endl;
    cout << "Count = " << count << endl;
    cout << "Average = " << average / length << endl;
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
    cout << endl;
    
    // ----- SEARCH ----- //
    int search, index = 0;
    
    cout << "Search data : ";
    cin >> search;
    
    for (int i = 1; i <= length; i++) {
        if (search == numbers[i]) {
            index++;
        }
    }
    
    if (index != 0) {
        for (int i = 1; i <= length; i++) {
            if (search == numbers[i]) {
                cout << "Data " << search << " ditemukan di urutan ke-" << i << endl;
            }
        }
    } else {
        cout << "Data " << search << " tidak ditemukan" << endl;
    }
    
    return 0;
}