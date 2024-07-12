#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    while (true) {
        system("clear");
        
        cout << "--------------------------------------------------" << endl;
        cout << "          PERMAINAN GUNTING BATU KERTAS           " << endl << endl;
        cout << "                    1. Gunting                    " << endl;
        cout << "                    2. Batu                       " << endl;
        cout << "                    3. Kertas                     " << endl;
        cout << "                    \033[1;31m4. Keluar\033[0m                     " << endl << endl;
        cout << "--------------------------------------------------" << endl << endl;
        
        string choices[] = {"Gunting", "Batu", "Kertas"};
        int playerScore, computerScore;
        
        int playerChoices;
        cout << "Silahkan pilih (1, 2, 3, 4) : ";
        cin >> playerChoices;
        
        int computerChoices = rand() % 3; // range 0 to 2
        
        if (playerChoices == 1) {
            string player = choices[playerChoices - 1];
            string computer = choices[computerChoices];
            if (player == choices[0] && computer == choices[0]) {
                cout << endl << "              Player [" << playerScore << "]:[" << computerScore << "] Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "                -----| Seri |-----" << endl << endl;
            } else if (player == choices[0] && computer == choices[1]) {
                computerScore++;
                cout << endl << "              Player [" << playerScore << "]:[" << computerScore << "] Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "           -----| Computer menang |-----" << endl << endl;
            } else if (player == choices[0] && computer == choices[2]) {
                playerScore++;
                cout << endl << "              Player [" << playerScore << "]:[" << computerScore << "] Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "            -----| Player menang |-----" << endl << endl;
            }
        } else if (playerChoices == 2) {
            string player = choices[playerChoices - 1];
            string computer = choices[computerChoices];
            if (player == choices[1] && computer == choices[0]) {
                playerScore++;
                cout << endl << "              Player [" << playerScore << "]:[" << computerScore << "] Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "            -----| Player menang |-----" << endl << endl;
            } else if (player == choices[1] && computer == choices[1]) {
                cout << endl << "              Player [" << playerScore << "]:[" << computerScore << "] Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "                -----| Seri |-----" << endl << endl;
            } else if (player == choices[1] && computer == choices[2]) {
                computerScore++;
                cout << endl << "              Player [" << playerScore << "]:[" << computerScore << "] Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "           -----| Computer menang |-----" << endl << endl;
            }
        } else if (playerChoices == 3) {
            string player = choices[playerChoices - 1];
            string computer = choices[computerChoices];
            if (player == choices[2] && computer == choices[0]) {
                computerScore++;
                cout << endl << "              Player [" << playerScore << "]:[" << computerScore << "] Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "           -----| Computer menang |-----" << endl << endl;
            } else if (player == choices[2] && computer == choices[1]) {
                playerScore++;
                cout << endl << "              Player [" << playerScore << "]:[" << computerScore << "] Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "            -----| Player menang |-----" << endl << endl;
            } else if (player == choices[2] && computer == choices[2]) {
                cout << endl << "              Player [" << playerScore << "]:[" << computerScore << "] Computer" << endl << endl;
                cout << "        Player         -->          " << player << endl;
                cout << "      Computer         -->          " << computer << endl << endl;
                cout << "                -----| Seri |-----" << endl << endl;
            }
        } else if (playerChoices == 4) {
            cout << endl;
            break;
        } else {
            cout << endl << "Invalid Input!" << endl;
            break;
        }
        
        char repeat;
        cout << "Ingin bermain lagi? (y/n) : ";
        cin >> repeat;
        
        if (repeat == 'y') {
            // pass
        } else if (repeat == 'n') {
            cout << endl;
            break;
        } else {
            cout << endl << "Invalid Input!" << endl;
            break;
        }
    }
    
    return 0;
}