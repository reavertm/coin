/**************************************************************************\
 * 
 *  Copyright (C) 1998-1999 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 73540378 Fax: +47 73943861
 *
\**************************************************************************/

/*!
  \class SoNode SoNode.h Inventor/nodes/SoNode.h
  \brief The SoNode class ...
  \ingroup nodes

  FIXME: write class doc
*/

#include <Inventor/nodes/SoNode.h>

#include <Inventor/SbString.h>
#include <Inventor/SoInput.h>
#include <Inventor/SoOutput.h>
#include <Inventor/fields/SoField.h>
#include <Inventor/nodes/SoNodes.h>

#include <Inventor/actions/SoActions.h>
#include <Inventor/errors/SoDebugError.h>

#include <assert.h>


/*!
  \enum SoNode::Stage
  FIXME: write documentation for enum
*/
/*!
  \var SoNode::Stage SoNode::FIRST_INSTANCE
  FIXME: write documentation for enum definition
*/
/*!
  \var SoNode::Stage SoNode::PROTO_INSTANCE
  FIXME: write documentation for enum definition
*/
/*!
  \var SoNode::Stage SoNode::OTHER_INSTANCE
  FIXME: write documentation for enum definition
*/


/*!
  \var uint32_t SoNode::uniqueId
  FIXME: write doc
*/
/*!
  \var uint32_t SoNode::nextUniqueId
  FIXME: write doc
*/
/*!
  \var int SoNode::nextActionMethodIndex
  FIXME: write doc
*/


// Syntax keywords for writing multiple references in .iv/.wrl files.
#define DEFINITION_KEYWORD "DEF"
#define REFERENCE_KEYWORD "USE"


uint32_t SoNode::nextUniqueId = 0;
int SoNode::nextActionMethodIndex = 0;
SoType SoNode::classTypeId = SoType::badType();


/*!
  FIXME: write function documentation
*/
SoType
SoNode::getClassTypeId(void)
{
  return SoNode::classTypeId;
}

/*!
  Constructor.
*/
SoNode::SoNode()
{
}

/*!
  Destructor.
*/
SoNode::~SoNode()
{
}

/*!
  FIXME: write function documentation
*/
SoNode *
SoNode::copy(SbBool copyConnections) const
{
  SoNode * newnode = (SoNode *)(this->getTypeId().createInstance());
  assert(newnode != NULL);

#if 0 // FIXME: tmp disabled during development. 19980923 mortene.
  newnode->setName(this->getName());
  newnode->copyFieldValues(this);
#endif // disabled

  return newnode;
}


/*!
  FIXME: write function documentation
*/
void
SoNode::notify(SoNotList * list)
{
  // FIXME: should put ourselves in the list. 19990701 mortene.
  inherited::notify(list);
}

/*!
  FIXME: write function documentation
*/
int
SoNode::getActionMethodIndex(const SoType type)
{
  return type.getData();
}

/*!
  Does initialization common for all objects of the
  SoNode class. This includes setting up the
  type system, among other things.
*/
void
SoNode::initClass(void)
{
  // Make sure we only initialize once.
  assert(SoNode::classTypeId == SoType::badType());

  SoNode::classTypeId = SoType::createType(inherited::getClassTypeId(),
					   "Node",
					   NULL,
					   SoNode::nextActionMethodIndex++);

  SoNode::initClasses();
}

/*!
  Clean out all statically allocated resources.
  This method is only useful for debugging purposes.
*/
void
SoNode::cleanClass(void)
{
  SoNode::cleanClasses();
}

