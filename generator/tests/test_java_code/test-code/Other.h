/**
 * @file Other.h
 * @brief Definition of the Other class.
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
 * @class Other
 * @sbmlbrief{x} TODO:Definition of the Other class.
 */


#ifndef Other_H__
#define Other_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/x/common/xfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/x/extension/XExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Other : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new Other using the given SBML Level, Version and
   * &ldquo;x&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Other.
   *
   * @param version an unsigned int, the SBML Version to assign to this Other.
   *
   * @param pkgVersion an unsigned int, the SBML X Version to assign to this
   * Other.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Other(unsigned int level = XExtension::getDefaultLevel(),
        unsigned int version = XExtension::getDefaultVersion(),
        unsigned int pkgVersion = XExtension::getDefaultPackageVersion());


  /**
   * Creates a new Other using the given XPkgNamespaces object.
   *
   * @param xns the XPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Other(XPkgNamespaces *xns);


  /**
   * Copy constructor for Other.
   *
   * @param orig the Other instance to copy.
   */
  Other(const Other& orig);


  /**
   * Assignment operator for Other.
   *
   * @param rhs the Other object whose values are to be used as the basis of
   * the assignment.
   */
  Other& operator=(const Other& rhs);


  /**
   * Creates and returns a deep copy of this Other object.
   *
   * @return a (deep) copy of this Other object.
   */
  virtual Other* clone() const;


  /**
   * Destructor for Other.
   */
  virtual ~Other();


  /**
   * Returns the XML element name of this Other object.
   *
   * For Other, the XML element name is always @c "other".
   *
   * @return the name of this element, i.e. @c "other".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the XML name of this Other object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBML type code for this Other object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_X_OTHER, SBMLXTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;



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

};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Other_t using the given SBML Level, Version and
 * &ldquo;x&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Other_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this Other_t.
 *
 * @param pkgVersion an unsigned int, the SBML X Version to assign to this
 * Other_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof Other_t
 */
LIBSBML_EXTERN
Other_t *
Other_create(unsigned int level = XExtension::getDefaultLevel(),
             unsigned int version = XExtension::getDefaultVersion(),
             unsigned int pkgVersion = XExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this Other_t object.
 *
 * @param o the Other_t structure.
 *
 * @return a (deep) copy of this Other_t object.
 *
 * @memberof Other_t
 */
LIBSBML_EXTERN
Other_t*
Other_clone(const Other_t* o);


/**
 * Frees this Other_t object.
 *
 * @param o the Other_t structure.
 *
 * @memberof Other_t
 */
LIBSBML_EXTERN
void
Other_free(Other_t* o);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Other_H__ */


