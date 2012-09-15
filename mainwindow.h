#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "news.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QtWebKit>
#include <QLineEdit>
#include <QLabel>
#include <QDockWidget>
#include <QStringListModel>
#include <QListView>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    public:
        MainWindow(QWidget *parent = 0);
        void resizeEvent(QResizeEvent *);
        void buildMenu();
        void buildDock();
        void openNews(QString path);
        void newNews();
        void manageSlots();
        void closeEvent(QCloseEvent *e);
        ~MainWindow();

    public slots:
        void sParse();
        void sOpen();
        void sSave();

    private:
        // Conteneur principal
        QVBoxLayout *mainLayout;
        QTextEdit *editor;
        QWebView *view;
        QWidget *middleArea;
        QHBoxLayout *titleLayout;
        QLabel *lbl;
        QLineEdit *nTitle;

        // Les menus
        QMenu *file;
        QMenu *edition;
        QMenu *viewMenu;
        QAction *newN;
        QAction *open;
        QAction *save;
        QAction *quit;
        QAction *parse;

        // La barre de menu
        QToolBar *bar;

        // Les docks
        QDockWidget *dockRessource;
        QDockWidget *dockZCode;
        QStringListModel *ressources;
        QListView *resView;

        // La news
        News *news;
        QFile *currentFile;
};

#endif // MAINWINDOW_H
