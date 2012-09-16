#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QLabel>

class About : public QDialog
{
    Q_OBJECT
    public:
        About(QWidget *parent = 0);

    private:
        QLabel *zozor;
        QLabel *presentation;
        QLabel *author;

    signals:

    public slots:

};

#endif // ABOUT_H
