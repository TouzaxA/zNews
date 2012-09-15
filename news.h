#ifndef NEWS_H
#define NEWS_H
#include <QString>
#include <QStringList>
#include <QFile>

class News {
    public:
        News();
        ~News();
        void setTitle(QString title);
        void setContent(QString content);
        void appendRessource(QString ressources);
        void saveIn(QFile *file);
        QString title();
        QString content();
        QStringList ressources();

    private:
        QString _title;
        QString _content;
        QStringList _ressource;
};

#endif // NEWS_H