/*!
  FIXME: write function documentation
*/
void
SoNode::initClasses(void)
{
#if !defined(COIN_EXCLUDE_SOCAMERA)
  SoCamera::initClass();
#endif // COIN_EXCLUDE_SOCAMERA
#if !defined(COIN_EXCLUDE_SOPERSPECTIVECAMERA)
  SoPerspectiveCamera::initClass();
#endif // COIN_EXCLUDE_SOPERSPECTIVECAMERA
#if !defined(COIN_EXCLUDE_SOORTHOGRAPHICCAMERA)
  SoOrthographicCamera::initClass();
#endif // COIN_EXCLUDE_SOORTHOGRAPHICCAMERA
#if !defined(COIN_EXCLUDE_SOSHAPE)
  SoShape::initClass();
#endif // COIN_EXCLUDE_SOSHAPE
#if !defined(COIN_EXCLUDE_SOANNOTEXT3)
  SoAnnoText3::initClass();
#endif // COIN_EXCLUDE_SOANNOTEXT3
#if !defined(COIN_EXCLUDE_SOASCIITEXT)
  SoAsciiText::initClass();
#endif // COIN_EXCLUDE_SOASCIITEXT
#if !defined(COIN_EXCLUDE_SOCONE)
  SoCone::initClass();
#endif // COIN_EXCLUDE_SOCONE
#if !defined(COIN_EXCLUDE_SOCUBE)
  SoCube::initClass();
#endif // COIN_EXCLUDE_SOCUBE
#if !defined(COIN_EXCLUDE_SOCYLINDER)
  SoCylinder::initClass();
#endif // COIN_EXCLUDE_SOCYLINDER
#if !defined(COIN_EXCLUDE_SOVERTEXSHAPE)
  SoVertexShape::initClass();
#endif // COIN_EXCLUDE_SOVERTEXSHAPE
#if !defined(COIN_EXCLUDE_SONONINDEXEDSHAPE)
  SoNonIndexedShape::initClass();
#endif // COIN_EXCLUDE_SONONINDEXEDSHAPE
#if !defined(COIN_EXCLUDE_SOFACESET)
  SoFaceSet::initClass();
#endif // COIN_EXCLUDE_SOFACESET
#if !defined(COIN_EXCLUDE_SOLINESET)
  SoLineSet::initClass();
#endif // COIN_EXCLUDE_SOLINESET
#if !defined(COIN_EXCLUDE_SOPOINTSET)
  SoPointSet::initClass();
#endif // COIN_EXCLUDE_SOPOINTSET
#if !defined(COIN_EXCLUDE_SOMARKERSET)
  SoMarkerSet::initClass();
#endif // COIN_EXCLUDE_SOMARKERSET
#if !defined(COIN_EXCLUDE_SOQUADMESH)
  SoQuadMesh::initClass();
#endif // COIN_EXCLUDE_SOQUADMESH
#if !defined(COIN_EXCLUDE_SOTRIANGLESTRIPSET)
  SoTriangleStripSet::initClass();
#endif // COIN_EXCLUDE_SOTRIANGLESTRIPSET
#if !defined(COIN_EXCLUDE_SOINDEXEDSHAPE)
  SoIndexedShape::initClass();
#endif // COIN_EXCLUDE_SOINDEXEDSHAPE
#if !defined(COIN_EXCLUDE_SOINDEXEDFACESET)
  SoIndexedFaceSet::initClass();
#endif // COIN_EXCLUDE_SOINDEXEDFACESET
#if !defined(COIN_EXCLUDE_SOINDEXEDLINESET)
  SoIndexedLineSet::initClass();
#endif // COIN_EXCLUDE_SOINDEXEDLINESET
#if !defined(COIN_EXCLUDE_SOINDEXEDTRIANGLESTRIPSET)
  SoIndexedTriangleStripSet::initClass();
#endif // COIN_EXCLUDE_SOINDEXEDTRIANGLESTRIPSET
#if !defined(COIN_EXCLUDE_SOIMAGE)
  SoImage::initClass();
#endif // COIN_EXCLUDE_SOIMAGE
#if !defined(COIN_EXCLUDE_SOINDEXEDNURBSCURVE)
  SoIndexedNurbsCurve::initClass();
#endif // COIN_EXCLUDE_SOINDEXEDNURBSCURVE
#if !defined(COIN_EXCLUDE_SOINDEXEDNURBSSURFACE)
  SoIndexedNurbsSurface::initClass();
#endif // COIN_EXCLUDE_SOINDEXEDNURBSSURFACE
#if !defined(COIN_EXCLUDE_SONURBSCURVE)
  SoNurbsCurve::initClass();
#endif // COIN_EXCLUDE_SONURBSCURVE
#if !defined(COIN_EXCLUDE_SONURBSSURFACE)
  SoNurbsSurface::initClass();
#endif // COIN_EXCLUDE_SONURBSSURFACE
#if !defined(COIN_EXCLUDE_SOSPHERE)
  SoSphere::initClass();
#endif // COIN_EXCLUDE_SOSPHERE
#if !defined(COIN_EXCLUDE_SOTEXT2)
  SoText2::initClass();
#endif // COIN_EXCLUDE_SOTEXT2
#if !defined(COIN_EXCLUDE_SOTEXT3)
  SoText3::initClass();
#endif // COIN_EXCLUDE_SOTEXT3
#if !defined(COIN_EXCLUDE_SOANNOTEXT3PROPERTY)
  SoAnnoText3Property::initClass();
#endif // COIN_EXCLUDE_SOANNOTEXT3PROPERTY
#if !defined(COIN_EXCLUDE_SOGROUP)
  SoGroup::initClass();
#endif // COIN_EXCLUDE_SOGROUP
#if !defined(COIN_EXCLUDE_SOSEPARATOR)
  SoSeparator::initClass();
#endif // COIN_EXCLUDE_SOSEPARATOR
#if !defined(COIN_EXCLUDE_SOANNOTATION)
  SoAnnotation::initClass();
#endif // COIN_EXCLUDE_SOANNOTATION
#if !defined(COIN_EXCLUDE_SOSELECTION)
  SoSelection::initClass();
#endif // COIN_EXCLUDE_SOSELECTION
#if !defined(COIN_EXCLUDE_SOEXTSELECTION)
  SoExtSelection::initClass();
#endif // COIN_EXCLUDE_SOEXTSELECTION
#if !defined(COIN_EXCLUDE_SOLOCATEHIGHLIGHT)
  SoLocateHighlight::initClass();
#endif // COIN_EXCLUDE_SOLOCATEHIGHLIGHT
#if !defined(COIN_EXCLUDE_SOWWWANCHOR)
  SoWWWAnchor::initClass();
#endif // COIN_EXCLUDE_SOWWWANCHOR
#if !defined(COIN_EXCLUDE_SOARRAY)
  SoArray::initClass();
#endif // COIN_EXCLUDE_SOARRAY
#if !defined(COIN_EXCLUDE_SOSWITCH)
  SoSwitch::initClass();
#endif // COIN_EXCLUDE_SOSWITCH
#if !defined(COIN_EXCLUDE_SOBLINKER)
  SoBlinker::initClass();
#endif // COIN_EXCLUDE_SOBLINKER
#if !defined(COIN_EXCLUDE_SOLOD)
  SoLOD::initClass();
#endif // COIN_EXCLUDE_SOLOD
#if !defined(COIN_EXCLUDE_SOLEVELOFSIMPLIFICATION)
  SoLevelOfSimplification::initClass();
#endif // COIN_EXCLUDE_SOLEVELOFSIMPLIFICATION
#if !defined(COIN_EXCLUDE_SOLEVELOFDETAIL)
  SoLevelOfDetail::initClass();
#endif // COIN_EXCLUDE_SOLEVELOFDETAIL
#if !defined(COIN_EXCLUDE_SOMULTIPLECOPY)
  SoMultipleCopy::initClass();
#endif // COIN_EXCLUDE_SOMULTIPLECOPY
#if !defined(COIN_EXCLUDE_SOPATHSWITCH)
  SoPathSwitch::initClass();
#endif // COIN_EXCLUDE_SOPATHSWITCH
#if !defined(COIN_EXCLUDE_SOTRANSFORMSEPARATOR)
  SoTransformSeparator::initClass();
#endif // COIN_EXCLUDE_SOTRANSFORMSEPARATOR
#if !defined(COIN_EXCLUDE_SOTRANSFORMATION)
  SoTransformation::initClass();
#endif // COIN_EXCLUDE_SOTRANSFORMATION
#if !defined(COIN_EXCLUDE_SOANTISQUISH)
  SoAntiSquish::initClass();
#endif // COIN_EXCLUDE_SOANTISQUISH
#if !defined(COIN_EXCLUDE_SOMATRIXTRANSFORM)
  SoMatrixTransform::initClass();
#endif // COIN_EXCLUDE_SOMATRIXTRANSFORM
#if !defined(COIN_EXCLUDE_SOROTATION)
  SoRotation::initClass();
#endif // COIN_EXCLUDE_SOROTATION
#if !defined(COIN_EXCLUDE_SOPENDULUM)
  SoPendulum::initClass();
#endif // COIN_EXCLUDE_SOPENDULUM
#if !defined(COIN_EXCLUDE_SOROTOR)
  SoRotor::initClass();
#endif // COIN_EXCLUDE_SOROTOR
#if !defined(COIN_EXCLUDE_SORESETTRANSFORM)
  SoResetTransform::initClass();
#endif // COIN_EXCLUDE_SORESETTRANSFORM
#if !defined(COIN_EXCLUDE_SOROTATIONXYZ)
  SoRotationXYZ::initClass();
#endif // COIN_EXCLUDE_SOROTATIONXYZ
#if !defined(COIN_EXCLUDE_SOSCALE)
  SoScale::initClass();
#endif // COIN_EXCLUDE_SOSCALE
#if !defined(COIN_EXCLUDE_SOTRANSLATION)
  SoTranslation::initClass();
#endif // COIN_EXCLUDE_SOTRANSLATION
#if !defined(COIN_EXCLUDE_SOSHUTTLE)
  SoShuttle::initClass();
#endif // COIN_EXCLUDE_SOSHUTTLE
#if !defined(COIN_EXCLUDE_SOSURROUNDSCALE)
  SoSurroundScale::initClass();
#endif // COIN_EXCLUDE_SOSURROUNDSCALE
#if !defined(COIN_EXCLUDE_SOTRANSFORM)
  SoTransform::initClass();
#endif // COIN_EXCLUDE_SOTRANSFORM
#if !defined(COIN_EXCLUDE_SOUNITS)
  SoUnits::initClass();
#endif // COIN_EXCLUDE_SOUNITS
#if !defined(COIN_EXCLUDE_SOBASECOLOR)
  SoBaseColor::initClass();
#endif // COIN_EXCLUDE_SOBASECOLOR
#if !defined(COIN_EXCLUDE_SOCALLBACK)
  SoCallback::initClass();
#endif // COIN_EXCLUDE_SOCALLBACK
#if !defined(COIN_EXCLUDE_SOCLIPPLANE)
  SoClipPlane::initClass();
#endif // COIN_EXCLUDE_SOCLIPPLANE
#if !defined(COIN_EXCLUDE_SOCOLORINDEX)
  SoColorIndex::initClass();
#endif // COIN_EXCLUDE_SOCOLORINDEX
#if !defined(COIN_EXCLUDE_SOCOMPLEXITY)
  SoComplexity::initClass();
#endif // COIN_EXCLUDE_SOCOMPLEXITY
#if !defined(COIN_EXCLUDE_SOCOORDINATE3)
  SoCoordinate3::initClass();
#endif // COIN_EXCLUDE_SOCOORDINATE3
#if !defined(COIN_EXCLUDE_SOCOORDINATE4)
  SoCoordinate4::initClass();
#endif // COIN_EXCLUDE_SOCOORDINATE4
#if !defined(COIN_EXCLUDE_SOLIGHT)
  SoLight::initClass();
#endif // COIN_EXCLUDE_SOLIGHT
#if !defined(COIN_EXCLUDE_SODIRECTIONALLIGHT)
  SoDirectionalLight::initClass();
#endif // COIN_EXCLUDE_SODIRECTIONALLIGHT
#if !defined(COIN_EXCLUDE_SOSPOTLIGHT)
  SoSpotLight::initClass();
#endif // COIN_EXCLUDE_SOSPOTLIGHT
#if !defined(COIN_EXCLUDE_SOPOINTLIGHT)
  SoPointLight::initClass();
#endif // COIN_EXCLUDE_SOPOINTLIGHT
#if !defined(COIN_EXCLUDE_SODRAWSTYLE)
  SoDrawStyle::initClass();
#endif // COIN_EXCLUDE_SODRAWSTYLE
#if !defined(COIN_EXCLUDE_SOENVIRONMENT)
  SoEnvironment::initClass();
#endif // COIN_EXCLUDE_SOENVIRONMENT
#if !defined(COIN_EXCLUDE_SOEVENTCALLBACK)
  SoEventCallback::initClass();
#endif // COIN_EXCLUDE_SOEVENTCALLBACK
#if !defined(COIN_EXCLUDE_SOFILE)
  SoFile::initClass();
#endif // COIN_EXCLUDE_SOFILE
#if !defined(COIN_EXCLUDE_SOFONT)
  SoFont::initClass();
#endif // COIN_EXCLUDE_SOFONT
#if !defined(COIN_EXCLUDE_SOFONTSTYLE)
  SoFontStyle::initClass();
#endif // COIN_EXCLUDE_SOFONTSTYLE
#if !defined(COIN_EXCLUDE_SOINFO)
  SoInfo::initClass();
#endif // COIN_EXCLUDE_SOINFO
#if !defined(COIN_EXCLUDE_SOLABEL)
  SoLabel::initClass();
#endif // COIN_EXCLUDE_SOLABEL
#if !defined(COIN_EXCLUDE_SOLIGHTMODEL)
  SoLightModel::initClass();
#endif // COIN_EXCLUDE_SOLIGHTMODEL
#if !defined(COIN_EXCLUDE_SOPROFILE)
  SoProfile::initClass();
#endif // COIN_EXCLUDE_SOPROFILE
#if !defined(COIN_EXCLUDE_SOLINEARPROFILE)
  SoLinearProfile::initClass();
#endif // COIN_EXCLUDE_SOLINEARPROFILE
#if !defined(COIN_EXCLUDE_SONURBSPROFILE)
  SoNurbsProfile::initClass();
#endif // COIN_EXCLUDE_SONURBSPROFILE
#if !defined(COIN_EXCLUDE_SOMATERIAL)
  SoMaterial::initClass();
#endif // COIN_EXCLUDE_SOMATERIAL
#if !defined(COIN_EXCLUDE_SOMATERIALBINDING)
  SoMaterialBinding::initClass();
#endif // COIN_EXCLUDE_SOMATERIALBINDING
#if !defined(COIN_EXCLUDE_SONORMAL)
  SoNormal::initClass();
#endif // COIN_EXCLUDE_SONORMAL
#if !defined(COIN_EXCLUDE_SONORMALBINDING)
  SoNormalBinding::initClass();
#endif // COIN_EXCLUDE_SONORMALBINDING
#if !defined(COIN_EXCLUDE_SOPACKEDCOLOR)
  SoPackedColor::initClass();
#endif // COIN_EXCLUDE_SOPACKEDCOLOR
#if !defined(COIN_EXCLUDE_SOPICKSTYLE)
  SoPickStyle::initClass();
#endif // COIN_EXCLUDE_SOPICKSTYLE
#if !defined(COIN_EXCLUDE_SOPOLYGONOFFSET)
  SoPolygonOffset::initClass();
#endif // COIN_EXCLUDE_SOPOLYGONOFFSET
#if !defined(COIN_EXCLUDE_SOPROFILECOORDINATE2)
  SoProfileCoordinate2::initClass();
#endif // COIN_EXCLUDE_SOPROFILECOORDINATE2
#if !defined(COIN_EXCLUDE_SOPROFILECOORDINATE3)
  SoProfileCoordinate3::initClass();
#endif // COIN_EXCLUDE_SOPROFILECOORDINATE3
#if !defined(COIN_EXCLUDE_SOSHAPEHINTS)
  SoShapeHints::initClass();
#endif // COIN_EXCLUDE_SOSHAPEHINTS
#if !defined(COIN_EXCLUDE_SOTEXTURE2)
  SoTexture2::initClass();
#endif // COIN_EXCLUDE_SOTEXTURE2
#if !defined(COIN_EXCLUDE_SOTEXTURE2TRANSFORM)
  SoTexture2Transform::initClass();
#endif // COIN_EXCLUDE_SOTEXTURE2TRANSFORM
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATE2)
  SoTextureCoordinate2::initClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATE2
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEBINDING)
  SoTextureCoordinateBinding::initClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEBINDING
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEFUNCTION)
  SoTextureCoordinateFunction::initClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEFUNCTION
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEDEFAULT)
  SoTextureCoordinateDefault::initClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEDEFAULT
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEENVIRONMENT)
  SoTextureCoordinateEnvironment::initClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEENVIRONMENT
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEPLANE)
  SoTextureCoordinatePlane::initClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEPLANE
