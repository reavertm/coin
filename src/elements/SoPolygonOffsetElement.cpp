/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2001 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

/*!
  \class SoPolygonOffsetElement Inventor/elements/SoPolygonOffsetElement.h
  \brief The SoPolygonOffsetElement class is yet to be documented.
  \ingroup elements

  FIXME: write doc.
*/

#include <Inventor/elements/SoPolygonOffsetElement.h>
#include <assert.h>

/*!
  \fn SoPolygonOffsetElement::Style

  FIXME: write doc.
*/

/*!
  \fn SoPolygonOffsetElement::style

  FIXME: write doc.
*/

/*!
  \fn SoPolygonOffsetElement::active

  FIXME: write doc.
*/

/*!
  \fn SoPolygonOffsetElement::offsetfactor

  FIXME: write doc.
*/

/*!
  \fn SoPolygonOffsetElement::offsetunits

  FIXME: write doc.
*/

SO_ELEMENT_SOURCE(SoPolygonOffsetElement);

/*!
  This static method initializes static data for the SoPolygonOffsetElement
  class.
*/

void
SoPolygonOffsetElement::initClass(void)
{
  SO_ELEMENT_INIT_CLASS(SoPolygonOffsetElement, inherited);
}

/*!
  The destructor.
*/

SoPolygonOffsetElement::~SoPolygonOffsetElement(void)
{
}

//! FIXME: write doc.

void
SoPolygonOffsetElement::init(SoState * state)
{
  inherited::init(state);
  SoPolygonOffsetElement::getDefault(this->offsetfactor,
                                     this->offsetunits,
                                     this->style,
                                     this->active);
}

//! FIXME: write doc.

void
SoPolygonOffsetElement::set(SoState * state, SoNode * node,
                            float factor, float units, Style styles, SbBool on)
{
  SoPolygonOffsetElement *elem = (SoPolygonOffsetElement *)
    SoReplacedElement::getElement(state, classStackIndex, node);
  elem->setElt(factor, units, styles, on);
}

//! FIXME: write doc.

void
SoPolygonOffsetElement::get(SoState * state, float & factor, float & units,
                            Style & styles, SbBool & on)
{
  const SoPolygonOffsetElement *elem = (SoPolygonOffsetElement *)
    SoElement::getConstElement(state, classStackIndex);

  factor = elem->offsetfactor;
  units = elem->offsetunits;
  styles = elem->style;
  on = elem->active;
}

//! FIXME: write doc.

void
SoPolygonOffsetElement::setElt(float factor, float units,
                               Style styles, SbBool on)
{
  this->offsetfactor = factor;
  this->offsetunits = units;
  this->style = styles;
  this->active = on;
}

//! FIXME: write doc.

void
SoPolygonOffsetElement::getDefault(float & factor, float & units,
                                   Style & styles, SbBool & on)
{
  factor = 0.0f;
  units = 0.0f;
  styles = SoPolygonOffsetElement::FILLED;
  on = FALSE;
}
