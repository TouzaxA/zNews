#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include "mainwindow.h"


class RunWindow : public QWidget
{
    Q_OBJECT
    public:
        explicit RunWindow(QWidget *parent = 0);
        ~RunWindow();
        void setMainWindow(MainWindow *mw);
    
    private:
        MainWindow *mw;
        QVBoxLayout *mainLayout;
        QHBoxLayout *secLayout;
        QVBoxLayout *thiLayout;
        QLabel *title;
        QLabel *lblImg;
        QPixmap *pixmap;

        // Les boutons de droite
        QPushButton *nNew;
        QPushButton *open;
        QPushButton *quit;

    signals:
    
    public slots:
        void openNews();
        void newNews();
    
};

#endif // RUNWINDOW_H
