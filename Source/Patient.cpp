#include <string>
#include "Patient.h"
#include <stdexcept>
#include <cctype>

// Constructor

    Patient::Patient(std::string name, int age, std::string telefon, std::string diagnosis) :
telefon(telefon),
diagnosis(diagnosis)
{
        // Name

        if (!name.empty()) {
            for (const char& c : name) {
                if (isalpha(c)) {
                    Patient::name.push_back(c);
                }
                else {
                    throw std::invalid_argument("Patient dont corect name");
                }
            }
        }
        else {
            throw std::invalid_argument("Patient dont corect name");
        }

        // Age

        if (age >= 0 && age <= 150) {
            Patient::age = age;
        }
        else {
            throw std::invalid_argument("Patient dont corect age");
        }
    }

Patient::Patient(int id, std::string name, int age, std::string telefon, std::string diagnosis)
    : id(id), name(name), age(age),
      telefon(telefon), diagnosis(diagnosis)
    {
        if (!name.empty()) {
            for (const char& c : name) {
                if (isalpha(c)) {
                    Patient::name.push_back(c);
                }
                else {
                    throw std::invalid_argument("Patient dont corect name");
                }
            }
        }
        else {
            throw std::invalid_argument("Patient dont corect name");
        }

        // Age

        if (age >= 0 && age <= 150) {
            Patient::age = age;
        }
        else {
            throw std::invalid_argument("Patient dont corect age");
        }
    }

  // Geters

    std::string Patient::getName() const {
        return name;
    }
    int Patient::getAge() const {
        return age;
    }
    std::string Patient::getTelefon() const {
        return telefon;
    }
    std::string Patient::getDiagnosis() const {
        return diagnosis;
    }
    int Patient::getId() const {
            return id;
    }

// Seters

    void Patient::setName(std::string name) {
        std::string NewName;
        if (!name.empty()) {
            for (const char& c : name) {
                if (isalpha(c)) {
                    NewName.push_back(c);
                }
                else {
                    throw std::invalid_argument("Patient dont corect name");
                }
            }
        }
        else {
            throw std::invalid_argument("Patient dont corect name");
        }
            Patient::name = NewName;
    }
 void Patient::setAge(int age) {
        if (age >= 0 && age <= 150) {
            Patient::age = age;
        }
        else {
            throw std::invalid_argument("Patient dont corect age");
        }
    }
void Patient::setTelefon(std::string telefon) {
        Patient::telefon = telefon;
    }
void Patient::setDiagnosis(std::string diagnosis) {
        Patient::diagnosis = diagnosis;
    }

void Patient::setId(int id)
    {
        this->id = id;
    }