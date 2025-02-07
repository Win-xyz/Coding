#include <iostream>
#include <cstdlib>
#include <ctime>
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
    system("clear");
    
    int screenWidth = getTerminalWidth();
    
    srand(time(0));
    int saldo = rand() % 50000000 + 50000000;
    int randomPin = rand() % 899999 + 100000;
    
    while (true) {
        
        cout << string(screenWidth, '-') << endl << endl << endl;
        cout << string((screenWidth - 12) / 2, ' ') << "\033[1;36mPIN = " << randomPin << "\033[0m" << endl << endl << endl;
        cout << string(screenWidth, '-') << endl << endl;
        
        string pin;
        cout << "Silahkan masukkan PIN : ";
        cin >> pin;
        
        int pinInteger = atoi(pin.c_str());
        
        bool isNumber = true;
        for (int i = 0; i < pin.length(); i++) {
            if (!isdigit(pin[i])) {
                isNumber = false;
            }
        }
        
        int pinLength = pin.length();
        
        if (isNumber == true && pinInteger == randomPin && pinLength == 6) {
            system("clear");
            
            cout << string(screenWidth, '-') << endl << endl << endl;
            cout << string((screenWidth - 35) / 2, ' ') << "\033[1;36mPilih bahasa\033[0m | \033[1;36mLanguange Preference\033[0m" << endl << endl << endl;
            cout << string((screenWidth - 35) / 2, ' ') << "-----------------------------------" << endl << endl << endl;
            cout << string((screenWidth - 35) / 2, ' ') << "\033[1;36m(1)\033[0m. Indonesia         \033[1;36m(2)\033[0m. English" << endl << endl << endl;
            cout << string(screenWidth, '-') << endl << endl;
            
            int languange;
            cout << "Silahkan pilih bahasa (1/2) : ";
            cin >> languange;
            
            if (languange == 1) {
                system("clear");
                cout << string(screenWidth, '-') << endl << endl << endl;
                cout << string((screenWidth - 14) / 2, ' ') << "\033[1;36mMenu Transaksi\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 39) / 2, ' ') << "---------------------------------------" << endl << endl << endl;
                cout << string((screenWidth - 39) / 2, ' ') << "\033[1;32m(1)\033[0m. Transfer      \033[1;32m(4)\033[0m. Penarikan Tunai" << endl << endl << endl;
                cout << string((screenWidth - 39) / 2, ' ') << "\033[1;32m(2)\033[0m. Pembayaran    \033[1;32m(5)\033[0m. Informasi Saldo" << endl << endl << endl;
                cout << string((screenWidth - 39) / 2, ' ') << "\033[1;32m(3)\033[0m. Setor Tunai   \033[1;31m(6)\033[0m. Batal Transaksi" << endl << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
                
                int transaction;
                cout << "Silahkan pilih transaksi (1, 2, 3, 4, 5, 6) : ";
                cin >> transaction;
                
                if (transaction == 1) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 8) / 2, ' ') << "\033[1;36mTransfer\033[0m" << endl << endl << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "-----------------------" << endl << endl << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BRI        =        002" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BNI        =        009" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BCA        =        009" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BSI        =        014" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BNI        =        451" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BTN        =        200" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "MANDIRI    =        008" << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    string bank[6] = {"BRI", "BNI", "BCA", "BSI", "BTN", "MANDIRI"};
                    string bankCode[6] = {"002", "009", "014", "451", "200", "008"};
                    
                    string code;
                    cout << "Silahkan masukkan kode bank tujuan : ";
                    cin >> code;
                    
                    bool isNumber = true;
                    for (int i = 0; i < code.length(); i++) {
                        if (!isdigit(code[i])) {
                            isNumber = false;
                        }
                    }
                    
                    bool valid = false;
                    int index;
                    for (int i = 0; i < (sizeof(bankCode) / sizeof(string)); i++) {
                        if (code == bankCode[i]) {
                            valid = true;
                            index = i;
                        }
                    }
                    
                    int codeLength = code.length();
                    
                    if (isNumber == true && valid == true && codeLength == 3) {
                        string accountNumber;
                        cout << endl << "Silahkan masukkan rekening tujuan : ";
                        cin >> accountNumber;
                        
                        bool isNumber = true;
                        for (int i = 0; i < accountNumber.length(); i++) {
                            if (!isdigit(accountNumber[i])) {
                                isNumber = false;
                            }
                        }
                        
                        if (isNumber == true && codeLength < 17) {
                            string nominal;
                            cout << endl << "Silahkan masukkan jumlah nominal : ";
                            cin >> nominal;
                            
                            bool isNumber = true;
                            for (int i = 0; i < nominal.length(); i++) {
                                if (!isdigit(nominal[i])) {
                                    isNumber = false;
                                }
                            }
                            
                            if (isNumber == true) {
                                time_t now = time(0);
                                char* dateTime = ctime(&now);
                                
                                string adminBank[4] = {"0", "2500", "5000", "6500"};
                                srand(time(0));
                                int random_index = rand() % 3;
                                int amount = atoi(nominal.c_str());
                                string adminString = adminBank[random_index];
                                int admin = atoi(adminString.c_str());
                                int total = amount + admin;
                                int referenceNumber = rand() % 1147483647 + 1000000000;
                                
                                string totalString = to_string(total);
                                
                                for (int i = adminString.length() - 3; i > 0; i -= 3) {
                                    adminString.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = totalString.length() - 3; i > 0; i -= 3) {
                                    totalString.insert(i, ".");
                                }
                                
                                if (saldo >= total) {
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 18) / 2, ' ') << "\033[1;36mTransaksi Berhasil\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Tanggal    :    " << dateTime;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Bank       :    " << bank[index] << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Rekening   :    " << accountNumber << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "No. Ref    :    " << abs(referenceNumber) << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Nominal    :    Rp" << nominal << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Admin      :    Rp" << adminString << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Total      :    Rp" << totalString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    saldo -= total;
                                } else {
                                    cout << endl << "\033[1;33mSaldo anda tidak cukup!\033[0m" << endl << endl;
                                    break;
                                }
                                
                                char repeat;
                                cout << "Ingin melanjutkan transaksi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
                            break;
                        }
                    } else {
                        cout << endl << "\033[1;31mInvalid Code!\033[0m" << endl << endl;
                        break;
                    }
                } else if (transaction == 2) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 10) / 2, ' ') << "\033[1;36mPembayaran\033[0m" << endl << endl << endl;
                    cout << string((screenWidth - 31) / 2, ' ') << "-------------------------------" << endl << endl << endl;
                    cout << string((screenWidth - 31) / 2, ' ') << "\033[1;32m(1)\033[0m. Air PDAM     \033[1;32m(2)\033[0m. Internet" << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    int payment;
                    cout << "Silahkan pilih pembayaran (1/2) : ";
                    cin >> payment;
                    
                    if (payment == 1) {
                        system("clear");
                        cout << string(screenWidth, '-') << endl << endl << endl;
                        cout << string((screenWidth - 27) / 2, ' ') << "\033[1;36mPembayaran Tagihan Air PDAM\033[0m" << endl << endl << endl;
                        cout << string(screenWidth, '-') << endl << endl;
                        
                        string customerNumber;
                        cout << "Silahkan masukkan nomor pelanggan : ";
                        cin >> customerNumber;
                        
                        bool isNumber = true;
                        for (int i = 0; i < customerNumber.length(); i++) {
                            if (!isdigit(customerNumber[i])) {
                                isNumber = false;
                            }
                        }
                        
                        int maxLength = customerNumber.length();
                        
                        if (isNumber == true && maxLength < 14) {
                            string nominal;
                            cout << endl << "Silahkan masukkan jumlah tagihan : ";
                            cin >> nominal;
                            
                            bool isNumber = true;
                            for (int i = 0; i < nominal.length(); i++) {
                                if (!isdigit(nominal[i])) {
                                    isNumber = false;
                                }
                            }
                                
                            if (isNumber == true) {
                                time_t now = time(0);
                                char* dateTime = ctime(&now);
                                
                                srand(time(0));
                                int referenceNumber = rand() % 1147483647 + 1000000000;
                                int amount = atoi(nominal.c_str());
                                int admin = 2500;
                                int total = amount + admin;
                                
                                string adminString = to_string(admin);
                                string totalString = to_string(total);
                                
                                for (int i = adminString.length() - 3; i > 0; i -= 3) {
                                    adminString.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = totalString.length() - 3; i > 0; i -= 3) {
                                    totalString.insert(i, ".");
                                }
                                
                                if (saldo >= amount && amount != 0)  {
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 18) / 2, ' ') << "\033[1;36mTransaksi Berhasil\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Tanggal          :    " << dateTime;
                                    cout << string((screenWidth - 40) / 2, ' ') << "No. Ref          :    " << abs(referenceNumber) << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "No. Pelanggan    :    " << customerNumber << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Tagihan          :    Rp" << nominal << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Admin            :    Rp" << adminString << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Total            :    Rp" << totalString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    saldo -= total;
                                    
                                    char repeat;
                                    cout << "Ingin melanjutkan transaksi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                                } else {
                                    cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                    break;
                                }
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Customer Number!\033[0m" << endl << endl;
                            break;
                        }
                    } else if (payment == 2) {
                        system("clear");
                        cout << string(screenWidth, '-') << endl << endl << endl;
                        cout << string((screenWidth - 27) / 2, ' ') << "\033[1;36mPembayaran Tagihan Internet\033[0m" << endl << endl << endl;
                        cout << string(screenWidth, '-') << endl << endl;
                        
                        string customerNumber;
                        cout << "Silahkan masukkan nomor pelanggan : ";
                        cin >> customerNumber;
                        
                        bool isNumber = true;
                        for (int i = 0; i < customerNumber.length(); i++) {
                            if (!isdigit(customerNumber[i])) {
                                isNumber = false;
                            }
                        }
                        
                        int maxLength = customerNumber.length();
                        
                        if (isNumber == true && maxLength < 14) {
                            string nominal;
                            cout << endl << "Silahkan masukkan jumlah tagihan : ";
                            cin >> nominal;
                            
                            bool isNumber = true;
                            for (int i = 0; i < nominal.length(); i++) {
                                if (!isdigit(nominal[i])) {
                                    isNumber = false;
                                }
                            }
                                
                            if (isNumber == true) {
                                time_t now = time(0);
                                char* dateTime = ctime(&now);
                                
                                srand(time(0));
                                int referenceNumber = rand() % 1147483647 + 1000000000;
                                int amount = atoi(nominal.c_str());
                                int admin = 2500;
                                int total = amount + admin;
                                
                                string adminString = to_string(admin);
                                string totalString = to_string(total);
                                
                                for (int i = adminString.length() - 3; i > 0; i -= 3) {
                                    adminString.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = totalString.length() - 3; i > 0; i -= 3) {
                                    totalString.insert(i, ".");
                                }
                                
                                if (saldo >= amount && amount != 0)  {
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 18) / 2, ' ') << "\033[1;36mTransaksi Berhasil\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Tanggal          :    " << dateTime;
                                    cout << string((screenWidth - 40) / 2, ' ') << "No. Ref          :    " << abs(referenceNumber) << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "No. Pelanggan    :    " << customerNumber << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Tagihan          :    Rp" << nominal << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Admin            :    Rp" << adminString << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Total            :    Rp" << totalString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    saldo -= total;
                                    
                                    char repeat;
                                    cout << "Ingin melanjutkan transaksi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                                } else {
                                    cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                    break;
                                }
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Customer Number!\033[0m" << endl << endl;
                            break;
                        }
                    } else {
                        cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
                        break;
                    }
                } else if (transaction == 3) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 11) / 2, ' ') << "\033[1;36mSetor Tunai\033[0m" << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    string nominal;
                    cout << "Silahkan masukkan jumlah nominal : ";
                    cin >> nominal;
                    
                    int amount = atoi(nominal.c_str());
                    
                    bool isNumber = true;
                    for (int i = 0; i < nominal.length(); i++) {
                        if (!isdigit(nominal[i])) {
                            isNumber = false;
                        }
                    }
                    
                    if (isNumber == true) {
                        time_t now = time(0);
                        char* dateTime = ctime(&now);
                        
                        srand(time(0));
                        int referenceNumber = rand() % 1147483647 + 1000000000;
                        
                        for (int i = nominal.length() - 3; i > 0; i -= 3) {
                            nominal.insert(i, ".");
                        }
                        
                        if (amount > 0)  {
                            saldo += amount;
                            
                            system("clear");
                            cout << string(screenWidth, '-') << endl << endl << endl;
                            cout << string((screenWidth - 18) / 2, ' ') << "\033[1;36mTransaksi Berhasil\033[0m" << endl << endl << endl;
                            cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                            cout << string((screenWidth - 40) / 2, ' ') << "Tanggal    :    " << dateTime;
                            cout << string((screenWidth - 40) / 2, ' ') << "No. Ref    :    " << abs(referenceNumber) << endl;
                            cout << string((screenWidth - 40) / 2, ' ') << "Jumlah     :    Rp" << nominal << endl << endl << endl;
                            cout << string(screenWidth, '-') << endl << endl;
                        } else {
                            cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                            break;
                        }
                        
                        char repeat;
                        cout << "Ingin melanjutkan transaksi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                    } else {
                        cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                        break;
                    }
                } else if (transaction == 4) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 15) / 2, ' ') << "\033[1;36mPenarikan Tunai\033[0m" << endl << endl;
                    cout << string((screenWidth - 32) / 2, ' ') << "--------------------------------" << endl << endl;
                    cout << string((screenWidth - 32) / 2, ' ') << "\033[1;32m(1)\033[0m. Rp50.000     \033[1;32m(2)\033[0m. Rp100.000" << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    int money;
                    cout << "Silahkan pilih pecahan uang (1/2) : ";
                    cin >> money;
                    
                    if (money == 1) {
                        string nominal;
                        cout << endl << "Silahkan masukkan jumlah nominal : ";
                        cin >> nominal;
                        
                        int amount = atoi(nominal.c_str());
                        
                        bool isNumber = true;
                        for (int i = 0; i < nominal.length(); i++) {
                            if (!isdigit(nominal[i])) {
                                isNumber = false;
                            }
                        }
                        
                        if (isNumber == true) {
                            time_t now = time(0);
                            char* dateTime = ctime(&now);
                            
                            if (amount % 50 == 0) {
                                if (saldo >= amount && saldo != 0)  {
                                    saldo -= amount;
                                    
                                    string saldoString = to_string(saldo);
                                    
                                    for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                        nominal.insert(i, ".");
                                    }
                                    
                                    for (int i = saldoString.length() - 3; i > 0; i -= 3) {
                                        saldoString.insert(i, ".");
                                    }
                                    
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 18) / 2, ' ') << "\033[1;36mTransaksi Berhasil\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Tanggal    :    " << dateTime;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Jumlah     :    Rp" << nominal << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Saldo      :    Rp" << saldoString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    char repeat;
                                    cout << "Ingin melanjutkan transaksi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                                } else {
                                    cout << endl << "\033[1;33mSaldo anda tidak cukup!\033[0m" << endl << endl;
                                    break;
                                }
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                            break;
                        }
                    } else if (money == 2) {
                        string nominal;
                        cout << endl << "Silahkan masukkan jumlah nominal : ";
                        cin >> nominal;
                        
                        int amount = atoi(nominal.c_str());
                        
                        bool isNumber = true;
                        for (int i = 0; i < nominal.length(); i++) {
                            if (!isdigit(nominal[i])) {
                                isNumber = false;
                            }
                        }
                        
                        if (isNumber == true) {
                            time_t now = time(0);
                            char* dateTime = ctime(&now);
                            
                            if (amount % 100 == 0) {
                                if (saldo >= amount && saldo != 0)  {
                                    saldo -= amount;
                                    
                                    string saldoString = to_string(saldo);
                                    
                                    for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                        nominal.insert(i, ".");
                                    }
                                    
                                    for (int i = saldoString.length() - 3; i > 0; i -= 3) {
                                        saldoString.insert(i, ".");
                                    }
                                    
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 18) / 2, ' ') << "\033[1;36mTransaksi Berhasil\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Tanggal    :    " << dateTime;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Jumlah     :    Rp" << nominal << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Saldo      :    Rp" << saldoString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    char repeat;
                                    cout << "Ingin melanjutkan transaksi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                                } else {
                                    cout << endl << "\033[1;33mSaldo anda tidak cukup!\033[0m" << endl << endl;
                                    break;
                                }
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                            break;
                        }
                    } else {
                        cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
                        break;
                    }
                } else if (transaction == 5) {
                    string saldoString = to_string(saldo);
                    
                    for (int i = saldoString.length() - 3; i > 0; i -= 3) {
                        saldoString.insert(i, ".");
                    }
                    
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 19) / 2, ' ') << "\033[1;36mSaldo Rekening Anda\033[0m" << endl << endl << endl;
                    cout << string((screenWidth - 20) / 2, ' ') << "--------------------" << endl << endl << endl;
                    cout << string((screenWidth - 20) / 2, ' ') << "Saldo = Rp" << saldoString << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    char repeat;
                    cout << "Ingin melanjutkan transaksi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                } else if (transaction == 6) {
                    cout << endl;
                    break;
                } else {
                    cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
                    break;
                }
            } else if (languange == 2) {
                system("clear");
                cout << string(screenWidth, '-') << endl << endl << endl;
                cout << string((screenWidth - 16) / 2, ' ') << "\033[1;36mTransaction Menu\033[0m" << endl << endl;
                cout << string((screenWidth - 36) / 2, ' ') << "------------------------------------" << endl << endl << endl;
                cout << string((screenWidth - 36) / 2, ' ') << "\033[1;32m(1)\033[0m. Transfer   \033[1;32m(4)\033[0m. Cash Withdrawal" << endl << endl;
                cout << string((screenWidth - 36) / 2, ' ') << "\033[1;32m(2)\033[0m. Payment    \033[1;32m(5)\033[0m. Account Balance" << endl << endl;
                cout << string((screenWidth - 36) / 2, ' ') << "\033[1;32m(3)\033[0m. Deposit    \033[1;31m(6)\033[0m. Cancel Transaction" << endl << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
                
                int transaction;
                cout << "Please select a transaction (1, 2, 3, 4, 5, 6) : ";
                cin >> transaction;
                
                if (transaction == 1) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 8) / 2, ' ') << "\033[1;36mTransfer\033[0m" << endl << endl << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "-----------------------" << endl << endl << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BRI        =        002" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BNI        =        009" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BCA        =        009" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BSI        =        014" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BNI        =        451" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "BTN        =        200" << endl;
                    cout << string((screenWidth - 23) / 2, ' ') << "MANDIRI    =        008" << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    string bank[6] = {"BRI", "BNI", "BCA", "BSI", "BTN", "MANDIRI"};
                    string bankCode[6] = {"002", "009", "014", "451", "200", "008"};
                    
                    string code;
                    cout << "Please enter the destination bank code : ";
                    cin >> code;
                    
                    bool isNumber = true;
                    for (int i = 0; i < code.length(); i++) {
                        if (!isdigit(code[i])) {
                            isNumber = false;
                        }
                    }
                    
                    bool valid = false;
                    int index;
                    for (int i = 0; i < (sizeof(bankCode) / sizeof(string)); i++) {
                        if (code == bankCode[i]) {
                            valid = true;
                            index = i;
                        }
                    }
                    
                    int codeLength = code.length();
                    
                    if (isNumber == true && valid == true && codeLength == 3) {
                        string accountNumber;
                        cout << endl << "Please enter the destination account number : ";
                        cin >> accountNumber;
                        
                        bool isNumber = true;
                        for (int i = 0; i < accountNumber.length(); i++) {
                            if (!isdigit(accountNumber[i])) {
                                isNumber = false;
                            }
                        }
                        
                        if (isNumber == true && codeLength < 17) {
                            string nominal;
                            cout << endl << "Please enter the transaction amount : ";
                            cin >> nominal;
                            
                            bool isNumber = true;
                            for (int i = 0; i < nominal.length(); i++) {
                                if (!isdigit(nominal[i])) {
                                    isNumber = false;
                                }
                            }
                            
                            if (isNumber == true) {
                                time_t now = time(0);
                                char* dateTime = ctime(&now);
                                
                                string adminBank[4] = {"0", "2500", "5000", "6500"};
                                srand(time(0));
                                int random_index = rand() % 3;
                                int amount = atoi(nominal.c_str());
                                string adminString = adminBank[random_index];
                                int admin = atoi(adminString.c_str());
                                int total = amount + admin;
                                int referenceNumber = rand() % 1147483647 + 1000000000;
                                
                                string totalString = to_string(total);
                                
                                for (int i = adminString.length() - 3; i > 0; i -= 3) {
                                    adminString.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = totalString.length() - 3; i > 0; i -= 3) {
                                    totalString.insert(i, ".");
                                }
                                
                                if (saldo >= total) {
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 22) / 2, ' ') << "\033[1;36mTransaction Successful\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Date        :   " << dateTime;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Bank        :   " << bank[index] << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Account     :   " << accountNumber << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Ref No.     :   " << abs(referenceNumber) << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Amount      :   Rp" << nominal << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Admin Fee   :   Rp" << adminString << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Total       :   Rp" << totalString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    saldo -= total;
                                } else {
                                    cout << endl << "\033[1;33mInsufficient balance!\033[0m" << endl << endl;
                                    break;
                                }
                                
                                char repeat;
                                cout << "Do you want to continue the transaction? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
                            break;
                        }
                    } else {
                        cout << endl << "\033[1;31mInvalid Code!\033[0m" << endl << endl;
                        break;
                    }
                } else if (transaction == 2) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 7) / 2, ' ') << "\033[1;36mPayment\033[0m" << endl << endl << endl;
                    cout << string((screenWidth - 33) / 2, ' ') << "---------------------------------" << endl << endl << endl;
                    cout << string((screenWidth - 33) / 2, ' ') << "\033[1;32m(1)\033[0m. PDAM Water     \033[1;32m(2)\033[0m. Internet" << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    int payment;
                    cout << "Please select payment option (1/2) : ";
                    cin >> payment;
                    
                    if (payment == 1) {
                        system("clear");
                        cout << string(screenWidth, '-') << endl << endl << endl;
                        cout << string((screenWidth - 19) / 2, ' ') << "\033[1;36mPay PDAM Water Bill\033[0m" << endl << endl << endl;
                        cout << string(screenWidth, '-') << endl << endl;
                        
                        string customerNumber;
                        cout << "Please enter customer number : ";
                        cin >> customerNumber;
                        
                        bool isNumber = true;
                        for (int i = 0; i < customerNumber.length(); i++) {
                            if (!isdigit(customerNumber[i])) {
                                isNumber = false;
                            }
                        }
                        
                        int maxLength = customerNumber.length();
                        
                        if (isNumber == true && maxLength < 14) {
                            string nominal;
                            cout << endl << "Please enter the bill amount : ";
                            cin >> nominal;
                            
                            bool isNumber = true;
                            for (int i = 0; i < nominal.length(); i++) {
                                if (!isdigit(nominal[i])) {
                                    isNumber = false;
                                }
                            }
                                
                            if (isNumber == true) {
                                time_t now = time(0);
                                char* dateTime = ctime(&now);
                                
                                srand(time(0));
                                int referenceNumber = rand() % 1147483647 + 1000000000;
                                int amount = atoi(nominal.c_str());
                                int admin = 2500;
                                int total = amount + admin;
                                
                                string adminString = to_string(admin);
                                string totalString = to_string(total);
                                
                                for (int i = adminString.length() - 3; i > 0; i -= 3) {
                                    adminString.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = totalString.length() - 3; i > 0; i -= 3) {
                                    totalString.insert(i, ".");
                                }
                                
                                if (saldo >= amount && amount != 0)  {
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 22) / 2, ' ') << "\033[1;32mTransaction Successful\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "-------------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Date           :   " << dateTime;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Ref No.        :   " << abs(referenceNumber) << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Customer No.   :   " << customerNumber << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Bill           :   Rp" << nominal << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Admin          :   Rp" << adminString << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Total          :   Rp" << totalString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    saldo -= total;
                                    
                                    char repeat;
                                    cout << "Do you want to continue the transaction? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                                } else {
                                    cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                    break;
                                }
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Customer Number!\033[0m" << endl << endl;
                            break;
                        }
                    } else if (payment == 2) {
                        system("clear");
                        cout << string(screenWidth, '-') << endl << endl << endl;
                        cout << string((screenWidth - 17) / 2, ' ') << "\033[1;36mPay Internet Bill\033[0m" << endl << endl << endl;
                        cout << string(screenWidth, '-') << endl << endl;
                        
                        string customerNumber;
                        cout << "Please enter customer number : ";
                        cin >> customerNumber;
                        
                        bool isNumber = true;
                        for (int i = 0; i < customerNumber.length(); i++) {
                            if (!isdigit(customerNumber[i])) {
                                isNumber = false;
                            }
                        }
                        
                        int maxLength = customerNumber.length();
                        
                        if (isNumber == true && maxLength < 14) {
                            string nominal;
                            cout << endl << "Please enter the bill amount : ";
                            cin >> nominal;
                            
                            bool isNumber = true;
                            for (int i = 0; i < nominal.length(); i++) {
                                if (!isdigit(nominal[i])) {
                                    isNumber = false;
                                }
                            }
                                
                            if (isNumber == true) {
                                time_t now = time(0);
                                char* dateTime = ctime(&now);
                                
                                srand(time(0));
                                int referenceNumber = rand() % 1147483647 + 1000000000;
                                int amount = atoi(nominal.c_str());
                                int admin = 2500;
                                int total = amount + admin;
                                
                                string adminString = to_string(admin);
                                string totalString = to_string(total);
                                
                                for (int i = adminString.length() - 3; i > 0; i -= 3) {
                                    adminString.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = totalString.length() - 3; i > 0; i -= 3) {
                                    totalString.insert(i, ".");
                                }
                                
                                if (saldo >= amount && amount != 0)  {
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 22) / 2, ' ') << "\033[1;32mTransaction Successful\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "-------------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Date           :   " << dateTime;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Ref No.        :   " << abs(referenceNumber) << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Customer No.   :   " << customerNumber << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Bill           :   Rp" << nominal << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Admin          :   Rp" << adminString << endl;
                                    cout << string((screenWidth - 43) / 2, ' ') << "Total          :   Rp" << totalString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    saldo -= total;
                                    
                                    char repeat;
                                    cout << "Do you want to continue the transaction? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                                } else {
                                    cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                    break;
                                }
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Customer Number!\033[0m" << endl << endl;
                            break;
                        }
                    } else {
                        cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
                        break;
                    }
                } else if (transaction == 3) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 12) / 2, ' ') << "\033[1;36mCash Deposit\033[0m" << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    string nominal;
                    cout << "Please enter the amount : ";
                    cin >> nominal;
                    
                    int amount = atoi(nominal.c_str());
                    
                    bool isNumber = true;
                    for (int i = 0; i < nominal.length(); i++) {
                        if (!isdigit(nominal[i])) {
                            isNumber = false;
                        }
                    }
                    
                    if (isNumber == true) {
                        time_t now = time(0);
                        char* dateTime = ctime(&now);
                        
                        srand(time(0));
                        int referenceNumber = rand() % 1147483647 + 1000000000;
                        
                        for (int i = nominal.length() - 3; i > 0; i -= 3) {
                            nominal.insert(i, ".");
                        }
                        
                        if (amount > 0)  {
                            saldo += amount;
                            
                            system("clear");
                            cout << string(screenWidth, '-') << endl << endl << endl;
                            cout << string((screenWidth - 22) / 2, ' ') << "\033[1;32mTransaction Successful\033[0m" << endl << endl << endl;
                            cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                            cout << string((screenWidth - 40) / 2, ' ') << "Date       :    " << dateTime;
                            cout << string((screenWidth - 40) / 2, ' ') << "Ref No.    :    " << abs(referenceNumber) << endl;
                            cout << string((screenWidth - 40) / 2, ' ') << "Amount     :    " << nominal << endl << endl << endl;
                            cout << string(screenWidth, '-') << endl << endl;
                        } else {
                            cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                            break;
                        }
                        
                        char repeat;
                        cout << "Do you want to continue the transaction? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                    } else {
                        cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                        break;
                    }
                } else if (transaction == 4) {
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 15) / 2, ' ') << "\033[1;36mCash Withdrawal\033[0m" << endl << endl << endl;
                    cout << string((screenWidth - 31) / 2, ' ') << "-------------------------------" << endl << endl << endl;
                    cout << string((screenWidth - 31) / 2, ' ') << "\033[1;32m(1)\033[0m. Rp50.000    \033[1;32m(2)\033[0m. Rp100.000" << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    int money;
                    cout << "Please select the denomination (1/2) : ";
                    cin >> money;
                    
                    if (money == 1) {
                        string nominal;
                        cout << endl << "Please enter the amount : ";
                        cin >> nominal;
                        
                        int amount = atoi(nominal.c_str());
                        
                        bool isNumber = true;
                        for (int i = 0; i < nominal.length(); i++) {
                            if (!isdigit(nominal[i])) {
                                isNumber = false;
                            }
                        }
                        
                        if (isNumber == true) {
                            time_t now = time(0);
                            char* dateTime = ctime(&now);
                            
                            if (amount % 50 == 0) {
                                if (saldo >= amount && saldo != 0)  {
                                    saldo -= amount;
                                    
                                    string saldoString = to_string(saldo);
                                    
                                    for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                        nominal.insert(i, ".");
                                    }
                                    
                                    for (int i = saldoString.length() - 3; i > 0; i -= 3) {
                                        saldoString.insert(i, ".");
                                    }
                                    
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 22) / 2, ' ') << "\033[1;32mTransaction Successful\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Date       :    " << dateTime;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Amount     :    " << nominal << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Balance    :    Rp" << saldoString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    char repeat;
                                    cout << "Do you want to continue the transaction? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                                } else {
                                    cout << endl << "\033[1;33mInsufficient balance!\033[0m" << endl << endl;
                                    break;
                                }
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                            break;
                        }
                    } else if (money == 2) {
                        string nominal;
                        cout << endl << "Please enter the amount : ";
                        cin >> nominal;
                        
                        int amount = atoi(nominal.c_str());
                        
                        bool isNumber = true;
                        for (int i = 0; i < nominal.length(); i++) {
                            if (!isdigit(nominal[i])) {
                                isNumber = false;
                            }
                        }
                        
                        if (isNumber == true) {
                            time_t now = time(0);
                            char* dateTime = ctime(&now);
                            
                            if (amount % 50 == 0) {
                                if (saldo >= amount && saldo != 0)  {
                                    saldo -= amount;
                                    
                                    string saldoString = to_string(saldo);
                                    
                                    for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                        nominal.insert(i, ".");
                                    }
                                    
                                    for (int i = saldoString.length() - 3; i > 0; i -= 3) {
                                        saldoString.insert(i, ".");
                                    }
                                    
                                    system("clear");
                                    cout << string(screenWidth, '-') << endl << endl << endl;
                                    cout << string((screenWidth - 22) / 2, ' ') << "\033[1;32mTransaction Successful\033[0m" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "----------------------------------------" << endl << endl << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Date       :    " << dateTime;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Amount     :    " << nominal << endl;
                                    cout << string((screenWidth - 40) / 2, ' ') << "Balance    :    Rp" << saldoString << endl << endl << endl;
                                    cout << string(screenWidth, '-') << endl << endl;
                                    
                                    char repeat;
                                    cout << "Do you want to continue the transaction? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                                } else {
                                    cout << endl << "\033[1;33mInsufficient balance!\033[0m" << endl << endl;
                                    break;
                                }
                            } else {
                                cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                                break;
                            }
                        } else {
                            cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                            break;
                        }
                    } else {
                        cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
                        break;
                    }
                } else if (transaction == 5) {
                    string saldoString = to_string(saldo);
                    
                    for (int i = saldoString.length() - 3; i > 0; i -= 3) {
                        saldoString.insert(i, ".");
                    }
                    
                    system("clear");
                    cout << string(screenWidth, '-') << endl << endl << endl;
                    cout << string((screenWidth - 20) / 2, ' ') << "\033[1;36mYour Account Balance\033[0m" << endl << endl << endl;
                    cout << string((screenWidth - 22) / 2, ' ') << "----------------------" << endl << endl << endl;
                    cout << string((screenWidth - 22) / 2, ' ') << "Balance = Rp" << saldoString << endl << endl << endl;
                    cout << string(screenWidth, '-') << endl << endl;
                    
                    char repeat;
                    cout << "Do you want to continue the transaction? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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
                } else if (transaction == 6) {
                    cout << endl;
                    break;
                } else {
                    cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
                    break;
                }
            } else {
                cout << endl << "\033[1;31mInvalid Input!\033[0m" << endl << endl;
                break;
            }
        } else {
            cout << endl << "\033[1;31mInvalid PIN!\033[0m" << endl << endl;
            break;
        }
    }
    
    return 0;
}