
#ifndef HOSPITALOS_DOCTOR_H
#define HOSPITALOS_DOCTOR_H

#include <string>

enum Specialization {
    Cardiology = 1,
    Neurology,
    Surgery,
    Pediatrics
};

class Doctor {
private:
    static int Nextid;
    int id;
    std::string name;
    int age;
    std::string telefon;
    Specialization specialization;
    int experienceYears;
public:
    Doctor(std::string name, int age, std::string telefon, Specialization specialization, int experienceYears);
    // Getery
    std::string getName() const;
    int getAge() const;
    std::string getTelefon() const;
    Specialization getSpecialization() const;
    int getExperienceYears() const;
    int getId() const;
    // Setery
    void setName(std::string name);
    void setAge(int age);
    void setTelefon(std::string telefon);
    void setSpecialization(Specialization spec);
    void setExperienceYears(int E_Yers);
};


#endif //HOSPITALOS_DOCTOR_H