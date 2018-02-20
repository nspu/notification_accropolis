#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "googlefirebase.h"
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icons/images/icon.png"));
    this->error = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSubmit_clicked()
{
    string key;
    QJsonObject mainJson;
    QJsonObject dataJson;
    QJsonDocument doc;
    QByteArray request_body;

    this->error = false;

    //prepare
    QNetworkAccessManager *m = new QNetworkAccessManager;
    QNetworkRequest request;
    request.setUrl(QUrl("https://fcm.googleapis.com/fcm/send"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    key = "key=" + GoogleFirebase::apikey;
    QByteArray qba(key.c_str(), key.length());
    request.setRawHeader("authorization", qba);

    //insert data for firebase
    mainJson.insert("to", "/topics/accrolive");
    mainJson.insert("priority", "normal");
    mainJson.insert("time_to_live", 100);


    //insert message
    dataJson.insert("message", ui->leMessage->text());
    mainJson.insert("data", dataJson);
    doc.setObject(mainJson);
    request_body = doc.toJson();

    //send
    r = m->post(request, request_body);

    //listener
    connect(r, SIGNAL(finished()), this, SLOT(requestFinished()));
    connect(r, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));
}

void MainWindow::requestFinished()
{
    if(!this->error){
        qDebug() << "requete OK";
        this->ui->lblResult->setStyleSheet("color: black");
        this->ui->lblResult->setText("Notification envoyée");
    }
}

void MainWindow::requestError(QNetworkReply::NetworkError error)
{
    this->error = true;
    qDebug() << "||" <<   error << "||" ;
    this->ui->lblResult->setStyleSheet("color: red");
    this->ui->lblResult->setText("Erreur : " + r->errorString());
}
