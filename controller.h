#include <iostream>

struct LoginInfo
{
    std::string username;
    std::string password;
};

struct Tutor{
    std::string name;
    std::string subject;
    std::string schedule;
};

Tutor tutorList[4] = {
    {"Godric Gryffindor", "Matematika", "Senin & Kamis, 16.00-18.00"},
    {"Helga Hufflepuff", "Literasi Bahasa Indonesia", "Selasa & Jumat, 16.00-18.00"},
    {"Rowena Ravenclaw", "Literasi Bahasa Inggris", "Rabu & Sabtu, 16.00-18.00"},
    {"Salazar Slytherin", "Penalaran Umum", "Kamis & Minggu, 14.00-16.00"}
};

class UIController
{
public:
    void lesSchedule()
    {
        std::cout << "Jadwal Les" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "Senin    | 14.00 - 20.00" << std::endl;
        std::cout << "Selasa   | 14.00 - 20.00" << std::endl;
        std::cout << "Rabu     | 14.00 - 20.00" << std::endl;
        std::cout << "Kamis    | 14.00 - 20.00" << std::endl;
        std::cout << "Jumat    | 14.00 - 20.00" << std::endl;
        std::cout << "Sabtu    | 09.00 - 17.00" << std::endl;
        std::cout << "Minggu   | 09.00 - 17.00" << std::endl;
    }

    void tutorSchedule()
    {
        std::cout << "Jadwal Tutor & Mata Pelajaran" << std::endl;
        std::cout << "========================================" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << (i+1) << ". " << tutorList[i].subject << std::endl;
            std::cout << "   Tutor: " << tutorList[i].name << std::endl;
            std::cout << "   Jadwal: " << tutorList[i].schedule << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    }

    int getUserInput()
    {
        int choice;
        system("cls");
        std::cout << "=== PINTEN Spesialis UTBK ===" << std::endl;
        std::cout << "Pilih menu:" << std::endl;
        std::cout << "1. Lihat jadwal operasional" << std::endl;
        std::cout << "2. Lihat jadwal tutor" << std::endl;
        std::cout << "3. Daftar kelas" << std::endl;
        std::cout << "4. Login admin" << std::endl;
        std::cout << "99. Keluar" << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << "Masukkan pilihan: ";
        std::cin >> choice;
        return choice;
    }

    LoginInfo getLoginInput()
    {
        system("cls");
        std::string name, password;
        std::cout << "=== LOGIN ADMIN ===" << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "Username: ";
        std::cin >> name;
        std::cout << "Password: ";
        std::cin >> password;
        return LoginInfo{name, password};
    }

    int getAdminInput()
    {
        int choice;
        system("cls");
        std::cout << "=== MENU ADMIN ===" << std::endl;
        std::cout << "1. View Students" << std::endl;
        std::cout << "2. View Class Registrations" << std::endl;
        std::cout << "3. Register New Student" << std::endl;
        std::cout << "4. Extend Student Registration" << std::endl;
        std::cout << "5. Remove Student" << std::endl;
        std::cout << "6. Logout" << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "Masukkan Pilihan: ";
        std::cin >> choice;
        return choice;
    }
};

