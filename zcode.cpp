#include "zcode.h"
#include <QRegExp>

ZCode::ZCode(QString &txt) {
    content = txt;
}

QString ZCode::encode() {
    // On travaille sur une copie
    QString toEncode = content.toAscii();

    // Le ZCode en lui même
    toEncode.replace(QRegExp("<gras>([^<]*)</gras>"), "<strong>\\1</strong>");
    toEncode.replace(QRegExp("<italique>([^<]*)</italique>"), "<span class=\"italique\">\\1</span>");
    toEncode.replace(QRegExp("<souligne>([^<]*)</souligne>"), "<span class=\"souligne\">\\1</span>");
    toEncode.replace(QRegExp("<barre>([^<]*)</barre>"), "<span class=\"barre\">\\1</span>");
    toEncode.replace(QRegExp("<flottant valeur=\"gauche\">([^<]*)</flottant>") , "<div class=\"flot_gauche\">\\1</span>");
    toEncode.replace(QRegExp("<flottant valeur=\"droite\">([^<]*)</flottant>") , "<div class=\"flot_droite\">\\1</span>");
    toEncode.replace(QRegExp("<titre1>([^<]*)</titre1>"), "<h3>\\1</h3>");
    toEncode.replace(QRegExp("<titre2>([^<]*)</titre2>"), "<h4>\\1</h4>");
    toEncode.replace(QRegExp("<liste>([^<]*)</liste>"), "<ul>\\1</ul>");
    toEncode.replace(QRegExp("<puce>([^<]*)</puce>"), "<li>\\1</li>");

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
