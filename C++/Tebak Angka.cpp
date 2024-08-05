#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    system("clear");
    
    srand(time(0));
    int randomNumbers = rand() % 100 + 1;
    
    while (true) {
        cout << "--------------------------------------------------" << endl << endl;
        cout << "             \033[1;36m# PERMAINAN TEBAK ANGKA #\033[0m            " << endl << endl;
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
            int number = stoi(guess);
            int difference = abs(randomNumbers - number);
            
            if (number > randomNumbers) {
                if (difference > 10) {
                    cout << endl << "       \033[1;31m# Angka yang ditebak terlalu tinggi #\033[0m      " << endl;
                    cout << "       \033[1;31m-------------------------------------\033[0m      " << endl;
                } else if (difference <= 10) {
                    cout << endl << "       \033[1;33m# Angka yang ditebak terlalu tinggi #\033[0m      " << endl;
                    cout << "       \033[1;33m-------------------------------------\033[0m      " << endl;
                }
            } else if (number < randomNumbers) {
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
                randomNumbers = rand() % 100 + 1;
            }
        } else {
            cout << endl << "\033[1;31mInvalid Number!\033[0m" << endl << endl;
            break;
        }
        
        char repeat;
        cout << endl << "Ingin bermain lagi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
        cin >> repeat;
        
        if (repeat == 'y') {
            system("clear");
        } else if (repeat == 'n') {
            cout << endl;
            break;
        } else {
            cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
            break;
        }
    }
    
    return 0;
}