#include "Database.h"
#include <stdexcept>

Database::Database() : patientNum(0) {} // Ініціалізація кількості пацієнтів

Database::~Database() {} // Деструктор

// Додати нового пацієнта
Patient& Database::addPatient(std::string patientName, std::string doctorName,
                              std::string speciality, std::string date,
                              std::string time, std::string status) {
    if (patientNum >= MaxPatients) {
        throw std::runtime_error("Database is full"); // Перевірка переповнення
    }

    // Ініціалізація нового пацієнта
    Patient& newPatient = patients[patientNum++];
    newPatient.setPatient(patientName);
    newPatient.setDoctor(doctorName);
    newPatient.setSpeciality(speciality);
    newPatient.setDate(date);
    newPatient.setTime(time);
    newPatient.setStatus(status);

    return newPatient;
}

// Отримати список усіх пацієнтів
std::vector<std::string> Database::getAllPatients() const {
    std::vector<std::string> results;
    for (int i = 0; i < patientNum; i++) {
        results.push_back(patients[i].toString());
    }
    return results;
}

// Отримати список пацієнтів за статусом
std::vector<std::string> Database::getPatientsByStatus(const std::string& status) const {
    std::vector<std::string> results;
    for (int i = 0; i < patientNum; i++) {
        if (status.empty() || patients[i].getStatus() == status) {
            results.push_back(patients[i].toString());
        }
    }
    return results;
}
