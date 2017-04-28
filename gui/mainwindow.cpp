/**
 * File name: mainwindow.cpp
 * Project: MashaFile (desktop client)
 *
 * Copyright (C) 2015 Iurie Nistor (http://sv-ti.com)
 *
 * This file is part of MashaFile.
 *
 * MashaFile is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "mainwindow.h"

#include <QFileDialog>
#include <QPushButton>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow() :
  gkickApi(std::make_unique<GKickApi>()),
  oscillatorWidget(NULL)
{
}

bool MainWindow::init(void)
{
  if (gkickApi.get()->hasErrors()) {
    return false;
  }
  
  setupUi(this);

  oscillators = gkickApi.get()->getOscillators();
  oscillatorWidget = new OscillatorWidget(verticalLayoutWidget, oscillators[0].get());
  viewOscillatorLayout->addWidget(oscillatorWidget);
  
  return true;
}

MainWindow::~MainWindow()
{
  //if (uploadButton != NULL) {
  //  delete uploadButton;
  //}
}

void
MainWindow::closeEvent(QCloseEvent *event)
{
  //  event->ignore();
  //this->setVisible(false);
}