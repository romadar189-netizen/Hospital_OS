#include <string>
#include "Doctor.h"
#include <stdexcept>
#include <cctype>

int Doctor::Nextid = 1000;
    Doctor::Doctor(std::string name, int age, std::string telefon, Specialization specialization, int experienceYears) :
telefon(telefon)
{
        // Name

        if (!name.empty()) {
            for (const char& c : name) {
                if (isalpha(c)) {
                    Doctor::name.push_back(c);
                }
                else {
                    throw std::invalid_argument("Doctor dont corect name");
                }
            }
        }
        else {
            throw std::invalid_argument("Doctor dont corect name");
        }

        // Age

        if (age >= 0 && age <= 150) {
            Doctor::age = age;
        }
        else {
            throw std::invalid_argument("Doctor dont corect age");
        }

        // ExperienceYers

        if (experienceYears >= 0 && experienceYears <= 70) {
            Doctor::experienceYears = experienceYears;
        }
        else {
            throw std::invalid_argument("Doctor dont corect experience yers");
        }

        // Specializatin

        if (specialization >= 1 && specialization <= 4) {
            Doctor::specialization = specialization;
        }
        else {
            throw std::invalid_argument("Doctor dont corect specialization");
        }
        id = Nextid++;
    }

// Geters
    std::string Doctor::getName() const {
        return name;
    }
    int Doctor::getAge() const {
        return age;
    }
    std::string Doctor::getTelefon() const {
        return telefon;
    }
    Specialization Doctor::getSpecialization() const {
        return specialization;
    }
     int Doctor::getExperienceYears() const {
        return experienceYears;
    }
    int Doctor::getId() const {
            return id;
    }
// Seters
    void Doctor::setName(std::string name) {
        std::string NewName;
        if (!name.empty()) {
            for (const char& c : name) {
                if (isalpha(c)) {
                    NewName.push_back(c);
                }
                else {
                    throw std::invalid_argument("Doctor dont corect name");
                }
            }
        }
        else {
            throw std::invalid_argument("Doctor dont corect name");
        }
            Doctor::name = NewName;
    }
 void Doctor::setAge(int age) {
        if (age >= 0 && age <= 150) {
            Doctor::age = age;
        }
        else {
            throw std::invalid_argument("Doctor dont corect age");
        }
    }
void Doctor::setTelefon(std::string telefon) {
        Doctor::telefon = telefon;
    }
void Doctor::setSpecialization(Specialization spec) {
        if (spec >= 1 && spec <= 4) {
            Doctor::specialization = spec;
        }
        else {
            throw std::invalid_argument("Doctor dont corect specialization");
        }
    }
void Doctor::setExperienceYears(int experienceYears) {
        if (experienceYears >= 0 && experienceYears <= 70) {
            Doctor::experienceYears = experienceYears;
        }
        else {
            throw std::invalid_argument("Doctor dont corect experience yers");
        }
    }