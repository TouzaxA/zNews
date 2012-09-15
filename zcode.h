#ifndef ZCODE_H
#define ZCODE_H
#include <QString>

class ZCode {
    public:
        ZCode(QString &txt);
        QString encode();
    private:
        QString content;
};

#endif // ZCODE_H
