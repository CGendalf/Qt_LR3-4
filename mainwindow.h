#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "Database.h"

// Головне вікно програми
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void SavePatient(); // Зберегти пацієнта
    void byStatus(); // Пошук за статусом

private:
    QLineEdit *patientName;
    QLineEdit *doctorName;
    QLineEdit *speciality;
    QLineEdit *date;
    QLineEdit *time;
    QLineEdit *status;
    QLineEdit *statusSearch;
    QPushButton *saveButton;
    QPushButton *byStatusButton;
    QTextEdit *patientList;
    Database db;
};
