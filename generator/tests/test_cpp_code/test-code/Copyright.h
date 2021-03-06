/**
 * @file Copyright.h
 * @brief Definition of the Copyright class.
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
 * This file is part of SOMETHING.
 * 

 * Copyright (C) 2013-2016 jointly by the following organizations:
 * 1. Abcdefg
 * 2. Hijklmonp
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class Copyright
 * @sbmlbrief{test} TODO:Definition of the Copyright class.
 */


#ifndef Copyright_H__
#define Copyright_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Copyright : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;

  /** @endcond */

public:

  /**
   * Creates a new Copyright using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Copyright.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Copyright.
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * Copyright.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Copyright(unsigned int level = TestExtension::getDefaultLevel(),
            unsigned int version = TestExtension::getDefaultVersion(),
            unsigned int pkgVersion =
              TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new Copyright using the given TestPkgNamespaces object.
   *
   * @param testns the TestPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Copyright(TestPkgNamespaces *testns);


  /**
   * Copy constructor for Copyright.
   *
   * @param orig the Copyright instance to copy.
   */
  Copyright(const Copyright& orig);


  /**
   * Assignment operator for Copyright.
   *
   * @param rhs the Copyright object whose values are to be used as the basis
   * of the assignment.
   */
  Copyright& operator=(const Copyright& rhs);


  /**
   * Creates and returns a deep copy of this Copyright object.
   *
   * @return a (deep) copy of this Copyright object.
   */
  virtual Copyright* clone() const;


  /**
   * Destructor for Copyright.
   */
  virtual ~Copyright();


  /**
   * Returns the value of the "id" attribute of this Copyright.
   *
   * @return the value of the "id" attribute of this Copyright as a string.
   */
  const std::string& getId() const;


  /**
   * Predicate returning @c true if this Copyright's "id" attribute is set.
   *
   * @return @c true if this Copyright's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this Copyright.
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
   * Unsets the value of the "id" attribute of this Copyright.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Returns the XML element name of this Copyright object.
   *
   * For Copyright, the XML element name is always @c "copyright".
   *
   * @return the name of this element, i.e. @c "copyright".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Copyright object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_TEST_MYBASE, SBMLTestTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * Copyright object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * Copyright have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Copyright object are:
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
 * Creates a new Copyright_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Copyright_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Copyright_t.
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * Copyright_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof Copyright_t
 */
LIBSBML_EXTERN
Copyright_t *
Copyright_create(unsigned int level = TestExtension::getDefaultLevel(),
                 unsigned int version = TestExtension::getDefaultVersion(),
                 unsigned int pkgVersion =
                   TestExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this Copyright_t object.
 *
 * @param c the Copyright_t structure.
 *
 * @return a (deep) copy of this Copyright_t object.
 *
 * @memberof Copyright_t
 */
LIBSBML_EXTERN
Copyright_t*
Copyright_clone(const Copyright_t* c);


/**
 * Frees this Copyright_t object.
 *
 * @param c the Copyright_t structure.
 *
 * @memberof Copyright_t
 */
LIBSBML_EXTERN
void
Copyright_free(Copyright_t* c);


/**
 * Returns the value of the "id" attribute of this Copyright_t.
 *
 * @param c the Copyright_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this Copyright_t as a pointer to
 * a string.
 *
 * @memberof Copyright_t
 */
LIBSBML_EXTERN
const char *
Copyright_getId(const Copyright_t * c);


/**
 * Predicate returning @c 1 if this Copyright_t's "id" attribute is set.
 *
 * @param c the Copyright_t structure.
 *
 * @return @c 1 if this Copyright_t's "id" attribute has been set, otherwise @c
 * 0 is returned.
 *
 * @memberof Copyright_t
 */
LIBSBML_EXTERN
int
Copyright_isSetId(const Copyright_t * c);


/**
 * Sets the value of the "id" attribute of this Copyright_t.
 *
 * @param c the Copyright_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Copyright_t
 */
LIBSBML_EXTERN
int
Copyright_setId(Copyright_t * c, const char * id);


/**
 * Unsets the value of the "id" attribute of this Copyright_t.
 *
 * @param c the Copyright_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Copyright_t
 */
LIBSBML_EXTERN
int
Copyright_unsetId(Copyright_t * c);


/**
 * Predicate returning @c 1 if all the required attributes for this Copyright_t
 * object have been set.
 *
 * @param c the Copyright_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * Copyright_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the Copyright_t object are:
 *
 * @memberof Copyright_t
 */
LIBSBML_EXTERN
int
Copyright_hasRequiredAttributes(const Copyright_t * c);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Copyright_H__ */


