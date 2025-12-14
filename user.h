#include <string>
#include "controller.h"

class User
{
public:
    void ViewJadwal()
    {
        UIController c;
        system("cls");
        c.lesSchedule();
        std::cout << "\n----------------------" << std::endl;
        std::cout << "Tekan tombol Enter untuk kembali...";
        std::cin.ignore();
        std::cin.get();
    }

    void ViewTutor()
    {
        UIController c;
        system("cls");
        c.tutorSchedule();
        std::cout << "\n========================================" << std::endl;
        std::cout << "Tekan tombol Enter untuk kembali...";
        std::cin.ignore();
        std::cin.get();
    }
};