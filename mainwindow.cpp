#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QDebug>

QSerialPort serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString comPort = ui->comBox->currentText();
    serial.setPortName(comPort);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::WriteOnly);

    if(serial.isOpen() && serial.isWritable())
    {
        QByteArray pos = QByteArray::number(ui->lcdNumber->intValue());
        serial.write(pos);
        ui->label_4->setText(pos);
        qDebug() << "QByteArray: " << pos << endl;
        ui->label_6->setText(pos);

        if (serial.flush()) //serial.flush() wartet bis ALLE Zeichen gesendet wurden!!!
        {
            qDebug() << "Flush: OK!" << endl;
            ui->label->setText("Flush: OK!");
        }
        else
        {
            qDebug() << "Flush: Nicht OK!" << endl;
            ui->label->setText("Flush: Nicht OK!");
        }
        serial.close();
    }
    else
    {
        qDebug() << "Nicht offen!";
        ui->label_4->setText("ERROR: !serial.isOpen()");
        ui->label_6->setText("");
        ui->label->setText("");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString comPort = ui->comBox->currentText();
    serial.setPortName(comPort);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);

    if(serial.isOpen() && serial.isWritable())
    {
        QString strWrite = ui->lineEdit->text();
        QByteArray pos = strWrite.toUtf8();
        serial.write(pos);
        ui->label_4->setText(pos);
        qDebug() << "QByteArray: " << pos << endl;
        ui->label_6->setText(pos);

        if (serial.flush()) //serial.flush() wartet bis ALLE Zeichen gesendet wurden!!!
        {
            qDebug() << "Flush: OK!" << endl;
            ui->label->setText("Flush: OK!");
        }
        else
        {
            qDebug() << "Flush: Nicht OK!" << endl;
            ui->label->setText("Flush: Nicht OK!");
        }
        serial.close();
    }
    else
    {
        qDebug() << "Nicht offen!";
        ui->label_4->setText("ERROR: !serial.isOpen()");
        ui->label_6->setText("");
        ui->label->setText("");
        ui->lineEdit->setText("");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString comPort = ui->comBox->currentText();
    serial.setPortName(comPort);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);

    if(serial.isOpen() && serial.isWritable())
    {
        QString strWrite = ui->lineEdit->text();
        QByteArray pos = QByteArray::number(ui->lcdNumber->intValue());
        QByteArray string = strWrite.toUtf8();
        string.append(pos);
        serial.write(string);
        ui->label_4->setText(string);
        qDebug() << "QByteArray: " << string << endl;
        ui->label_6->setText(string);

        if (serial.flush()) //serial.flush() wartet bis ALLE Zeichen gesendet wurden!!!
        {
            qDebug() << "Flush: OK!" << endl;
            ui->label->setText("Flush: OK!");
        }
        else
        {
            qDebug() << "Flush: Nicht OK!" << endl;
            ui->label->setText("Flush: Nicht OK!");
        }
        serial.close();
    }
    else
    {
        qDebug() << "Nicht offen!";
        ui->label_4->setText("ERROR: !serial.isOpen()");
        ui->label_6->setText("");
        ui->label->setText("");
        ui->lineEdit->setText("");
    }
}
