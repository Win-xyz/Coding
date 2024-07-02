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
    for (int i = 0; i < data_count; i ++) {
        cout << "Masukkan data index ke " << i << " : ";
        cin >> numbers[i];
    }
    
    int length = sizeof(numbers) / sizeof(int);
    int count = 0, min = 2147483647, max = 0;
    float average;
    
    cout << endl;
    
    for (int i = 0; i < length; i++) {
        cout << "Data index ke " << i << " = " << numbers[i] << endl;
        
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
    
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < length; i++) {
        cout << "Sorting data index ke " << i << " = " << numbers[i] << endl;
    }
    
    cout << endl;
    cout << "Count = " << count << endl;
    cout << "Average = " << average / length << endl;
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
    cout << endl;
    
    // ----- SEARCH ----- //
    int search;
    bool valid = false;
    
    cout << "Search data : ";
    cin >> search;
    
    for (int i = 0; i < length; i++) {
        if (search == numbers[i]) {
            valid = true;
        }
    }
    
    if (valid == true) {
        for (int i = 0; i < length; i++) {
            if (search == numbers[i]) {
                cout << "Data " << search << " ditemukan di index ke " << i << endl;
            }
        }
    } else {
        cout << "Data " << search << " tidak ditemukan" << endl;
    }
    
    return 0;
}