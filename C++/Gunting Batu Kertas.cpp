#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    while (true) {
        system("clear");
        
        cout << "--------------------------------------------------" << endl << endl;
        cout << "         \033[1;36m# PERMAINAN GUNTING BATU KERTAS #\033[0m        " << endl << endl;
        cout << "                    1. Gunting                    " << endl;
        cout << "                    2. Batu                       " << endl;
        cout << "                    3. Kertas                     " << endl;
        cout << "                    \033[1;31m4. Keluar\033[0m                     " << endl << endl;
        cout << "--------------------------------------------------" << endl << endl;
        
        string choices[] = {"Gunting", "Batu", "Kertas"};
        int playerScore, computerScore;
        
        int playerChoices;
        cout << "Silahkan pilih (1, 2, 3) : ";
        cin >> playerChoices;
        
        int computerChoices = rand() % 3;
        
        if (playerChoices == 1) {
            string player = choices[playerChoices - 1];
            string computer = choices[computerChoices];
            if (player == choices[0] && computer == choices[0]) {
                cout << endl << "              Player \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "                -----| \033[1;36mSeri\033[0m |-----" << endl << endl;
            } else if (player == choices[0] && computer == choices[1]) {
                computerScore++;
                cout << endl << "              Player \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "           -----| \033[1;31mComputer menang\033[0m |-----" << endl << endl;
            } else if (player == choices[0] && computer == choices[2]) {
                playerScore++;
                cout << endl << "              Player \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "            -----| \033[1;32mPlayer menang\033[0m |-----" << endl << endl;
            }
        } else if (playerChoices == 2) {
            string player = choices[playerChoices - 1];
            string computer = choices[computerChoices];
            if (player == choices[1] && computer == choices[0]) {
                playerScore++;
                cout << endl << "              Player \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "            -----| \033[1;32mPlayer menang\033[0m |-----" << endl << endl;
            } else if (player == choices[1] && computer == choices[1]) {
                cout << endl << "              Player \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "                -----| \033[1;36mSeri\033[0m |-----" << endl << endl;
            } else if (player == choices[1] && computer == choices[2]) {
                computerScore++;
                cout << endl << "              Player \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "           -----| \033[1;31mComputer menang\033[0m |-----" << endl << endl;
            }
        } else if (playerChoices == 3) {
            string player = choices[playerChoices - 1];
            string computer = choices[computerChoices];
            if (player == choices[2] && computer == choices[0]) {
                computerScore++;
                cout << endl << "              Player \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "           -----| \033[1;31mComputer menang\033[0m |-----" << endl << endl;
            } else if (player == choices[2] && computer == choices[1]) {
                playerScore++;
                cout << endl << "              Player \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "            -----| \033[1;32mPlayer menang\033[0m |-----" << endl << endl;
            } else if (player == choices[2] && computer == choices[2]) {
                cout << endl << "              Player \033[1;33m[" << playerScore << "]\033[0m:\033[1;33m[" << computerScore << "]\033[0m Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "                -----| \033[1;36mSeri\033[0m |-----" << endl << endl;
            }
        } else if (playerChoices == 4) {
            cout << endl;
            break;
        } else {
            cout << endl << "\033[1;31mInvalid Choice!\033[0m" << endl << endl;
            break;
        }
        
        char repeat;
        cout << "Ingin bermain lagi? (\033[1;32my\033[0m/\033[1;31mn\033[0m]) : ";
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