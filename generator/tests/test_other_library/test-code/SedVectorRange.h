/**
 * @file SedVectorRange.h
 * @brief Definition of the SedVectorRange class.
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
 * @class SedVectorRange
 * @sbmlbrief{sedml} TODO:Definition of the SedVectorRange class.
 */


#ifndef SedVectorRange_H__
#define SedVectorRange_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>
#include <vector>


#include <sedml/SedRange.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedVectorRange : public SedRange
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::vector<double> mValue;

  /** @endcond */

public:

  /**
   * Creates a new SedVectorRange using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedVectorRange.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedVectorRange.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedVectorRange(unsigned int level = SEDML_DEFAULT_LEVEL,
                 unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedVectorRange using the given SedNamespaces object @p
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
  SedVectorRange(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedVectorRange.
   *
   * @param orig the SedVectorRange instance to copy.
   */
  SedVectorRange(const SedVectorRange& orig);


  /**
   * Assignment operator for SedVectorRange.
   *
   * @param rhs the SedVectorRange object whose values are to be used as the
   * basis of the assignment.
   */
  SedVectorRange& operator=(const SedVectorRange& rhs);


  /**
   * Creates and returns a deep copy of this SedVectorRange object.
   *
   * @return a (deep) copy of this SedVectorRange object.
   */
  virtual SedVectorRange* clone() const;


  /**
   * Destructor for SedVectorRange.
   */
  virtual ~SedVectorRange();


  /**
   * Returns the value of the "value" attribute of this SedVectorRange.
   *
   * @return the value of the "value" attribute of this SedVectorRange as a
   * vector.
   */
  const std::vector<double>& getValue() const;


  /**
   * Predicate returning @c true if this SedVectorRange's "value" attribute is
   * set.
   *
   * @return @c true if this SedVectorRange's "value" attribute has been set,
   * otherwise @c false is returned.
   */
  bool hasValues() const;


  /**
   * Return the number of elements in this SedVectorRange's "value" attribute.
   *
   * @return the number of elements in the SedVectorRange's "value" attribute.
   */
  unsigned int getNumValues() const;


  /**
   * Sets the value of the "value" attribute of this SedVectorRange.
   *
   * @param value std::vector<double> value of the "value" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setValue(const std::vector<double>& value);


  /**
   * Adds another value to the "value" attribute of this SedVectorRange.
   *
   * @param value double of the "value" attribute to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int addValue(double value);


  /**
   * Clears the "value" element of this SedVectorRange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int clearValues();


  /**
   * Returns the XML element name of this SedVectorRange object.
   *
   * For SedVectorRange, the XML element name is always @c "vectorRange".
   *
   * @return the name of this element, i.e. @c "vectorRange".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedVectorRange object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   *
   * @sedmlconstant{SEDML_RANGE_VECTORRANGE, SEDMLSedmlTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedVectorRange object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedVectorRange have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedVectorRange object are:
   */
  virtual bool hasRequiredAttributes() const;



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
   * Reads other XML such as math/notes etc.
   */
  virtual bool readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

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
 * Creates a new SedVectorRange_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedVectorRange_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedVectorRange_t.
 *
 * @throws SEDMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SEDML object, are either invalid or mismatched with respect to the parent
 * SedDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof SedVectorRange_t
 */
LIBSEDML_EXTERN
SedVectorRange_t *
SedVectorRange_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedVectorRange_t object.
 *
 * @param svr the SedVectorRange_t structure.
 *
 * @return a (deep) copy of this SedVectorRange_t object.
 *
 * @memberof SedVectorRange_t
 */
LIBSEDML_EXTERN
SedVectorRange_t*
SedVectorRange_clone(const SedVectorRange_t* svr);


/**
 * Frees this SedVectorRange_t object.
 *
 * @param svr the SedVectorRange_t structure.
 *
 * @memberof SedVectorRange_t
 */
LIBSEDML_EXTERN
void
SedVectorRange_free(SedVectorRange_t* svr);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * SedVectorRange_t object have been set.
 *
 * @param svr the SedVectorRange_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * SedVectorRange_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the SedVectorRange_t object are:
 *
 * @memberof SedVectorRange_t
 */
LIBSEDML_EXTERN
int
SedVectorRange_hasRequiredAttributes(const SedVectorRange_t * svr);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedVectorRange_H__ */


