import os
import random

os.system("clear")

def tebak_angka():
    while True:
        random_number = random.randint(1, 3)
        user_number = int(input("\n\tSilahkan tebak angka antara 1-3 : "))
        
        if user_number > 0 and user_number < 4:
            if user_number == random_number:
                print("\n\tSelamat anda berhasil menebaknya :D")
            else:
                print("\n\tSayang sekali anda gagal menebaknya :(")
                print(f"\n\tAngka yang benar adalah --> {random_number}")
        else:
            print("\n\tTolong tebak angka antara 1-5!")
            
        print("\n\t" + "-" * 35)
        repeat = input("\n\tIngin bermain lagi? (y/n) : ")
        
        if repeat.lower() == 'y':
            os.system("clear")
        elif repeat.lower() == 'n':
            print("")
            break
        else:
            print("\n\tInvalid Input!\n")
            break
        
if __name__ == "__main__":
    tebak_angka()