#if !defined(COIN_EXCLUDE_SOVERTEXPROPERTY)
  SoVertexProperty::initClass();
#endif // COIN_EXCLUDE_SOVERTEXPROPERTY
#if !defined(COIN_EXCLUDE_SOWWWINLINE)
  SoWWWInline::initClass();
#endif // COIN_EXCLUDE_SOWWWINLINE
}

/*!
  FIXME: write function documentation
*/
void
SoNode::cleanClasses(void)
{
#if !defined(COIN_EXCLUDE_SOWWWINLINE)
  SoWWWInline::cleanClass();
#endif // COIN_EXCLUDE_SOWWWINLINE
#if !defined(COIN_EXCLUDE_SOVERTEXPROPERTY)
  SoVertexProperty::cleanClass();
#endif // COIN_EXCLUDE_SOVERTEXPROPERTY
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEPLANE)
  SoTextureCoordinatePlane::cleanClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEPLANE
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEENVIRONMENT)
  SoTextureCoordinateEnvironment::cleanClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEENVIRONMENT
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEDEFAULT)
  SoTextureCoordinateDefault::cleanClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEDEFAULT
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEFUNCTION)
  SoTextureCoordinateFunction::cleanClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEFUNCTION
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEBINDING)
  SoTextureCoordinateBinding::cleanClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEBINDING
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATE2)
  SoTextureCoordinate2::cleanClass();
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATE2
#if !defined(COIN_EXCLUDE_SOTEXTURE2TRANSFORM)
  SoTexture2Transform::cleanClass();
