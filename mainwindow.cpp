#include "mainwindow.h"
#include "fonction.h"
#include "zcode.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QtWebKit>
#include <QMessageBox>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QListView>
#include <QDir>
#include <QFileDialog>
#include <QDesktopServices>
#include <QtXml>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setMinimumSize(800, 600);

    middleArea = new QWidget;

    titleLayout = new QHBoxLayout;
    lbl = new QLabel("Titre :");
    nTitle = new QLineEdit;
    nTitle->setText("Titre");
    titleLayout->addWidget(lbl);
    titleLayout->addWidget(nTitle);

    mainLayout = new QVBoxLayout;
    editor = new QTextEdit;
    editor->setText("Inserez ici votre contenu :p ");
    view = new QWebView;



    mainLayout->addLayout(titleLayout);
    mainLayout->addWidget(editor);
    mainLayout->addWidget(view);

    middleArea->setLayout(mainLayout);

    setCentralWidget(middleArea);

    buildMenu();
    buildDock();
    sParse();

    news = new News;

    manageSlots();
}

void MainWindow::resizeEvent(QResizeEvent *) {
    int size = middleArea->height();
    editor->setFixedHeight((size/10)*4);
}

void MainWindow::buildMenu() {
    file = menuBar()->addMenu("&Fichier");
    edition = menuBar()->addMenu("&Edition");
    viewMenu = menuBar()->addMenu("&Affichage");

    newN = new QAction("&Nouveau", this);
    newN->setShortcut(QKeySequence(QKeySequence::New));
    newN->setIcon(QIcon(":/runWindow/Ressources/new.png"));
    open = new QAction("&Ouvrir", this);
    open->setShortcut(QKeySequence(QKeySequence::Open));
    open->setIcon(QIcon(":/runWindow/Ressources/open.png"));
    save = new QAction("&Sauvegarder", this);
    save->setShortcut(QKeySequence(QKeySequence::Save));
    save->setIcon(QIcon(":/runWindow/Ressources/save.png"));

    file->addAction(newN);
    file->addAction(open);
    file->addAction(save);

    // Le bouton Quitter qui ne doit pas exister sur Mac
    #ifndef Q_WS_MAC
    quit = new QAction("&Quitter", this);
    quit->setShortcut(QKeySequence(QKeySequence::Quit));
    quit->setIcon(QIcon(":/runWindow/Ressources/exit.png"));
    file->addAction(quit);
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
    #endif

    parse = new QAction("&Previsualiser", this);
    parse->setShortcut(QKeySequence("Ctrl+P"));
    parse->setIcon(QIcon(":/runWindow/Ressources/parse.png"));
    viewMenu->addAction(parse);

    bar = addToolBar("News");
    bar->setMovable(false);
    bar->addAction(newN);
    bar->addAction(open);
    bar->addAction(save);
    bar->addSeparator();
    bar->addAction(parse);
}

void MainWindow::buildDock() {
    dockRessource = new QDockWidget("Ressources", this);
    addDockWidget(Qt::LeftDockWidgetArea, dockRessource);
    /*ressources = new QStringListModel(news->ressources());
    resView = new QListView;
    resView->setModel(ressources);
    dockRessource->setWidget(resView);*/

    dockZCode = new QDockWidget("ZCode", this);
    addDockWidget(Qt::LeftDockWidgetArea, dockZCode);
}

void MainWindow::openNews(QString path) {
    QString title;
    QString content;

    // On va ouvrir le fichier XML et en extraire ce dont on a besoin
    QDomDocument dom("news_xml");
    QFile newsFile(path);
    if(!newsFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Impossible d'ouvrir le fichier", "Erreur lors de l'ouverture de " + path);
        qApp->exit();
    }
    if(!dom.setContent(&newsFile, false)) {
        newsFile.close();
        QMessageBox::critical(this, "Impossible de parser le XML", "Impossible d'analyser le fichier " + path);
        qApp->exit();
    }
    QDomElement racine = dom.documentElement();
    racine = racine.firstChildElement();
    while(!racine.isNull()) {
        if(racine.tagName() == "header") {
            QDomElement elm = racine.firstChildElement();
            while(!elm.isNull()) {
                if(elm.tagName() == "title") {
                    title = elm.text();
                }
                elm = elm.nextSiblingElement();
            }
        }
        racine = racine.nextSiblingElement();
        if(racine.tagName() == "content") {
            content = trim(racine.text());
        }
        racine = racine.nextSiblingElement();
    }
    news->setContent(content);
    news->setTitle(title);
    nTitle->setText(title);
    editor->setText(content);
    sParse();
    newsFile.close();
    currentFile = &newsFile;
}

