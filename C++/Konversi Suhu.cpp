#include <iostream>
#include <cstdlib>
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
    system("clear");
    
    int screenWidth = getTerminalWidth();
    
    while (true) {
        cout << string(screenWidth, '-') << endl << endl;
        cout << string((screenWidth - 17) / 2, ' ') << "\033[1;36m# KONVERSI SUHU #\033[0m" << endl << endl;
        cout << string((screenWidth - 31) / 2, ' ') << "-------------------------------" << endl << endl;
        cout << string((screenWidth - 31) / 2, ' ') << "\033[1;32m(1)\033[0m. Celcius    \033[1;32m(2)\033[0m. Fahrenheit" << endl << endl;
        cout << string((screenWidth - 31) / 2, ' ') << "\033[1;32m(3)\033[0m. Réamur     \033[1;32m(4)\033[0m. Kelvin" << endl << endl;
        cout << string((screenWidth - 11) / 2, ' ') << "\033[1;31m(5)\033[0m. Keluar" << endl << endl;
        cout << string(screenWidth, '-') << endl << endl;
        
        int initialTemperatureType, finalTemperatureType;
        double formula;
        string temperatureValue;
        
        cout << "Silahkan pilih jenis suhu awal (1, 2, 3, 4) : ";
        cin >> initialTemperatureType;
        
        if (initialTemperatureType == 1) {
            cout << endl << "Silahkan masukkan jumlah suhu : ";
            cin >> temperatureValue;
            
            bool isNumber = true;
            for (int i = 0; i < temperatureValue.length(); i++) {
                if (!isdigit(temperatureValue[i])) {
                    isNumber = false;
                }
            }
            
            if (isNumber == true) {
                cout << endl << "Silahkan pilih jenis suhu akhir (1, 2, 3, 4) : ";
                cin >> finalTemperatureType;
                
                if (finalTemperatureType == 1) {
                    cout << endl << "\033[1;33mJenis suhu tidak boleh sama!\033[0m" << endl;
                } else if (finalTemperatureType == 2) {
                    int integerTemperatureValue = stoi(temperatureValue);
                    formula = (integerTemperatureValue * 9 / 5 + 32);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "°C" << " = " << formula << "°F" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 3) {
                    int integerTemperatureValue = stoi(temperatureValue);
                    formula = (integerTemperatureValue * 4 / 5);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "°C" << " = " << formula << "°Ré" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 4) {
                    int integerTemperatureValue = stoi(temperatureValue);
                    formula = (integerTemperatureValue + 273.15);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "°C" << " = " << formula << "K" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 5) {
                    cout << endl;
                    break;
                } else {
                    cout << endl << "\033[1;31mInvalid Type!\033[0m" << endl << endl;
                    break;
                }
            } else {
                cout << endl << "\033[1;31mInvalid Value!\033[0m" << endl << endl;
                break;
            }
        } else if (initialTemperatureType == 2) {
            cout << endl << "Silahkan masukkan jumlah suhu : ";
            cin >> temperatureValue;
            
            bool isNumber = true;
            for (int i = 0; i < temperatureValue.length(); i++) {
                if (!isdigit(temperatureValue[i])) {
                    isNumber = false;
                }
            }
            
            if (isNumber == true) {
                cout << endl << "Silahkan pilih jenis suhu akhir (1, 2, 3, 4) : ";
                cin >> finalTemperatureType;
                
                if (finalTemperatureType == 1) {
                    int integerTemperatureValue = stoi(temperatureValue);
                    formula = ((integerTemperatureValue - 32) * 5 / 9);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "°F" << " = " << formula << "°C" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 2) {
                    cout << endl << "\033[1;33mJenis suhu tidak boleh sama!\033[0m" << endl;
                } else if (finalTemperatureType == 3) {
                    int integerTemperatureValue = stoi(temperatureValue);
                    formula = ((integerTemperatureValue - 32) * 4 / 9);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "°F" << " = " << formula << "°Ré" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 4) {
                    int integerTemperatureValue = stoi(temperatureValue);
                    formula = ((integerTemperatureValue + 459.67) * 5 / 9);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "°F" << " = " << formula << "K" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 5) {
                    cout << endl;
                    break;
                } else {
                    cout << endl << "\033[1;31mInvalid Type!\033[0m" << endl << endl;
                    break;
                }
            } else {
                cout << endl << "\033[1;31mInvalid Value!\033[0m" << endl << endl;
                break;
            }
        } else if (initialTemperatureType == 3) {
            cout << endl << "Silahkan masukkan jumlah suhu : ";
            cin >> temperatureValue;
            
            bool isNumber = true;
            for (int i = 0; i < temperatureValue.length(); i++) {
                if (!isdigit(temperatureValue[i])) {
                    isNumber = false;
                }
            }
            
            if (isNumber == true) {
                cout << endl << "Silahkan pilih jenis suhu akhir (1, 2, 3, 4) : ";
                cin >> finalTemperatureType;
                
                if (finalTemperatureType == 1) {
                    int integerTemperatureValue = stoi(temperatureValue);
                    formula = (integerTemperatureValue * 5 / 4);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "°Ré" << " = " << formula << "°C" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 2) {
                    int integerTemperatureValue = stoi(temperatureValue);
                    formula = (integerTemperatureValue * 9 / 4 + 32);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "°Ré" << " = " << formula << "°F" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 3) {
                    cout << endl << "\033[1;33mJenis suhu tidak boleh sama!\033[0m" << endl;
                } else if (finalTemperatureType == 4) {
                    int integerTemperatureValue = stoi(temperatureValue);
                    formula = (integerTemperatureValue * 5 / 4 + 273.15);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "°Ré" << " = " << formula << "K" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 5) {
                    cout << endl;
                    break;
                } else {
                    cout << endl << "\033[1;31mInvalid Type!\033[0m" << endl << endl;
                    break;
                }
            } else {
                cout << endl << "\033[1;31mInvalid Value!\033[0m" << endl << endl;
                break;
            }
        } else if (initialTemperatureType == 4) {
            cout << endl << "Silahkan masukkan jumlah suhu : ";
            cin >> temperatureValue;
            
            if (isdigit(temperatureValue[0])) {
                cout << endl << "Silahkan pilih jenis suhu akhir (1, 2, 3, 4) : ";
                cin >> finalTemperatureType;
                
                if (finalTemperatureType == 1) {
                    double doubleTemperatureValue = stod(temperatureValue);
                    formula = (doubleTemperatureValue - 273.15);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "K" << " = " << formula << "°C" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 2) {
                    double doubleTemperatureValue = stod(temperatureValue);
                    formula = (doubleTemperatureValue * 9 / 5 - 459.67);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "K" << " = " << formula << "°F" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 3) {
                    double doubleTemperatureValue = stod(temperatureValue);
                    formula = ((doubleTemperatureValue - 273.15) * 4 / 5);
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;32m" << temperatureValue << "K" << " = " << formula << "°Ré" << "\033[0m" << endl << endl;
                    cout << string(screenWidth, '-') << endl;
                } else if (finalTemperatureType == 4) {
                    cout << endl << "\033[1;33mJenis suhu tidak boleh sama!\033[0m" << endl;
                } else if (finalTemperatureType == 5) {
                    cout << endl;
                    break;
                } else {
                    cout << endl << "\033[1;31mInvalid Type!\033[0m" << endl << endl;
                    break;
                }
            } else {
                cout << endl << "\033[1;31mInvalid Value!\033[0m" << endl << endl;
                break;
            }
        } else {
            cout << endl << "\033[1;31mInvalid Type!\033[0m" << endl << endl;
            break;
        }
        
        char repeat;
        cout << endl << "Ingin melakukan konversi lagi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
        cin >> repeat;
        
        if (tolower(repeat) == 'y') {
            system("clear");
        } else if (tolower(repeat) == 'n') {
            cout << endl;
            break;
        } else {
            cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
            break;
        }
    }
    return 0;
}