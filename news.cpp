#include "news.h"
#include <QString>
#include <QStringList>
#include <QTextStream>

News::News() {
    _ressource = QStringList();
}

void News::setTitle(QString title) {
    _title = title;
}

void News::setContent(QString content) {
    _content = content;
}

QString News::content() {
    return _content;
}

QString News::title() {
    return _title;
}

void News::appendRessource(QString res) {
    _ressource.append(res);
}

QStringList News::ressources() {
    return _ressource;
}

void News::saveIn(QFile *file) {
    // On ouvre le fichier en écriture
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream flux(file);
    flux.setCodec("UTF-8");
    // Entête du fichier
    flux << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"?>" << endl;
    flux << "<news>" << endl;
    flux << "<header>" << endl;
    flux << "<title><![CDATA[ " + title() + " ]]></title>" << endl;
    flux << "</header>" << endl;
    flux << "<content>" << endl << "<![CDATA[" << endl << content() << endl << "]]>" << endl << "</content>" << endl;
    flux << "</news>" << endl;
    file->close();
}

News::~News() {

}
