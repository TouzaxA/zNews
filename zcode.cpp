#include "zcode.h"

ZCode::ZCode(QString &txt) {
    content = txt;
}

QString ZCode::encode() {
    // On travaille sur une copie
    QString toEncode = content.toAscii();

    // Le ZCode en lui même

    // Les smileys :p
    toEncode.replace(" :) ", " <img src=\"smileys/smile.png\" /> ");
    toEncode.replace(" :D ", " <img src=\"smileys/heureux.png\" /> ");
    toEncode.replace(" ;) ", " <img src=\"smileys/clin.png\" /> ");
    toEncode.replace(" :p ", " <img src=\"smileys/langue.png\" /> ");
    toEncode.replace(" :lol: ", " <img src=\"smileys/rire.gif\" /> ");
    toEncode.replace(" :euh: ", " <img src=\"smileys/unsure.gif\" /> ");
    toEncode.replace(" :( ", " <img src=\"smileys/triste.png\" /> ");
    toEncode.replace(" :o ", " <img src=\"smileys/huh.png\" /> ");
    toEncode.replace(" :colere2: ", " <img src=\"smileys/mechant.png\" /> ");
    toEncode.replace(" o_O ", " <img src=\"smileys/blink.gif\" /> ");
    toEncode.replace(" ^^ ", " <img src=\"smileys/hihi.png\" /> ");
    toEncode.replace(" :-° ", " <img src=\"smileys/siffle.png\" /> ");
    toEncode.replace(" :ange: ", " <img src=\"smileys/ange.png\" /> ");
    toEncode.replace(" :colere: ", " <img src=\"smileys/angry.gif\" /> ");
    toEncode.replace(" :diable: ", " <img src=\"smileys/diable.png\" /> ");
    toEncode.replace(" :magicien: ", " <img src=\"smileys/magicien.png\" /> ");
    toEncode.replace(" :ninja: ", " <img src=\"smileys/ninja.png\" /> ");
    toEncode.replace(" >_< ", " <img src=\"smileys/pinch.png\" /> ");
    toEncode.replace(" :pirate: ", " <img src=\"smileys/pirate.png\" /> ");
    toEncode.replace(" :'( ", " <img src=\"smileys/pleure.png\" /> ");
    toEncode.replace(" :honte: ", " <img src=\"smileys/rouge.png\" /> ");
    toEncode.replace(" :soleil: ", " <img src=\"smileys/soleil.png\" /> ");
    toEncode.replace(" :waw: ", " <img src=\"smileys/waw.png\" /> ");
    toEncode.replace(" :zorro: ", " <img src=\"smileys/zorro.png\" /> ");


    return toEncode;
}
