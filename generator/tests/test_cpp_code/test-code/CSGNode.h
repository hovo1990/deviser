/**
 * @file CSGNode.h
 * @brief Definition of CSGNode.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2015 jointly by the following organizations:
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
 */


#ifndef CSGNode_H__
#define CSGNode_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/spatial/common/spatialfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/spatial/extension/SpatialExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class CSGPrimitive;
class CSGTranslation;
class CSGRotation;
class CSGScale;
class CSGHomogeneousTransformation;
class CSGPseudoPrimitive;
class CSGSetOperator;

class LIBSBML_EXTERN CSGNode : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;

  /** @endcond */

public:

  /**
   * Creates a new CSGNode using the given SBML Level, Version and
   * &ldquo;spatial&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this CSGNode
   *
   * @param version an unsigned int, the SBML Version to assign to this CSGNode
   *
   * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
   * this CSGNode
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  CSGNode(unsigned int level = SpatialExtension::getDefaultLevel(),
          unsigned int version = SpatialExtension::getDefaultVersion(),
          unsigned int pkgVersion =
            SpatialExtension::getDefaultPackageVersion());


  /**
   * Creates a new CSGNode using the given SpatialPkgNamespaces object.
   *
   * @param spatialns the SpatialPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  CSGNode(SpatialPkgNamespaces *spatialns);


  /**
   * Copy constructor for CSGNode.
   *
   * @param orig; the CSGNode instance to copy.
   */
  CSGNode(const CSGNode& orig);


  /**
   * Assignment operator for CSGNode.
   *
   * @param rhs; the CSGNode object whose values are to be used as the basis of
   * the assignment
   */
  CSGNode& operator=(const CSGNode& rhs);


  /**
   * Creates and returns a deep copy of this CSGNode object.
   *
   * @return a (deep) copy of this CSGNode object.
   */
  virtual CSGNode* clone() const;


  /**
   * Destructor for CSGNode.
   */
  virtual ~CSGNode();


  /**
   * Returns the value of the "id" attribute of this CSGNode.
   *
   * @return the value of the "id" attribute of this CSGNode as a string.
   */
  const std::string& getId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * CSGNode's "id" attribute has been set.
   *
   * @return @c true if this CSGNode's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this CSGNode.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Unsets the value of the "id" attribute of this CSGNode.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Predicate returning @c true if this abstract "CSGNode" is of type
   * CSGPrimitive
   *
   * @return @c true if this abstract "CSGNode" is of type CSGPrimitive, @c
   * false otherwise
   */
  virtual bool isCSGPrimitive() const;


  /**
   * Predicate returning @c true if this abstract "CSGNode" is of type
   * CSGTranslation
   *
   * @return @c true if this abstract "CSGNode" is of type CSGTranslation, @c
   * false otherwise
   */
  virtual bool isCSGTranslation() const;


  /**
   * Predicate returning @c true if this abstract "CSGNode" is of type
   * CSGRotation
   *
   * @return @c true if this abstract "CSGNode" is of type CSGRotation, @c
   * false otherwise
   */
  virtual bool isCSGRotation() const;


  /**
   * Predicate returning @c true if this abstract "CSGNode" is of type CSGScale
   *
   * @return @c true if this abstract "CSGNode" is of type CSGScale, @c false
   * otherwise
   */
  virtual bool isCSGScale() const;


  /**
   * Predicate returning @c true if this abstract "CSGNode" is of type
   * CSGHomogeneousTransformation
   *
   * @return @c true if this abstract "CSGNode" is of type
   * CSGHomogeneousTransformation, @c false otherwise
   */
  virtual bool isCSGHomogeneousTransformation() const;


  /**
   * Predicate returning @c true if this abstract "CSGNode" is of type
   * CSGPseudoPrimitive
   *
   * @return @c true if this abstract "CSGNode" is of type CSGPseudoPrimitive,
   * @c false otherwise
   */
  virtual bool isCSGPseudoPrimitive() const;


  /**
   * Predicate returning @c true if this abstract "CSGNode" is of type
   * CSGSetOperator
   *
   * @return @c true if this abstract "CSGNode" is of type CSGSetOperator, @c
   * false otherwise
   */
  virtual bool isCSGSetOperator() const;


  /**
   * Returns the XML element name of this CSGNode object.
   *
   * For CSGNode, the XML element name is always @c "csgNode".
   *
   * @return the name of this element, i.e. @c "csgNode".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this CSGNode object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_SPATIAL_CSGNODE, SBMLSpatialTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * CSGNode object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * CSGNode have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the CSGNode object are:
   */
  virtual bool hasRequiredAttributes() const;



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
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */


