#include <fstream>
#include <string>
#include "student.h"

class Admin : public User
{
private:
    std::string name;
    std::string password;

public:
    Admin() {}
    Admin(std::string _name, std::string _password)
    {
        Admin::name = _name;
        Admin::password = _password;
    }

    std::string getName() { return Admin::name; }
    std::string getPassword() { return Admin::password; }

    void RegisterStudent(Student *student)
    {
        system("cls");
        std::ofstream studentOut;
        studentOut.open("students.csv", std::ios::app);
        studentOut << student->getNISN() << ",";
        studentOut << student->getName() << ",";
        studentOut << student->getRegistrationDate() << ",";
        studentOut << student->getExpiryDate() << ",";
        studentOut << std::endl;
        studentOut.close();
    }

    void ExtendRegistration()
    {
        system("cls");
        std::ofstream tempOut;
        std::fstream file("students.csv");
        
        if (!file.is_open())
        {
            std::cerr << "Error membuka file" << std::endl;
            return;
        }

        int selectedIndex;
        std::string line;
        int studentIndex = 1;
        
        std::cout << "INDEX | NAMA SISWA | TANGGAL EXPIRED" << std::endl;
        std::cout << "------|------------|------------------" << std::endl;
        
        while (getline(file, line))
        {
            std::string data[4];
            std::string buff;
            int dataPos = 0;
            
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ',')
                {
                    data[dataPos] = buff;
                    dataPos++;
                    buff = "";
                    continue;
                }
                buff += line[i];
            }
            
            std::cout << "[" << studentIndex << "] ";
            std::cout << data[1] << " | ";
            std::cout << data[3];
            std::cout << "\n======\n";
            studentIndex++;
        }
        
        std::string updatedExpiryDate;
        std::cout << "Masukkan index siswa: ";
        std::cin >> selectedIndex;
        std::cout << "Tanggal expired baru [YYYY/MM/DD]: ";
        std::cin >> updatedExpiryDate;

        tempOut.open("temp.csv", std::ios::app);
        studentIndex = 1;
        std::ifstream file2temp("students.csv");
        
        if (!file2temp.is_open())
        {
            std::cerr << "Error membuka file" << std::endl;
            return;
        }
        
        while (getline(file2temp, line))
        {
            std::string data[4];
            std::string buff;
            int dataPos = 0;
            
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ',')
                {
                    data[dataPos] = buff;
                    dataPos++;
                    buff = "";
                    continue;
                }
                buff += line[i];
            }
            
            tempOut << data[0] << ",";
            tempOut << data[1] << ",";
            tempOut << data[2] << ",";
            
            if(studentIndex == selectedIndex){
                tempOut << updatedExpiryDate << ",";
            }
            else {
                tempOut << data[3] << ",";
            }
            
            tempOut << std::endl;
            studentIndex++;
        }
        
        tempOut.close();
        file.close();
        file2temp.close();
        remove("students.csv");
        rename("temp.csv", "students.csv");
    }

    void RemoveStudent()
    {
        system("cls");
        std::ofstream tempOut;
        std::fstream file("students.csv");
        
        if (!file.is_open())
        {
            std::cerr << "Error membuka file" << std::endl;
            return;
        }

        int selectedIndex;
        std::string line;
        int studentIndex = 1;
        
        std::cout << "INDEX | NAMA SISWA | NISN" << std::endl;
        std::cout << "------|------------|-------------" << std::endl;
        
        while (getline(file, line))
        {
            std::string data[4];
            std::string buff;
            int dataPos = 0;
            
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ',')
                {
                    data[dataPos] = buff;
                    dataPos++;
                    buff = "";
                    continue;
                }
                buff += line[i];
            }
            
            std::cout << "[" << studentIndex << "] ";
            std::cout << data[1] << " | ";
            std::cout << data[0];
            std::cout << "\n======\n";
            studentIndex++;
        }
        
        std::cout << "Masukkan index siswa yang akan dihapus: ";
        std::cin >> selectedIndex;

        tempOut.open("temp.csv", std::ios::app);
        studentIndex = 1;
        std::ifstream file2temp("students.csv");
        
        if (!file2temp.is_open())
        {
            std::cerr << "Error membuka file" << std::endl;
            return;
        }
        
        while (getline(file2temp, line))
        {
            if (studentIndex == selectedIndex)
            {
                studentIndex++;
                continue;
            }
            
            std::string data[4];
            std::string buff;
            int dataPos = 0;
            
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ',')
                {
                    data[dataPos] = buff;
                    dataPos++;
                    buff = "";
                    continue;
                }
                buff += line[i];
            }
            
            tempOut << data[0] << ",";
            tempOut << data[1] << ",";
            tempOut << data[2] << ",";
            tempOut << data[3] << ",";
            tempOut << std::endl;
            studentIndex++;
        }
        
        tempOut.close();
        file.close();
        file2temp.close();
        remove("students.csv");
        rename("temp.csv", "students.csv");
    }

    void ViewStudents()
    {
        system("cls");
        std::fstream file("students.csv");
        
        if (!file.is_open())
        {
            std::cerr << "Error membuka file" << std::endl;
            return;
        }

        std::string line;
        int studentIndex = 1;
        
        std::cout << "=== DAFTAR SISWA ===" << std::endl;
        
        while (getline(file, line))
        {
            std::string data[4];
            std::string buff;
            int dataPos = 0;
            
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ',')
                {
                    data[dataPos] = buff;
                    dataPos++;
                    buff = "";
                    continue;
                }
                buff += line[i];
            }
            
            std::cout << "[" << studentIndex << "]" << std::endl;
            std::cout << "Nama: " << data[1] << std::endl;
            std::cout << "NISN: " << data[0] << std::endl;
            std::cout << "Terdaftar sejak: " << data[2] << std::endl;
            std::cout << "Berakhir pada: " << data[3] << std::endl;
            std::cout << "\n======\n\n";
            studentIndex++;
        }
    }

    void ViewRegistrations(){
        system("cls");
        std::fstream file("registrations.csv");
        
        if (!file.is_open())
        {
            std::cerr << "Error membuka file" << std::endl;
            return;
        }

        std::string line;
        int regIndex = 1;
        
        std::cout << "=== DAFTAR PENDAFTARAN KELAS ===" << std::endl;
        
        while (getline(file, line))
        {
            std::string data[4];
            std::string buff;
            int dataPos = 0;
            
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ',')
                {
                    data[dataPos] = buff;
                    dataPos++;
                    buff = "";
                    continue;
                }
                buff += line[i];
            }
            
            std::cout << "[" << regIndex << "]" << std::endl;
            std::cout << "Nama Siswa: " << data[1] << std::endl;
            std::cout << "Mata Pelajaran: " << data[2] << std::endl;
            std::cout << "Tutor: " << data[3] << std::endl;
            std::cout << "\n======\n\n";
            regIndex++;
        }
    }
};

