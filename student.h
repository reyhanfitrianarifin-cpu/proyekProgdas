#include <fstream>
#include "user.h"

class Student : public User {
private:
    std::string nisn;
    std::string name;
    std::string registrationDate;
    std::string expiryDate;

public:
    Student (std::string _nisn, std::string _name, std::string _registrationDate, std::string _expiryDate){
        Student::nisn = _nisn;
        Student::name = _name;
        Student::registrationDate = _registrationDate;
        Student::expiryDate = _expiryDate;
    }

    std::string getNISN(){
        return Student::nisn;
    }

    std::string getName(){
        return Student::name;
    }

    std::string getRegistrationDate(){
        return Student::registrationDate;
    }

    std::string getExpiryDate(){
        return Student::expiryDate;
    }

    void registerClass(int subjectID){
        std::ofstream ofs;
        ofs.open("registrations.csv", std::ios::app);
        ofs << Student::nisn << ",";
        ofs << Student::name << ",";
        ofs << tutorList[subjectID-1].subject << ",";
        ofs << tutorList[subjectID-1].name << ",";
        ofs << std::endl;
        ofs.close();
    }
};

struct StudentValidationResult
{
    bool isValid;
    Student student;
};

StudentValidationResult validateNISN(std::string _NISN)
{
    std::ifstream studentFile;
    studentFile.open("students.csv");
    std::string line;
    bool isNISNFound = false;
    Student s = Student("", "", "", "");

    while (!studentFile.eof())
    {
        getline(studentFile, line);
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
        
        s = Student(data[0], data[1], data[2], data[3]);
        
        if (data[0] == _NISN)
        {
            isNISNFound = true;
            break;
        }
    }
    
    studentFile.close();
    return StudentValidationResult{isNISNFound, s};
}