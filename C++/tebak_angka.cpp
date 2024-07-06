#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    system("clear");
    
    srand(time(0));
    int random_numbers;
    random_numbers = rand() % 100 + 1; // range 1 to 100
    
    while (true) {
        cout << "--------------------------------------------------" << endl << endl;
        cout << "              PERMAINAN TEBAK ANGKA               " << endl << endl;
        cout << "--------------------------------------------------" << endl << endl;
        string guess;
        cout << "Silahkan tebak angka antara 1-100 : ";
        cin >> guess;
        
        bool isNumber = true;
        for (int i = 0; i < guess.length(); i++) {
            if (!isdigit(guess[i])) {
                isNumber = false;
            }
        }
        
        if (isNumber == true) {
            int number = atoi(guess.c_str()); // convert string to integer
            int difference = abs(random_numbers - number);
            
            if (number > random_numbers) {
                if (difference > 10) {
                    cout << endl << "       \033[1;31m# Angka yang ditebak terlalu tinggi #\033[0m      " << endl;
                    cout << "       \033[1;31m-------------------------------------\033[0m      " << endl;
                } else if (difference <= 10) {
                    cout << endl << "       \033[1;33m# Angka yang ditebak terlalu tinggi #\033[0m      " << endl;
                    cout << "       \033[1;33m-------------------------------------\033[0m      " << endl;
                }
            } else if (number < random_numbers) {
                if (difference > 10) {
                    cout << endl << "       \033[1;31m# Angka yang ditebak terlalu rendah #\033[0m      " << endl;
                    cout << "       \033[1;31m-------------------------------------\033[0m      " << endl;
                } else if (difference <= 10) {
                    cout << endl << "       \033[1;33m# Angka yang ditebak terlalu rendah #\033[0m      " << endl;
                    cout << "       \033[1;33m-------------------------------------\033[0m      " << endl;
                }
            } else {
                cout << endl << "       \033[1;32m# Selamat anda berhasil menebaknya #\033[0m       " << endl;
                cout << "       \033[1;32m------------------------------------\033[0m       " << endl;
                random_numbers = rand() % 100 + 1;
            }
        } else {
            cout << endl << "Invalid Input!" << endl << endl;
            break;
        }
        
        char repeat;
        cout << endl << "Ingin bermain lagi? (y/n) : ";
        cin >> repeat;
        
        if (repeat == 'y') {
            system("clear");
        } else if (repeat == 'n') {
            cout << endl;
            break;
        } else {
            cout << endl << "Invalid Input!" << endl << endl;
            break;
        }
    }
    
    return 0;
}