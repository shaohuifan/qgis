/***************************************************************************
                          qgslegenditem.h  -  description
                             -------------------
    begin                : Sun Jul 28 2002
    copyright            : (C) 2002 by Gary E.Sherman
    email                : sherman at mrcc dot com
        Romans 3:23=>Romans 6:23=>Romans 5:8=>Romans 10:9,10=>Romans 12
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSLEGENDITEM_H
#define QGSLEGENDITEM_H
#include <qwidget.h>

class QgsSymbol;
/**
  *@author Gary E.Sherman
  */

class QgsLegendItem : public QWidget{
	Q_OBJECT
public: 
	QgsLegendItem();
	~QgsLegendItem();
  /** Write property of QString layerName. */
  virtual void setLayerName( const QString& _newVal);
  /** Write property of QString displayName. */
  virtual void setDisplayName( const QString& _newVal);
private: // Private attributes
  /**  */
  QgsSymbol * symbol;
public: // Public attributes
  /**  */
  QString displayName;
  /**  */
  QString layerName;
};

#endif
