/*
 * zNews: logiciel de rédaction de news pour le site du zéro
 * Logiciel distribué sous licence GPL
 * Créé par Pierre Pélisset (toshy62@hotmail.fr)
 */

#include "runwindow.h"
#include "fonction.h"
#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QFileDialog>
#include <QDesktopServices>
#include <QInputDialog>

RunWindow::RunWindow(QWidget *parent) : QWidget(parent) {
    mainLayout = new QVBoxLayout;
    secLayout = new QHBoxLayout;
    thiLayout = new QVBoxLayout;

    title = new QLabel("ZNews : Ecrivez vos news");
    mainLayout->addWidget(title);

    lblImg = new QLabel(this);
    pixmap = new QPixmap(":/runWindow/Ressources/zozor.png");
    lblImg->setPixmap(*pixmap);

    nNew = new QPushButton("Nouvelle news");
    nNew->setIcon(QIcon(":/runWindow/Ressources/new.png"));

    open = new QPushButton("Ouvrir une news");
    open->setIcon(QIcon(":/runWindow/Ressources/open.png"));

    quit = new QPushButton("Quitter zNews");
    quit->setIcon(QIcon(":/runWindow/Ressources/exit.png"));

    thiLayout->addWidget(nNew);
    thiLayout->addWidget(open);
    thiLayout->addWidget(quit);

    secLayout->addWidget(lblImg);
    secLayout->addLayout(thiLayout);
    mainLayout->addLayout(secLayout);

    setLayout(mainLayout);

    connect(open, SIGNAL(clicked()), this, SLOT(openNews()));
    connect(nNew, SIGNAL(clicked()), this, SLOT(newNews()));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

RunWindow::~RunWindow() {
    delete pixmap;
}

void RunWindow::openNews() {
    QString newsFile = QFileDialog::getOpenFileName(this, "Ouvrir une news", QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation), "News (*.news)");

    // On ouvre la news
    mw->openNews(newsFile);
    hide();
    mw->show();
}

void RunWindow::newNews() {
    /*QStringList cat;
    cat << "Logiciel" << "Programmation" << "Projet des zeros" << "Site du Zero" << "Web" << "Tutoriels" << "Concours" << "Securite"<< "Telephonie mobile" << "Livre du Zero" << "Libre" << "Sciences" << "Récap'" << "Evenements" << "Autres" << "Robotique" << "Interviews" << "Ebook";
    QString newCat = QInputDialog::getItem(this, "Categorie", "Selectionner la categorie de la news", cat);*/
    mw->newNews();
    hide();
    mw->show();
}

void RunWindow::setMainWindow(MainWindow *m_w) {
    mw = m_w;
}
