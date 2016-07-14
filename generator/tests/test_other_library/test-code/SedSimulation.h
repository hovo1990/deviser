/**
 * @file SedSimulation.h
 * @brief Definition of the SedSimulation class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2016, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedSimulation
 * @sbmlbrief{sedml} TODO:Definition of the SedSimulation class.
 */


#ifndef SedSimulation_H__
#define SedSimulation_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedAlgorithm.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedSimulation : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mId;
  std::string mName;
  SedAlgorithm* mAlgorithm;

  /** @endcond */

public:

  /**
   * Creates a new SedSimulation using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedSimulation.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedSimulation.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedSimulation(unsigned int level = SEDML_DEFAULT_LEVEL,
                unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedSimulation using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedSimulation(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedSimulation.
   *
   * @param orig the SedSimulation instance to copy.
   */
  SedSimulation(const SedSimulation& orig);


  /**
   * Assignment operator for SedSimulation.
   *
   * @param rhs the SedSimulation object whose values are to be used as the
   * basis of the assignment.
   */
  SedSimulation& operator=(const SedSimulation& rhs);


  /**
   * Creates and returns a deep copy of this SedSimulation object.
   *
   * @return a (deep) copy of this SedSimulation object.
   */
  virtual SedSimulation* clone() const;


  /**
   * Destructor for SedSimulation.
   */
  virtual ~SedSimulation();


  /**
   * Returns the value of the "id" attribute of this SedSimulation.
   *
   * @return the value of the "id" attribute of this SedSimulation as a string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this SedSimulation.
   *
   * @return the value of the "name" attribute of this SedSimulation as a
   * string.
   */
  const std::string& getName() const;


  /**
   * Predicate returning @c true if this SedSimulation's "id" attribute is set.
   *
   * @return @c true if this SedSimulation's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true if this SedSimulation's "name" attribute is
   * set.
   *
   * @return @c true if this SedSimulation's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetName() const;


  /**
   * Sets the value of the "id" attribute of this SedSimulation.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Sets the value of the "name" attribute of this SedSimulation.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setName(const std::string& name);


  /**
   * Unsets the value of the "id" attribute of this SedSimulation.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "name" attribute of this SedSimulation.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetName();


  /**
   * Returns the value of the "algorithm" element of this SedSimulation.
   *
   * @return the value of the "algorithm" element of this SedSimulation as a
   * SedAlgorithm*.
   */
  const SedAlgorithm* getAlgorithm() const;


  /**
   * Returns the value of the "algorithm" element of this SedSimulation.
   *
   * @return the value of the "algorithm" element of this SedSimulation as a
   * SedAlgorithm*.
   */
  SedAlgorithm* getAlgorithm();


  /**
   * Predicate returning @c true if this SedSimulation's "algorithm" element is
   * set.
   *
   * @return @c true if this SedSimulation's "algorithm" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetAlgorithm() const;


  /**
   * Sets the value of the "algorithm" element of this SedSimulation.
   *
   * @param algorithm SedAlgorithm* value of the "algorithm" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAlgorithm(const SedAlgorithm* algorithm);


  /**
   * Creates a new SedAlgorithm object, adds it to this SedSimulation object
   * and returns the SedAlgorithm object created.
   *
   * @return a new SedAlgorithm object instance.
   */
  SedAlgorithm* createAlgorithm();


  /**
   * Unsets the value of the "algorithm" element of this SedSimulation.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAlgorithm();


  /**
   * Returns the XML element name of this SedSimulation object.
   *
   * For SedSimulation, the XML element name is always @c "simulation".
   *
   * @return the name of this element, i.e. @c "simulation".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedSimulation object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   *
   * @sedmlconstant{SEDML_SIMULATION, SEDMLSedmlTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedSimulation object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedSimulation have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedSimulation object are:
   * @li "id"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedSimulation object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedSimulation have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedSimulation object are:
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Accepts the given SedVisitor
   */
  virtual bool accept(SedVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the parent SedDocument
   */
  virtual void setSedDocument(SedDocument* d);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SedBase element with the given @p id.
   */
  virtual SedBase* getElementBySId(const std::string& id);


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedSimulation_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedSimulation_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedSimulation_t.
 *
 * @throws SEDMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SEDML object, are either invalid or mismatched with respect to the parent
 * SedDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
SedSimulation_t *
SedSimulation_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedSimulation_t object.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @return a (deep) copy of this SedSimulation_t object.
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedSimulation_clone(const SedSimulation_t* ss);


/**
 * Frees this SedSimulation_t object.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
void
SedSimulation_free(SedSimulation_t* ss);


/**
 * Returns the value of the "id" attribute of this SedSimulation_t.
 *
 * @param ss the SedSimulation_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedSimulation_t as a pointer
 * to a string.
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
const char *
SedSimulation_getId(const SedSimulation_t * ss);


/**
 * Returns the value of the "name" attribute of this SedSimulation_t.
 *
 * @param ss the SedSimulation_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedSimulation_t as a
 * pointer to a string.
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
const char *
SedSimulation_getName(const SedSimulation_t * ss);


/**
 * Predicate returning @c 1 if this SedSimulation_t's "id" attribute is set.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @return @c 1 if this SedSimulation_t's "id" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetId(const SedSimulation_t * ss);


/**
 * Predicate returning @c 1 if this SedSimulation_t's "name" attribute is set.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @return @c 1 if this SedSimulation_t's "name" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetName(const SedSimulation_t * ss);


/**
 * Sets the value of the "id" attribute of this SedSimulation_t.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_setId(SedSimulation_t * ss, const char * id);


/**
 * Sets the value of the "name" attribute of this SedSimulation_t.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_setName(SedSimulation_t * ss, const char * name);


/**
 * Unsets the value of the "id" attribute of this SedSimulation_t.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetId(SedSimulation_t * ss);


/**
 * Unsets the value of the "name" attribute of this SedSimulation_t.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetName(SedSimulation_t * ss);


/**
 * Returns the value of the "algorithm" element of this SedSimulation_t.
 *
 * @param ss the SedSimulation_t structure whose algorithm is sought.
 *
 * @return the value of the "algorithm" element of this SedSimulation_t as a
 * SedAlgorithm*.
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedSimulation_getAlgorithm(const SedSimulation_t * ss);


/**
 * Predicate returning @c 1 if this SedSimulation_t's "algorithm" element is
 * set.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @return @c 1 if this SedSimulation_t's "algorithm" element has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetAlgorithm(const SedSimulation_t * ss);


/**
 * Sets the value of the "algorithm" element of this SedSimulation_t.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @param algorithm SedAlgorithm_t* value of the "algorithm" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_setAlgorithm(SedSimulation_t * ss,
                           const SedAlgorithm_t* algorithm);


/**
 * Creates a new SedAlgorithm_t object, adds it to this SedSimulation_t object
 * and returns the SedAlgorithm_t object created.
 *
 * @param ss the SedSimulation_t structure to which the SedAlgorithm_t should
 * be added.
 *
 * @return a new SedAlgorithm_t object instance.
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedSimulation_createAlgorithm(SedSimulation_t* ss);


/**
 * Unsets the value of the "algorithm" element of this SedSimulation_t.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetAlgorithm(SedSimulation_t * ss);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * SedSimulation_t object have been set.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * SedSimulation_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the SedSimulation_t object are:
 * @li "id"
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_hasRequiredAttributes(const SedSimulation_t * ss);


/**
 * Predicate returning @c 1 if all the required elements for this
 * SedSimulation_t object have been set.
 *
 * @param ss the SedSimulation_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this
 * SedSimulation_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the SedSimulation_t object are:
 *
 * @memberof SedSimulation_t
 */
LIBSEDML_EXTERN
int
SedSimulation_hasRequiredElements(const SedSimulation_t * ss);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedSimulation_H__ */


