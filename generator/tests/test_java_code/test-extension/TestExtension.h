/**
 * @file TestExtension.h
 * @brief Definition of TestExtension.
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
 * @class TestExtension
 * @sbmlbrief{test} Base extension class.
 *
 * @class TestPkgNamespaces
 * @sbmlbrief{test} SBMLNamespaces extension.
 */


#ifndef TestExtension_H__
#define TestExtension_H__


#include <sbml/common/extern.h>
#include <sbml/SBMLTypeCodes.h>


#ifdef __cplusplus


#include <sbml/extension/SBMLExtension.h>
#include <sbml/extension/SBMLExtensionNamespaces.h>
#include <sbml/extension/SBMLExtensionRegister.h>

#ifndef TEST_CREATE_NS
#define TEST_CREATE_NS(variable, sbmlns)\
EXTENSION_CREATE_NS(TestPkgNamespaces, variable, sbmlns);
#endif

#include <vector>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN TestExtension : public SBMLExtension
{
public:

  /**
   * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
   * libSBML extension.
   *
   * @return the package nickname, as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string& getPackageName();


  /**
   * Returns the default SBML Level implemented by this libSBML extension.
   *
   * @return the SBML Level, as an unsigned integer.
   *
   * @copydetails doc_note_static_methods
   */
  static unsigned int getDefaultLevel();


  /**
   * Returns the default SBML Version implemented by this libSBML extension.
   *
   * @return the Version within the default SBML Level, as an unsigned integer.
   *
   * @copydetails doc_note_static_methods
   */
  static unsigned int getDefaultVersion();


  /**
   * Returns the default version of the SBML Level&nbsp;3 package implemented
   * by this libSBML extension.
   *
   * @return the default version number of the SBML Level&nbsp;3 package
   * definition, as an unsigned integer.
   *
   * @copydetails doc_note_static_methods
   */
  static unsigned int getDefaultPackageVersion();


  /**
   * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
   * by this libSBML extension.
   *
   * @return the XML namespace, as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string& getXmlnsL3V1V1();


  /**
   * Creates a new TestExtension instance.
   */
  TestExtension();


  /**
   * Copy constructor for TestExtension.
   *
   * @param orig the TestExtension instance to copy.
   */
  TestExtension(const TestExtension& orig);


  /**
   * Assignment operator for TestExtension.
   *
   * @param rhs the TestExtension object whose values are to be used as the
   * basis of the assignment.
   */
  TestExtension& operator=(const TestExtension& rhs);


  /**
   * Creates and returns a deep copy of this TestExtension object.
   *
   * @return a (deep) copy of this TestExtension object.
   */
  virtual TestExtension* clone() const;


  /**
   * Destructor for TestExtension.
   */
  virtual ~TestExtension();


  /**
   * Returns the name of this SBML Level&nbsp;3 package ("test").
   *
   * @return a string representing the name of this package ("test").
   */
  virtual const std::string& getName() const;


  /**
   * Returns a string representing the SBML XML namespace of this SBML
   * Level&nbsp;3 package.
   *
   * @param sbmlLevel the level of SBML.
   *
   * @param sbmlVersion the version of SBML.
   *
   * @param pkgVersion the version of this package.
   *
   * @return a string representing the name of this package ("test").
   *
   * The namespace URI constructed by this method corresponds to the
   * combination of the Level and Version of SBML, and the Version of the SBML
   * Level&nbsp;3 package. (At the time of this writing, the only SBML Level
   * that supports packages is Level&nbsp;3, so the value of @p sbmlLevel is
   * necessarily always <code>3</code>.)
   */
  virtual const std::string& getURI(unsigned int sbmlLevel,
                                    unsigned int sbmlVersion,
                                    unsigned int pkgVersion) const;


  /**
   * Returns the SBML Level for the given URI of this package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "test" package.
   *
   * @return the SBML Level for the given URI of this package, or @c 0 if the
   * given URI is invalid.
   */
  virtual unsigned int getLevel(const std::string& uri) const;


  /**
   * Returns the Version within the SBML Level for the given URI of this
   * package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "test" package.
   *
   * @return the SBML Version within the SBML Level for the given URI of this
   * package, or @c 0 if the given URI is invalid.
   */
  virtual unsigned int getVersion(const std::string& uri) const;


  /**
   * Returns the SBML Level&nbsp;3 package version for the given URI of this
   * package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "test" package.
   *
   * @return the version of the SBML Level&nbsp;3 package for the given URI of
   * this package, or @c 0 if the given URI is invalid.
   */
  virtual unsigned int getPackageVersion(const std::string& uri) const;


  /**
   * Returns a TestPkgNamespaces object.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "test" package.
   *
   * @return TestPkgNamespaces object corresponding to the given URI of this
   * package, or @c NULL if the given URI is not defined in the "test" package.
   */
  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string& uri)
    const;


  /**
   * Takes a type code of the &ldquo;test&rdquo; package and returns a string
   * describing the code.
   *
   * @param typeCode a libSBML type code defined by the libSBML extension
   * implementing support for the SBML Level&nbsp;3 &ldquo;test&rdquo; package.
   *
   * @return a text string representing the type code given by @p typeCode. If
   * the type code is unrecognized for this implementation of the libSBML
   * &ldquo;test&rdquo; package, the string returned will be <code>"(Unknown
   * SBML Test Type)"</code>.
   */
  virtual const char* getStringFromTypeCode(int typeCode) const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the entry in the error table at this index.
   *
   * @param index an unsigned integer representing the index of the error.
   *
   * @return packageErrorTableEntry object in the TestSBMLErrorTable.
   */
  virtual packageErrorTableEntry getErrorTable(unsigned int index) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Return the index in the error table with the given errorId.
   *
   * @param errorId an unsigned integer representing the errorId of the error.
   *
   * @return unsigned int representing the index in the TestSBMLErrorTable
   * corresponding to the errorId given.
   */
  virtual unsigned int getErrorTableIndex(unsigned int errorId) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the offset for the errorId range for the "test" package.
   *
   * @return unsigned int representing the offset for errors in the
   * TestSBMLErrorTable.
   */
  virtual unsigned int getErrorIdOffset() const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Initializes test extension by creating an object of this class with the
   * required SBasePlugin derived objects and registering the object to the
   * SBMLExtensionRegistry class
   *
   * This function is automatically invoked when creatingthe following global
   * object in TestExtension.cpp
   *
   * static SBMLExtensionRegister<TestExtension> testExtensionRegistry;
   */
  static void init();

  /** @endcond */


};

