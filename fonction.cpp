#include "fonction.h"
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

QString getRessourcePath() {
    #ifndef Q_WS_MAC
        return QString(QCoreApplication::applicationDirPath() + "/Resources/");
    #else
        QString path(QCoreApplication::applicationDirPath());
        path.remove(path.length() - QString("/MacOs").length(), QString("/MacOs").length());

        return (path + "/Resources/");
    #endif
}

QString trim(QString str) {
    int spaceBegin(0), spaceEnd(0);
    int length = str.length();

    for(int i = 0; i <= (length-1); i++) {
        if(str[i].toAscii() == ' ' || str[i].toAscii() == '\t' || str[i].toAscii() == '\n' || str[i].toAscii() == '\r') {
            spaceBegin++;
        } else {
            break;
        }
    }

    for(int i = length-1; i >= 0; i--) {
        if(str[i].toAscii() == ' ' || str[i].toAscii() == '\t' || str[i].toAscii() == '\n' || str[i].toAscii() == '\r') {
             spaceEnd++;
        } else {
          break;
        }
    }

    // Length devient la taille de la nouvelle chaine
    length = length - spaceBegin - spaceEnd;

    QString final("");
    for(int i = 0; i <= length-1; i++) {
        final.append(str[spaceBegin + i]);
    }

    return final;
}

#if defined(Q_WS_WIN)
    void CopyDir(QString srcPath, QString destPath){
        QMessageBox::critical(0, "Fonction non implementée", "La fonction CopyDir n'est pas implementée pour Windows");
        return false;
    }
#else
void CopyDir(QString srcPath, QString destPath) {
    srcPath = trim(srcPath);
    destPath = trim(destPath);

    int length = srcPath.length();
    char last = srcPath[length-1].toAscii();
    if(last != '/') {
        srcPath.append("/");
    }

    length = destPath.length();
    last = destPath[length-1].toAscii();
    if(last != '/') {
        destPath.append("/");
    }

    QString cmd = "cp -R " + srcPath + "* " + destPath;
    system(cmd.toAscii());
}
#endif
