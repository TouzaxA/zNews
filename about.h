#ifndef ABOUT_H
#define ABOUT_H

#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QHBoxLayout>

class About : public QDialog
{
    Q_OBJECT
    public:
        About(QWidget *parent = 0);

    private:
        QLabel *zozor;
        QLabel *title;
        QLabel *presentation;
        QLabel *author;
        QPushButton *credits;
        QPushButton *license;
        QPushButton *close;
        QString const *creditsText;
        QString const *licenseText;
        QTextEdit *creditsTextEdit;
        QTextEdit *licenseTextEdit;
        QHBoxLayout *hLayout;
        QVBoxLayout *vLayout;
        QVBoxLayout *cLayout;

    signals:

    public slots:
        void slotLicense();
        void slotCredits();

};

#endif // ABOUT_H
