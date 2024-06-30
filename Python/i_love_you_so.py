import os
import sys
from time import sleep

os.system("clear")

def i_love_you_so():
    song_lyrics = [
        ("I'm gonna pack my things", 0.1, 0.8, "yellow"),
        ("and leave you behind", 0.1, 0.6, "yellow"),
        ("this feeling's old and I know", 0.095, 0.9, "yellow"),
        ("that I've made up my mind", 0.09, 0.5, "yellow"),
        ("I hope you feel what I felt", 0.1, 0.7, "yellow"),
        ("when you shattered my soul", 0.09, 0.5, "yellow"),
        ("'cause you were cruel", 0.075, 0.34, "yellow"),
        ("and I'm a fool", 0.08, 0.7, "yellow"),
        ("so, please let me go", 0.1, 2.3, "red"),
        ("but I love you so", 0.13, 1.5, "yellow"),
        ("please let me go", 0.13, 0.7, "red"),
        ("I love you so", 0.15, 1.5, "yellow"),
        ("please let me go", 0.13, 0.8, "red"),
        ("I love you so", 0.15, 1.6, "yellow"),
        ("please let me go", 0.13, 0.8, "red"),
        ("I LOVE YOU SO ♡.", 0.14, 3.4, "yellow")
    ]
    
    print(f"{'The Walters - I Love You So':^50}\n\n")
    
    for lyrics, char_delay, line_delay, color in song_lyrics:
        if color == "yellow":
            print("\033[1;33m", end="")
        
        if color == "red":
            print("\033[1;31m", end="")
        
        for char in lyrics:
            print(char, end="")
            sys.stdout.flush()
            sleep(char_delay)
            
        if color == "red":
            print("\033[39m", end="")
            
        if color == "yellow":
            print("\033[39m", end="")
            
        sleep(line_delay)
        print("")
    print("")

if __name__ == "__main__":
    i_love_you_so()