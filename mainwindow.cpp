#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QObject>


#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    testDomParser = new DomParser();

    m_serial_port = new QSerialPort(this);
    connect(m_serial_port, SIGNAL(readyRead()), this, SLOT(read_port()));
    connect(m_serial_port, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(serial_error_handler(QSerialPort::SerialPortError)));

    m_serial_port->setPortName("COM2");
    m_serial_port->setBaudRate(115200);
    m_serial_port->setDataBits(QSerialPort::Data8);
    m_serial_port->setParity(QSerialPort::NoParity);
    m_serial_port->setStopBits(QSerialPort::OneStop);
    m_serial_port->setFlowControl(QSerialPort::NoFlowControl);

    if(m_serial_port->open(QIODevice::ReadWrite)) {
        ui->statusBar->setText(tr("port open successed"));
    } else {
        ui->statusBar->setText(tr("port open failed"));
    }



}



MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::importMetaTedsAction()
{
    QString strFileName = "";
    QString strFullName = "";
    strFullName = QFileDialog::getOpenFileName(this,tr("选取要打开的TEDS文件"), "", tr("teds files (*.xml)"));
    if (strFullName == NULL)
        return false;
    QFileInfo fileInfo(strFullName);
    strFileName = fileInfo.fileName();
    if (strFileName == NULL)
        return false;
    cout << strFileName.toLatin1().data() << endl;

    if (!testDomParser->readMetaTedsFile(strFileName))
    {
        cerr << "Error : Parser test teds xml file faild" << endl;
    }

    return true;

}

bool MainWindow::importPhyTedsAction()
{
    QString strFileName = "";
    QString strFullName = "";
    strFullName = QFileDialog::getOpenFileName(this,tr("选取要打开的TEDS文件"), "", tr("teds files (*.xml)"));
    if (strFullName == NULL)
        return false;
    QFileInfo fileInfo(strFullName);
    strFileName = fileInfo.fileName();
    if (strFileName == NULL)
        return false;
    cout << strFileName.toLatin1().data() << endl;

    if (!testDomParser->readPhyTedsFile(strFileName))
    {
        cerr << "Error : Parser test teds xml file faild" << endl;
    }

    return true;

}

bool MainWindow::importTransducerTedsAction()
{
    QString strFileName = "";
    QString strFullName = "";
    strFullName = QFileDialog::getOpenFileName(this,tr("选取要打开的TEDS文件"), "", tr("teds files (*.xml)"));
    if (strFullName == NULL)
        return false;
    QFileInfo fileInfo(strFullName);
    strFileName = fileInfo.fileName();
    if (strFileName == NULL)
        return false;
    cout << strFileName.toLatin1().data() << endl;

    if (!testDomParser->readTransducerTedsFile(strFileName))
    {
        cerr << "Error : Parser test teds xml file faild" << endl;
    }

    return true;
}

void MainWindow::serial_error_handler(QSerialPort::SerialPortError serial_error)
{
    if(serial_error != QSerialPort::NoError) {
        ui->statusBar->setText(tr("serial port error: ") + m_serial_port->errorString());
    }
}

void MainWindow::read_port()
{
    QByteArray byte_arr = m_serial_port->readAll();
    QString str = QString(byte_arr);
    ui->textReceived->appendPlainText(str);
}

qint64 MainWindow::write_port(QByteArray &byte_arr)
{
    qint64 writed = m_serial_port->write(byte_arr.constData(), byte_arr.length());
    return writed;
}
void MainWindow::buttonWriteData()
{
    ui->textSended->appendPlainText("\n\nwrite data:\n");
    QString strWrite = "data for test";
    QByteArray byte_arr(strWrite.toLatin1());
    ui->textSended->appendPlainText(QString(byte_arr));
    int ret = write_port(byte_arr);
    ui->textSended->appendPlainText("write " + QString::number(ret) + "\n");
}
