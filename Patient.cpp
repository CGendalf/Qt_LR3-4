#include "Patient.h"

// Конструктор за замовчуванням
Patient::Patient() {
    PatientName = "";
    DoctorName = "";
    Speciality = "";
    Date = "";
    Time = "";
    Status = "";
}

// Ініціалізація полів
Patient::Patient(std::string patient, std::string doctor, std::string speciality,
                 std::string date, std::string time, std::string status)
    : PatientName(patient), DoctorName(doctor), Speciality(speciality),
    Date(date), Time(time), Status(status)
{

}

void Patient::setPatient(std::string patient)
{
    PatientName = patient;
}

std::string Patient::getPatient() const
{
    return PatientName;
}

void Patient::setDoctor(std::string doctor)
{
    DoctorName = doctor;
}

std::string Patient::getDoctor() const
{
    return DoctorName;
}

void Patient::setSpeciality(std::string speciality)
{
    Speciality = speciality;
}

std::string Patient::getSpeciality() const
{
    return Speciality;
}

void Patient::setDate(std::string date)
{
    Date = date;
}

std::string Patient::getDate() const
{
    return Date;
}

void Patient::setTime(std::string time)
{
    Time = time;
}

std::string Patient::getTime() const
{
    return Time;
}

void Patient::setStatus(std::string status)
{
    Status = status;
}

std::string Patient::getStatus() const
{
    return Status;
}

std::string Patient::toString() const
{
    return "Patient: " + PatientName + ", Doctor: " + DoctorName +
           ", Speciality: " + Speciality + ", Date: " + Date +
           ", Time: " + Time + ", Status: " + Status;
}
