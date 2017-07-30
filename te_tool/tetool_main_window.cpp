/*!
  \file tetool_main_window.cpp
  \brief file to implement the TEToolMainWindow class
*/

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

#include "tetool_main_window.h"

/*!
  \fn TEToolMainWindow::TEToolMainWindow(QWidget *parent)
  \brief Default constructor for the TEToolMainWindow class
  \param parent QObject to handle the Qt parenting
 */
TEToolMainWindow::TEToolMainWindow(QWidget *parent) :
QMainWindow(parent) {
  setupUi(this);
  connect(aboutAction, &QAction::triggered,
          this, &TEToolMainWindow::onAbout);
  connect(exportCSVAction, &QAction::triggered,
          this, &TEToolMainWindow::onExportCSV);
  connect(imporCSVAction, &QAction::triggered,
          this, &TEToolMainWindow::onImportCSV);
  connect(exitAction, &QAction::triggered,
          this, &TEToolMainWindow::onExit);
  connect(connectAction, &QAction::triggered,
          this, &TEToolMainWindow::onConnect);
  connect(disconnectAction, &QAction::triggered,
          this, &TEToolMainWindow::onDisconnect);
  connect(aboutQtAction, &QAction::triggered,
          qApp, &QApplication::aboutQt);

}

/*!
  \fn TEToolMainWindow::~TEToolMainWindow()
  \brief Default destructor for the TEToolMainWindow
*/

TEToolMainWindow::~TEToolMainWindow() {

}

/*!
  \fn void TEToolMainWindow::onAbout() const
  \brief handles the about triggered signal
*/

void TEToolMainWindow::onAbout(){
  QMessageBox::about(this, "Title Examiner",
                     "The Title Examiner.\n\n"
                     "Development.");
  return;
}

/*!
  \fn void TEToolMainWindow::onExportCSV() const
  \brief handles the exporting to csv slot
*/

void TEToolMainWindow::onExportCSV(){
  QString fileName = QFileDialog::getSaveFileName(this, tr("Export CSV"),
                                                  QDir::homePath(),
                                                  tr("csv (*.csv)"));
}

/*!
  \fn void TEToolMainWindow::onImportCSV() const
  \brief handles the importing on csv files
*/

void TEToolMainWindow::onImportCSV(){
  QString fileName = QFileDialog::getOpenFileName(this, tr("Import CSV"),
                                                  QDir::homePath(),
                                                  tr("csv (*.csv)"));
}

/*!
  \fn void TEToolMainWindow::onExit() const
  \brief exits the application
*/

void TEToolMainWindow::onExit(){
  QMessageBox quitQuery(QMessageBox::Warning, "Title Examiner",
                        "Are you sure you want to quit?",
                        QMessageBox::Yes | QMessageBox::No, this);
  if(quitQuery.exec()) {
      QApplication::exit();
    }
}

/*!
  \fn void TEToolMainWindow::onConnect()
  \brief handles connecting to the database
*/

void TEToolMainWindow::onConnect() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Connect to a Database"),
                                                  QDir::homePath(),
                                                  tr("SQL Database (*.db)"));
}

/*!
  \fn void TEToolMainWindow::onDisconnect()
  \brief handles the disconnecting from the database
*/

void TEToolMainWindow::onDisconnect() {
  qDebug() << "Disconnect!";
}
