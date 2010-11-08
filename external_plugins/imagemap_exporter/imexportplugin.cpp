/***************************************************************************
  imexportplugin.cpp 
  Import tool for various worldmap analysis output files
Functions:

-------------------
begin                : Jan 21, 2004
copyright            : (C) 2004 by Tim Sutton
email                : tim@linfiniti.com

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
/*  $Id$ */

// includes

#include <qgisapp.h>
#include <qgsmaplayer.h>
#include <qgsrasterlayer.h>
#include "imexportplugin.h"


#include <qtoolbar.h>
#include <qmenubar.h>
#include <qmessagebox.h>
#include <qpopupmenu.h>
#include <qlineedit.h>
#include <qaction.h>
#include <qapplication.h>
#include <qcursor.h>

//non qt includes
#include <iostream>

//the gui subclass
#include "imexportplugingui.h"

// xpm for creating the toolbar icon
#include "icon.xpm"

#ifdef WIN32
#define QGISEXTERN extern "C" __declspec( dllexport )
#else
#define QGISEXTERN extern "C"
#endif

static const char * const sIdent = "$Id$";
static const char * const sName = "ImageMapExporter";
static const char * const sDescription = "Exports imagemaps for webpages.";
static const char * const sVersion = "Version 0.1";
static const QgisPlugin::PLUGINTYPE sType = QgisPlugin::UI;


//////////////////////////////////////////////////////////////////////
//
// THE FOLLOWING METHODS ARE MANDATORY FOR ALL PLUGINS
//
//////////////////////////////////////////////////////////////////////

/**
 * Constructor for the plugin. The plugin is passed a pointer to the main app
 * and an interface object that provides access to exposed functions in QGIS.
 * @param theQGisApp - Pointer to the QGIS main window
 * @param theQGisInterface - Pointer to the QGIS interface object
 */
IMExportPlugin::IMExportPlugin(QgisApp * theQGisApp, QgisIface * theQgisInterface):
                 mQGisApp(theQGisApp), 
                 mQGisIface(theQgisInterface),
                 QgisPlugin(sName,sDescription,sVersion,sType)
{
}

IMExportPlugin::~IMExportPlugin()
{

}


/*
 * Initialize the GUI interface for the plugin 
 */
void IMExportPlugin::initGui()
{
  QPopupMenu *pluginMenu = mQGisIface->getPluginMenu("&Image Map Exporter");
  mMenuId = pluginMenu->insertItem(QIconSet(icon),"&Image Map Exporter", this, SLOT(run()));

  // Create the action for the tool
  QAction *myQActionPointer = new QAction("Image Map Exporter", QIconSet(icon),
					  "&Wmi",0, this, "run");
  connect(myQActionPointer, SIGNAL(activated()), this, SLOT(run()));
  mQGisIface->addToolBarIcon(myQActionPointer);
}

//method defined in interface
void IMExportPlugin::help()
{
  //implement me!
}

// Slot called when the buffer menu item is activated
void IMExportPlugin::run()
{
  if (mQGisIface->activeLayer() == NULL ||
      mQGisIface->activeLayer()->type() != QgsMapLayer::VECTOR) {
    QMessageBox::critical(mQGisApp, "Error", 
			  "You must select a vector layer.");
    return;
  }
  
  IMExportPluginGui *myPluginGui=new IMExportPluginGui(mQGisIface, mQGisApp,"Image Map Exporter",true,0);
  //listen for when the layer has been made so we can draw it
  connect(myPluginGui, SIGNAL(drawRasterLayer(QString)), this, SLOT(drawRasterLayer(QString)));
  connect(myPluginGui, SIGNAL(drawVectorLayer(QString,QString,QString)), this, SLOT(drawVectorLayer(QString,QString,QString)));
  myPluginGui->show();
}
//!draw a raster layer in the qui - intended to respond to signal sent by diolog when it as finished creating
//layer
void IMExportPlugin::drawRasterLayer(QString theQString)
{
  mQGisIface->addRasterLayer(theQString);
}
//!draw a vector layer in the qui - intended to respond to signal sent by diolog when it as finished creating a layer
////needs to be given vectorLayerPath, baseName, providerKey ("ogr" or "postgres");
void IMExportPlugin::drawVectorLayer(QString thePathNameQString, QString theBaseNameQString, QString theProviderQString)
{
 mQGisIface->addVectorLayer( thePathNameQString, theBaseNameQString, theProviderQString);
}

// Unload the plugin by cleaning up the GUI
void IMExportPlugin::unload()
{
  // remove the GUI
  mQGisIface->removePluginMenuItem("&Image Map Exporter",mMenuId);
  delete mToolBarPointer;
}


//////////////////////////////////////////////////////////////////////////
//
//
//  THE FOLLOWING CODE IS AUTOGENERATED BY THE PLUGIN BUILDER SCRIPT
//    YOU WOULD NORMALLY NOT NEED TO MODIFY THIS, AND YOUR PLUGIN
//      MAY NOT WORK PROPERLY IF YOU MODIFY THIS INCORRECTLY
//
//
//////////////////////////////////////////////////////////////////////////


/** 
 * Required extern functions needed  for every plugin 
 * These functions can be called prior to creating an instance
 * of the plugin class
 */
// Class factory to return a new instance of the plugin class
QGISEXTERN QgisPlugin * classFactory(QgisApp * theQGisAppPointer, QgisIface * theQgisInterfacePointer)
{
  return new IMExportPlugin(theQGisAppPointer, theQgisInterfacePointer);
}
// Return the name of the plugin - note that we do not user class members as
// the class may not yet be insantiated when this method is called.
QGISEXTERN QString name()
{
  return sName;
}

// Return the description
QGISEXTERN QString description()
{
  return sDescription;
}

// Return the type (either UI or MapLayer plugin)
QGISEXTERN int type()
{
  return sType;
}

// Return the version number for the plugin
QGISEXTERN QString version()
{
  return sVersion;
}

// Delete ourself
QGISEXTERN void unload(QgisPlugin * thePluginPointer)
{
  delete thePluginPointer;
}

