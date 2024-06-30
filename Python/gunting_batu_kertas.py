import os
import random

os.system("clear")

def gunting_batu_kertas():
    player_score = 0
    computer_score = 0
    screen_width = os.get_terminal_size().columns
    choices = ["Gunting", "Batu", "Kertas"]
    menu_choices = ("1. Gunting", "2. Batu", "3. Kertas", "4. Keluar")
    max_length = max(len(choice) for choice in menu_choices)
    
    while True:
        print("-" * screen_width)
        print(f"{'PERMAINAN GUNTING BATU KERTAS':^{screen_width}}\n")
        for choice in menu_choices:
            print(f"{choice:^{screen_width - max_length + len(choice)}}")
        print("\n" + "-" * screen_width)
        
        player_choices = int(input("\nSilahkan pilih (1, 2, 3, 4) : "))
        computer_choices = random.choice(choices)
        
        if player_choices == 1:
            player_choices = choices[0]
            if player_choices == choices[0] and computer_choices == choices[0]:
                print(f"\n\t      Player [{player_score}]:[{computer_score}] Computer")
                print(f"\n\tPlayer {'-->':^20} {player_choices}")
                print(f"\tComputer {'-->':^20} {computer_choices}")
                print(f"\n{'-----| Seri |-----':^{screen_width}}")
            elif player_choices == choices[0] and computer_choices == choices[1]:
                computer_score += 1
                print(f"\n\t      Player [{player_score}]:[{computer_score}] Computer")
                print(f"\n\tPlayer {'-->':^20} {player_choices}")
                print(f"\tComputer {'-->':^20} {computer_choices}")
                print(f"\n{'-----| Computer menang |-----':^{screen_width}}")
            elif player_choices == choices[0] and computer_choices == choices[2]:
                player_score += 1
                print(f"\n\t      Player [{player_score}]:[{computer_score}] Computer")
                print(f"\n\tPlayer {'-->':^20} {player_choices}")
                print(f"\tComputer {'-->':^20} {computer_choices}")
                print(f"\n{'-----| Player menang |-----':^{screen_width}}")
                
        elif player_choices == 2:
            player_choices = choices[1]
            if player_choices == choices[1] and computer_choices == choices[0]:
                player_score += 1
                print(f"\n\t      Player [{player_score}]:[{computer_score}] Computer")
                print(f"\n\tPlayer {'-->':^20} {player_choices}")
                print(f"\tComputer {'-->':^20} {computer_choices}")
                print(f"\n{'-----| Player menang |-----':^{screen_width}}")
            elif player_choices == choices[1] and computer_choices == choices[1]:
                print(f"\n\t      Player [{player_score}]:[{computer_score}] Computer")
                print(f"\n\tPlayer {'-->':^20} {player_choices}")
                print(f"\tComputer {'-->':^20} {computer_choices}")
                print(f"\n{'-----| Seri |-----':^{screen_width}}")
            elif player_choices == choices[1] and computer_choices == choices[2]:
                computer_score += 1
                print(f"\n\t      Player [{player_score}]:[{computer_score}] Computer")
                print(f"\n\tPlayer {'-->':^20} {player_choices}")
                print(f"\tComputer {'-->':^20} {computer_choices}")
                print(f"\n{'-----| Computer menang |-----':^{screen_width}}")
                
        elif player_choices == 3:
            player_choices = choices[2]
            if player_choices == choices[2] and computer_choices == choices[0]:
                computer_score += 1
                print(f"\n\t      Player [{player_score}]:[{computer_score}] Computer")
                print(f"\n\tPlayer {'-->':^20} {player_choices}")
                print(f"\tComputer {'-->':^20} {computer_choices}")
                print(f"\n{'-----| Computer menang |-----':^{screen_width}}")
            elif player_choices == choices[2] and computer_choices == choices[1]:
                player_score += 1
                print(f"\n\t      Player [{player_score}]:[{computer_score}] Computer")
                print(f"\n\tPlayer {'-->':^20} {player_choices}")
                print(f"\tComputer {'-->':^20} {computer_choices}")
                print(f"\n{'-----| Player menang |-----':^{screen_width}}")
            elif player_choices == choices[2] and computer_choices == choices[2]:
                print(f"\n\t      Player [{player_score}]:[{computer_score}] Computer")
                print(f"\n\tPlayer {'-->':^20} {player_choices}")
                print(f"\tComputer {'-->':^20} {computer_choices}")
                print(f"\n{'-----| Seri |-----':^{screen_width}}")
        
        elif player_choices == 4:
            print("")
            break
        else:
            print("\nPilihan yang tersedia hanya (1, 2, 3, dan 4)")
        
        repeat = input("\nIngin bermain lagi? (y/n) : ")
        
        if repeat.lower() == 'y':
            os.system("clear")
        elif repeat.lower() == 'n':
            print("")
            break
        else:
            print("\nInvalid Input!\n")
            break

if __name__ == "__main__":
    gunting_batu_kertas()