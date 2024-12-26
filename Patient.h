#pragma once

#include <string>

// Клас Patient для представлення пацієнта
class Patient {
private:
    std::string PatientName; // Ім'я пацієнта
    std::string DoctorName; // Ім'я лікаря
    std::string Speciality; // Спеціальність
    std::string Date; // Дата прийому
    std::string Time; // Час прийому
    std::string Status; // Статус

public:
    Patient(); // Конструктор за замовчуванням
    Patient(std::string patient, std::string doctor, std::string speciality,
            std::string date, std::string time, std::string status);

    // Методи для встановлення та отримання полів
    void setPatient(std::string patient);
    std::string getPatient() const;
    void setDoctor(std::string doctor);
    std::string getDoctor() const;
    void setSpeciality(std::string speciality);
    std::string getSpeciality() const;
    void setDate(std::string date);
    std::string getDate() const;
    void setTime(std::string time);
    std::string getTime() const;
    void setStatus(std::string status);
    std::string getStatus() const;

    // Форматований рядок з даними пацієнта
    std::string toString() const;
};
