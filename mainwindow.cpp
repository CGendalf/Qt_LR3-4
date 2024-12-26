#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QString>

// Конструктор головного вікна
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), db() {
    // Ініціалізація полів введення
    patientName = new QLineEdit(this);
    doctorName = new QLineEdit(this);
    speciality = new QLineEdit(this);
    date = new QLineEdit(this);
    time = new QLineEdit(this);
    status = new QLineEdit(this);
    statusSearch = new QLineEdit(this);

    // Ініціалізація кнопок
    saveButton = new QPushButton("Save and Display Patients", this);
    byStatusButton = new QPushButton("Search by Status", this);

    // Область для виводу пацієнтів
    patientList = new QTextEdit(this);
    patientList->setReadOnly(true);

    // Розташування віджетів
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    layout->addWidget(new QLabel("Patient Name:"));
    layout->addWidget(patientName);
    layout->addWidget(new QLabel("Doctor Name:"));
    layout->addWidget(doctorName);
    layout->addWidget(new QLabel("Speciality:"));
    layout->addWidget(speciality);
    layout->addWidget(new QLabel("Date:"));
    layout->addWidget(date);
    layout->addWidget(new QLabel("Time:"));
    layout->addWidget(time);
    layout->addWidget(new QLabel("Status:"));
    layout->addWidget(status);

    layout->addWidget(saveButton);

    layout->addWidget(new QLabel("Search by Status:"));
    layout->addWidget(statusSearch);
    layout->addWidget(byStatusButton);

    layout->addWidget(new QLabel("Patient Records:"));
    layout->addWidget(patientList);

    setCentralWidget(centralWidget);

    // Підключення сигналів до слотів
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::SavePatient);
    connect(byStatusButton, &QPushButton::clicked, this, &MainWindow::byStatus);
}

// Деструктор
MainWindow::~MainWindow() {}

// Зберегти пацієнта
void MainWindow::SavePatient() {
    QString patientNameText = patientName->text();
    QString doctorNameText = doctorName->text();
    QString specialityText = speciality->text();
    QString dateText = date->text();
    QString timeText = time->text();
    QString statusText = status->text();

    if (patientNameText.isEmpty() || doctorNameText.isEmpty() || specialityText.isEmpty() ||
        dateText.isEmpty() || timeText.isEmpty() || statusText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled!");
        return;
    }

    db.addPatient(patientNameText.toStdString(), doctorNameText.toStdString(),
                  specialityText.toStdString(), dateText.toStdString(),
                  timeText.toStdString(), statusText.toStdString());

    // Очищення введених полів
    patientName->clear();
    doctorName->clear();
    speciality->clear();
    date->clear();
    time->clear();
    status->clear();

    // Оновлення списку пацієнтів
    patientList->clear();
    std::vector<std::string> allPatients = db.getAllPatients();
    for (const std::string& record : allPatients) {
        patientList->append(QString::fromStdString(record));
    }
}

// Пошук пацієнтів за статусом
void MainWindow::byStatus() {
    QString searchStatus = statusSearch->text();

    if (searchStatus.isEmpty()) {
        QMessageBox::warning(this, "Search Error", "Please enter a status to search!");
        return;
    }

    std::vector<std::string> results = db.getPatientsByStatus(searchStatus.toStdString());

    // Виведення результатів пошуку
    patientList->clear();
    for (const std::string& record : results) {
        patientList->append(QString::fromStdString(record));
    }
}
