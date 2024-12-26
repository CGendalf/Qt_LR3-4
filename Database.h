#pragma once

#include "Patient.h"
#include <vector>
#include <string>

// Клас Database для управління списком пацієнтів
class Database {
private:
    static const int MaxPatients = 100; // Максимальна кількість пацієнтів
    Patient patients[MaxPatients]; // Масив для збереження пацієнтів
    int patientNum; // Поточна кількість пацієнтів

public:
    Database(); // Конструктор
    ~Database(); // Деструктор

    // Додати пацієнта
    Patient& addPatient(std::string patientName, std::string doctorName,
                        std::string speciality, std::string date,
                        std::string time, std::string status);

    // Отримати список пацієнтів за статусом
    std::vector<std::string> getPatientsByStatus(const std::string& status) const;

    // Отримати список усіх пацієнтів
    std::vector<std::string> getAllPatients() const;
};
