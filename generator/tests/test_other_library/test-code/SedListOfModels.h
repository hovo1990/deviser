/**
 * @file SedListOfModels.h
 * @brief Definition of the SedListOfModels class.
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
 * @class SedListOfModels
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfModels class.
 */


#ifndef SedListOfModels_H__
#define SedListOfModels_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedModel.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfModels : public SedListOf
{

public:

  /**
   * Creates a new SedListOfModels using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedListOfModels.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedListOfModels.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedListOfModels(unsigned int level = SEDML_DEFAULT_LEVEL,
                  unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfModels using the given SedNamespaces object @p
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
  SedListOfModels(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfModels.
   *
   * @param orig the SedListOfModels instance to copy.
   */
  SedListOfModels(const SedListOfModels& orig);


  /**
   * Assignment operator for SedListOfModels.
   *
   * @param rhs the SedListOfModels object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfModels& operator=(const SedListOfModels& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfModels object.
   *
   * @return a (deep) copy of this SedListOfModels object.
   */
  virtual SedListOfModels* clone() const;


  /**
   * Destructor for SedListOfModels.
   */
  virtual ~SedListOfModels();


  /**
   * Get a SedModel from the SedListOfModels.
   *
   * @param n an unsigned int representing the index of the SedModel to
   * retrieve.
   *
   * @return the nth SedModel in this SedListOfModels.
   *
   * @see size()
   */
  virtual SedModel* get(unsigned int n);


  /**
   * Get a SedModel from the SedListOfModels.
   *
   * @param n an unsigned int representing the index of the SedModel to
   * retrieve.
   *
   * @return the nth SedModel in this SedListOfModels.
   *
   * @see size()
   */
  virtual const SedModel* get(unsigned int n) const;


  /**
   * Get a SedModel from the SedListOfModels based on its identifier.
   *
   * @param sid a string representing the identifier of the SedModel to
   * retrieve.
   *
   * @return the SedModel in this SedListOfModels with the given id or NULL if
   * no such SedModel exists.
   *
   * @see size()
   */
  virtual SedModel* get(const std::string& sid);


  /**
   * Get a SedModel from the SedListOfModels based on its identifier.
   *
   * @param sid a string representing the identifier of the SedModel to
   * retrieve.
   *
   * @return the SedModel in this SedListOfModels with the given id or NULL if
   * no such SedModel exists.
   *
   * @see size()
   */
  virtual const SedModel* get(const std::string& sid) const;


  /**
   * Removes the nth SedModel from this SedListOfModels and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SedModel to remove.
   *
   * @return a pointer to the nth SedModel in this SedListOfModels.
   *
   * @see size()
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual SedModel* remove(unsigned int n);


  /**
   * Removes the SedModel from this SedListOfModels based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedModel to remove.
   *
   * @return the SedModel in this SedListOfModels based on the identifier or
   * NULL if no such SedModel exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual SedModel* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedModel to this SedListOfModels.
   *
   * @param sm the SedModel object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createModel()
   */
  int addModel(const SedModel* sm);


  /**
   * Get the number of SedModel objects in this SedListOfModels.
   *
   * @return the number of SedModel objects in this SedListOfModels.
   */
  unsigned int getNumModels() const;


  /**
   * Creates a new SedModel object, adds it to this SedListOfModels object and
   * returns the SedModel object created.
   *
   * @return a new SedModel object instance.
   *
   * @see addModel(const SedModel* sm)
   */
  SedModel* createModel();


  /**
   * Returns the XML element name of this SedListOfModels object.
   *
   * For SedListOfModels, the XML element name is always @c "listOfModels".
   *
   * @return the name of this element, i.e. @c "listOfModels".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfModels object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   *
   * @sedmlconstant{SEDML_LIST_OF, SEDMLTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSEDML type code for the SEDML objects contained in this
   * SedListOfModels object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML typecode for the objects contained in this
   * SedListOfModels:
   *
   * @sedmlconstant{SEDML_MODEL, SEDMLSedmlTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode() const;


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new SedModel in this SedListOfModels
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the namespace for the Sedml package
   */
  virtual void writeXMLNS(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedModel_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedModel_t to
 * retrieve.
 *
 * @return the nth SedModel_t in this SedListOf_t.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
const SedModel_t*
SedListOfModels_getModel(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedModel_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedModel_t to
 * retrieve.
 *
 * @return the SedModel_t in this SedListOf_t with the given id or NULL if no
 * such SedModel_t exists.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
const SedModel_t*
SedListOfModels_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedModel_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedModel_t to remove.
 *
 * @return a pointer to the nth SedModel_t in this SedListOf_t.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedListOfModels_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedModel_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedModel_t to remove.
 *
 * @return the SedModel_t in this SedListOf_t based on the identifier or NULL
 * if no such SedModel_t exists.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedListOfModels_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfModels_H__ */


