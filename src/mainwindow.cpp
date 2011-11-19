#include "mainwindow.hpp"

mainwindow::mainwindow()
{
    w = new mainwid();

    a_about = new QAction(tr("&About"),this);
    connect(a_about,SIGNAL(triggered()),this,SLOT(about()));

    help_bar = menuBar()->addMenu(tr("&Help and Info"));
    help_bar->addAction(a_about);

    setCentralWidget(w);
    setWindowTitle(tr("Gat2"));
}

void mainwindow::about(){
    QMessageBox::about(this,tr("About Gat2"),
            tr("<h2>Gat2</h2>"
               "<p>Copyright (c) 2011 opamp"
               "<p>version:: 2.1")); // version
}
