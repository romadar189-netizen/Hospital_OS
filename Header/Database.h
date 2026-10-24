#ifndef HOSPITALOS_DATABASE_H
#define HOSPITALOS_DATABASE_H

#include <pqxx/pqxx>
#include <string>
#include "Patient.h"
#include <vector>

class Database {
private:
    pqxx::connection connection;

public:
    std::vector<Patient> getPatients();

    explicit Database(const std::string& connectionString);
    bool isConnected() const;

    int addPatient(const Patient& patient);
    void deletePatient(int id);
    void updatePatient(const Patient& patient);
};

#endif //HOSPITALOS_DATABASE_H
