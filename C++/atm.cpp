#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    system("clear");
    
    srand(time(0));
    int saldo = rand() % 50000000 + 50000000;
    int random_pin = rand() % 899999 + 100000;
    
    while (true) {
        
        cout << "--------------------------------------------------" << endl << endl << endl;
        cout << "                   \033[1;36mPIN = " << random_pin << "\033[0m" << endl << endl << endl;
        cout << "--------------------------------------------------" << endl << endl;
        
        string pin;
        cout << "Silahkan masukkan PIN : ";
        cin >> pin;
        
        int pin_integer = atoi(pin.c_str());
        
        bool isNumber = true;
        for (int i = 0; i < pin.length(); i++) {
            if (!isdigit(pin[i])) {
                isNumber = false;
            }
        }
        
        int pin_length = pin.length();
        
        if (isNumber == true && pin_integer == random_pin && pin_length == 6) {
            system("clear");
            
            cout << "--------------------------------------------------" << endl << endl << endl;
            cout << "        \033[1;36mPilih bahasa\033[0m | \033[1;36mLanguange Preference\033[0m" << endl << endl;
            cout << "        -----------------------------------       " << endl << endl;
            cout << "        (1). Indonesia         (2). English" << endl << endl << endl;
            cout << "--------------------------------------------------" << endl << endl;
            
            int languange;
            cout << "Silahkan pilih bahasa (1/2) : ";
            cin >> languange;
            
            if (languange == 1) {
                system("clear");
                cout << "--------------------------------------------------" << endl << endl << endl;
                cout << "                  \033[1;36mMenu Transaksi\033[0m" << endl << endl;
                cout << "      ---------------------------------------     " << endl << endl;
                cout << "      \033[1;32m(1)\033[0m. Transfer      \033[1;32m(4)\033[0m. Penarikan Tunai" << endl << endl;
                cout << "      \033[1;32m(2)\033[0m. Pembayaran    \033[1;32m(5)\033[0m. Informasi Saldo" << endl << endl;
                cout << "      \033[1;32m(3)\033[0m. Setor Tunai   \033[1;31m(6)\033[0m. Batal Transaksi" << endl << endl << endl;
                cout << "--------------------------------------------------" << endl << endl;
                
                int transaction;
                cout << "Silahkan pilih transaksi (1, 2, 3, 4, 5, 6) : ";
                cin >> transaction;
                
                if (transaction == 1) {
                    system("clear");
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "                     \033[1;36mTransfer\033[0m" << endl << endl;
                    cout << "              -----------------------             " << endl << endl;
                    cout << "              BRI        =        002             " << endl;
                    cout << "              BNI        =        009             " << endl;
                    cout << "              BCA        =        014             " << endl;
                    cout << "              BSI        =        451             " << endl;
                    cout << "              BTN        =        200             " << endl;
                    cout << "              MANDIRI    =        008             " << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
                    string bank[6] = {"BRI", "BNI", "BCA", "BSI", "BTN", "MANDIRI"};
                    string bank_code[6] = {"002", "009", "014", "451", "200", "008"};
                    
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
                    for (int i = 0; i < (sizeof(bank_code) / sizeof(string)); i++) {
                        if (code == bank_code[i]) {
                            valid = true;
                            index = i;
                        }
                    }
                    
                    int code_length = code.length();
                    
                    if (isNumber == true && valid == true && code_length == 3) {
                        string account_number;
                        cout << endl << "Silahkan masukkan rekening tujuan : ";
                        cin >> account_number;
                        
                        bool isNumber = true;
                        for (int i = 0; i < account_number.length(); i++) {
                            if (!isdigit(account_number[i])) {
                                isNumber = false;
                            }
                        }
                        
                        if (isNumber == true && code_length < 17) {
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
                                // datetime
                                time_t now = time(0);
                                char* date_time = ctime(&now);
                                
                                string admin_bank[4] = {"0", "2500", "5000", "6500"};
                                srand(time(0));
                                int random_index = rand() % 3;
                                int amount = atoi(nominal.c_str());
                                string admin_string = admin_bank[random_index];
                                int admin = atoi(admin_string.c_str());
                                int total = amount + admin;
                                int reference_number = rand() % 1147483647 + 1000000000;
                                
                                string total_string = to_string(total);
                                
                                for (int i = admin_string.length() - 3; i > 0; i -= 3) {
                                    admin_string.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = total_string.length() - 3; i > 0; i -= 3) {
                                    total_string.insert(i, ".");
                                }
                                
                                if (saldo >= total) {
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m" << endl << endl;
                                    cout << "     ----------------------------------------     " << endl << endl << endl;
                                    cout << "     Tanggal    :    " << date_time;
                                    cout << "     Bank       :    " << bank[index] << endl;
                                    cout << "     Rekening   :    " << account_number << endl;
                                    cout << "     No. Ref    :    " << abs(reference_number) << endl;
                                    cout << "     Nominal    :    Rp" << nominal << endl;
                                    cout << "     Admin      :    Rp" << admin_string << endl;
                                    cout << "     Total      :    Rp" << total_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    saldo -= total;
                                } else {
                                    cout << endl << "\033[1;33mSaldo anda tidak cukup!\033[0m" << endl << endl;
                                    break;
                                }
                                
                                char repeat;
                                cout << "Ingin melanjutkan transaksi? (y/n) : ";
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
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "                    \033[1;36mPembayaran\033[0m" << endl << endl;
                    cout << "          -------------------------------         " << endl << endl;
                    cout << "          \033[1;32m(1)\033[0m. Air PDAM     \033[1;32m(2)\033[0m. Internet" << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
                    int payment;
                    cout << "Silahkan pilih pembayaran (1/2) : ";
                    cin >> payment;
                    
                    if (payment == 1) {
                        system("clear");
                        cout << "--------------------------------------------------" << endl << endl << endl;
                        cout << "            \033[1;36mPembayaran Tagihan Air PDAM\033[0m" << endl << endl << endl;
                        cout << "--------------------------------------------------" << endl << endl;
                        
                        string customer_number;
                        cout << "Silahkan masukkan nomor pelanggan : ";
                        cin >> customer_number;
                        
                        bool isNumber = true;
                        for (int i = 0; i < customer_number.length(); i++) {
                            if (!isdigit(customer_number[i])) {
                                isNumber = false;
                            }
                        }
                        
                        int max_length = customer_number.length();
                        
                        if (isNumber == true && max_length < 14) {
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
                                char* date_time = ctime(&now);
                                
                                srand(time(0));
                                int reference_number = rand() % 1147483647 + 1000000000;
                                int amount = atoi(nominal.c_str());
                                int admin = 2500;
                                int total = amount + admin;
                                
                                string admin_string = to_string(admin);
                                string total_string = to_string(total);
                                
                                for (int i = admin_string.length() - 3; i > 0; i -= 3) {
                                    admin_string.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = total_string.length() - 3; i > 0; i -= 3) {
                                    total_string.insert(i, ".");
                                }
                                
                                if (saldo >= amount && amount != 0)  {
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m" << endl << endl;
                                    cout << "  ----------------------------------------------  " << endl << endl << endl;
                                    cout << "  Tanggal          :    " << date_time;
                                    cout << "  No. Ref          :    " << abs(reference_number) << endl;
                                    cout << "  No. Pelanggan    :    " << customer_number << endl;
                                    cout << "  Tagihan          :    Rp" << nominal << endl;
                                    cout << "  Admin            :    Rp" << admin_string << endl;
                                    cout << "  Total            :    Rp" << total_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    saldo -= total;
                                    
                                    char repeat;
                                    cout << "Ingin melanjutkan transaksi? (y/n) : ";
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
                        cout << "--------------------------------------------------" << endl << endl << endl;
                        cout << "           \033[1;36mPembayaran Tagihan Internet\033[0m" << endl << endl << endl;
                        cout << "--------------------------------------------------" << endl << endl;
                        
                        string customer_number;
                        cout << "Silahkan masukkan nomor pelanggan : ";
                        cin >> customer_number;
                        
                        bool isNumber = true;
                        for (int i = 0; i < customer_number.length(); i++) {
                            if (!isdigit(customer_number[i])) {
                                isNumber = false;
                            }
                        }
                        
                        int max_length = customer_number.length();
                        
                        if (isNumber == true && max_length < 14) {
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
                                char* date_time = ctime(&now);
                                
                                srand(time(0));
                                int reference_number = rand() % 1147483647 + 1000000000;
                                int amount = atoi(nominal.c_str());
                                int admin = 2500;
                                int total = amount + admin;
                                
                                string admin_string = to_string(admin);
                                string total_string = to_string(total);
                                
                                for (int i = admin_string.length() - 3; i > 0; i -= 3) {
                                    admin_string.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = total_string.length() - 3; i > 0; i -= 3) {
                                    total_string.insert(i, ".");
                                }
                                
                                if (saldo >= amount && amount != 0)  {
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m" << endl << endl;
                                    cout << "  ----------------------------------------------  " << endl << endl << endl;
                                    cout << "  Tanggal          :    " << date_time;
                                    cout << "  No. Ref          :    " << abs(reference_number) << endl;
                                    cout << "  No. Pelanggan    :    " << customer_number << endl;
                                    cout << "  Tagihan          :    Rp" << nominal << endl;
                                    cout << "  Admin            :    Rp" << admin_string << endl;
                                    cout << "  Total            :    Rp" << total_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    saldo -= total;
                                    
                                    char repeat;
                                    cout << "Ingin melanjutkan transaksi? (y/n) : ";
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
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "                    \033[1;36mSetor Tunai\033[0m" << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
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
                        char* date_time = ctime(&now);
                        
                        srand(time(0));
                        int reference_number = rand() % 1147483647 + 1000000000;
                        
                        for (int i = nominal.length() - 3; i > 0; i -= 3) {
                            nominal.insert(i, ".");
                        }
                        
                        if (amount > 0)  {
                            saldo += amount;
                            
                            system("clear");
                            cout << "--------------------------------------------------" << endl << endl << endl;
                            cout << "                \033[1;32mTransaksi Berhasil\033[0m" << endl << endl;
                            cout << "     ----------------------------------------    " << endl << endl << endl;
                            cout << "     Tanggal    :    " << date_time;
                            cout << "     No. Ref    :    " << abs(reference_number) << endl;
                            cout << "     Jumlah     :    Rp" << nominal << endl << endl << endl;
                            cout << "--------------------------------------------------" << endl << endl;
                        } else {
                            cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                            break;
                        }
                        
                        char repeat;
                        cout << "Ingin melanjutkan transaksi? (y/n) : ";
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
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "                 \033[1;36mPenarikan Tunai\033[0m" << endl << endl;
                    cout << "         --------------------------------         " << endl << endl;
                    cout << "         \033[1;32m(1)\033[0m. Rp50.000     \033[1;32m(2)\033[0m. Rp100.000" << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
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
                            char* date_time = ctime(&now);
                            
                            if (amount % 50 == 0) {
                                if (saldo >= amount && saldo != 0)  {
                                    saldo -= amount;
                                    
                                    string saldo_string = to_string(saldo);
                                    
                                    for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                        nominal.insert(i, ".");
                                    }
                                    
                                    for (int i = saldo_string.length() - 3; i > 0; i -= 3) {
                                        saldo_string.insert(i, ".");
                                    }
                                    
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m" << endl << endl;
                                    cout << "     ----------------------------------------    " << endl << endl << endl;
                                    cout << "     Tanggal    :    " << date_time;
                                    cout << "     Jumlah     :    Rp" << nominal << endl;
                                    cout << "     Saldo      :    Rp" << saldo_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    char repeat;
                                    cout << "Ingin melanjutkan transaksi? (y/n) : ";
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
                            char* date_time = ctime(&now);
                            
                            if (amount % 100 == 0) {
                                if (saldo >= amount && saldo != 0)  {
                                    saldo -= amount;
                                    
                                    string saldo_string = to_string(saldo);
                                    
                                    for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                        nominal.insert(i, ".");
                                    }
                                    
                                    for (int i = saldo_string.length() - 3; i > 0; i -= 3) {
                                        saldo_string.insert(i, ".");
                                    }
                                    
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "                \033[1;32mTransaksi Berhasil\033[0m" << endl << endl;
                                    cout << "     ----------------------------------------    " << endl << endl << endl;
                                    cout << "     Tanggal    :    " << date_time;
                                    cout << "     Jumlah     :    Rp" << nominal << endl;
                                    cout << "     Saldo      :    Rp" << saldo_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    char repeat;
                                    cout << "Ingin melanjutkan transaksi? (y/n) : ";
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
                    string saldo_string = to_string(saldo);
                    
                    for (int i = saldo_string.length() - 3; i > 0; i -= 3) {
                        saldo_string.insert(i, ".");
                    }
                    
                    system("clear");
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "               \033[1;36mSaldo Rekening Anda\033[0m" << endl << endl;
                    cout << "               --------------------               " << endl << endl;
                    cout << "               Saldo = Rp" << saldo_string << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
                    char repeat;
                    cout << "Ingin melanjutkan transaksi? (y/n) : ";
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
                cout << "--------------------------------------------------" << endl << endl << endl;
                cout << "                 \033[1;36mTransaction Menu\033[0m" << endl << endl;
                cout << "      ---------------------------------------     " << endl << endl;
                cout << "      \033[1;32m(1)\033[0m. Transfer   \033[1;32m(4)\033[0m. Cash Withdrawal" << endl << endl;
                cout << "      \033[1;32m(2)\033[0m. Payment    \033[1;32m(5)\033[0m. Account Balance" << endl << endl;
                cout << "      \033[1;32m(3)\033[0m. Deposit    \033[1;31m(6)\033[0m. Cancel Transaction" << endl << endl << endl;
                cout << "--------------------------------------------------" << endl << endl;
                
                int transaction;
                cout << "Please select a transaction (1, 2, 3, 4, 5, 6) : ";
                cin >> transaction;
                
                if (transaction == 1) {
                    system("clear");
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "                     \033[1;36mTransfer\033[0m" << endl << endl;
                    cout << "              -----------------------             " << endl << endl;
                    cout << "              BRI        =        002             " << endl;
                    cout << "              BNI        =        009             " << endl;
                    cout << "              BCA        =        014             " << endl;
                    cout << "              BSI        =        451             " << endl;
                    cout << "              BTN        =        200             " << endl;
                    cout << "              MANDIRI    =        008             " << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
                    string bank[6] = {"BRI", "BNI", "BCA", "BSI", "BTN", "MANDIRI"};
                    string bank_code[6] = {"002", "009", "014", "451", "200", "008"};
                    
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
                    for (int i = 0; i < (sizeof(bank_code) / sizeof(string)); i++) {
                        if (code == bank_code[i]) {
                            valid = true;
                            index = i;
                        }
                    }
                    
                    int code_length = code.length();
                    
                    if (isNumber == true && valid == true && code_length == 3) {
                        string account_number;
                        cout << endl << "Please enter the destination account number : ";
                        cin >> account_number;
                        
                        bool isNumber = true;
                        for (int i = 0; i < account_number.length(); i++) {
                            if (!isdigit(account_number[i])) {
                                isNumber = false;
                            }
                        }
                        
                        if (isNumber == true && code_length < 17) {
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
                                // datetime
                                time_t now = time(0);
                                char* date_time = ctime(&now);
                                
                                string admin_bank[4] = {"0", "2500", "5000", "6500"};
                                srand(time(0));
                                int random_index = rand() % 3;
                                int amount = atoi(nominal.c_str());
                                string admin_string = admin_bank[random_index];
                                int admin = atoi(admin_string.c_str());
                                int total = amount + admin;
                                int reference_number = rand() % 1147483647 + 1000000000;
                                
                                string total_string = to_string(total);
                                
                                for (int i = admin_string.length() - 3; i > 0; i -= 3) {
                                    admin_string.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = total_string.length() - 3; i > 0; i -= 3) {
                                    total_string.insert(i, ".");
                                }
                                
                                if (saldo >= total) {
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m" << endl << endl;
                                    cout << "     ----------------------------------------     " << endl << endl << endl;
                                    cout << "     Date        :   " << date_time;
                                    cout << "     Bank        :   " << bank[index] << endl;
                                    cout << "     Account     :   " << account_number << endl;
                                    cout << "     Ref No.     :   " << abs(reference_number) << endl;
                                    cout << "     Amount      :   Rp" << nominal << endl;
                                    cout << "     Admin Fee   :   Rp" << admin_string << endl;
                                    cout << "     Total       :   Rp" << total_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    saldo -= total;
                                } else {
                                    cout << endl << "\033[1;33mInsufficient balance!\033[0m" << endl << endl;
                                    break;
                                }
                                
                                char repeat;
                                cout << "Do you want to continue the transaction? (y/n) : ";
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
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "                      \033[1;36mPayment\033[0m" << endl << endl;
                    cout << "        -----------------------------------       " << endl << endl;
                    cout << "        \033[1;32m(1)\033[0m. PDAM Water       \033[1;32m(2)\033[0m. Internet" << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
                    int payment;
                    cout << "Please select payment option (1/2) : ";
                    cin >> payment;
                    
                    if (payment == 1) {
                        system("clear");
                        cout << "--------------------------------------------------" << endl << endl << endl;
                        cout << "                \033[1;36mPay PDAM Water Bill\033[0m" << endl << endl << endl;
                        cout << "--------------------------------------------------" << endl << endl;
                        
                        string customer_number;
                        cout << "Please enter customer number : ";
                        cin >> customer_number;
                        
                        bool isNumber = true;
                        for (int i = 0; i < customer_number.length(); i++) {
                            if (!isdigit(customer_number[i])) {
                                isNumber = false;
                            }
                        }
                        
                        int max_length = customer_number.length();
                        
                        if (isNumber == true && max_length < 14) {
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
                                char* date_time = ctime(&now);
                                
                                srand(time(0));
                                int reference_number = rand() % 1147483647 + 1000000000;
                                int amount = atoi(nominal.c_str());
                                int admin = 2500;
                                int total = amount + admin;
                                
                                string admin_string = to_string(admin);
                                string total_string = to_string(total);
                                
                                for (int i = admin_string.length() - 3; i > 0; i -= 3) {
                                    admin_string.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = total_string.length() - 3; i > 0; i -= 3) {
                                    total_string.insert(i, ".");
                                }
                                
                                if (saldo >= amount && amount != 0)  {
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m" << endl << endl;
                                    cout << "    -------------------------------------------   " << endl << endl << endl;
                                    cout << "    Date           :   " << date_time;
                                    cout << "    Ref No.        :   " << abs(reference_number) << endl;
                                    cout << "    Customer No.   :   " << customer_number << endl;
                                    cout << "    Bill           :   Rp" << nominal << endl;
                                    cout << "    Admin          :   Rp" << admin_string << endl;
                                    cout << "    Total          :   Rp" << total_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    saldo -= total;
                                    
                                    char repeat;
                                    cout << "Do you want to continue the transaction? (y/n) : ";
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
                        cout << "--------------------------------------------------" << endl << endl << endl;
                        cout << "                \033[1;36mPay Internet Bill\033[0m" << endl << endl << endl;
                        cout << "--------------------------------------------------" << endl << endl;
                        
                        string customer_number;
                        cout << "Please enter customer number : ";
                        cin >> customer_number;
                        
                        bool isNumber = true;
                        for (int i = 0; i < customer_number.length(); i++) {
                            if (!isdigit(customer_number[i])) {
                                isNumber = false;
                            }
                        }
                        
                        int max_length = customer_number.length();
                        
                        if (isNumber == true && max_length < 14) {
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
                                char* date_time = ctime(&now);
                                
                                srand(time(0));
                                int reference_number = rand() % 1147483647 + 1000000000;
                                int amount = atoi(nominal.c_str());
                                int admin = 2500;
                                int total = amount + admin;
                                
                                string admin_string = to_string(admin);
                                string total_string = to_string(total);
                                
                                for (int i = admin_string.length() - 3; i > 0; i -= 3) {
                                    admin_string.insert(i, ".");
                                }
                                
                                for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                    nominal.insert(i, ".");
                                }
                                
                                for (int i = total_string.length() - 3; i > 0; i -= 3) {
                                    total_string.insert(i, ".");
                                }
                                
                                if (saldo >= amount && amount != 0)  {
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m" << endl << endl;
                                    cout << "    -------------------------------------------   " << endl << endl << endl;
                                    cout << "    Date           :   " << date_time;
                                    cout << "    Ref No.        :   " << abs(reference_number) << endl;
                                    cout << "    Customer No.   :   " << customer_number << endl;
                                    cout << "    Bill           :   Rp" << nominal << endl;
                                    cout << "    Admin          :   Rp" << admin_string << endl;
                                    cout << "    Total          :   Rp" << total_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    saldo -= total;
                                    
                                    char repeat;
                                    cout << "Do you want to continue the transaction? (y/n) : ";
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
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "                   \033[1;36mCash Deposit\033[0m" << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
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
                        char* date_time = ctime(&now);
                        
                        srand(time(0));
                        int reference_number = rand() % 1147483647 + 1000000000;
                        
                        for (int i = nominal.length() - 3; i > 0; i -= 3) {
                            nominal.insert(i, ".");
                        }
                        
                        if (amount > 0)  {
                            saldo += amount;
                            
                            system("clear");
                            cout << "--------------------------------------------------" << endl << endl << endl;
                            cout << "              \033[1;32mTransaction Successful\033[0m" << endl << endl;
                            cout << "     ----------------------------------------     " << endl << endl << endl;
                            cout << "     Date       :    " << date_time;
                            cout << "     Ref No.    :    " << abs(reference_number) << endl;
                            cout << "     Amount     :    Rp" << nominal << endl << endl << endl;
                            cout << "--------------------------------------------------" << endl << endl;
                        } else {
                            cout << endl << "\033[1;31mInvalid Nominal!\033[0m" << endl << endl;
                            break;
                        }
                        
                        char repeat;
                        cout << "Do you want to continue the transaction? (y/n) : ";
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
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "                 \033[1;36mCash Withdrawal\033[0m" << endl << endl;
                    cout << "         --------------------------------         " << endl << endl;
                    cout << "         \033[1;32m(1)\033[0m. Rp50.000     \033[1;32m(2)\033[0m. Rp100.000" << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
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
                            char* date_time = ctime(&now);
                            
                            if (amount % 50 == 0) {
                                if (saldo >= amount && saldo != 0)  {
                                    saldo -= amount;
                                    
                                    string saldo_string = to_string(saldo);
                                    
                                    for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                        nominal.insert(i, ".");
                                    }
                                    
                                    for (int i = saldo_string.length() - 3; i > 0; i -= 3) {
                                        saldo_string.insert(i, ".");
                                    }
                                    
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m" << endl << endl;
                                    cout << "     ----------------------------------------     " << endl << endl << endl;
                                    cout << "     Date       :    " << date_time;
                                    cout << "     Amount     :    Rp" << nominal << endl;
                                    cout << "     Balance    :    Rp" << saldo_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    char repeat;
                                    cout << "Do you want to continue the transaction? (y/n) : ";
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
                            char* date_time = ctime(&now);
                            
                            if (amount % 50 == 0) {
                                if (saldo >= amount && saldo != 0)  {
                                    saldo -= amount;
                                    
                                    string saldo_string = to_string(saldo);
                                    
                                    for (int i = nominal.length() - 3; i > 0; i -= 3) {
                                        nominal.insert(i, ".");
                                    }
                                    
                                    for (int i = saldo_string.length() - 3; i > 0; i -= 3) {
                                        saldo_string.insert(i, ".");
                                    }
                                    
                                    system("clear");
                                    cout << "--------------------------------------------------" << endl << endl << endl;
                                    cout << "              \033[1;32mTransaction Successful\033[0m" << endl << endl;
                                    cout << "     ----------------------------------------     " << endl << endl << endl;
                                    cout << "     Date       :    " << date_time;
                                    cout << "     Amount     :    Rp" << nominal << endl;
                                    cout << "     Balance    :    Rp" << saldo_string << endl << endl << endl;
                                    cout << "--------------------------------------------------" << endl << endl;
                                    
                                    char repeat;
                                    cout << "Do you want to continue the transaction? (y/n) : ";
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
                    string saldo_string = to_string(saldo);
                    
                    for (int i = saldo_string.length() - 3; i > 0; i -= 3) {
                        saldo_string.insert(i, ".");
                    }
                    
                    system("clear");
                    cout << "--------------------------------------------------" << endl << endl << endl;
                    cout << "               \033[1;36mYour Account Balance\033[0m" << endl << endl;
                    cout << "              ----------------------              " << endl << endl;
                    cout << "              Balance = Rp" << saldo_string << endl << endl << endl;
                    cout << "--------------------------------------------------" << endl << endl;
                    
                    char repeat;
                    cout << "Do you want to continue the transaction? (y/n) : ";
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