#endif // COIN_EXCLUDE_SOTEXTURE2TRANSFORM
#if !defined(COIN_EXCLUDE_SOTEXTURE2)
  SoTexture2::cleanClass();
#endif // COIN_EXCLUDE_SOTEXTURE2
#if !defined(COIN_EXCLUDE_SOSHAPEHINTS)
  SoShapeHints::cleanClass();
#endif // COIN_EXCLUDE_SOSHAPEHINTS
#if !defined(COIN_EXCLUDE_SOPROFILECOORDINATE3)
  SoProfileCoordinate3::cleanClass();
#endif // COIN_EXCLUDE_SOPROFILECOORDINATE3
#if !defined(COIN_EXCLUDE_SOPROFILECOORDINATE2)
  SoProfileCoordinate2::cleanClass();
#endif // COIN_EXCLUDE_SOPROFILECOORDINATE2
#if !defined(COIN_EXCLUDE_SOPOLYGONOFFSET)
  SoPolygonOffset::cleanClass();
#endif // COIN_EXCLUDE_SOPOLYGONOFFSET
#if !defined(COIN_EXCLUDE_SOPICKSTYLE)
  SoPickStyle::cleanClass();
#endif // COIN_EXCLUDE_SOPICKSTYLE
#if !defined(COIN_EXCLUDE_SOPACKEDCOLOR)
  SoPackedColor::cleanClass();
#endif // COIN_EXCLUDE_SOPACKEDCOLOR
#if !defined(COIN_EXCLUDE_SONORMALBINDING)
  SoNormalBinding::cleanClass();
#endif // COIN_EXCLUDE_SONORMALBINDING
#if !defined(COIN_EXCLUDE_SONORMAL)
  SoNormal::cleanClass();
#endif // COIN_EXCLUDE_SONORMAL
#if !defined(COIN_EXCLUDE_SOMATERIALBINDING)
  SoMaterialBinding::cleanClass();
#endif // COIN_EXCLUDE_SOMATERIALBINDING
#if !defined(COIN_EXCLUDE_SOMATERIAL)
  SoMaterial::cleanClass();
#endif // COIN_EXCLUDE_SOMATERIAL
#if !defined(COIN_EXCLUDE_SONURBSPROFILE)
  SoNurbsProfile::cleanClass();
#endif // COIN_EXCLUDE_SONURBSPROFILE
#if !defined(COIN_EXCLUDE_SOLINEARPROFILE)
  SoLinearProfile::cleanClass();
#endif // COIN_EXCLUDE_SOLINEARPROFILE
#if !defined(COIN_EXCLUDE_SOPROFILE)
  SoProfile::cleanClass();
#endif // COIN_EXCLUDE_SOPROFILE
#if !defined(COIN_EXCLUDE_SOLIGHTMODEL)
  SoLightModel::cleanClass();
#endif // COIN_EXCLUDE_SOLIGHTMODEL
#if !defined(COIN_EXCLUDE_SOLABEL)
  SoLabel::cleanClass();
#endif // COIN_EXCLUDE_SOLABEL
#if !defined(COIN_EXCLUDE_SOINFO)
  SoInfo::cleanClass();
#endif // COIN_EXCLUDE_SOINFO
#if !defined(COIN_EXCLUDE_SOFONTSTYLE)
  SoFontStyle::cleanClass();
#endif // COIN_EXCLUDE_SOFONTSTYLE
#if !defined(COIN_EXCLUDE_SOFONT)
  SoFont::cleanClass();
#endif // COIN_EXCLUDE_SOFONT
#if !defined(COIN_EXCLUDE_SOFILE)
  SoFile::cleanClass();
