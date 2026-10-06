
#ifndef HOSPITALOS_PATIENT_H
#define HOSPITALOS_PATIENT_H
#include <string>

class Patient {
private:
    static int Nextid;
     int id;
    std::string name;
    int age;
    std::string telefon;
    std::string diagnosis;
public:
     Patient(std::string name, int age, std::string telefon, std::string diagnosis);
    // Getery
    std::string getName() const;
    int getAge() const;
    std::string getTelefon() const;
    std::string getDiagnosis() const;
    int getId() const;
    // Setery
    void setName(std::string name);
    void setAge(int age);
    void setTelefon(std::string telefon);
    void setDiagnosis(std::string diagnosis);
};

#endif //HOSPITALOS_PATIENT_H