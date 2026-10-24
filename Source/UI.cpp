#include "UI.h"
#include <iostream>
#include <string>
#include <cctype>

// Add

void UI::AddPatientToUI() {
    std::cout << "===== Add Patient =====" << std::endl;
    std::string name;
    int age;
    std::string telefon;
    std::string diagnos;
    std::cout << "Patient name minimal Liter 2: ";
    std::cin >> name;
    std::cout << "Patient age: ";
    std::cin >> age;
    std::cin.ignore();
    std::cout << "Patient telefon: ";
    getline(std::cin, telefon);
    while (true) {
        bool Corect_T = true;

        if (telefon.length() < 6 || telefon[0] != '+') {
            Corect_T = false;
        }

        for (size_t i = 1; i < telefon.length(); i++) {
            if (!std::isdigit(telefon[i])) {
                Corect_T = false;
            }
        }

        if (Corect_T) {
            break;
        }
        else {
            std::cout << "Invalid telefon try again";
            std::getline(std::cin, telefon);
        }
    }
    std::cout << "Patient diagnos: ";
    std::getline(std::cin, diagnos);
    try {
        Patient patient(name, age, telefon, diagnos);
        UI::hospital.addPatient(patient);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=================" << std::endl;
}

void UI::AddDoctorToUI() {
    std::cout << "===== Add Doctor =====" << std::endl;
    std::string name;
    int age;
    std::string telefon;
    Specialization specalization;
    int number_Spec;
    int experienceYears;
    std::cout << "Doctor name minimal Liter 2: ";
    std::cin >> name;
    std::cout << "Doctor age: ";
    std::cin >> age;
    std::cin.ignore();
    std::cout << "Doctor telefon: ";
    std::getline(std::cin, telefon);
    while (true) {
        bool Corect_T = true;

        if (telefon.length() < 6|| telefon[0] != '+') {
            Corect_T = false;
        }

        for (size_t i = 1; i < telefon.length(); i++) {
            if (!std::isdigit(telefon[i])) {
                Corect_T = false;
            }
        }

        if (Corect_T) {
            break;
        }
        else {
            std::cout << "Invalid telefon try again";
            std::getline(std::cin, telefon);
        }
    }
    std::cout << "1. Cardiology" << std::endl
    << "2.  Neurology" << std::endl
    << "3. Surgery" << std::endl
    << "4. Pediatrics" << std::endl
    << "Enter number for specalization: " << std::endl;
    std::cin >> number_Spec;
    switch (number_Spec) {
        case 1: {
            specalization = Cardiology;
            break;
        }
        case 2: {
            specalization = Neurology;
            break;
        }
            case 3: {
            specalization = Surgery;
            break;
        }
            case 4: {
            specalization = Pediatrics;
            break;
        }
            default: {
            std::cout << "Default specalization Cardiology" << std::endl;
            specalization = Cardiology;
        }
    }
    std::cout << "Doctor experience years: ";
    std::cin >> experienceYears;
    try {
        Doctor doctor(name, age, telefon, specalization , experienceYears);
        UI::hospital.addDoctor(doctor);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=================" << std::endl;
}

void UI::AddRoomToUI() {
    Type type;
    int capacity;
    int number_Type;
    std::cout << "Add Room" << std::endl;
    std::cout << "Enter capacity of room: ";
    std::cin >> capacity;
    std::cout << "1. General ward" << std::endl
    << "2. Private room" << std::endl
    << "3.  ICU" << std::endl
    << "4. Operating room" << std::endl
    << "Enter type of room: " << std::endl;
    std::cin >> number_Type;
    switch (number_Type) {
        case 1: {
            type = GeneralWard;
            break;
        }
            case 2: {
            type = PrivateRoom;
            break;
        }
            case 3: {
            type = ICU;
            break;
        }
            case 4: {
            type = OperatingRoom;
            break;
        }
        default: {
            std::cout << "Default type room Privat room" << std::endl;
            type = PrivateRoom;
        }
    }
    try {
        Room room(type, capacity, 0);
        UI::hospital.addRoom(room);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=================" << std::endl;
}

// Show

void UI::ShowAllPatientsUI() {
    UI::hospital.ShowaAllPatients();
}
void UI::ShowAllDoctorsUI() {
    UI::hospital.ShowaAllDoctors();
}
void UI::ShowAllRoomsUI() {
    UI::hospital.ShowaAllRooms();
}

UI::UI(Database& database) : hospital(database){}

// Menu Patient

void UI::PatientMenu() {
    int chois = 0;
    int id;
    while (chois != 10) {
        // Menu
        std::cout << "1. Add patient" << std::endl
        << "2. Show all patient" << std::endl
        << "3. Set name" << std::endl
        << "4. Set age" << std::endl
        << "5. Set telefon" << std::endl
        << "6. Set diagnos" << std::endl
        << "7. Patient telefon" << std::endl
        << "8. Patient diagnos" << std::endl
        << "9. Delete Patient" << std::endl
        << "10. Back to main menu" << std::endl;
        std::cout << "Eneter number: ";
        std::cin >> chois;
        std::cin.ignore();
        switch (chois) {
            case 1: {
                UI::AddPatientToUI();
                break;
            }
            case 2: {
                // Show All patient

                std::cout << "===== Show All Patient =====" << std::endl;
                UI::ShowAllPatientsUI();
                std::cout << "======================" << std::endl;
                break;
            }
            case 3: {
                // Set Name

                std::cout << "===== Set Name =====" << std::endl;
                std::string name;
                UI::ShowAllPatientsUI();
                std::cout << "Enter id do you want patient: ";
                std::cin >> id;
                try {
                    Patient& patient = hospital.getPatient(id);
                    std::cout << "Enter name do you want patient: ";
                    std::cin>> name;
                    patient.setName(name);
                    UI::hospital.updatePatient(patient);
                }
                catch (const std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "===================" << std::endl;
                break;
            }
                case 4: {
                // Set age

                std::cout << "===== Set Age ===== " << std::endl;
                int age;
                UI::ShowAllPatientsUI();
                std::cout << "Enter id do you want patient: ";
                std::cin >> id;
                try {
                    Patient& patient = hospital.getPatient(id);
                    std::cout << "Enter age do you want patient: ";
                    std::cin>> age;
                    patient.setAge(age);
                    UI::hospital.updatePatient(patient);
                }
                catch (const std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "===================" << std::endl;
                break;
            }
                case 5: {
                // Set telefon

                std::cout << "===== Set Telefon =====" << std::endl;
                std::string telefon;
                UI::ShowAllPatientsUI();
                std::cout << "Enter id do you want patient: ";
                std::cin >> id;
                std::cin.ignore();
                try {
                    Patient& patient = hospital.getPatient(id);
                    std::cout << "Enter telefon do you want patient: ";
                    std::getline(std::cin, telefon);
                    while (true) {
                        bool Corect_T = true;

                        if (telefon.length() < 6 || telefon[0] != '+') {
                            Corect_T = false;
                        }

                        for (size_t i = 1; i < telefon.length(); i++) {
                            if (!std::isdigit(telefon[i])) {
                                Corect_T = false;
                            }
                        }

                        if (Corect_T) {
                            break;
                        }
                        else {
                            std::cout << "Invalid telefon try again";
                            std::getline(std::cin, telefon);
                        }
                    }
                    patient.setTelefon(telefon);
                    UI::hospital.updatePatient(patient);
                }catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================== " << std::endl;
                break;
            }
                case 6: {
                // set diagnos


                std::cout << "===== Show Diagnosis  =====" << std::endl;
                std::string diagnos;
                UI::ShowAllPatientsUI();
                std::cout << "Enter id do you want patient: ";
                std::cin >> id;
                std::cin.ignore();
                try {
                    Patient& patient = hospital.getPatient(id);
                    std::cout << "Enter diagnos do you want patient: ";
                    std::getline(std::cin, diagnos);
                    patient.setDiagnosis(diagnos);
                    UI::hospital.updatePatient(patient);
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "===================" << std::endl;
                break;
            }
                case 7: {
                // Get Telefon
                std::cout << "===== Telefon Patient =====" << std::endl;
                UI::ShowAllPatientsUI();
                std::cout << "Enter id do you want patient: ";
                std::cin >> id;
                try {
                    Patient& patient = hospital.getPatient(id);
                    std::cout << "Telefon " << patient.getName() << " - " << patient.getTelefon() << std::endl;
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                    std::cout << "===================" << std::endl;
                break;
            }
                case 8: {
                // Get Diagnos
                std::cout << "===== Diagnos Patient =====" << std::endl;
                UI::ShowAllPatientsUI();
                std::cout << "Enter id do you want patient: ";
                std::cin >> id;
                try {
                    Patient& patient = hospital.getPatient(id);
                    std::cout << "Diagnos " << patient.getName() << " - " << patient.getDiagnosis() << std::endl;
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                    std::cout << "===================" << std::endl;
                break;
            }
            case 9: {
                std::cout << "===== Delete Patient =====" << std::endl;
                UI::ShowAllPatientsUI();
                std::cout << "Enter id do you want patient: ";
                std::cin >> id;
                try {
                    UI::hospital.DeletePatient(id);
                }catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================" << std::endl;
                break;
            }
            case 10: {
                return;
            }
                default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    }
}

void UI::DoctorMenu() {
    int choice = 0;
    int id;
    while (choice != 12) {
        std::cout << "1. Add doctor" << std::endl
        << "2. Show doctor" << std::endl
        << "3. Set name" << std::endl
        << "4. Set age" << std::endl
        << "5. Set telefon" << std::endl
        << "6. Set specalization" << std::endl
        << "7. Set experience years" << std::endl
        << "8. Doctor specalization" << std::endl
        << "9. Doctor telefon" << std::endl
        << "10. Doctor experience yers" << std::endl
        << "11. Delete doctor" << std::endl
        << "12. Back to main menu" << std::endl;
        std::cout << "Eneter number: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: {
                UI::AddDoctorToUI();
                break;
            }
            case 2: {
                // Show All doctor

                std::cout << "===== Show All Doctor =====" << std::endl;
                UI::ShowAllDoctorsUI();
                std::cout << "======================" << std::endl;
                break;
            }
            case 3: {
                // Set Name

                std::cout << "===== Set Name =====" << std::endl;
                std::string name;
                UI::ShowAllDoctorsUI();
                std::cout << "Enter id do you want doctor: ";
                std::cin >> id;
                try {
                    Doctor& doctor = hospital.getDoctor(id);
                    std::cout << "Enter name do you want doctor: ";
                    std::cin>> name;
                    doctor.setName(name);
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "===================" << std::endl;
                break;
            }
                case 4: {
                // Set age

                std::cout << "===== Set Age ===== " << std::endl;
                int age;
                UI::ShowAllDoctorsUI();
                std::cout << "Enter id do you want doctor: ";
                std::cin >> id;
                try {
                    Doctor& doctor = hospital.getDoctor(id);
                    std::cout << "Enter age do you want doctor: ";
                    std::cin>> age;
                    doctor.setAge(age);
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "===================" << std::endl;
                break;
            }
                case 5: {
                // Set telefon

                std::cout << "===== Set Telefon =====" << std::endl;
                std::string telefon;
                UI::ShowAllDoctorsUI();
                std::cout << "Enter id do you want doctor: ";
                std::cin >> id;
                std::cin.ignore();
               try {
                   Doctor& doctor = hospital.getDoctor(id);
                   std::cout << "Enter telefon do you want doctor: ";
                   std::getline(std::cin, telefon);

                   while (true) {
                       bool Corect_T = true;

                       if (telefon.length() < 6 || telefon[0] != '+') {
                           Corect_T = false;
                       }

                       for (size_t i = 1; i < telefon.length(); i++) {
                           if (!std::isdigit(telefon[i])) {
                               Corect_T = false;
                           }
                       }

                       if (Corect_T) {
                           break;
                       }
                       else {
                           std::cout << "Invalid telefon try again";
                           std::getline(std::cin, telefon);
                       }
                   }
                   doctor.setTelefon(telefon);
               } catch (std::exception &e) {
                   std::cout << e.what() << std::endl;
               }
                std::cout << "==================== " << std::endl;
                break;
            }
                case 6: {
                // set specalization


                std::cout << "===== Set spealization =====" << std::endl;
                int specalization;
                Specialization spec;
                UI::ShowAllDoctorsUI();
                std::cout << "Enter id do you want doctor: ";
                std::cin >> id;
                try {
                    Doctor& doctor = hospital.getDoctor(id);
                    std::cout << "1. Cardiology" << std::endl
                    << "2.  Neurology" << std::endl
                    << "3. Surgery" << std::endl
                    << "4. Pediatrics" << std::endl
                    << "Enter specalization do you want doctor: ";
                    std::cin >> specalization;
                    switch (specalization) {
                        case 1: {
                            spec = Cardiology;
                            break;
                        }
                        case 2: {
                            spec = Neurology;
                            break;
                        }
                        case 3: {
                            spec = Surgery;
                            break;
                        }
                        case 4: {
                            spec = Pediatrics;
                            break;
                        }
                        default: {
                            std::cout << "Default specalization Cardiology" << std::endl;
                            spec = Cardiology;
                        }
                            doctor.setSpecialization(spec);
                    }
                }
                        catch (std::exception &e) {
                            std::cout << e.what() << std::endl;
                        }
                        std::cout << "===================" << std::endl;
                        break;
                }
                case 7: {
                    // Set exprecion yers

                    std::cout << "===== Set experience years ===== " << std::endl;
                    int expY;
                    UI::ShowAllDoctorsUI();
                    std::cout << "Enter id do you want doctor: ";
                    std::cin >> id;
                    try {
                        Doctor& doctor = hospital.getDoctor(id);
                        std::cout << "Enter experience years do you want doctor: ";
                        std::cin>> expY;
                        doctor.setExperienceYears(expY);
                    }
                    catch (std::exception &e) {
                        std::cout << e.what() << std::endl;
                    }
                    std::cout << "===================" << std::endl;
                    break;
                }

                case 8: {
                    // Get Specalization
                    std::cout << "===== Specalization Doctor =====" << std::endl;
                    UI::ShowAllDoctorsUI();
                    std::cout << "Enter id do you want doctor: ";
                    std::cin >> id;
                try {
                    Doctor& doctor = hospital.getDoctor(id);
                    std::cout << "Specalization " << doctor.getName() << " - " ;
                    switch (doctor.getSpecialization()) {
                        case Cardiology: {
                            std::cout << "Cardiology" << std::endl;
                            break;
                        }
                        case Neurology: {
                            std::cout << "Neurology" << std::endl;
                            break;
                        }
                        case Surgery: {
                            std::cout << "Surgery" << std::endl;
                            break;
                        }
                        case Pediatrics: {
                            std::cout << "Pediatrics" << std::endl;
                            break;
                        }
                    }
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "=====================" << std::endl;
                   break;
                }

                case 9: {
                // Get Telefon
                std::cout << "===== Telefon Doctor =====" << std::endl;
                UI::ShowAllDoctorsUI();
                std::cout << "Enter id do you want doctor: ";
                std::cin >> id;
                try {
                    Doctor& doctor = hospital.getDoctor(id);
                    std::cout << "Telefon " << doctor.getName() << " - " << doctor.getTelefon() << std::endl;
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 10: {
                std::cout << "===== Doctor experience years =====" << std::endl;
                UI::ShowAllDoctorsUI();
                std::cout << "Enter id do you want doctor: ";
                std::cin >> id;
                try {
                    Doctor& doctor = hospital.getDoctor(id);
                    std::cout << "Experience years " << doctor.getName() << " - " << doctor.getExperienceYears() << std::endl;
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 11: {
                std::cout << "===== Delete Doctor =====" << std::endl;
                UI::ShowAllDoctorsUI();
                std::cout << "Enter id do you want doctor: ";
                std::cin >> id;
                try {
                    UI::hospital.DeleteDoctor(id);
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================" << std::endl;
                break;
            }
            case 12: {
return;
            }
                default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    }
}

// Menu Rooms

void UI::RoomMenu() {
    int choice = 0;
    int id = 1000;
    while (choice != 11) {
        std::cout << "1. Add room" << std::endl
        << "2. Show room" << std::endl
        << "3. Set room number" << std::endl
        << "4. Set type" << std::endl
        << "5. Set capacity" << std::endl
        << "6. Set ocuppied" << std::endl
        << "7. Room Type" << std::endl
        << "8. Room capacity" << std::endl
        << "9. Room ocuppied" << std::endl
        << "10. Delete room" << std::endl
        << "11. Back to main menu" << std::endl;
        std::cout << "Eneter number: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: {
                UI::AddRoomToUI();
                break;
            }
            case 2: {
                std::cout << "===== Show room =====" << std::endl;
                UI::ShowAllRoomsUI();
                std::cout << "======================" << std::endl;
                break;
            }
                case 3: {
                std::cout << "===== Set room number =====" << std::endl;
                int room_number;
                UI::ShowAllRoomsUI();
                std::cout << "Enter id do you want room: ";
                std::cin >> id;
                try {
                    Room& room = hospital.getRoom(id);
                    std::cout << "Enter room number: ";
                    std::cin >> room_number;
                    room.setRoomNumber(room_number);
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "=====================" << std::endl;
                break;
            }
            case 4: {
                int number_T;
                Type type;
                std::cout << "===== Set Type =====" << std::endl;
                UI::ShowAllRoomsUI();
                std::cout << "Enter id do you want room: ";
                std::cin >> id;
                try {
                    Room& room = hospital.getRoom(id);
                    std::cout << "1. General Ward" << std::endl
                    << "2. Private Room" << std::endl
                    << "3. ICU" << std::endl
                    << "4. Operating Room" << std::endl
                    << "Enter number for type: ";
                    std::cin >> number_T;
                    switch (number_T) {
                        case 1: {
                            type = GeneralWard;
                            break;
                        }
                        case 2: {
                            type = PrivateRoom;
                            break;
                        }
                        case 3: {
                            type = ICU;
                            break;
                        }
                        case 4: {
                            type = OperatingRoom;
                            break;
                        }
                        default: {
                            std::cout << "Invalid choice - Default type ICU" << std::endl;
                            type = ICU;
                        }
                    }
                    room.setType(type);
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================" << std::endl;
                break;
            }
                case 5: {
                // Set Capacity
                int capacity;
                std::cout << "===== Set Capacity =====" << std::endl;
                UI::ShowAllRoomsUI();
                std::cout << "Enter id do you want room: ";
                std::cin >> id;
                try {
                    Room& room = hospital.getRoom(id);
                    std::cout << "Enter capacity: " << std::endl;
                    std::cin >> capacity;
                    while (capacity > 50 || capacity < 0 || capacity < room.getOccupied()) {
                        std::cout << "===== Invalid capacity =====" << std::endl;
                        std::cout << "Enter capacity: " << std::endl;
                        std::cin >> capacity;
                    }
                    room.setCapacity(capacity);
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================" << std::endl;
                break;
            }
            case 6: {
                // Set Ocuppied
                int ocupied;
                std::cout << "===== Set Ocuppied =====" << std::endl;
                UI::ShowAllRoomsUI();
                std::cout << "Enter id do you want room: ";
                std::cin >> id;
                try {
                    Room& room = hospital.getRoom(id);
                    std::cout << "Enter ocuppied: " << std::endl;
                    std::cin >> ocupied;
                    while (ocupied > room.getCapacity() || ocupied < 0) {
                        std::cout << "===== Invalid ocuppied! =====" << std::endl;
                        std::cout << "Enter ocuppied: " << std::endl;
                        std::cin >> ocupied;
                    }
                    room.setOccupied(ocupied);
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================" << std::endl;
                break;
            }
            case 7: {
                std::cout << "===== Room Type =====" << std::endl;
                UI::ShowAllRoomsUI();
                std::cout << "Enter id do you want room: ";
                std::cin >> id;
                try {
                    Room& room = hospital.getRoom(id);
                    std::cout << "Room " << room.getRoomNumber() << " - ";
                    switch (room.getType()) {
                        case GeneralWard: {
                            std::cout << "General Ward" << std::endl;
                            break;
                        }
                        case PrivateRoom: {
                            std::cout << "Private Room" << std::endl;
                            break;
                        }
                        case ICU: {
                            std::cout << "ICU" << std::endl;
                            break;
                        }
                        case OperatingRoom: {
                            std::cout << "Operating Room" << std::endl;
                            break;
                        }
                    }
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================" << std::endl;
                break;
            }
            case 8: {
                std::cout << "===== Room Capacity =====" << std::endl;
                UI::ShowAllRoomsUI();
                std::cout << "Enter id do you want room: ";
                std::cin >> id;
                try {
                    Room& room = hospital.getRoom(id);
                    std::cout << "Room " << room.getRoomNumber() << " - " << room.getCapacity() << std::endl;
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================" << std::endl;
                break;
            }
                case 9: {
                std::cout << "===== Room Occupied =====" << std::endl;
                UI::ShowAllRoomsUI();
                std::cout << "Enter id do you want room: ";
                std::cin >> id;
                try {
                    Room& room = hospital.getRoom(id);
                    std::cout << "Room " << room.getRoomNumber() << " - " << room.getOccupied() << std::endl;
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================" << std::endl;
                break;
            }
                case 10: {
                std::cout << "===== Room Delete =====" << std::endl;
                UI::ShowAllRoomsUI();
                std::cout << "Enter id do you want room: ";
                std::cin >> id;
                try {
                    UI::hospital.DeleteRoom(id);
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "==================" << std::endl;
                break;
            }
                case 11: {
                return;
            }
                default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    }
}

void UI::MainMenu() {
    int chois = 0;
    while (chois != 4) {
        std::cout << "1. Menu Room" << std::endl
        << "2. Manu Doctor" << std::endl
        << "3. Menu Patient" << std::endl
        << "4. Exit" << std::endl;
        std::cout << "Enter number: ";
        std::cin >> chois;
        std::cin.ignore();
        switch (chois) {
            case 1: {
                std::cout << "+++++ Menu Room +++++" << std::endl;
                RoomMenu();
                std::cout << "+++++++++++++++++++++" << std::endl;
                break;
            }
            case 2: {
                std::cout << "+++++ Menu Doctor +++++" << std::endl;
                DoctorMenu();
                std::cout << "+++++++++++++++++++++" << std::endl;
                break;
            }
            case 3: {
                std::cout << "+++++ Menu Patient +++++" << std::endl;
                PatientMenu();
                std::cout << "+++++++++++++++++++++" << std::endl;
                break;
            }
            case 4: {
                std::cout << "Tanck you (^ ^)" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    }
}