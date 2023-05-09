#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>



class MainWindow : public QWidget {
Q_OBJECT
private:
    static void navigationBar(QWidget *parent);

    static QWidget *navigationBarLeft();

    static QWidget *navigationBarRight();

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;
};

#endif // MAINWINDOW_H
