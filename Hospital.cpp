#include "Hospital.h"

#include <stdexcept>
#include <iostream>
#include <vector>



// Getery
Patient &Hospital::getPatient(int id) {
    for (size_t i = 0; i < patients.size(); i++) {
        if (id == patients[i].getId()) {
            return patients[i];
        }
    }
    throw std::runtime_error("Patient not found");
}

Doctor &Hospital::getDoctor(int id) {
    for (size_t i = 0; i < doctors.size(); i++) {
        if (id == doctors[i].getId()) {
            return doctors[i];
        }
    }
    throw std::runtime_error("Doctor not found");
}

Room &Hospital::getRoom(int id) {
    for (size_t i = 0; i < rooms.size(); i++) {
        if (id == rooms[i].getId()) {
            return rooms[i];
        }
    }
    throw std::runtime_error("Room not found");
}

// Add

void Hospital::addPatient (const Patient& patient) {
    Hospital::patients.push_back(patient);
}
void Hospital::addDoctor(const Doctor& doctor) {
    Hospital::doctors.push_back(doctor);
}
void Hospital::addRoom(const Room& room) {
    Hospital::rooms.push_back(room);
}

// Function

void Hospital::ShowaAllPatients() {
    int i = 0;
    for (const Patient& patient : patients) {
        std::cout << i++ << " " << patient.getName() << " - " << patient.getAge() << ": " << patient.getId() << std::endl;
    }
}

void Hospital::ShowaAllDoctors() {
    int i = 0;
    for (const Doctor& doctor : doctors) {
        std::cout << i++ << " " << doctor.getName() << " - " << doctor.getAge() << ": " << doctor.getId() << std::endl;
    }
}

void Hospital::ShowaAllRooms() {
    int i = 0;
    for (const Room& room : rooms) {
        std::cout << i++ << room.getRoomNumber() << " - " << room.getId() << std::endl;
    }
}

// Delet
void Hospital::DeletePatient(int id) {
    for (auto i = patients.begin(); i != patients.end(); i++) {
        if (i->getId() == id) {
            patients.erase(i);
            return;
        }
    }
    throw std::runtime_error("Patient not found");
}

void Hospital::DeleteDoctor(int id) {
    for (auto i = doctors.begin(); i != doctors.end(); i++) {
        if (i->getId() == id) {
            doctors.erase(i);
            return;
        }
    }
    throw std::runtime_error("Doctor not found");
}

void Hospital::DeleteRoom(int id) {
    for (auto i = rooms.begin(); i != rooms.end(); i++) {
        if (i->getId() == id) {
            rooms.erase(i);
            return;
        }
    }
    throw std::runtime_error("Room not found");
}