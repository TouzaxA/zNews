#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QMessageBox>
#include "mainwindow.h"
#include "fonction.h"
#include "runwindow.h"

int main(int argc, char *argv[]) {

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); // L'application utilise l'UTF-8 pour l'affichage des caractères

    QApplication a(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    MainWindow mw;

    RunWindow rw;
    rw.setMainWindow(&mw);
    rw.show();

    return a.exec();
}