#endif // COIN_EXCLUDE_SOFILE
#if !defined(COIN_EXCLUDE_SOEVENTCALLBACK)
  SoEventCallback::cleanClass();
#endif // COIN_EXCLUDE_SOEVENTCALLBACK
#if !defined(COIN_EXCLUDE_SOENVIRONMENT)
  SoEnvironment::cleanClass();
#endif // COIN_EXCLUDE_SOENVIRONMENT
#if !defined(COIN_EXCLUDE_SODRAWSTYLE)
  SoDrawStyle::cleanClass();
#endif // COIN_EXCLUDE_SODRAWSTYLE
#if !defined(COIN_EXCLUDE_SOPOINTLIGHT)
  SoPointLight::cleanClass();
#endif // COIN_EXCLUDE_SOPOINTLIGHT
#if !defined(COIN_EXCLUDE_SOSPOTLIGHT)
  SoSpotLight::cleanClass();
#endif // COIN_EXCLUDE_SOSPOTLIGHT
#if !defined(COIN_EXCLUDE_SODIRECTIONALLIGHT)
  SoDirectionalLight::cleanClass();
#endif // COIN_EXCLUDE_SODIRECTIONALLIGHT
#if !defined(COIN_EXCLUDE_SOLIGHT)
  SoLight::cleanClass();
#endif // COIN_EXCLUDE_SOLIGHT
#if !defined(COIN_EXCLUDE_SOCOORDINATE4)
  SoCoordinate4::cleanClass();
#endif // COIN_EXCLUDE_SOCOORDINATE4
#if !defined(COIN_EXCLUDE_SOCOORDINATE3)
  SoCoordinate3::cleanClass();
#endif // COIN_EXCLUDE_SOCOORDINATE3
#if !defined(COIN_EXCLUDE_SOCOMPLEXITY)
  SoComplexity::cleanClass();
#endif // COIN_EXCLUDE_SOCOMPLEXITY
#if !defined(COIN_EXCLUDE_SOCOLORINDEX)
  SoColorIndex::cleanClass();
#endif // COIN_EXCLUDE_SOCOLORINDEX
#if !defined(COIN_EXCLUDE_SOCLIPPLANE)
  SoClipPlane::cleanClass();
#endif // COIN_EXCLUDE_SOCLIPPLANE
#if !defined(COIN_EXCLUDE_SOCALLBACK)
  SoCallback::cleanClass();
#endif // COIN_EXCLUDE_SOCALLBACK
#if !defined(COIN_EXCLUDE_SOBASECOLOR)
  SoBaseColor::cleanClass();
#endif // COIN_EXCLUDE_SOBASECOLOR
#if !defined(COIN_EXCLUDE_SOUNITS)
  SoUnits::cleanClass();
#endif // COIN_EXCLUDE_SOUNITS
#if !defined(COIN_EXCLUDE_SOTRANSFORM)
  SoTransform::cleanClass();
#endif // COIN_EXCLUDE_SOTRANSFORM
#if !defined(COIN_EXCLUDE_SOSURROUNDSCALE)
  SoSurroundScale::cleanClass();
#endif // COIN_EXCLUDE_SOSURROUNDSCALE
#if !defined(COIN_EXCLUDE_SOSHUTTLE)
  SoShuttle::cleanClass();
#endif // COIN_EXCLUDE_SOSHUTTLE
#if !defined(COIN_EXCLUDE_SOTRANSLATION)
  SoTranslation::cleanClass();
#endif // COIN_EXCLUDE_SOTRANSLATION
#if !defined(COIN_EXCLUDE_SOSCALE)
  SoScale::cleanClass();
#endif // COIN_EXCLUDE_SOSCALE
#if !defined(COIN_EXCLUDE_SOROTATIONXYZ)
  SoRotationXYZ::cleanClass();
#endif // COIN_EXCLUDE_SOROTATIONXYZ
#if !defined(COIN_EXCLUDE_SORESETTRANSFORM)
  SoResetTransform::cleanClass();
#endif // COIN_EXCLUDE_SORESETTRANSFORM
#if !defined(COIN_EXCLUDE_SOROTOR)
  SoRotor::cleanClass();
#endif // COIN_EXCLUDE_SOROTOR
#if !defined(COIN_EXCLUDE_SOPENDULUM)
  SoPendulum::cleanClass();
#endif // COIN_EXCLUDE_SOPENDULUM
#if !defined(COIN_EXCLUDE_SOROTATION)
  SoRotation::cleanClass();
#endif // COIN_EXCLUDE_SOROTATION
#if !defined(COIN_EXCLUDE_SOMATRIXTRANSFORM)
  SoMatrixTransform::cleanClass();
#endif // COIN_EXCLUDE_SOMATRIXTRANSFORM
#if !defined(COIN_EXCLUDE_SOANTISQUISH)
  SoAntiSquish::cleanClass();
#endif // COIN_EXCLUDE_SOANTISQUISH
#if !defined(COIN_EXCLUDE_SOTRANSFORMATION)
  SoTransformation::cleanClass();
#endif // COIN_EXCLUDE_SOTRANSFORMATION
#if !defined(COIN_EXCLUDE_SOTRANSFORMSEPARATOR)
  SoTransformSeparator::cleanClass();
#endif // COIN_EXCLUDE_SOTRANSFORMSEPARATOR
#if !defined(COIN_EXCLUDE_SOPATHSWITCH)
  SoPathSwitch::cleanClass();
#endif // COIN_EXCLUDE_SOPATHSWITCH
#if !defined(COIN_EXCLUDE_SOMULTIPLECOPY)
  SoMultipleCopy::cleanClass();
#endif // COIN_EXCLUDE_SOMULTIPLECOPY
#if !defined(COIN_EXCLUDE_SOLEVELOFDETAIL)
  SoLevelOfDetail::cleanClass();
#endif // COIN_EXCLUDE_SOLEVELOFDETAIL
#if !defined(COIN_EXCLUDE_SOLEVELOFSIMPLIFICATION)
  SoLevelOfSimplification::cleanClass();
#endif // COIN_EXCLUDE_SOLEVELOFSIMPLIFICATION
#if !defined(COIN_EXCLUDE_SOLOD)
  SoLOD::cleanClass();
#endif // COIN_EXCLUDE_SOLOD
#if !defined(COIN_EXCLUDE_SOBLINKER)
  SoBlinker::cleanClass();
#endif // COIN_EXCLUDE_SOBLINKER
#if !defined(COIN_EXCLUDE_SOSWITCH)
  SoSwitch::cleanClass();
