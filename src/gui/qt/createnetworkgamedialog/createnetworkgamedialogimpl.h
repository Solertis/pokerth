/***************************************************************************
 *   Copyright (C) 2006 by FThauer FHammer   *
 *   f.thauer@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef CREATENETWORKGAMEDIALOGIMPL_H
#define CREATENETWORKGAMEDIALOGIMPL_H

#include "ui_createnetworkgamedialog.h"

#include <QtGui>
#include <QtCore>

class Session;
class ConfigFile;
class changeCompleteBlindsDialogImpl;


class createNetworkGameDialogImpl: public QDialog, public Ui::createNetworkGameDialog {
Q_OBJECT
public:
    createNetworkGameDialogImpl(QWidget *parent = 0, ConfigFile *c = 0);

	void exec();
	changeCompleteBlindsDialogImpl* getChangeCompleteBlindsDialog() { return myChangeCompleteBlindsDialog; }

public slots:

	void createGame();
	void cancel();
	void fillFormular();
	void showDialog();
	void keyPressEvent ( QKeyEvent * event );

	void callChangeBlindsDialog(bool);
private:
		
	ConfigFile *myConfig;	
	changeCompleteBlindsDialogImpl *myChangeCompleteBlindsDialog;
};

#endif
