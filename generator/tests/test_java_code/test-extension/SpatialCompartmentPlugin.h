/**
 * @file SpatialCompartmentPlugin.h
 * @brief Definition of the SpatialCompartmentPlugin class.
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
 * @class SpatialCompartmentPlugin
 * @sbmlbrief{spatial} Extension of Compartment.
 */


#ifndef SpatialCompartmentPlugin_H__
#define SpatialCompartmentPlugin_H__


#include <sbml/common/extern.h>


#ifdef __cplusplus


#include <sbml/extension/SBasePlugin.h>
#include <sbml/packages/spatial/sbml/CompartmentMapping.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN SpatialCompartmentPlugin : public SBasePlugin
{
protected:

  /** @cond doxygenLibsbmlInternal */

  CompartmentMapping* mCompartmentMapping;

  /** @endcond */

public:

  /**
   * Creates a new SpatialCompartmentPlugin using the given uri, prefix and
   * package namespace.
   *
   * @param uri a string, representing the uri of the package.
   *
   * @param prefix a string, the prefix to be used.
   *
   * @param spatialns a pointer to the SpatialPkgNamespaces object to be used.
   */
  SpatialCompartmentPlugin(const std::string& uri,
                           const std::string& prefix,
                           SpatialPkgNamespaces* spatialns);


  /**
   * Copy constructor for SpatialCompartmentPlugin.
   *
   * @param orig the SpatialCompartmentPlugin instance to copy.
   */
  SpatialCompartmentPlugin(const SpatialCompartmentPlugin& orig);


  /**
   * Assignment operator for SpatialCompartmentPlugin.
   *
   * @param rhs the SpatialCompartmentPlugin object whose values are to be used
   * as the basis of the assignment.
   */
  SpatialCompartmentPlugin& operator=(const SpatialCompartmentPlugin& rhs);


  /**
   * Creates and returns a deep copy of this SpatialCompartmentPlugin object.
   *
   * @return a (deep) copy of this SpatialCompartmentPlugin object.
   */
  virtual SpatialCompartmentPlugin* clone() const;


  /**
   * Destructor for SpatialCompartmentPlugin.
   */
  virtual ~SpatialCompartmentPlugin();


  /**
   * Returns the value of the "compartmentMapping" element of this
   * SpatialCompartmentPlugin.
   *
   * @return the value of the "compartmentMapping" element of this
   * SpatialCompartmentPlugin as a CompartmentMapping*.
   */
  const CompartmentMapping* getCompartmentMapping() const;


  /**
   * Returns the value of the "compartmentMapping" element of this
   * SpatialCompartmentPlugin.
   *
   * @return the value of the "compartmentMapping" element of this
   * SpatialCompartmentPlugin as a CompartmentMapping*.
   */
  CompartmentMapping* getCompartmentMapping();


  /**
   * Predicate returning @c true if this SpatialCompartmentPlugin's
   * "compartmentMapping" element is set.
   *
   * @return @c true if this SpatialCompartmentPlugin's "compartmentMapping"
   * element has been set, otherwise @c false is returned.
   */
  bool isSetCompartmentMapping() const;


  /**
   * Sets the value of the "compartmentMapping" element of this
   * SpatialCompartmentPlugin.
   *
   * @param compartmentMapping CompartmentMapping* value of the
   * "compartmentMapping" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCompartmentMapping(const CompartmentMapping* compartmentMapping);


  /**
   * Creates a new CompartmentMapping object, adds it to this
   * SpatialCompartmentPlugin object and returns the CompartmentMapping object
   * created.
   *
   * @return a new CompartmentMapping object instance.
   */
  CompartmentMapping* createCompartmentMapping();


  /**
   * Unsets the value of the "compartmentMapping" element of this
   * SpatialCompartmentPlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCompartmentMapping();


  /**
   * Predicate returning @c true if all the required elements for this
   * SpatialCompartmentPlugin object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SpatialCompartmentPlugin have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SpatialCompartmentPlugin object are:
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
   * Connects to parent element
   */
  virtual void connectToParent(SBase* base);

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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Append items from model (used in comp flattening)
   *
   * @param model a pointer to a model object.
   *
   */
  int appendFrom(const Model* model);

  /** @endcond */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#endif /* !SpatialCompartmentPlugin_H__ */