#endif // COIN_EXCLUDE_SOSWITCH
#if !defined(COIN_EXCLUDE_SOARRAY)
  SoArray::cleanClass();
#endif // COIN_EXCLUDE_SOARRAY
#if !defined(COIN_EXCLUDE_SOWWWANCHOR)
  SoWWWAnchor::cleanClass();
#endif // COIN_EXCLUDE_SOWWWANCHOR
#if !defined(COIN_EXCLUDE_SOLOCATEHIGHLIGHT)
  SoLocateHighlight::cleanClass();
#endif // COIN_EXCLUDE_SOLOCATEHIGHLIGHT
#if !defined(COIN_EXCLUDE_SOEXTSELECTION)
  SoExtSelection::cleanClass();
#endif // COIN_EXCLUDE_SOEXTSELECTION
#if !defined(COIN_EXCLUDE_SOSELECTION)
  SoSelection::cleanClass();
#endif // COIN_EXCLUDE_SOSELECTION
#if !defined(COIN_EXCLUDE_SOANNOTATION)
  SoAnnotation::cleanClass();
#endif // COIN_EXCLUDE_SOANNOTATION
#if !defined(COIN_EXCLUDE_SOSEPARATOR)
  SoSeparator::cleanClass();
#endif // COIN_EXCLUDE_SOSEPARATOR
#if !defined(COIN_EXCLUDE_SOGROUP)
  SoGroup::cleanClass();
#endif // COIN_EXCLUDE_SOGROUP
#if !defined(COIN_EXCLUDE_SOANNOTEXT3PROPERTY)
  SoAnnoText3Property::cleanClass();
#endif // COIN_EXCLUDE_SOANNOTEXT3PROPERTY
#if !defined(COIN_EXCLUDE_SOTEXT3)
  SoText3::cleanClass();
#endif // COIN_EXCLUDE_SOTEXT3
#if !defined(COIN_EXCLUDE_SOTEXT2)
  SoText2::cleanClass();
#endif // COIN_EXCLUDE_SOTEXT2
#if !defined(COIN_EXCLUDE_SOSPHERE)
  SoSphere::cleanClass();
#endif // COIN_EXCLUDE_SOSPHERE
#if !defined(COIN_EXCLUDE_SONURBSSURFACE)
  SoNurbsSurface::cleanClass();
#endif // COIN_EXCLUDE_SONURBSSURFACE
#if !defined(COIN_EXCLUDE_SONURBSCURVE)
  SoNurbsCurve::cleanClass();
#endif // COIN_EXCLUDE_SONURBSCURVE
#if !defined(COIN_EXCLUDE_SOINDEXEDNURBSSURFACE)
  SoIndexedNurbsSurface::cleanClass();
#endif // COIN_EXCLUDE_SOINDEXEDNURBSSURFACE
#if !defined(COIN_EXCLUDE_SOINDEXEDNURBSCURVE)
  SoIndexedNurbsCurve::cleanClass();
#endif // COIN_EXCLUDE_SOINDEXEDNURBSCURVE
#if !defined(COIN_EXCLUDE_SOIMAGE)
  SoImage::cleanClass();
#endif // COIN_EXCLUDE_SOIMAGE
#if !defined(COIN_EXCLUDE_SOINDEXEDTRIANGLESTRIPSET)
  SoIndexedTriangleStripSet::cleanClass();
#endif // COIN_EXCLUDE_SOINDEXEDTRIANGLESTRIPSET
#if !defined(COIN_EXCLUDE_SOINDEXEDLINESET)
  SoIndexedLineSet::cleanClass();
#endif // COIN_EXCLUDE_SOINDEXEDLINESET
#if !defined(COIN_EXCLUDE_SOINDEXEDFACESET)
  SoIndexedFaceSet::cleanClass();
#endif // COIN_EXCLUDE_SOINDEXEDFACESET
#if !defined(COIN_EXCLUDE_SOINDEXEDSHAPE)
  SoIndexedShape::cleanClass();
#endif // COIN_EXCLUDE_SOINDEXEDSHAPE
#if !defined(COIN_EXCLUDE_SOTRIANGLESTRIPSET)
  SoTriangleStripSet::cleanClass();
#endif // COIN_EXCLUDE_SOTRIANGLESTRIPSET
#if !defined(COIN_EXCLUDE_SOQUADMESH)
  SoQuadMesh::cleanClass();
#endif // COIN_EXCLUDE_SOQUADMESH
#if !defined(COIN_EXCLUDE_SOMARKERSET)
  SoMarkerSet::cleanClass();
#endif // COIN_EXCLUDE_SOMARKERSET
#if !defined(COIN_EXCLUDE_SOPOINTSET)
  SoPointSet::cleanClass();
#endif // COIN_EXCLUDE_SOPOINTSET
#if !defined(COIN_EXCLUDE_SOLINESET)
  SoLineSet::cleanClass();
#endif // COIN_EXCLUDE_SOLINESET
#if !defined(COIN_EXCLUDE_SOFACESET)
  SoFaceSet::cleanClass();
#endif // COIN_EXCLUDE_SOFACESET
#if !defined(COIN_EXCLUDE_SONONINDEXEDSHAPE)
  SoNonIndexedShape::cleanClass();
#endif // COIN_EXCLUDE_SONONINDEXEDSHAPE
#if !defined(COIN_EXCLUDE_SOVERTEXSHAPE)
  SoVertexShape::cleanClass();
#endif // COIN_EXCLUDE_SOVERTEXSHAPE
#if !defined(COIN_EXCLUDE_SOCYLINDER)
  SoCylinder::cleanClass();
#endif // COIN_EXCLUDE_SOCYLINDER
#if !defined(COIN_EXCLUDE_SOCUBE)
  SoCube::cleanClass();
#endif // COIN_EXCLUDE_SOCUBE
#if !defined(COIN_EXCLUDE_SOCONE)
  SoCone::cleanClass();
#endif // COIN_EXCLUDE_SOCONE
#if !defined(COIN_EXCLUDE_SOASCIITEXT)
  SoAsciiText::cleanClass();
#endif // COIN_EXCLUDE_SOASCIITEXT
#if !defined(COIN_EXCLUDE_SOANNOTEXT3)
  SoAnnoText3::cleanClass();
#endif // COIN_EXCLUDE_SOANNOTEXT3
#if !defined(COIN_EXCLUDE_SOSHAPE)
  SoShape::cleanClass();
#endif // COIN_EXCLUDE_SOSHAPE
#if !defined(COIN_EXCLUDE_SOORTHOGRAPHICCAMERA)
  SoOrthographicCamera::cleanClass();
