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
    
    int screenWidth = getTerminalWidth();
    int playerScore = 0;
    int computerScore = 0;
    
    while (true) {
        system("clear");
        
        cout << string(screenWidth, '-') << endl << endl;
        cout << string((screenWidth - 33) / 2, ' ') << "\033[1;36m# PERMAINAN GUNTING BATU KERTAS #\033[0m" << endl << endl;
        cout << string((screenWidth - 38) / 2, ' ') << "--------------------------------------" << endl << endl << endl;
        cout << string((screenWidth - 38) / 2, ' ') << "\033[1;32m(1)\033[0m. Gunting   \033[1;32m(2)\033[0m. Batu   \033[1;32m(3)\033[0m. Kertas" << endl << endl << endl;
        cout << string((screenWidth - 11) / 2, ' ') << "\033[1;31m(4)\033[0m. Keluar" << endl << endl;
        cout << string(screenWidth, '-') << endl << endl;
        
        string choices[] = {"Gunting", "Batu", "Kertas"};
        
        int playerChoices;
        cout << "Silahkan pilih (1, 2, 3) : ";
        cin >> playerChoices;
        
        int computerChoices = rand() % 3;
        
        if (playerChoices == 1) {
            string player = choices[playerChoices - 1];
            string computer = choices[computerChoices];
            if (player == choices[0] && computer == choices[0]) {
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 5) / 2, ' ') << "\033[1;33mSCORE\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m|\033[0m Player   \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m  Computer \033[1;33m|\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;36mPlayer\033[0m           -->          " << player << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31mComputer\033[0m         -->          " << computer << endl << endl << endl;
                cout << string((screenWidth - 18) / 2, ' ') << "-----| \033[1;36mSeri\033[0m |-----" << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
            } else if (player == choices[0] && computer == choices[1]) {
                computerScore++;
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 5) / 2, ' ') << "\033[1;33mSCORE\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m|\033[0m Player   \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m  Computer \033[1;33m|\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;36mPlayer\033[0m           -->          " << player << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31mComputer\033[0m         -->          " << computer << endl << endl << endl;
                cout << string((screenWidth - 29) / 2, ' ') << "-----| \033[1;31mComputer menang\033[0m |-----" << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
            } else if (player == choices[0] && computer == choices[2]) {
                playerScore++;
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 5) / 2, ' ') << "\033[1;33mSCORE\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m|\033[0m Player   \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m  Computer \033[1;33m|\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;36mPlayer\033[0m           -->          " << player << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31mComputer\033[0m         -->          " << computer << endl << endl << endl;
                cout << string((screenWidth - 27) / 2, ' ') << "-----| \033[1;32mPlayer menang\033[0m |-----" << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
            }
        } else if (playerChoices == 2) {
            string player = choices[playerChoices - 1];
            string computer = choices[computerChoices];
            if (player == choices[1] && computer == choices[0]) {
                playerScore++;
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 5) / 2, ' ') << "\033[1;33mSCORE\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m|\033[0m Player   \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m  Computer \033[1;33m|\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;36mPlayer\033[0m           -->          " << player << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31mComputer\033[0m         -->          " << computer << endl << endl << endl;
                cout << string((screenWidth - 27) / 2, ' ') << "-----| \033[1;32mPlayer menang\033[0m |-----" << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
            } else if (player == choices[1] && computer == choices[1]) {
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 5) / 2, ' ') << "\033[1;33mSCORE\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m|\033[0m Player   \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m  Computer \033[1;33m|\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;36mPlayer\033[0m           -->          " << player << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31mComputer\033[0m         -->          " << computer << endl << endl << endl;
                cout << string((screenWidth - 18) / 2, ' ') << "-----| \033[1;36mSeri\033[0m |-----" << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
            } else if (player == choices[1] && computer == choices[2]) {
                computerScore++;
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 5) / 2, ' ') << "\033[1;33mSCORE\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m|\033[0m Player   \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m  Computer \033[1;33m|\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;36mPlayer\033[0m           -->          " << player << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31mComputer\033[0m         -->          " << computer << endl << endl << endl;
                cout << string((screenWidth - 29) / 2, ' ') << "-----| \033[1;31mComputer menang\033[0m |-----" << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
            }
        } else if (playerChoices == 3) {
            string player = choices[playerChoices - 1];
            string computer = choices[computerChoices];
            if (player == choices[2] && computer == choices[0]) {
                computerScore++;
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 5) / 2, ' ') << "\033[1;33mSCORE\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m|\033[0m Player   \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m  Computer \033[1;33m|\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;36mPlayer\033[0m           -->          " << player << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31mComputer\033[0m         -->          " << computer << endl << endl << endl;
                cout << string((screenWidth - 29) / 2, ' ') << "-----| \033[1;31mComputer menang\033[0m |-----" << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
            } else if (player == choices[2] && computer == choices[1]) {
                playerScore++;
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 5) / 2, ' ') << "\033[1;33mSCORE\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m|\033[0m Player   \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m  Computer \033[1;33m|\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;36mPlayer\033[0m           -->          " << player << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31mComputer\033[0m         -->          " << computer << endl << endl << endl;
                cout << string((screenWidth - 27) / 2, ' ') << "-----| \033[1;32mPlayer menang\033[0m |-----" << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
            } else if (player == choices[2] && computer == choices[2]) {
                system("clear");
                cout << string(screenWidth, '-') << endl << endl;
                cout << string((screenWidth - 5) / 2, ' ') << "\033[1;33mSCORE\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m|\033[0m Player   \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m  Computer \033[1;33m|\033[0m" << endl;
                cout << string((screenWidth - 30) / 2, ' ') << "\033[1;33m+----------------------------+\033[0m" << endl << endl << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;36mPlayer\033[0m           -->          " << player << endl;
                cout << string((screenWidth - 37) / 2, ' ') << "\033[1;31mComputer\033[0m         -->          " << computer << endl << endl << endl;
                cout << string((screenWidth - 18) / 2, ' ') << "-----| \033[1;36mSeri\033[0m |-----" << endl << endl;
                cout << string(screenWidth, '-') << endl << endl;
            }
        } else if (playerChoices == 4) {
            cout << endl;
            break;
        } else {
            cout << endl << "\033[1;31mInvalid Choice!\033[0m" << endl << endl;
            break;
        }
        
        char repeat;
        cout << "Ingin bermain lagi? (\033[1;32my\033[0m/\033[1;31mn\033[0m) : ";
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