struct ValidationResult
{
    bool isSuccess;
    Admin admin;
};

ValidationResult validateLogin(LoginInfo &loginInfo)
{
    Admin arrAdmin[5] = {
        Admin("admin1", "pass123"),
        Admin("admin2", "pass456"),
        Admin("admin", "admin"),
    };

    int indexFlag = -1;
    for (int i = 0; i < 5; i++)
    {
        if (loginInfo.username == arrAdmin[i].getName() && 
            loginInfo.password == arrAdmin[i].getPassword())
        {
            indexFlag = i;
            break;
        }
    }

    if (indexFlag >= 0)
    {
        std::cout << "Login berhasil!" << std::endl;
        return ValidationResult{true, arrAdmin[indexFlag]};
    }
    
    std::cout << "Username atau password salah. Silakan coba lagi." << std::endl;
    return ValidationResult{false, Admin("", "")};
}

void UIAdmin(Admin *admin)
{
    const int VIEW_STUDENTS = 1;
    const int VIEW_REGISTRATIONS = 2;
    const int ADD_STUDENT = 3;
    const int EXTEND_REGISTRATION = 4;
    const int REMOVE_STUDENT = 5;
    const int LOGOUT = 6;

    UIController c;
    bool shouldExit = false;
    std::string nisn, name, registrationDate, expiryDate;
    Student student = Student("", "", "", "");

    while (true)
    {
        if (shouldExit)
        {
            break;
        }

        int choice = c.getAdminInput();
        
        switch (choice)
        {
        case LOGOUT:
            shouldExit = true;
            break;
            
        case VIEW_STUDENTS:
            admin->ViewStudents();
            std::cout << "\n----------------------" << std::endl;
            std::cout << "Tekan tombol Enter untuk kembali...";
            std::cin.ignore();
            std::cin.get();
            break;
            
        case VIEW_REGISTRATIONS:
            admin->ViewRegistrations();
            std::cout << "\n----------------------" << std::endl;
            std::cout << "Tekan tombol Enter untuk kembali...";
            std::cin.ignore();
            std::cin.get();
            break;
            
        case ADD_STUDENT:
            system("cls");
            std::cout << "=== DAFTARKAN SISWA BARU ===" << std::endl;
            std::cout << "============================" << std::endl;
            std::cin.ignore(1, '\n');
            std::cout << "NISN: ";
            getline(std::cin, nisn);
            std::cout << "Nama: ";
            getline(std::cin, name);
            std::cout << "Tanggal Pendaftaran [YYYY/MM/DD]: ";
            getline(std::cin, registrationDate);
            std::cout << "Tanggal Berakhir [YYYY/MM/DD]: ";
            getline(std::cin, expiryDate);
            
            student = Student(nisn, name, registrationDate, expiryDate);
            admin->RegisterStudent(&student);
            
            std::cout << "\nData siswa berhasil ditambahkan!" << std::endl;
            std::cout << "\n----------------------" << std::endl;
            std::cout << "Tekan tombol Enter untuk kembali...";
            std::cin.get();
            break;
            
        case EXTEND_REGISTRATION:
            admin->ExtendRegistration();
            std::cout << "\n----------------------" << std::endl;
            std::cout << "Tekan tombol Enter untuk kembali...";
            std::cin.ignore();
            std::cin.get();
            break;
            
        case REMOVE_STUDENT:
            admin->RemoveStudent();
            std::cout << "\n----------------------" << std::endl;
            std::cout << "Tekan tombol Enter untuk kembali...";
            std::cin.ignore();
            std::cin.get();
            break;
            
        default:
            std::cout << "Pilihan tidak valid!" << std::endl;
            break;
        }
    }
}