#endif // COIN_EXCLUDE_SOORTHOGRAPHICCAMERA
#if !defined(COIN_EXCLUDE_SOPERSPECTIVECAMERA)
  SoPerspectiveCamera::cleanClass();
#endif // COIN_EXCLUDE_SOPERSPECTIVECAMERA
#if !defined(COIN_EXCLUDE_SOCAMERA)
  SoCamera::cleanClass();
#endif // COIN_EXCLUDE_SOCAMERA
}

// *************************************************************************

/*!
  FIXME: write function documentation
*/
void
SoNode::setOverride(const SbBool state)
{
  this->stateflags.override = state;
}

/*!
  FIXME: write function documentation
*/
SbBool
SoNode::isOverride(void) const
{
  return this->stateflags.override;
}

// *************************************************************************
// * ACTION STUFF
// *************************************************************************

#if !defined(COIN_EXCLUDE_SOACTION)
/*!
  This function performs the typical operation of a node for any action.
  Default method does nothing.
*/
void
SoNode::doAction(SoAction *)
{
}
#endif // !COIN_EXCLUDE_SOACTION


/*!
  FIXME: write function documentation
*/
SbBool 
SoNode::affectsState() const
{
  return TRUE; // default
}

/*!
  Returns the last node that was give \a name in SoBase::setName()
*/
SoNode *
SoNode::getByName(const SbName & name)
{
  // got to search through dictionary to find the last node with
  // 'name'
  assert(0);
  return NULL;
}

/*!
  Finds all nodes with name set the \a name. Returns the number
  of nodes with the specified name.
*/
int 
SoNode::getByName(const SbName & name, SoNodeList & list)
{
  // FIXME
  assert(0);
  return 0;
}


#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION)
/*!
  FIXME: write function documentation
*/
void
SoNode::getBoundingBoxS(SoAction * const action, SoNode * const node)
{
  assert(action && node);
  //  assert(action->getTypeId().isDerivedFrom(SoGetBoundingBoxAction::getClassTypeId()));
  SoGetBoundingBoxAction * bboxaction = (SoGetBoundingBoxAction *)action;
  bboxaction->checkResetBefore();
  node->getBoundingBox(bboxaction);
  bboxaction->checkResetAfter();
}

/*!
  FIXME: write function documentation
*/
void
SoNode::getBoundingBox(SoGetBoundingBoxAction *)
{
}
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION


#if !defined(COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION)
/*!
  FIXME: write function documentation
*/
void
SoNode::getPrimitiveCountS(SoAction * const action, SoNode * const node)
{
  assert(action && node);
  //  assert(action->getTypeId().isDerivedFrom(SoGetPrimitiveCountAction::getClassTypeId()));
  node->getPrimitiveCount((SoGetPrimitiveCountAction *)action);
}

/*!
  FIXME: write function documentation
*/
void
SoNode::getPrimitiveCount(SoGetPrimitiveCountAction *)
{
}
#endif // !COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION

// *************************************************************************

#if !defined(COIN_EXCLUDE_SOGLRENDERACTION)
/*!
  This static method is used for calling the respective virtual method on the
  node.
*/
void
SoNode::GLRenderS(SoAction * const action,
		  SoNode * const node)
{
  assert(action && node);
  assert(action->getTypeId() == SoGLRenderAction::getClassTypeId());
  SoGLRenderAction * const renderAction =
    (SoGLRenderAction *)(action);
  
  switch (action->getCurPathCode()) {
  case SoAction::NO_PATH:
    node->GLRender(renderAction);
    break;
  case SoAction::IN_PATH:
    node->GLRenderInPath(renderAction);
    break;
  case SoAction::OFF_PATH:
    if (node->affectsState()) node->GLRenderOffPath(renderAction);
    break;
  case SoAction::BELOW_PATH:
    node->GLRenderBelowPath(renderAction);
    break;
  default:
    assert(0 && "Unknown path code");
    break;
  }
}

/*!
  This method is used by SoGLRenderAction render traversals. The default
  method does nothing, of course, so all classes which does rendering
  or influences rendering state need to reimplement this.
*/
void
SoNode::GLRender(SoGLRenderAction * action)
{
}

/*!
  FIXME: write doc
*/
void
SoNode::GLRenderBelowPath(SoGLRenderAction * action)
{
  this->GLRender(action);
}

/*!
  FIXME: write doc
*/
void
SoNode::GLRenderInPath(SoGLRenderAction * action)
{
  this->GLRender(action);
}

/*!
  FIXME: write doc
*/
void
SoNode::GLRenderOffPath(SoGLRenderAction * action)
{
  this->GLRender(action);
}
#endif // !COIN_EXCLUDE_SOGLRENDERACTION

// *************************************************************************

#if !defined(COIN_EXCLUDE_SOCALLBACKACTION)
/*!
  FIXME: write function documentation
*/
void
SoNode::callbackS(SoAction * const action,
		  SoNode * const node)
{
  assert(action && node);
  assert(action->getTypeId() == SoCallbackAction::getClassTypeId());
  SoCallbackAction * const callbackAction =
    (SoCallbackAction *)(action);
  node->callback(callbackAction);
}

/*!
  FIXME: write function documentation
*/
void
SoNode::callback(SoCallbackAction * action)
{
}
#endif // COIN_EXCLUDE_SOCALLBACKACTION

// *************************************************************************

#if !defined(COIN_EXCLUDE_SOGETMATRIXACTION)
/*!
  FIXME: write function documentation
*/
void
SoNode::getMatrixS(SoAction * const action, SoNode * const node)
{
  assert(action && node);
  assert(action->getTypeId() == SoGetMatrixAction::getClassTypeId());
  SoGetMatrixAction * const getMatrixAction =
    (SoGetMatrixAction *)(action);
  node->getMatrix(getMatrixAction);
}

/*!
//FIXME: How does doxygen manage links from classnames in the documentation?
//       (kintel 19990616)
  This is the default virtual function used by SoGetMatrixAction.
  It may be overloaded in subclasses (usually SoTransform subclasses)
*/
void
SoNode::getMatrix(SoGetMatrixAction * action)
{
  //FIXME: This should return identity as default (kintel 19990615)
}
#endif // !COIN_EXCLUDE_SOGETMATRIXACTION

// *************************************************************************

