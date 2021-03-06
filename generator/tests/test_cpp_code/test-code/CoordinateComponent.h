/**
 * @file CoordinateComponent.h
 * @brief Definition of the CoordinateComponent class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class CoordinateComponent
 * @sbmlbrief{spatial} TODO:Definition of the CoordinateComponent class.
 */


#ifndef CoordinateComponent_H__
#define CoordinateComponent_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/spatial/common/spatialfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/spatial/extension/SpatialExtension.h>
#include <sbml/packages/spatial/sbml/Boundary.h>
#include <sbml/packages/spatial/sbml/Boundary.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN CoordinateComponent : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  CoordinateKind_t mType;
  std::string mUnit;
  Boundary* mBoundaryMin;
  Boundary* mBoundaryMax;

  /** @endcond */

public:

  /**
   * Creates a new CoordinateComponent using the given SBML Level, Version and
   * &ldquo;spatial&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * CoordinateComponent.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * CoordinateComponent.
   *
   * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
   * this CoordinateComponent.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  CoordinateComponent(unsigned int level = SpatialExtension::getDefaultLevel(),
                      unsigned int version =
                        SpatialExtension::getDefaultVersion(),
                      unsigned int pkgVersion =
                        SpatialExtension::getDefaultPackageVersion());


  /**
   * Creates a new CoordinateComponent using the given SpatialPkgNamespaces
   * object.
   *
   * @param spatialns the SpatialPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  CoordinateComponent(SpatialPkgNamespaces *spatialns);


  /**
   * Copy constructor for CoordinateComponent.
   *
   * @param orig the CoordinateComponent instance to copy.
   */
  CoordinateComponent(const CoordinateComponent& orig);


  /**
   * Assignment operator for CoordinateComponent.
   *
   * @param rhs the CoordinateComponent object whose values are to be used as
   * the basis of the assignment.
   */
  CoordinateComponent& operator=(const CoordinateComponent& rhs);


  /**
   * Creates and returns a deep copy of this CoordinateComponent object.
   *
   * @return a (deep) copy of this CoordinateComponent object.
   */
  virtual CoordinateComponent* clone() const;


  /**
   * Destructor for CoordinateComponent.
   */
  virtual ~CoordinateComponent();


  /**
   * Returns the value of the "id" attribute of this CoordinateComponent.
   *
   * @return the value of the "id" attribute of this CoordinateComponent as a
   * string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "type" attribute of this CoordinateComponent.
   *
   * @return the value of the "type" attribute of this CoordinateComponent as a
   * CoordinateKind_t.
   */
  CoordinateKind_t getType() const;


  /**
   * Returns the value of the "type" attribute of this CoordinateComponent.
   *
   * @return the value of the "type" attribute of this CoordinateComponent as a
   * string.
   */
  const std::string& getTypeAsString() const;


  /**
   * Returns the value of the "unit" attribute of this CoordinateComponent.
   *
   * @return the value of the "unit" attribute of this CoordinateComponent as a
   * string.
   */
  const std::string& getUnit() const;


  /**
   * Predicate returning @c true if this CoordinateComponent's "id" attribute
   * is set.
   *
   * @return @c true if this CoordinateComponent's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true if this CoordinateComponent's "type" attribute
   * is set.
   *
   * @return @c true if this CoordinateComponent's "type" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetType() const;


  /**
   * Predicate returning @c true if this CoordinateComponent's "unit" attribute
   * is set.
   *
   * @return @c true if this CoordinateComponent's "unit" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetUnit() const;


  /**
   * Sets the value of the "id" attribute of this CoordinateComponent.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Sets the value of the "type" attribute of this CoordinateComponent.
   *
   * @param type CoordinateKind_t value of the "type" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setType(const CoordinateKind_t type);


  /**
   * Sets the value of the "type" attribute of this CoordinateComponent.
   *
   * @param type std::string& of the "type" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setType(const std::string& type);


  /**
   * Sets the value of the "unit" attribute of this CoordinateComponent.
   *
   * @param unit std::string& value of the "unit" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUnit(const std::string& unit);


  /**
   * Unsets the value of the "id" attribute of this CoordinateComponent.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "type" attribute of this CoordinateComponent.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetType();


  /**
   * Unsets the value of the "unit" attribute of this CoordinateComponent.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUnit();


  /**
   * Returns the value of the "boundaryMin" element of this
   * CoordinateComponent.
   *
   * @return the value of the "boundaryMin" element of this CoordinateComponent
   * as a Boundary*.
   */
  const Boundary* getBoundaryMin() const;


  /**
   * Returns the value of the "boundaryMin" element of this
   * CoordinateComponent.
   *
   * @return the value of the "boundaryMin" element of this CoordinateComponent
   * as a Boundary*.
   */
  Boundary* getBoundaryMin();


  /**
   * Returns the value of the "boundaryMax" element of this
   * CoordinateComponent.
   *
   * @return the value of the "boundaryMax" element of this CoordinateComponent
   * as a Boundary*.
   */
  const Boundary* getBoundaryMax() const;


  /**
   * Returns the value of the "boundaryMax" element of this
   * CoordinateComponent.
   *
   * @return the value of the "boundaryMax" element of this CoordinateComponent
   * as a Boundary*.
   */
  Boundary* getBoundaryMax();


  /**
   * Predicate returning @c true if this CoordinateComponent's "boundaryMin"
   * element is set.
   *
   * @return @c true if this CoordinateComponent's "boundaryMin" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetBoundaryMin() const;


  /**
   * Predicate returning @c true if this CoordinateComponent's "boundaryMax"
   * element is set.
   *
   * @return @c true if this CoordinateComponent's "boundaryMax" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetBoundaryMax() const;


  /**
   * Sets the value of the "boundaryMin" element of this CoordinateComponent.
   *
   * @param boundaryMin Boundary* value of the "boundaryMin" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBoundaryMin(const Boundary* boundaryMin);


  /**
   * Sets the value of the "boundaryMax" element of this CoordinateComponent.
   *
   * @param boundaryMax Boundary* value of the "boundaryMax" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBoundaryMax(const Boundary* boundaryMax);


  /**
   * Creates a new Boundary object, adds it to this CoordinateComponent object
   * and returns the Boundary object created.
   *
   * @return a new Boundary object instance.
   */
  Boundary* createBoundaryMin();


  /**
   * Creates a new Boundary object, adds it to this CoordinateComponent object
   * and returns the Boundary object created.
   *
   * @return a new Boundary object instance.
   */
  Boundary* createBoundaryMax();


  /**
   * Unsets the value of the "boundaryMin" element of this CoordinateComponent.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBoundaryMin();


  /**
   * Unsets the value of the "boundaryMax" element of this CoordinateComponent.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBoundaryMax();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this CoordinateComponent object.
   *
   * For CoordinateComponent, the XML element name is always @c
   * "coordinateComponent".
   *
   * @return the name of this element, i.e. @c "coordinateComponent".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this CoordinateComponent object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_SPATIAL_COORDINATECOMPONENT, SBMLSpatialTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * CoordinateComponent object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * CoordinateComponent have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the CoordinateComponent object are:
   * @li "id"
   * @li "type"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * CoordinateComponent object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * CoordinateComponent have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the CoordinateComponent object are:
   * @li "boundaryMin"
   * @li "boundaryMax"
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument
   */
  virtual void setSBMLDocument(SBMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * filter, an ElementFilter that may impose restrictions on the objects to be
   * retrieved.
   *
   * @return a List* pointer of pointers to all SBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(ElementFilter * filter = NULL);


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new CoordinateComponent_t using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * CoordinateComponent_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * CoordinateComponent_t.
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this CoordinateComponent_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
CoordinateComponent_t *
CoordinateComponent_create(
                           unsigned int level =
                             SpatialExtension::getDefaultLevel(),
                           unsigned int version =
                             SpatialExtension::getDefaultVersion(),
                           unsigned int pkgVersion =
                             SpatialExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this CoordinateComponent_t object.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @return a (deep) copy of this CoordinateComponent_t object.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
CoordinateComponent_t*
CoordinateComponent_clone(const CoordinateComponent_t* cc);


/**
 * Frees this CoordinateComponent_t object.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
void
CoordinateComponent_free(CoordinateComponent_t* cc);


/**
 * Returns the value of the "id" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this CoordinateComponent_t as a
 * pointer to a string.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
const char *
CoordinateComponent_getId(const CoordinateComponent_t * cc);


/**
 * Returns the value of the "type" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this CoordinateComponent_t as a
 * CoordinateKind_t.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
CoordinateKind_t
CoordinateComponent_getType(const CoordinateComponent_t * cc);


/**
 * Returns the value of the "type" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this CoordinateComponent_t as a
 * const char *.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
const char *
CoordinateComponent_getTypeAsString(const CoordinateComponent_t * cc);


/**
 * Returns the value of the "unit" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure whose unit is sought.
 *
 * @return the value of the "unit" attribute of this CoordinateComponent_t as a
 * pointer to a string.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
const char *
CoordinateComponent_getUnit(const CoordinateComponent_t * cc);


/**
 * Predicate returning @c 1 if this CoordinateComponent_t's "id" attribute is
 * set.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @return @c 1 if this CoordinateComponent_t's "id" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetId(const CoordinateComponent_t * cc);


/**
 * Predicate returning @c 1 if this CoordinateComponent_t's "type" attribute is
 * set.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @return @c 1 if this CoordinateComponent_t's "type" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetType(const CoordinateComponent_t * cc);


/**
 * Predicate returning @c 1 if this CoordinateComponent_t's "unit" attribute is
 * set.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @return @c 1 if this CoordinateComponent_t's "unit" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetUnit(const CoordinateComponent_t * cc);


/**
 * Sets the value of the "id" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_setId(CoordinateComponent_t * cc, const char * id);


/**
 * Sets the value of the "type" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @param type CoordinateKind_t value of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_setType(CoordinateComponent_t * cc,
                            CoordinateKind_t type);


/**
 * Sets the value of the "type" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @param type const char * of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_setTypeAsString(CoordinateComponent_t * cc,
                                    const char * type);


/**
 * Sets the value of the "unit" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @param unit const char * value of the "unit" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_setUnit(CoordinateComponent_t * cc, const char * unit);


/**
 * Unsets the value of the "id" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetId(CoordinateComponent_t * cc);


/**
 * Unsets the value of the "type" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetType(CoordinateComponent_t * cc);


/**
 * Unsets the value of the "unit" attribute of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetUnit(CoordinateComponent_t * cc);


/**
 * Returns the value of the "boundaryMin" element of this
 * CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure whose boundaryMin is sought.
 *
 * @return the value of the "boundaryMin" element of this CoordinateComponent_t
 * as a Boundary*.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
const Boundary_t*
CoordinateComponent_getBoundaryMin(const CoordinateComponent_t * cc);


/**
 * Returns the value of the "boundaryMax" element of this
 * CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure whose boundaryMax is sought.
 *
 * @return the value of the "boundaryMax" element of this CoordinateComponent_t
 * as a Boundary*.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
const Boundary_t*
CoordinateComponent_getBoundaryMax(const CoordinateComponent_t * cc);


/**
 * Predicate returning @c 1 if this CoordinateComponent_t's "boundaryMin"
 * element is set.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @return @c 1 if this CoordinateComponent_t's "boundaryMin" element has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetBoundaryMin(const CoordinateComponent_t * cc);


/**
 * Predicate returning @c 1 if this CoordinateComponent_t's "boundaryMax"
 * element is set.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @return @c 1 if this CoordinateComponent_t's "boundaryMax" element has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetBoundaryMax(const CoordinateComponent_t * cc);


/**
 * Sets the value of the "boundaryMin" element of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @param boundaryMin Boundary_t* value of the "boundaryMin" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_setBoundaryMin(CoordinateComponent_t * cc,
                                   const Boundary_t* boundaryMin);


/**
 * Sets the value of the "boundaryMax" element of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @param boundaryMax Boundary_t* value of the "boundaryMax" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_setBoundaryMax(CoordinateComponent_t * cc,
                                   const Boundary_t* boundaryMax);


/**
 * Creates a new Boundary_t object, adds it to this CoordinateComponent_t
 * object and returns the Boundary_t object created.
 *
 * @param cc the CoordinateComponent_t structure to which the Boundary_t should
 * be added.
 *
 * @return a new Boundary_t object instance.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
Boundary_t*
CoordinateComponent_createBoundaryMin(CoordinateComponent_t* cc);


/**
 * Creates a new Boundary_t object, adds it to this CoordinateComponent_t
 * object and returns the Boundary_t object created.
 *
 * @param cc the CoordinateComponent_t structure to which the Boundary_t should
 * be added.
 *
 * @return a new Boundary_t object instance.
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
Boundary_t*
CoordinateComponent_createBoundaryMax(CoordinateComponent_t* cc);


/**
 * Unsets the value of the "boundaryMin" element of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetBoundaryMin(CoordinateComponent_t * cc);


/**
 * Unsets the value of the "boundaryMax" element of this CoordinateComponent_t.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetBoundaryMax(CoordinateComponent_t * cc);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * CoordinateComponent_t object have been set.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * CoordinateComponent_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the CoordinateComponent_t object are:
 * @li "id"
 * @li "type"
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_hasRequiredAttributes(const CoordinateComponent_t * cc);


/**
 * Predicate returning @c 1 if all the required elements for this
 * CoordinateComponent_t object have been set.
 *
 * @param cc the CoordinateComponent_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this
 * CoordinateComponent_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the CoordinateComponent_t object are:
 * @li "boundaryMin"
 * @li "boundaryMax"
 *
 * @memberof CoordinateComponent_t
 */
LIBSBML_EXTERN
int
CoordinateComponent_hasRequiredElements(const CoordinateComponent_t * cc);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !CoordinateComponent_H__ */


