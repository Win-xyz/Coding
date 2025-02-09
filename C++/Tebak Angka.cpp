#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

int getTerminalWidth() {
    int width = 50;
    
    #ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    #else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width = w.ws_col;
    #endif
    
    return width;
}

using namespace std;

int main() {
    int screenWidth = getTerminalWidth();
    
    system("clear");
    
    srand(time(0));
    int randomNumbers = rand() % 100 + 1;
    
    while (true) {
        cout << string(screenWidth, '-') << endl << endl;
        cout << string((screenWidth - 25) / 2, ' ') << "\033[1;36m# PERMAINAN TEBAK ANGKA #\033[0m" << endl << endl;
        cout << string((screenWidth - 26) / 2, ' ') << "-------------------------" << endl << endl << endl;
        cout << string((screenWidth - 8) / 2, ' ') << "\033[1;34mPetunjuk\033[0m" << endl;
        cout << string((screenWidth - 22) / 2, ' ') << "\033[1;34m+--------------------+\033[0m" << endl;
        cout << string((screenWidth - 22) / 2, ' ') << "\033[1;34m|\033[0m \033[1;31mMerah\033[0m  : Jauh      \033[1;34m|\033[0m" << endl;
        cout << string((screenWidth - 22) / 2, ' ') << "\033[1;34m|\033[0m \033[1;33mKuning\033[0m : Mendekati \033[1;34m|\033[0m" << endl;
        cout << string((screenWidth - 22) / 2, ' ') << "\033[1;34m|\033[0m \033[1;32mHijau\033[0m  : Tepat     \033[1;34m|\033[0m" << endl;
        cout << string((screenWidth - 22) / 2, ' ') << "\033[1;34m+--------------------+\033[0m" << endl << endl << endl;
        cout << string(screenWidth, '-') << endl << endl;
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
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31m# Angka yang ditebak terlalu tinggi #\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (difference <= 10) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 37) / 2, ' ') << "\033[1;33m# Angka yang ditebak terlalu tinggi #\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                }
            } else if (number < randomNumbers) {
                if (difference > 10) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31m# Angka yang ditebak terlalu rendah #\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (difference <= 10) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 37) / 2, ' ') << "\033[1;33m# Angka yang ditebak terlalu rendah #\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                }
            } else {
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 36) / 2, ' ') << "\033[1;32m# Selamat anda berhasil menebaknya #\033[0m" << endl << endl;
                cout << string(screenWidth, '-') << endl;
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