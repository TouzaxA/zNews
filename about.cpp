#include "about.h"

About::About(QWidget *parent) : QDialog(parent) {
    setFixedSize(400, 250);
    zozor = new QLabel(this);
    zozor->setPixmap(QPixmap(":/runWindow/Ressources/zozor.png"));
    zozor->move(10, 30);

    presentation = new QLabel(this);
    presentation->setText("<center>zNews : Ecrivais vos news</center><br />zNews est un logiciel de redaction de news a <br />l'attention des utisateurs du site du zero.<br />");
    presentation->move(100, 20);
    presentation->setFixedWidth(300);

    author = new QLabel(this);
    author->setText("<br />zNews est un logiciel libre distribue sous licence GPL.<br />Zozor et le site du zero sont la propriete de Simple It<br />Pour participer au projet c'est <a href=\"https://github.com/Toshy62/zNews\">ici</a><br /><br /><b>Contributeurs :</b> <br />Toshy62(programmeur),<br />Echec et Matt(testeur)");
    author->move(10, 109);
}
