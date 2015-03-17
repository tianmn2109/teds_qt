#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "domparser.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DomParser * testDomParser;

    QSerialPort *m_serial_port;

    qint64 write_port(QByteArray &byte_arr);




public slots:
    bool importMetaTedsAction();
    bool importPhyTedsAction();
    bool importTransducerTedsAction();
    void read_port();
    void serial_error_handler(QSerialPort::SerialPortError serial_error);
    void buttonWriteData();
    void buttonWritePhy();
    void buttonWriteTs();
    void buttonWriteTeds();

};

#endif // MAINWINDOW_H
