#include "about.h"

About::About(QWidget *parent) : QDialog(parent) {

    zozor = new QLabel(this);
    zozor->setPixmap(QPixmap(":/runWindow/Ressources/zozor.png"));
    zozor->setAlignment(Qt::AlignCenter);

    title = new QLabel(this);
    title->setText("<center><p><strong>zNews</strong></p><p>1.0</p></center>");

    presentation = new QLabel(this);
    presentation->setText("<center><p>zNews est un logiciel de rédaction de news conçu pour le Site du Zéro.<br />Il permet notamment de rédiger hors connexion grâce à l'export XML.</p><p><a href=\"https://github.com/Toshy62/zNews\">Site Web de zNews</a></p></center>");
    presentation->setOpenExternalLinks(true);

    author = new QLabel(this);
    author->setText("<font size=2><center><p>Copyright © 2012 Les auteurs de zNews<br />Zozor et le Site du Zéro sont la propriété de <a href=\"http://www.simple-it.fr\">Simple IT</a></p></center></font>");
    author->setOpenExternalLinks(true);

    // Les trois boutons du bas
    credits = new QPushButton(this);
    credits->setText("Crédits");
    credits->setCheckable(true);

    license = new QPushButton(this);
    license->setText("Licence");
    license->setCheckable(true);

    close = new QPushButton(this);
    close->setText("Fermer");

    // Les scroll areas
    creditsTextEdit = new QTextEdit();
    creditsTextEdit->setHtml("<font size=2><table align=center><tr><td>Développeur principal :</td><td>Pierre Pélisset (Toshy62)</td></tr><tr><td>Contributeur(s) :</td><td>Matthieu Vieira (Échec et Matt)</td></tr></table><p align=center>Un problème ? Consultez le wiki : <a href=\"https://github.com/Toshy62/zNews/wiki\">https://github.com/Toshy62/zNews/wiki</a></p></font>");
    creditsTextEdit->setReadOnly(true);

    licenseTextEdit = new QTextEdit("<font size=2><p>zNews est un logiciel libre ; vous pouvez le redistribuer et/ou le modifier selon les termes de la <u>Licence Publique Générale GNU</u>, telle que publiée par la Free Software Foundation ; version 3 de la licence.</p><p>zNews est distribué dans l'espoir qu'il vous sera utile, <u>mais sans aucune garantie</u> ; sans même la garantie implicite de <u>valeur marchande</u> ou <u>d'adéquation à un besoin particulier</u>.<p>Vous pouvez consulter la Licence Publique Générale GNU à cette adresse : <a href=\"http://www.gnu.org/copyleft/gpl.html\">http://www.gnu.org/copyleft/gpl.html</a>. La licence ayant une valeur juridique est en anglais mais une traduction non officielle est disponible afin de permettre aux anglophobes de comprendre les termes de la licence : <a href=\"http://dachary.org/loic/gpl-french.pdf\">http://dachary.org/loic/gpl-french.pdf</a>.</p></font>");
    licenseTextEdit->setReadOnly(true);

    // Le positionnement avec les layouts
    hLayout = new QHBoxLayout;
    hLayout->addWidget(credits);
    hLayout->addWidget(license);
    hLayout->addSpacing(200);
    hLayout->addWidget(close);

    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(zozor);
    vLayout->addWidget(title);
    vLayout->addWidget(presentation);
    vLayout->addWidget(author);
    vLayout->addWidget(creditsTextEdit);
    vLayout->addWidget(licenseTextEdit);
    vLayout->addLayout(hLayout);

    creditsTextEdit->hide();
    licenseTextEdit->hide();

    setLayout(vLayout);
    setMinimumSize(525, 300);
    setMaximumSize(525, 300);

    // Connexion aux slots

    QObject::connect(close, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(credits, SIGNAL(clicked()), this, SLOT(slotCredits()));
    QObject::connect(license, SIGNAL(clicked()), this, SLOT(slotLicense()));

}

void About::slotCredits() {

    license->setChecked(false);

    if(credits->isChecked()) {
        author->hide();
        presentation->hide();
        licenseTextEdit->hide();
        creditsTextEdit->show();
    }
    else {
        author->show();
        presentation->show();
        creditsTextEdit->hide();
    }


}

void About::slotLicense() {

     credits->setChecked(false);

     if(license->isChecked()) {
        author->hide();
        presentation->hide();
        creditsTextEdit->hide();
        licenseTextEdit->show();
     }
     else {
         author->show();
         presentation->show();
         licenseTextEdit->hide();
     }

}
