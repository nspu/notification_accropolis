#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtWidgets/QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btnSubmit_clicked();
    void requestFinished();
    void requestError(QNetworkReply::NetworkError error);

private:
    Ui::MainWindow *ui;
    bool error;
    QNetworkReply *r ;

};

#endif // MAINWINDOW_H
