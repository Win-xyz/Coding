import os
from time import sleep

os.system("clear")

def kontak():
    all_contacts = [
        "Ahmad Daniel", "Aisyah Echa", "Bang Fadli",
        "Bang Misba", "Bu Ismirawaty", "Cikila",
        "Denil", "Fendi", "Ghaida Basyra",
        "Hafis Khalik", "Herwind", "Ismansyah",
        "Jumisrang", "Kak Titi", "Mukhlisah",
        "Nida", "Putri", "Rasman",
        "Selvi Febrianti", "Ummul Qurnia", "Yusniar"
    ]
    all_contacts.sort()
    
    screen_width = os.get_terminal_size().columns
    
    while True:
        print("-" * screen_width)
        print(f"{'KONTAK':^{screen_width}}\n")
        print(f"{'1. Cek kontak   ':^{screen_width}}")
        print(f"{'2. Tambah kontak':^{screen_width}}")
        print(f"{'3. Hapus kontak ':^{screen_width}}")
        print(f"{'4. Cari kontak  ':^{screen_width}}")
        print(f"{'5. Keluar       ':^{screen_width}}")
        print("\n" + "-" * screen_width + "\n")
        
        user_choice = int(input("Silahkan pilih (1, 2, 3, 4, 5) : "))
        
        if user_choice == 1:
            os.system("clear")
            print("-" * screen_width)
            print(f"{'DAFTAR KONTAK':^{screen_width}}\n")
            for order, contact in enumerate(all_contacts, start = 1):
                print(f"{order}. {contact}")
            print("\n" + "-" * screen_width)
            
        elif user_choice == 2:
            new_contact = input("\nMasukkan nama kontak : ").strip()
            print("\nMenambahkan kontak baru...", end="")
            sleep(2)
            all_contacts.append(new_contact)
            print(f"\n\nKontak '{new_contact}' berhasil ditambahkan.")
            
        elif user_choice == 3:
            os.system("clear")
            print("-" * screen_width)
            print(f"{'HAPUS KONTAK':^{screen_width}}\n")
            for order, contact in enumerate(all_contacts, start = 1):
                print(f"{order}. {contact}")
            print("\n" + "-" * screen_width)
            
            delete_contact = input("\nMasukkan nomor urut atau nama kontak : ").strip()
            
            if delete_contact.isdigit():
                if int(delete_contact) > len(all_contacts):
                    print("\nKontak tidak ditemukan!")
                else:
                    contact = all_contacts[int(delete_contact) - 1]
                    if contact in all_contacts:
                        print("\nMenghapus kontak...", end="")
                        sleep(2)
                        all_contacts.remove(contact)
                        print(f"\n\nKontak '{contact}' berhasil dihapus.")
            else:
                if delete_contact in all_contacts:
                    print("\nMenghapus kontak...", end="")
                    sleep(2)
                    all_contacts.remove(delete_contact)
                    print(f"\n\nKontak '{delete_contact}' berhasil dihapus.")
                else:
                    print("\nKontak tidak ditemukan!")
            
        elif user_choice == 4:
            os.system("clear")
            print("-" * screen_width)
            print(f"{'CARI KONTAK':^{screen_width}}\n")
            for order, contact in enumerate(all_contacts, start = 1):
                print(f"{order}. {contact}")
            print("\n" + "-" * screen_width)
            search_contact = input("\nMasukkan nama kontak : ").strip()
            if search_contact in all_contacts:
                print(f"\nKontak yang dicari ditemukan pada urutan ke-{all_contacts.index(search_contact) + 1} dalam daftar kontak.")
            else:
                print("\nKontak yang dicari tidak ditemukan dalam daftar kontak.")
                
        elif user_choice == 5:
            print("")
            break
        else:
            print("\nInvalid Input!\n")
            break
        
        repeat = input("\nIngin melanjutkan? (y/n) : ")
        
        if repeat.lower() == 'y':
            os.system("clear")
        elif repeat.lower() == 'n':
            print("")
            break
        else:
            print("\nInvalid Input!\n")
            break
        
if __name__ == "__main__":
    kontak()