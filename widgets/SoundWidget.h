/****************************************************************************
 ** Deling Final Fantasy VIII Field Editor
 ** Copyright (C) 2009-2012 Arzel Jérôme <myst6re@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#ifndef SOUNDWIDGET_H
#define SOUNDWIDGET_H

#include "widgets/PageWidget.h"
#include "Listwidget.h"

class SoundWidget : public PageWidget
{
	Q_OBJECT
public:
	SoundWidget();
	void clear();
	void setReadOnly(bool ro);
	void fill();
	inline QString tabName() const { return tr("Sons"); }
private slots:
	void setCurrentSound(int id);
	void addSound();
	void removeSound();
	void editSfxValue(double v);
	void exportAkao();
	void importAkao();
private:
	void build();
	void fillList(int count);

	QToolBar *toolBar;
	QListWidget *list1;
	// Sfx
	QWidget *sfxGroup;
	QDoubleSpinBox *sfxValue;
	// AkaoList
	QWidget *akaoGroup;
	QPushButton *exportButton, *importButton;
	QLabel *akaoId;

};

#endif // SOUNDWIDGET_H
