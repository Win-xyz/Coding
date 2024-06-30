print("\t" + "======= | Konversi Suhu | =======")
print("\t\t" + "1. Celcius")
print("\t\t" + "2. Fahrenheit")
print("\t\t" + "3. Reamur")
print("\t\t" + "4. Kelvin")
print("\t" + "=================================")

while True:
    jenis_awal = int(input("\n\t" + "Pilih Jenis Suhu (1, 2, 3, 4) = "))
    
    if jenis_awal == 1:
        jumlah_suhu = float(input("\n\t" + "Masukkan Jumlah Suhu = "))
        jenis_akhir = int(input("\n\t" + "Konversi Ke (1, 2, 3, 4) = "))
        if jenis_akhir == 2:
            hasil_konversi = jumlah_suhu * (9/5) + 32
            print("\n\t" + str(jumlah_suhu) + "°C" + " = " + str(hasil_konversi) + "°F")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        elif jenis_akhir == 3:
            hasil_konversi = jumlah_suhu * (4/5)
            print("\n\t" + str(jumlah_suhu) + "°C" + " = " + str(hasil_konversi) + "°R")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        elif jenis_akhir == 4:
            hasil_konversi = jumlah_suhu + 273.15
            print("\n\t" + str(jumlah_suhu) + "°C" + " = " + str(hasil_konversi) + "K")
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        else:
            print("\n\t" + "Invalid Input!!!")
    elif jenis_awal == 2:
        jumlah_suhu = float(input("\n\t" + "Masukkan Jumlah Suhu = "))
        jenis_akhir = int(input("\n\t" + "Konversi Ke (1, 2, 3, 4) = "))
        if jenis_akhir == 1:
            hasil_konversi = (jumlah_suhu - 32) * (5/9)
            print("\n\t" + str(jumlah_suhu) + "°F" + " = " + str(hasil_konversi) + "°C")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        elif jenis_akhir == 3:
            hasil_konversi = (jumlah_suhu - 32) * (4/9)
            print("\n\t" + str(jumlah_suhu) + "°F" + " = " + str(hasil_konversi) + "°R")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        elif jenis_akhir == 4:
            hasil_konversi = (jumlah_suhu - 32) * (5/9) + 273.15
            print("\n\t" + str(jumlah_suhu) + "°F" + " = " + str(hasil_konversi) + "K")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        else:
            print("\n\t" + "Invalid Input!!!")
    elif jenis_awal == 3:
        jumlah_suhu = float(input("\n\t" + "Masukkan Jumlah Suhu = "))
        jenis_akhir = int(input("\n\t" + "Konversi Ke (1, 2, 3, 4) = "))
        if jenis_akhir == 1:
            hasil_konversi = jumlah_suhu * (5/4)
            print("\n\t" + str(jumlah_suhu) + "°R" + " = " + str(hasil_konversi) + "°C")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        elif jenis_akhir == 2:
            hasil_konversi = jumlah_suhu * (9/4) + 32
            print("\n\t" + str(jumlah_suhu) + "°R" + " = " + str(hasil_konversi) + "°F")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        elif jenis_akhir == 4:
            hasil_konversi = jumlah_suhu * (5/4) + 273.15
            print("\n\t" + str(jumlah_suhu) + "°R" + " = " + str(hasil_konversi) + "K")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        else:
            print("\n\t" + "Invalid Input!!!")
    elif jenis_awal == 4:
        jumlah_suhu = float(input("\n\t" + "Masukkan Jumlah Suhu = "))
        jenis_akhir = int(input("\n\t" + "Konversi Ke (1, 2, 3, 4) = "))
        if jenis_akhir == 1:
            hasil_konversi = jumlah_suhu - 273.15
            print("\n\t" + str(jumlah_suhu) + "K" + " = " + str(hasil_konversi) + "°C")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        elif jenis_akhir == 2:
            hasil_konversi = (jumlah_suhu - 273.15) * (9/5) + 32
            print("\n\t" + str(jumlah_suhu) + "K" + " = " + str(hasil_konversi) + "°F")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        elif jenis_akhir == 3:
            hasil_konversi = (jumlah_suhu - 273.15) * (4/5)
            print("\n\t" + str(jumlah_suhu) + "K" + " = " + str(hasil_konversi) + "°R")
            
            ulangi = input("\n\tIngin Mengulangi Kembali? (y/n) = ")
            if ulangi == "y":
                pass
            elif ulangi == "n":
                break
            else:
                print("\n\tInvalid Input!!!")
                break
        else:
            print("\n\t" + "Invalid Input!!!")
            break
    else:
        print("\n\t" + "Invalid Input!!!")
        break