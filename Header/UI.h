
#ifndef HOSPITALOS_UI_H
#define HOSPITALOS_UI_H


#include "Patient.h"
#include "Doctor.h"
#include "Room.h"
#include "Hospital.h"

class UI {
private:
    Hospital hospital;
public:
    // Show

    void ShowAllPatientsUI();
    void ShowAllDoctorsUI();
    void ShowAllRoomsUI();


    //Menu

    void MainMenu();
    void PatientMenu();
    void DoctorMenu();
    void RoomMenu();

    // Patient

    void AddPatientToUI();

    // Doctor

    void AddDoctorToUI();

    // Room

    void AddRoomToUI();

    explicit UI(Database& database);

};
#endif //HOSPITALOS_UI_H