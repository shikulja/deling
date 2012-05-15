/****************************************************************************
 ** Deling Final Fantasy VIII Field Editor
 ** Copyright (C) 2009-2012 Arzel J�r�me <myst6re@gmail.com>
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
#include "BGPreview.h"

BGPreview::BGPreview(QWidget *parent)
	: QScrollArea(parent), label(0)
{
	setAlignment(Qt::AlignCenter);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	QPalette pal = palette();
	pal.setColor(QPalette::Active, QPalette::Window, Qt::black);
	pal.setColor(QPalette::Inactive, QPalette::Window, Qt::black);
	pal.setColor(QPalette::Disabled, QPalette::Window, pal.color(QPalette::Disabled, QPalette::Text));
	setPalette(pal);
	setFrameShape(QFrame::NoFrame);

	createContents();
}

void BGPreview::createContents()
{
	if(label)	label->deleteLater();
	label = new QLabel();
}

void BGPreview::fill(const QPixmap &background)
{
	createContents();

	setCursor(QCursor(Qt::PointingHandCursor));

	if(background.width()>width() || background.height()>height()) {
		if(background.height()==height())
			label->setPixmap(background.scaled(background.width()*width()/background.height(), height(), Qt::KeepAspectRatio));
		else
			label->setPixmap(background.scaled(width(), height(), Qt::KeepAspectRatio));
	}
	else
		label->setPixmap(background);

	setWidget(label);
}

void BGPreview::clear()
{
	createContents();
	setWidget(label);
	setCursor(QCursor(Qt::ArrowCursor));
}

void BGPreview::mouseReleaseEvent(QMouseEvent *event)
{
	if(event->button() == Qt::LeftButton)
		emit triggered();
}
