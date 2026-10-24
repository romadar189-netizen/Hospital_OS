
#ifndef HOSPITALOS_HOSPITAL_H
#define HOSPITALOS_HOSPITAL_H


#include <vector>
#include "Doctor.h"
#include "Patient.h"
#include "Room.h"
#include "Database.h"



class Hospital {
private:
    Database &database;
    std::vector<Doctor> doctors;
    std::vector<Patient> patients;
    std::vector<Room> rooms;
public:
    //Getery
    Patient &getPatient(int id);
    Doctor &getDoctor(int id);
    Room &getRoom(int id);

    //Add

    void addPatient(const Patient& patient);
    void addDoctor(const Doctor& doctor);
    void addRoom(const Room& room);

    //Function

    void ShowaAllPatients();
    void ShowaAllDoctors();
    void ShowaAllRooms();

    // Delet

    void DeletePatient(int id);
    void DeleteDoctor(int id);
    void DeleteRoom(int id);


    //Database function

    void updatePatient(const Patient& patient);
    explicit Hospital(Database& database);
};


#endif //HOSPITALOS_HOSPITAL_H