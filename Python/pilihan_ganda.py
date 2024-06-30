nilai = 0

def soal_1():
    global nilai
    print("\n\n    1. Siapakah penemu bola lampu?")
    print("\tA. Nikola Tesla")
    print("\tB. Thomas Edison")
    print("\tC. John Logie Baird")
    print("\tD. Martin Cooper")
    jawaban = 'B'
    user_answer = input("\n\tJawaban anda (A, B, C, D) = ")
    if user_answer == jawaban:
        nilai += 20
        soal_2()
    else:
        soal_2()
    
def soal_2():
    global nilai
    print("\n\n    2. Apa nama planet ke-6 dalam tata surya?")
    print("\tA. Venus")
    print("\tB. Neptunus")
    print("\tC. Uranus")
    print("\tD. Saturnus")
    jawaban = 'D'
    user_answer = input("\n\tJawaban anda (A, B, C, D) = ")
    if user_answer == jawaban:
        nilai += 20
        soal_3()
    else:
        soal_3()
        
def soal_3():
    global nilai
    print("\n\n    3. Berasal dari negara manakah mata uang bath?")
    print("\tA. Vietnam")
    print("\tB. Thailand")
    print("\tC. Filipina")
    print("\tD. Kamboja")
    jawaban = 'B'
    user_answer = input("\n\tJawaban anda (A, B, C, D) = ")
    if user_answer == jawaban:
        nilai += 20
        soal_4()
    else:
        soal_4()
    
def soal_4():
    global nilai
    print("\n\n    4. Arah jam 9 sama dengan arah?")
    print("\tA. Utara")
    print("\tB. Timur")
    print("\tC. Selatan")
    print("\tD. Barat")
    jawaban = 'D'
    user_answer = input("\n\tJawaban anda (A, B, C, D) = ")
    if user_answer == jawaban:
        nilai += 20
        soal_5()
    else:
        soal_5()
    
def soal_5():
    global nilai
    print("\n\n    5. Apa nama samudera terbesar di dunia?")
    print("\tA. Pasifik")
    print("\tB. Hindia")
    print("\tC. Antartika")
    print("\tD. Atlantik")
    jawaban = 'A'
    user_answer = input("\n\tJawaban anda (A, B, C, D) = ")
    if user_answer == jawaban:
        nilai += 20

print("\n\t----------- PILIHAN GANDA -----------")
print("\nPilihlah jawaban yang benar diantara A, B, C, dan D")

while True:
    user_ready = input("\n\n\tApakah anda ingin memulai? (y/n) = ")
    if user_ready == 'y':
        soal_1()
        view_results = input("\n\n    Ketik \"y\" jika anda ingin melihat nilai anda (y/n) = ")
        if view_results == 'y':
            print(f"\n\t# Nilai anda = {nilai} #")
        elif view_results == 'n':
            break
        else:
            print("\n\tInvalid Input!!!")
            break
    elif user_ready == 'n':
        break
    else:
        print("\n\tInvalid Input!!!")
        break