#if !defined(COIN_EXCLUDE_SOHANDLEEVENTACTION)
/*!
  FIXME: write function documentation
*/
void
SoNode::handleEventS(SoAction * const action, SoNode * const node)
{
  assert(action && node);
  assert(action->getTypeId() == SoHandleEventAction::getClassTypeId());
  SoHandleEventAction * const handleEventAction =
    (SoHandleEventAction *)(action);
  node->handleEvent(handleEventAction);
}

/*!
  FIXME: write function documentation
*/
void
SoNode::handleEvent(SoHandleEventAction * action)
{
}
#endif // !COIN_EXCLUDE_SOHANDLEEVENTACTION

// *************************************************************************

#if !defined(COIN_EXCLUDE_SOPICKACTION)
/*!
  FIXME: write function documentation
*/
void
SoNode::pickS(SoAction * const action, SoNode * const node)
{
  assert(action && node);
  assert(action->getTypeId() == SoPickAction::getClassTypeId());
  SoPickAction * const pickAction =
    (SoPickAction *)(action);
  node->pick(pickAction);
}

/*!
  FIXME: write function documentation
*/
void
SoNode::pick(SoPickAction * action)
{
}
#endif // !COIN_EXCLUDE_SOPICKACTION

// *************************************************************************

#if !defined(COIN_EXCLUDE_SORAYPICKACTION)
/*!
  FIXME: write function documentation
*/
void
SoNode::rayPickS(SoAction * const action, SoNode * const node)
{
  assert(action && node);
  assert(action->getTypeId() == SoRayPickAction::getClassTypeId());
  SoRayPickAction * const rayPickAction =
    (SoRayPickAction *)(action);
  node->rayPick(rayPickAction);
}

/*!
  FIXME: write function documentation
*/
void
SoNode::rayPick(SoRayPickAction * action)
{
}
#endif // !COIN_EXCLUDE_SORAYPICKACTION

// *************************************************************************

#if !defined(COIN_EXCLUDE_SOSEARCHACTION)
/*!
  FIXME: write function documentation
*/
void
SoNode::searchS(SoAction * const action, SoNode * const node)
{
  assert(action && node);
  assert(action->getTypeId() == SoSearchAction::getClassTypeId());
  SoSearchAction * const searchAction =
    (SoSearchAction *)(action);
  node->search(searchAction);
}

/*!
  This method is used by SoSearchAction instances to traverse and search the
  scene graph.  It must be overridden in SoSwitch nodes to take into account
  if the search involves every single node, or just the nodes involved in
  normal graph traversal.
*/
void
SoNode::search(SoSearchAction * action)
{
  if (action->isFound())
    return;

  int lookFor = action->getFind();
  SbBool flag;

  if ((lookFor & SoSearchAction::NODE) &&
       (this == action->getNode())) {
    action->addPath(action->getCurPath()->copy());
#if 0 // debug
    SoDebugError::postInfo("SoNode::search", "NODE match found.\n");
#endif // debug
  } else if ((lookFor & SoSearchAction::NAME) && 
      (this->getName() == action->getName())) {
    action->addPath(action->getCurPath()->copy());
#if 0 // debug
    SoDebugError::postInfo("SoNode::search", "NAME match found.\n");
#endif // debug
  } else if ((lookFor & SoSearchAction::TYPE) &&
      ((this->getTypeId() == action->getType(flag)) ||
      (flag && this->getTypeId().isDerivedFrom(action->getType(flag))))) {
    action->addPath(action->getCurPath()->copy());
#if 0 // debug
    SoDebugError::postInfo("SoNode::search", "TYPE match found.\n");
#endif // debug
  }
#if 0 // debug
  else {
    SoDebugError::postInfo("SoNode::search", "no match for %p (type '%s').",
			   this, this->getTypeId().getName().getString());
  }
#endif // debug

  
  //doAction(action);  // this is correct, right? I don't think so: pederb
}

#endif // !COIN_EXCLUDE_SOSEARCHACTION

// *************************************************************************

#if !defined(COIN_EXCLUDE_SOWRITEACTION)
/*!
  FIXME: write function documentation
*/
void
SoNode::writeS(SoAction * const action, SoNode * const node)
{
  assert(action && node);
  assert(action->getTypeId() == SoWriteAction::getClassTypeId());
  SoWriteAction * const writeAction = (SoWriteAction *)(action);
  node->write(writeAction);
}

/*!
  FIXME: write function documentation
*/
void
SoNode::write(SoWriteAction * action)
{
  SoOutput * out = action->getOutput();
  if (out->getStage() == SoOutput::COUNT_REFS) {
    // FIXME: code missing here. 19990701 mortene.
  }
  else if (out->getStage() == SoOutput::WRITE) {
    this->writeInstance(out);
  }
  else assert(0 && "unknown stage");
}
#endif // !COIN_EXCLUDE_SOWRITEACTION

/*!
  FIXME: write function documentation
*/
SoChildList *
SoNode::getChildren(void) const
{
  return NULL;
}

/*!
  FIXME: write doc
*/
void
SoNode::grabEventsSetup(void)
{
  assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write doc
*/
void
SoNode::grabEventsCleanup(void)
{
  assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write doc
*/
void 
SoNode::startNotify(void)
{
  inherited::startNotify();
//    assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write function documentation
*/
uint32_t
SoNode::getNodeId(void) const
{
  return this->uniqueId;
}

/*!
  This method is called from write() if we're in the actual writing pass
  of the write action taking place. It dumps the node to the given output
  stream.
*/
void
SoNode::writeInstance(SoOutput * out)
{
  if (this->writeHeader(out, FALSE, FALSE)) return;

  const SoFieldData * fd = this->getFieldData();
  for (int i=0; i < fd->getNumFields(); i++)
    fd->getField(this, i)->write(out, fd->getFieldName(i));
  
  this->writeFooter(out);
}

/*!
  FIXME: write function documentation
*/
SoNode *
SoNode::addToCopyDict(void) const
{
  assert(0 && "FIXME: not implemented");
  return NULL;
}

/*!
  FIXME: write function documentation
*/
void
SoNode::copyContents(const SoFieldContainer * fromFC, SbBool copyConnections)
{
  assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write function documentation
*/
SoFieldContainer *
SoNode::copyThroughConnection(void) const
{
  assert(0 && "FIXME: not implemented");
  return NULL;
}

/*!
  FIXME: write function documentation
*/
uint32_t
SoNode::getNextNodeId(void)
{
  return SoNode::nextUniqueId;
}

/*!
  FIXME: write function documentation
*/
const SoFieldData **
SoNode::getFieldDataPtr(void)
{
  assert(0 && "FIXME: not implemented");
  return NULL;
}
