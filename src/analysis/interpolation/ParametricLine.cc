/***************************************************************************
                          ParametricLine.cc  -  description
                             -------------------
    copyright            : (C) 2004 by Marco Hugentobler
    email                : mhugent@geo.unizh.ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "ParametricLine.h"
#include <iostream>


void ParametricLine::add( ParametricLine* pl )
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
}

void ParametricLine::calcFirstDer( float t, Vector3D* v )
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
}

void ParametricLine::calcSecDer( float t, Vector3D* v )
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
}

void ParametricLine::calcPoint( float t, Point3D* )
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
}

ParametricLine* ParametricLine::getParent() const
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
  return 0;
}

void ParametricLine::remove( int i )
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
}

void ParametricLine::setControlPoly( QVector<Point3D*>* cp )
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
}

void ParametricLine::setParent( ParametricLine* paral )
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
}

int ParametricLine::getDegree() const
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
  return mDegree;
}

const Point3D* ParametricLine::getControlPoint( int number ) const
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
  return 0;
}

const QVector<Point3D*>* ParametricLine::getControlPoly() const
{
  std::cout << "warning, derive a class from ParametricLine" << std::endl;
  return 0;
}
