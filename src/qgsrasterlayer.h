/***************************************************************************
						  gsrasterlayer.h  -  description
							 -------------------
	begin                : Fri Jun 28 2002
	copyright            : (C) 2002 by Gary E.Sherman
	email                : sherman at mrcc.com
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSRASTERLAYER_H
#define QGSRASTERLAYER_H

#include <qvaluevector.h>

#include "qgsmaplayer.h"

class QgsRect;
class GDALDataset;



struct RasterBandStats {
  QString bandName;
  int bandNo;
  double minValDouble;
  double maxValDouble;
  //the distance between min & max
  double rangeDouble;
  double meanDouble;
  double sumSqrDevDouble; //used to calculate stddev
  double stdDevDouble;
  double sumDouble;
  int elementCountInt;
  double noDataDouble;
};
typedef QMap<QString, RasterBandStats> RasterStatsMap;

/*! \class QgsRasterLayer
 * \brief Raster layer class
 */

class QgsRasterLayer : public QgsMapLayer  {
  Q_OBJECT
    public: 
      //! Constructor
      QgsRasterLayer(QString path = 0, QString baseName = 0);
      //! Destructor
      ~QgsRasterLayer();
      void draw(QPainter * theQPainter, QgsRect * theViewExtent, QgsCoordinateTransform * theQgsCoordinateTransform);
      //void identify(QgsRect *r);

      //
      // Accessor and mutator for showGrayAsColorFlag
      //
      bool getShowGrayAsColorFlag() { return showGrayAsColorFlag;}
      void setShowGrayAsColorFlag(bool theFlag) {showGrayAsColorFlag=theFlag;}
      //
      // Accessor and mutator for invertHistogramFlag
      //
      bool getInvertHistogramFlag() { return invertHistogramFlag; }
      void setInvertHistogramFlag(bool theFlag) { invertHistogramFlag=theFlag; }
      //
      // Accessor and mutator for stdDevsToPlotDouble
      //
      double getStdDevsToPlot() { return stdDevsToPlotDouble; };
      void setStdDevsToPlot(double theDouble) {stdDevsToPlotDouble = theDouble;};
      //get the number of bands in this layer
      const unsigned int getBandCount() {return rasterStatsMap.size();};
      // Get RasterBandStats for a band given its numer (read only)
      const  RasterBandStats getRasterBandStats(int);
      // Overloaded method that also returns stats for a band, but uses the band color name 
      const  RasterBandStats getRasterBandStats(QString theBandName);
      // Find out whether a given band exists 
      bool hasBand(QString theBandName);
      //accessor for transparency level
      unsigned int getTransparency(); 
      // Accessor and mutator for red band name (allows alternate mappings e.g. map blue as red colour)
      QString getRedBandName() {return redBandNameQString;};
      void setRedBandName(QString theBandNameQString);
      // Accessor and mutator for green band name
      QString getGreenBandName() {return greenBandNameQString;};
      void setGreenBandName(QString theBandNameQString);
      // Accessor and mutator for blue band name 
      QString getBlueBandName() {return blueBandNameQString;};
      void setBlueBandName(QString theBandNameQString);
      // Accessor and mutator for gray band name 
      QString getGrayBandName() {return grayBandNameQString;};
      void setGrayBandName(QString theBandNameQString);
      // Accessor and mutator for showDebugOverlayFlag
      bool getShowDebugOverlayFlag() {return showDebugOverlayFlag;};
      void setShowDebugOverlayFlag(bool theFlag) {showDebugOverlayFlag=theFlag;};
      // Accessor and mutator for min and max red
      double getMinRedDouble() {return minRedDouble;};
      void setMinRedDouble(double theDouble) {minRedDouble=theDouble;};
      double getMaxRedDouble() {return maxRedDouble;};
      void setMaxRedDouble(double theDouble) {maxRedDouble=theDouble;};      
      // Accessor and mutator for min and max green
      double getMinGreenDouble() {return minGreenDouble;};
      void setMinGreenDouble(double theDouble) {minGreenDouble=theDouble;};
      double getMaxGreenDouble() {return maxGreenDouble;};
      void setMaxGreenDouble(double theDouble) {maxGreenDouble=theDouble;};  
      // Accessor and mutator for min and max red
      double getMinBlueDouble() {return minBlueDouble;};
      void setMinBlueDouble(double theDouble) {minBlueDouble=theDouble;};
      double getMaxBlueDouble() {return maxBlueDouble;};
      void setMaxBlueDouble(double theDouble) {maxBlueDouble=theDouble;};  
      // Accessor and mutator for min and max red
      double getMinGrayDouble() {return minGrayDouble;};
      void setMinGrayDouble(double theDouble) {minGrayDouble=theDouble;};
      double getMaxGrayDouble() {return maxGrayDouble;};
      void setMaxGrayDouble(double theDouble) {maxGrayDouble=theDouble;};    
      //this enumerator describes the types of scaling algorithms that can be used
      enum COLOR_SCALING_ALGORITHM 
      {
  	STRETCH_TO_MINMAX, //linear histogram stretch
	STRETCH_AND_CLIP_TO_MINMAX,
	CLIP_TO_MINMAX
      };             
      //Accessor and mutator for the color scaling algorithm
      int getColorScalingAlgorithm() {return colorScalingAlgorithm;};
      void setColorScalingAlgorithm(COLOR_SCALING_ALGORITHM theAlgorithm) { colorScalingAlgorithm=theAlgorithm;};
      //get a legend image for this layer
      QPixmap getLegendQPixmap();
      public slots:
          //mutator for transparency
          void slot_setTransparency(unsigned int); //should be between 0 and 255
    // emit a signal asking for a repaint
     void triggerRepaint();
    private:
      //flag to indicate whether debug infor overlay should be rendered onto the raster
      bool showDebugOverlayFlag;
      //private method to calculate various stats about this layer
      void calculateStats();

      GDALDataset  *gdalDataset;
      // values for mapping pixel to world coordinates
      double adfGeoTransform[6];
      // flag indicating whether grayscale images should be rendered as pseudocolor
      bool showGrayAsColorFlag;
      // flag indicating whether the histogram should be inverted or not
      bool invertHistogramFlag;
      // Number of stddev to plot (0) to ignore
      double stdDevsToPlotDouble;
      // a collection of stats - one for each band in the layer 
      // the map key corresonds to the gdal GetColorInterpretation for that band
      RasterStatsMap rasterStatsMap;
      // transparency for this layer should be 0-255
      unsigned int transparencyLevelInt;
      //the band to be associated with the color red - usually 1
      QString redBandNameQString;
      //the band to be associated with the color green - usually 2
      QString greenBandNameQString;
      //the band to be associated with the color blue - usually 3
      QString blueBandNameQString;
      //the band to be associated with the grayscale only ouput - usually 1
      QString grayBandNameQString;
      // minimum red value - used in scaling procedure
      double minRedDouble;
      // maximum red value - used in scaling procedure
      double maxRedDouble;      
      // minimum green value - used in scaling procedure
      double minGreenDouble;
      // maximum green value - used in scaling procedure
      double maxGreenDouble;
      // minimum blue value - used in scaling procedure
      double minBlueDouble;
      // maximum blue value - used in scaling procedure
      double maxBlueDouble;
      // minimum gray value - used in scaling procedure
      double minGrayDouble;
      // maximum gray value - used in scaling procedure
      double maxGrayDouble;
      //the colour scaling algorithm to be used (see enum COLOR_SCALING_ALGORITHM)
      int colorScalingAlgorithm;
signals:
      void repaintRequested();
};

#endif
