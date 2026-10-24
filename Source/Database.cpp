
#include "Database.h"
#include <iostream>
Database::Database(const std::string& connectionString)
    : connection(connectionString){}

bool Database::isConnected() const
{
    return connection.is_open();
}

std::vector<Patient> Database::getPatients()
{
    pqxx::work txn(connection);

    pqxx::result result = txn.exec(
        "SELECT id, name, age, phone, diagnosis FROM patients"
    );

    std::vector<Patient> patients;

    for (const auto& row : result)
    {
        patients.emplace_back(
            row["id"].as<int>(),
            row["name"].as<std::string>(),
            row["age"].as<int>(),
            row["phone"].as<std::string>(),
            row["diagnosis"].as<std::string>()
        );
    }

    txn.commit();

    return patients;
}

int Database::addPatient(const Patient& patient)
{
    pqxx::work txn(connection);

    pqxx::result result = txn.exec_params(
        "INSERT INTO patients (name, age, phone, diagnosis) "
        "VALUES ($1, $2, $3, $4) RETURNING id",
        patient.getName(),
        patient.getAge(),
        patient.getTelefon(),
        patient.getDiagnosis()
    );

    int id = result[0]["id"].as<int>();

    txn.commit();

    return id;
}

void Database::deletePatient(int id)
{
    pqxx::work txn(connection);

    txn.exec_params(
        "DELETE FROM patients WHERE id = $1",
        id
    );

    txn.commit();
}

void Database::updatePatient(const Patient& patient)
{
    pqxx::work txn(connection);

    txn.exec_params(
        "UPDATE patients "
        "SET name = $1, age = $2, phone = $3, diagnosis = $4 "
        "WHERE id = $5",
        patient.getName(),
        patient.getAge(),
        patient.getTelefon(),
        patient.getDiagnosis(),
        patient.getId()
    );

    txn.commit();
}