/**
 *
 * Required typedef definitions
 *
 * TestPkgNamespace is derived from SBMLNamespaces class and used when creating
 * an object of SBase derived classes defined in the test package
 *
 * SBMLExtensionNamespaces<TestExtension> must be instantiated in
 * TestExtension.cpp for DLL
 *
 */
typedef SBMLExtensionNamespaces<TestExtension> TestPkgNamespaces;


LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_BEGIN


/**
 * @enum SBMLTestTypeCode_t
 * @brief SBMLTestTypeCode_t Enumeration of possible types in the libSBML
 * &ldquo;test&rdquo; package implementation.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 */
typedef enum
{
  SBML_TEST_MYBASE         =   100  /*!<MyBase */
, SBML_TEST_CLASSTWO       =   101  /*!<ClassTwo */
, SBML_TEST_CLASSTHREE     =   102  /*!<ClassThree */
} SBMLTestTypeCode_t;


typedef enum
{
  TEST_ENUM_ONE       /*!<One */
, TEST_ENUM_TWO       /*!<Two */
, ENUM_INVALID        /*!<invalid Enum */
} Enum_t;


/**
 */
LIBSBML_EXTERN
const char*
Enum_toString(Enum_t e);


/**
 */
LIBSBML_EXTERN
Enum_t
Enum_fromString(const char* code);


/**
 */
LIBSBML_EXTERN
int
Enum_isValid(Enum_t e);


/**
 */
LIBSBML_EXTERN
int
Enum_isValidString(const char* code);


typedef enum
{
  TEST_FRED_T_TOM        /*!<tom */
, TEST_FRED_T_DICK       /*!<dick */
, FRED_INVALID           /*!<invalid Fred */
} Fred_t;


/**
 */
LIBSBML_EXTERN
const char*
Fred_toString(Fred_t f);


/**
 */
LIBSBML_EXTERN
Fred_t
Fred_fromString(const char* code);


/**
 */
LIBSBML_EXTERN
int
Fred_isValid(Fred_t f);


/**
 */
LIBSBML_EXTERN
int
Fred_isValidString(const char* code);




LIBSBML_CPP_NAMESPACE_END




#endif /* !TestExtension_H__ */


