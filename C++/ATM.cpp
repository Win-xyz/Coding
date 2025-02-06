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
        
        cout << std::string(screenWidth, '-') << endl << endl << endl;
        cout << "                   \033[1;36mPIN = " << randomPin << "\033[0m" << endl << endl << endl;
        cout << std::string(screenWidth, '-') << endl << endl;
        
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
            
            cout << std::string(screenWidth, '-') << endl << endl << endl;
            cout << "        \033[1;36mPilih bahasa\033[0m | \033[1;36mLanguange Preference\033[0m" << endl << endl;
            cout << "        -----------------------------------       " << endl << endl;
            cout << "        (1). Indonesia         (2). English" << endl << endl << endl;
            cout << std::string(screenWidth, '-') << endl << endl;
            
            int languange;
            cout << "Silahkan pilih bahasa (1/2) : ";
            cin >> languange;
            
            if (languange == 1) {
                system("clear");
                cout << std::string(screenWidth, '-') << endl << endl << endl;
                cout << "                  \033[1;36mMenu Transaksi\033[0m                  " << endl << endl;
                cout << "      ---------------------------------------     " << endl << endl;
                cout << "      \033[1;32m(1)\033[0m. Transfer      \033[1;32m(4)\033[0m. Penarikan Tunai     " << endl << endl;
                cout << "      \033[1;32m(2)\033[0m. Pembayaran    \033[1;32m(5)\033[0m. Informasi Saldo     " << endl << endl;
                cout << "      \033[1;32m(3)\033[0m. Setor Tunai   \033[1;31m(6)\033[0m. Batal Transaksi     " << endl << endl << endl;
                cout << std::string(screenWidth, '-') << endl << endl;
                
                int transaction;
                cout << "Silahkan pilih transaksi (1, 2, 3, 4, 5, 6) : ";
                cin >> transaction;
                
                if (transaction == 1) {
                    system("clear");
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "                     \033[1;36mTransfer\033[0m                     " << endl << endl;
                    cout << "              -----------------------             " << endl << endl;
                    cout << "              BRI        =        002             " << endl;
                    cout << "              BNI        =        009             " << endl;
                    cout << "              BCA        =        014             " << endl;
                    cout << "              BSI        =        451             " << endl;
                    cout << "              BTN        =        200             " << endl;
                    cout << "              MANDIRI    =        008             " << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m                " << endl << endl;
                                    cout << "     ----------------------------------------     " << endl << endl << endl;
                                    cout << "     Tanggal    :    " << dateTime;
                                    cout << "     Bank       :    " << bank[index] << endl;
                                    cout << "     Rekening   :    " << accountNumber << endl;
                                    cout << "     No. Ref    :    " << abs(referenceNumber) << endl;
                                    cout << "     Nominal    :    Rp" << nominal << endl;
                                    cout << "     Admin      :    Rp" << adminString << endl;
                                    cout << "     Total      :    Rp" << totalString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "                    \033[1;36mPembayaran\033[0m                    " << endl << endl;
                    cout << "          -------------------------------         " << endl << endl;
                    cout << "          \033[1;32m(1)\033[0m. Air PDAM     \033[1;32m(2)\033[0m. Internet         " << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
                    int payment;
                    cout << "Silahkan pilih pembayaran (1/2) : ";
                    cin >> payment;
                    
                    if (payment == 1) {
                        system("clear");
                        cout << std::string(screenWidth, '-') << endl << endl << endl;
                        cout << "            \033[1;36mPembayaran Tagihan Air PDAM\033[0m           " << endl << endl << endl;
                        cout << std::string(screenWidth, '-') << endl << endl;
                        
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m                " << endl << endl;
                                    cout << "  ----------------------------------------------  " << endl << endl << endl;
                                    cout << "  Tanggal          :    " << dateTime;
                                    cout << "  No. Ref          :    " << abs(referenceNumber) << endl;
                                    cout << "  No. Pelanggan    :    " << customerNumber << endl;
                                    cout << "  Tagihan          :    Rp" << nominal << endl;
                                    cout << "  Admin            :    Rp" << adminString << endl;
                                    cout << "  Total            :    Rp" << totalString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                        cout << std::string(screenWidth, '-') << endl << endl << endl;
                        cout << "           \033[1;36mPembayaran Tagihan Internet\033[0m            " << endl << endl << endl;
                        cout << std::string(screenWidth, '-') << endl << endl;
                        
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m                " << endl << endl;
                                    cout << "  ----------------------------------------------  " << endl << endl << endl;
                                    cout << "  Tanggal          :    " << dateTime;
                                    cout << "  No. Ref          :    " << abs(referenceNumber) << endl;
                                    cout << "  No. Pelanggan    :    " << customerNumber << endl;
                                    cout << "  Tagihan          :    Rp" << nominal << endl;
                                    cout << "  Admin            :    Rp" << adminString << endl;
                                    cout << "  Total            :    Rp" << totalString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "                    \033[1;36mSetor Tunai\033[0m                   " << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
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
                            cout << std::string(screenWidth, '-') << endl << endl << endl;
                            cout << "                \033[1;32mTransaksi Berhasil\033[0m                " << endl << endl;
                            cout << "     ----------------------------------------    " << endl << endl << endl;
                            cout << "     Tanggal    :    " << dateTime;
                            cout << "     No. Ref    :    " << abs(referenceNumber) << endl;
                            cout << "     Jumlah     :    Rp" << nominal << endl << endl << endl;
                            cout << std::string(screenWidth, '-') << endl << endl;
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
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "                 \033[1;36mPenarikan Tunai\033[0m                  " << endl << endl;
                    cout << "         --------------------------------         " << endl << endl;
                    cout << "         \033[1;32m(1)\033[0m. Rp50.000     \033[1;32m(2)\033[0m. Rp100.000" << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m                " << endl << endl;
                                    cout << "     ----------------------------------------    " << endl << endl << endl;
                                    cout << "     Tanggal    :    " << dateTime;
                                    cout << "     Jumlah     :    Rp" << nominal << endl;
                                    cout << "     Saldo      :    Rp" << saldoString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m                " << endl << endl;
                                    cout << "     ----------------------------------------    " << endl << endl << endl;
                                    cout << "     Tanggal    :    " << dateTime;
                                    cout << "     Jumlah     :    Rp" << nominal << endl;
                                    cout << "     Saldo      :    Rp" << saldoString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "               \033[1;36mSaldo Rekening Anda\033[0m                " << endl << endl;
                    cout << "               --------------------               " << endl << endl;
                    cout << "               Saldo = Rp" << saldoString << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
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
                cout << std::string(screenWidth, '-') << endl << endl << endl;
                cout << "                 \033[1;36mTransaction Menu\033[0m                 " << endl << endl;
                cout << "      ---------------------------------------     " << endl << endl;
                cout << "      \033[1;32m(1)\033[0m. Transfer   \033[1;32m(4)\033[0m. Cash Withdrawal        " << endl << endl;
                cout << "      \033[1;32m(2)\033[0m. Payment    \033[1;32m(5)\033[0m. Account Balance        " << endl << endl;
                cout << "      \033[1;32m(3)\033[0m. Deposit    \033[1;31m(6)\033[0m. Cancel Transaction     " << endl << endl << endl;
                cout << std::string(screenWidth, '-') << endl << endl;
                
                int transaction;
                cout << "Please select a transaction (1, 2, 3, 4, 5, 6) : ";
                cin >> transaction;
                
                if (transaction == 1) {
                    system("clear");
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "                     \033[1;36mTransfer\033[0m                     " << endl << endl;
                    cout << "              -----------------------             " << endl << endl;
                    cout << "              BRI        =        002             " << endl;
                    cout << "              BNI        =        009             " << endl;
                    cout << "              BCA        =        014             " << endl;
                    cout << "              BSI        =        451             " << endl;
                    cout << "              BTN        =        200             " << endl;
                    cout << "              MANDIRI    =        008             " << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m              " << endl << endl;
                                    cout << "     ----------------------------------------     " << endl << endl << endl;
                                    cout << "     Date        :   " << dateTime;
                                    cout << "     Bank        :   " << bank[index] << endl;
                                    cout << "     Account     :   " << accountNumber << endl;
                                    cout << "     Ref No.     :   " << abs(referenceNumber) << endl;
                                    cout << "     Amount      :   Rp" << nominal << endl;
                                    cout << "     Admin Fee   :   Rp" << adminString << endl;
                                    cout << "     Total       :   Rp" << totalString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "                      \033[1;36mPayment\033[0m                     " << endl << endl;
                    cout << "        -----------------------------------       " << endl << endl;
                    cout << "        \033[1;32m(1)\033[0m. PDAM Water       \033[1;32m(2)\033[0m. Internet       " << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
                    int payment;
                    cout << "Please select payment option (1/2) : ";
                    cin >> payment;
                    
                    if (payment == 1) {
                        system("clear");
                        cout << std::string(screenWidth, '-') << endl << endl << endl;
                        cout << "                \033[1;36mPay PDAM Water Bill\033[0m               " << endl << endl << endl;
                        cout << std::string(screenWidth, '-') << endl << endl;
                        
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m              " << endl << endl;
                                    cout << "    -------------------------------------------   " << endl << endl << endl;
                                    cout << "    Date           :   " << dateTime;
                                    cout << "    Ref No.        :   " << abs(referenceNumber) << endl;
                                    cout << "    Customer No.   :   " << customerNumber << endl;
                                    cout << "    Bill           :   Rp" << nominal << endl;
                                    cout << "    Admin          :   Rp" << adminString << endl;
                                    cout << "    Total          :   Rp" << totalString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                        cout << std::string(screenWidth, '-') << endl << endl << endl;
                        cout << "                \033[1;36mPay Internet Bill\033[0m                 " << endl << endl << endl;
                        cout << std::string(screenWidth, '-') << endl << endl;
                        
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m              " << endl << endl;
                                    cout << "    -------------------------------------------   " << endl << endl << endl;
                                    cout << "    Date           :   " << dateTime;
                                    cout << "    Ref No.        :   " << abs(referenceNumber) << endl;
                                    cout << "    Customer No.   :   " << customerNumber << endl;
                                    cout << "    Bill           :   Rp" << nominal << endl;
                                    cout << "    Admin          :   Rp" << adminString << endl;
                                    cout << "    Total          :   Rp" << totalString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "                   \033[1;36mCash Deposit\033[0m                   " << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
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
                            cout << std::string(screenWidth, '-') << endl << endl << endl;
                            cout << "              \033[1;32mTransaction Successful\033[0m              " << endl << endl;
                            cout << "     ----------------------------------------     " << endl << endl << endl;
                            cout << "     Date       :    " << dateTime;
                            cout << "     Ref No.    :    " << abs(referenceNumber) << endl;
                            cout << "     Amount     :    Rp" << nominal << endl << endl << endl;
                            cout << std::string(screenWidth, '-') << endl << endl;
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
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "                 \033[1;36mCash Withdrawal\033[0m                  " << endl << endl;
                    cout << "         --------------------------------         " << endl << endl;
                    cout << "         \033[1;32m(1)\033[0m. Rp50.000     \033[1;32m(2)\033[0m. Rp100.000         " << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m              " << endl << endl;
                                    cout << "     ----------------------------------------     " << endl << endl << endl;
                                    cout << "     Date       :    " << dateTime;
                                    cout << "     Amount     :    Rp" << nominal << endl;
                                    cout << "     Balance    :    Rp" << saldoString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m              " << endl << endl;
                                    cout << "     ----------------------------------------     " << endl << endl << endl;
                                    cout << "     Date       :    " << dateTime;
                                    cout << "     Amount     :    Rp" << nominal << endl;
                                    cout << "     Balance    :    Rp" << saldoString << endl << endl << endl;
                                    cout << std::string(screenWidth, '-') << endl << endl;
                                    
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
                    cout << std::string(screenWidth, '-') << endl << endl << endl;
                    cout << "               \033[1;36mYour Account Balance\033[0m               " << endl << endl;
                    cout << "              ----------------------              " << endl << endl;
                    cout << "              Balance = Rp" << saldoString << endl << endl << endl;
                    cout << std::string(screenWidth, '-') << endl << endl;
                    
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