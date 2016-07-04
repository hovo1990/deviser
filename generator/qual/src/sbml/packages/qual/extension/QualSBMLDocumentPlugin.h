/**
 * @file QualSBMLDocumentPlugin.h
 * @brief Definition of the QualSBMLDocumentPlugin class.
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
 * @class QualSBMLDocumentPlugin
 * @sbmlbrief{qual} Extension of SBMLDocument.
 */


#ifndef QualSBMLDocumentPlugin_H__
#define QualSBMLDocumentPlugin_H__


#include <sbml/common/extern.h>


#ifdef __cplusplus


#include <sbml/extension/SBMLDocumentPlugin.h>
#include <sbml/packages/qual/extension/QualExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN QualSBMLDocumentPlugin : public SBMLDocumentPlugin
{

public:

  /**
   * Creates a new QualSBMLDocumentPlugin using the given uri, prefix and
   * package namespace.
   *
   * @param uri a string, representing the uri of the package.
   *
   * @param prefix a string, the prefix to be used.
   *
   * @param qualns a pointer to the QualPkgNamespaces object to be used.
   */
  QualSBMLDocumentPlugin(const std::string& uri,
                         const std::string& prefix,
                         QualPkgNamespaces* qualns);


  /**
   * Copy constructor for QualSBMLDocumentPlugin.
   *
   * @param orig the QualSBMLDocumentPlugin instance to copy.
   */
  QualSBMLDocumentPlugin(const QualSBMLDocumentPlugin& orig);


  /**
   * Assignment operator for QualSBMLDocumentPlugin.
   *
   * @param rhs the QualSBMLDocumentPlugin object whose values are to be used
   * as the basis of the assignment.
   */
  QualSBMLDocumentPlugin& operator=(const QualSBMLDocumentPlugin& rhs);


  /**
   * Creates and returns a deep copy of this QualSBMLDocumentPlugin object.
   *
   * @return a (deep) copy of this QualSBMLDocumentPlugin object.
   */
  virtual QualSBMLDocumentPlugin* clone() const;


  /**
   * Destructor for QualSBMLDocumentPlugin.
   */
  virtual ~QualSBMLDocumentPlugin();



  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate indicating whether 'comp' flattening has been implemented for
   * the Qual package.
   */
  virtual bool isCompFlatteningImplemented() const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Calls check consistency for any relevant Qual validators.
   */
  virtual unsigned int checkConsistency();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the Qual attributes in the top-level element.
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */




  #endif /* !SWIG */


protected:

};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#endif /* !QualSBMLDocumentPlugin_H__ */


