/*!
  \file tetool_main_window.h
  \brief file to define the TEToolMainWindow
*/

#ifndef TETOOL_MAIN_WINDOW_H
#define TETOOL_MAIN_WINDOW_H

#include "ui_tetool_main_window_base.h"

/*!
  \class TEToolMainWindow
  \brief class to handle the main GUI for the TE tool
  \extends QMainWindow
  \extends Ui::TEToolMainWindow
 */
class TEToolMainWindow : public QMainWindow, private Ui::TEToolMainWindow {
  Q_OBJECT

public:
  explicit TEToolMainWindow(QWidget *parent = 0);
  virtual ~TEToolMainWindow() override;

private slots:
  void onAbout();
  void onExportCSV();
  void onImportCSV();
  void onExit();
  void onConnect();
  void onDisconnect();
};

#endif // TETOOL_MAIN_WINDOW_H
