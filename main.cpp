#include <iostream>
#include "admin.h"

using namespace std;

int main() {
    const int JADWAL = 1;
    const int TUTOR = 2;
    const int DAFTAR_KELAS = 3;
    const int LOGIN = 4;
    const int KELUAR = 99;

    UIController c;
    User user;
    Admin admin;
    LoginInfo loginInfo;
    ValidationResult result;
    StudentValidationResult svr = StudentValidationResult{false, Student("", "", "", "")};
    
    std::string NISN;
    bool shouldExit = false;

    while (true) {
        if (shouldExit) {
            break;
        }

        int choice = c.getUserInput();
        
        switch (choice) {
        case KELUAR:
            cout << "\nTerima kasih telah memilih PINTEN Spesialis UTBK sebagai teman belajar Anda!" << endl;
            shouldExit = true;
            break;
            
        case JADWAL:
            user.ViewJadwal();
            break;
            
        case TUTOR:
            user.ViewTutor();
            break;
            
        case DAFTAR_KELAS:
            system("cls");
            c.tutorSchedule();
            std::cout << "\n========================================" << std::endl;
            std::cout << "Masukkan NISN Anda: ";
            std::cin >> NISN;
            
            svr = validateNISN(NISN);
            
            if(!svr.isValid){
                std::cout << "\nMaaf, NISN tidak terdaftar dalam sistem." << std::endl;
                std::cout << "Silakan hubungi admin untuk pendaftaran." << std::endl;
                cout << "\n========================================" << endl;
                cout << "Tekan tombol Enter untuk kembali...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            
            int subjectId;
            std::cout << "\n========================================" << std::endl;
            std::cout << "Halo, " << svr.student.getName() << "!" << std::endl;
            std::cout << "Pilih mata pelajaran [1-4]: ";
            cin >> subjectId;
            
            if(subjectId < 1 || subjectId > 4){
                std::cout << "Pilihan tidak valid!" << std::endl;
                cout << "\n========================================" << endl;
                cout << "Tekan tombol Enter untuk kembali...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            
            svr.student.registerClass(subjectId);
            cout << "\nPendaftaran kelas berhasil!" << endl;
            cout << "Mata Pelajaran: " << tutorList[subjectId-1].subject << endl;
            cout << "Tutor: " << tutorList[subjectId-1].name << endl;
            cout << "\n========================================" << endl;
            cout << "Tekan tombol Enter untuk kembali...";
            std::cin.ignore();
            std::cin.get();
            break;
            
        case LOGIN:
            loginInfo = c.getLoginInput();
            result = validateLogin(loginInfo);
            
            if (!result.isSuccess) {
                cout << "\n========================================" << endl;
                cout << "Tekan tombol Enter untuk kembali...";
                cin.ignore();
                cin.get();
                break;
            }
            
            UIAdmin(&result.admin);
            break;
            
        default:
            cout << "Pilihan yang Anda masukkan salah!" << endl;
            break;
        }
    }

    return 0;
}