protected:


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
 * Creates a new CSGPrimitive (CSGNode_t) using the given SBML Level, Version
 * and &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this CSGNode_t
 *
 * @param version an unsigned int, the SBML Version to assign to this CSGNode_t
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this CSGNode_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
CSGNode_t *
CSGNode_createCSGPrimitive(
                           unsigned int level =
                             SpatialExtension::getDefaultLevel(),
                           unsigned int version =
                             SpatialExtension::getDefaultVersion(),
                           unsigned int pkgVersion =
                             SpatialExtension::getDefaultPackageVersion());


/**
 * Creates a new CSGTranslation (CSGNode_t) using the given SBML Level, Version
 * and &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this CSGNode_t
 *
 * @param version an unsigned int, the SBML Version to assign to this CSGNode_t
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this CSGNode_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
CSGNode_t *
CSGNode_createCSGTranslation(
                             unsigned int level =
                               SpatialExtension::getDefaultLevel(),
                             unsigned int version =
                               SpatialExtension::getDefaultVersion(),
                             unsigned int pkgVersion =
                               SpatialExtension::getDefaultPackageVersion());


/**
 * Creates a new CSGRotation (CSGNode_t) using the given SBML Level, Version
 * and &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this CSGNode_t
 *
 * @param version an unsigned int, the SBML Version to assign to this CSGNode_t
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this CSGNode_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
CSGNode_t *
CSGNode_createCSGRotation(
                          unsigned int level =
                            SpatialExtension::getDefaultLevel(),
                          unsigned int version =
                            SpatialExtension::getDefaultVersion(),
                          unsigned int pkgVersion =
                            SpatialExtension::getDefaultPackageVersion());


/**
 * Creates a new CSGScale (CSGNode_t) using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this CSGNode_t
 *
 * @param version an unsigned int, the SBML Version to assign to this CSGNode_t
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this CSGNode_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
CSGNode_t *
CSGNode_createCSGScale(
                       unsigned int level =
                         SpatialExtension::getDefaultLevel(),
                       unsigned int version =
                         SpatialExtension::getDefaultVersion(),
                       unsigned int pkgVersion =
                         SpatialExtension::getDefaultPackageVersion());


/**
 * Creates a new CSGHomogeneousTransformation (CSGNode_t) using the given SBML
 * Level, Version and &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this CSGNode_t
 *
 * @param version an unsigned int, the SBML Version to assign to this CSGNode_t
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this CSGNode_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
CSGNode_t *
CSGNode_createCSGHomogeneousTransformation(
                                           unsigned int level =
                                             SpatialExtension::getDefaultLevel(),
                                           unsigned int version =
                                             SpatialExtension::getDefaultVersion(),
                                           unsigned int pkgVersion =
                                             SpatialExtension::getDefaultPackageVersion());


/**
 * Creates a new CSGPseudoPrimitive (CSGNode_t) using the given SBML Level,
 * Version and &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this CSGNode_t
 *
 * @param version an unsigned int, the SBML Version to assign to this CSGNode_t
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this CSGNode_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
CSGNode_t *
CSGNode_createCSGPseudoPrimitive(
                                 unsigned int level =
                                   SpatialExtension::getDefaultLevel(),
                                 unsigned int version =
                                   SpatialExtension::getDefaultVersion(),
                                 unsigned int pkgVersion =
                                   SpatialExtension::getDefaultPackageVersion());


/**
 * Creates a new CSGSetOperator (CSGNode_t) using the given SBML Level, Version
 * and &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this CSGNode_t
 *
 * @param version an unsigned int, the SBML Version to assign to this CSGNode_t
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this CSGNode_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
CSGNode_t *
CSGNode_createCSGSetOperator(
                             unsigned int level =
                               SpatialExtension::getDefaultLevel(),
                             unsigned int version =
                               SpatialExtension::getDefaultVersion(),
                             unsigned int pkgVersion =
                               SpatialExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this CSGNode_t object.
 *
 * @param csgn; the CSGNode_t structure
 *
 * @return a (deep) copy of this CSGNode_t object.
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
CSGNode_t*
CSGNode_clone(const CSGNode_t* csgn);


/**
 * Frees this CSGNode_t object.
 *
 * @param csgn; the CSGNode_t structure
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
void
CSGNode_free(CSGNode_t* csgn);


/**
 * Returns the value of the "id" attribute of this CSGNode_t.
 *
 * @param csgn the CSGNode_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this CSGNode_t as a pointer to a
 * string.
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
const char *
CSGNode_getId(const CSGNode_t * csgn);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this CSGNode_t's "id"
 * attribute has been set.
 *
 * @param csgn the CSGNode_t structure.
 *
 * @return @c 1 if this CSGNode_t's "id" attribute has been set, otherwise @c 0
 * is returned.
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_isSetId(const CSGNode_t * csgn);


/**
 * Sets the value of the "id" attribute of this CSGNode_t.
 *
 * @param csgn the CSGNode_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_setId(CSGNode_t * csgn, const char * id);


/**
 * Unsets the value of the "id" attribute of this CSGNode_t.
 *
 * @param csgn the CSGNode_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_unsetId(CSGNode_t * csgn);


/**
 * Predicate returning @c 1 if this CSGNode_t is of type CSGPrimitive_t
 *
 * @param csgn the CSGNode_t structure.
 *
 * @return @c 1 if this CSGNode_t is of type CSGPrimitive_t, @c 0 otherwise
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_isCSGPrimitive(const CSGNode_t * csgn);


/**
 * Predicate returning @c 1 if this CSGNode_t is of type CSGTranslation_t
 *
 * @param csgn the CSGNode_t structure.
 *
 * @return @c 1 if this CSGNode_t is of type CSGTranslation_t, @c 0 otherwise
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_isCSGTranslation(const CSGNode_t * csgn);


/**
 * Predicate returning @c 1 if this CSGNode_t is of type CSGRotation_t
 *
 * @param csgn the CSGNode_t structure.
 *
 * @return @c 1 if this CSGNode_t is of type CSGRotation_t, @c 0 otherwise
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_isCSGRotation(const CSGNode_t * csgn);


/**
 * Predicate returning @c 1 if this CSGNode_t is of type CSGScale_t
 *
 * @param csgn the CSGNode_t structure.
 *
 * @return @c 1 if this CSGNode_t is of type CSGScale_t, @c 0 otherwise
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_isCSGScale(const CSGNode_t * csgn);


/**
 * Predicate returning @c 1 if this CSGNode_t is of type
 * CSGHomogeneousTransformation_t
 *
 * @param csgn the CSGNode_t structure.
 *
 * @return @c 1 if this CSGNode_t is of type CSGHomogeneousTransformation_t, @c
 * 0 otherwise
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_isCSGHomogeneousTransformation(const CSGNode_t * csgn);


/**
 * Predicate returning @c 1 if this CSGNode_t is of type CSGPseudoPrimitive_t
 *
 * @param csgn the CSGNode_t structure.
 *
 * @return @c 1 if this CSGNode_t is of type CSGPseudoPrimitive_t, @c 0
 * otherwise
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_isCSGPseudoPrimitive(const CSGNode_t * csgn);


/**
 * Predicate returning @c 1 if this CSGNode_t is of type CSGSetOperator_t
 *
 * @param csgn the CSGNode_t structure.
 *
 * @return @c 1 if this CSGNode_t is of type CSGSetOperator_t, @c 0 otherwise
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_isCSGSetOperator(const CSGNode_t * csgn);


/**
 * Predicate returning @c 1 if all the required attributes for this CSGNode_t
 * object have been set.
 *
 * @param csgn the CSGNode_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this CSGNode_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the CSGNode_t object are:
 *
 * @memberof CSGNode_t
 */
LIBSBML_EXTERN
int
CSGNode_hasRequiredAttributes(const CSGNode_t * csgn);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !CSGNode_H__ */