void MainWindow::newNews() {
    news->setTitle(QString());
    news->setContent(QString());
}


MainWindow::~MainWindow() {
    if(currentFile != 0) {
        delete currentFile;
        currentFile = 0;
    }
    delete news;
}

void MainWindow::manageSlots() {
    connect(nTitle, SIGNAL(textChanged(QString)), this, SLOT(sParse()));
    connect(editor, SIGNAL(textChanged()), this, SLOT(sParse()));
    connect(parse, SIGNAL(triggered()), this, SLOT(sParse()));
    connect(open, SIGNAL(triggered()), this, SLOT(sOpen()));
    connect(save, SIGNAL(triggered()), this, SLOT(sSave()));
}

void MainWindow::sParse() {

    // On recupere le template de base
    QFile tpl(":/runWindow/Ressources/template.tpl");
    tpl.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream fluxR(&tpl);
    QString tplContent = fluxR.readAll();
    QString content = editor->toPlainText();
    content.replace("\n", "<br />");

    ZCode code(content);
    content = code.encode();

    tplContent.replace("TITRE_NEWS", nTitle->text());
    tplContent.replace("CONTENU_NEWS", content);

    QDir dir = QDesktopServices::storageLocation(QDesktopServices::TempLocation);
    dir.mkdir(QString("~cache/"));
    QFile file(dir.absolutePath() + "/~cache/index.htm");
    if (file.open(QFile::WriteOnly)) {
        QTextStream out(&file);
        out << tplContent;
    } else {
        QMessageBox::information(this, "Erreur", "Impossible d'accéder en écriture au fichier :" + dir.absolutePath() + "/~cache/index.htm");
    }
    QDir tmp(dir.absolutePath() + "/~cache/css");
    if(!tmp.exists()) {
        CopyDir(getRessourcePath() + "znews/", dir.absolutePath() + "/~cache");
    }


    view->load(QUrl(dir.absolutePath() + "/~cache/index.htm"));
}

void MainWindow::sOpen() {
    QString saveContent = news->content();
    QString saveTitle = news->title();
    // On vérifie qu'il y a eu des modification
    if(saveContent != editor->toPlainText() || saveTitle != nTitle->text()) {
        // On propose de sauvegarder la news avant
        int save = QMessageBox::question(this, "Sauvegarder la news en cours", "Voulez-vous sauvegarder la news en cours ?", QMessageBox::Yes | QMessageBox::Default, QMessageBox::No);
        if(save == QMessageBox::Yes) {
            // On sauvegarde
            sSave();
        }
    }
    QString newsFile = QFileDialog::getOpenFileName(this, "Ouvrir une news", QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation), "News (*.news)");
    openNews(newsFile);

}

void MainWindow::sSave() {
    // On recupère les informations de la news
    news->setTitle(nTitle->text());
    news->setContent(editor->toPlainText());

    // On regarde si un fichier news existe
    if(currentFile == 0) {
        QString path = QFileDialog::getSaveFileName(this, "Enregistrer la news", QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation), "News (*.news)");
        currentFile = new QFile(path);
        news->saveIn(currentFile);
    }
}

void MainWindow::closeEvent(QCloseEvent *e) {
    int save = QMessageBox::question(this, "Sauvegarder la news en cours", "Voulez-vous sauvegarder la news en cours ?", QMessageBox::Yes | QMessageBox::Default, QMessageBox::No);
    if(save == QMessageBox::Yes) {
        // On sauvegarde
        sSave();
    }
    e->accept();
}
