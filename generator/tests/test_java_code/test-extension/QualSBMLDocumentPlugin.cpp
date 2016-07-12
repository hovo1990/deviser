/**
 * @file QualSBMLDocumentPlugin.cpp
 * @brief Implementation of the QualSBMLDocumentPlugin class.
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
 */
#include <sbml/packages/qual/extension/QualSBMLDocumentPlugin.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>
#include <sbml/packages/qual/validator/QualConsistencyValidator.h>
#include <sbml/packages/qual/validator/QualIdentifierConsistencyValidator.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new QualSBMLDocumentPlugin using the given uri, prefix and package
 * namespace.
 */
QualSBMLDocumentPlugin::QualSBMLDocumentPlugin(const std::string& uri,
                                               const std::string& prefix,
                                               QualPkgNamespaces* qualns)
  : SBMLDocumentPlugin(uri, prefix, qualns)
{
}


/*
 * Copy constructor for QualSBMLDocumentPlugin.
 */
QualSBMLDocumentPlugin::QualSBMLDocumentPlugin(const QualSBMLDocumentPlugin&
  orig)
  : SBMLDocumentPlugin( orig )
{
}


/*
 * Assignment operator for QualSBMLDocumentPlugin.
 */
QualSBMLDocumentPlugin&
QualSBMLDocumentPlugin::operator=(const QualSBMLDocumentPlugin& rhs)
{
  if (&rhs != this)
  {
    SBMLDocumentPlugin::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this QualSBMLDocumentPlugin object.
 */
QualSBMLDocumentPlugin*
QualSBMLDocumentPlugin::clone() const
{
  return new QualSBMLDocumentPlugin(*this);
}


/*
 * Destructor for QualSBMLDocumentPlugin.
 */
QualSBMLDocumentPlugin::~QualSBMLDocumentPlugin()
{
}



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
QualSBMLDocumentPlugin::accept(SBMLVisitor& v) const
{
  const SBMLDocument* sbmld = static_cast<const
    SBMLDocument*>(this->getParentSBMLObject());
  v.visit(*sbmld);
  v.leave(*sbmld);

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate indicating whether 'comp' flattening has been implemented for the
 * Qual package.
 */
bool
QualSBMLDocumentPlugin::isCompFlatteningImplemented() const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Calls check consistency for any relevant Qual validators.
 */
unsigned int
QualSBMLDocumentPlugin::checkConsistency()
{
  unsigned int nerrors = 0;
  unsigned int total_errors = 0;

  SBMLDocument* doc = static_cast<SBMLDocument*>(this->getParentSBMLObject());
  SBMLErrorLog* log = doc->getErrorLog();

  unsigned char applicableValidators = doc->getApplicableValidators();
  bool id = ((applicableValidators & 0x01) ==0x01);
  bool core = ((applicableValidators & 0x02) ==0x02);

  QualIdentifierConsistencyValidator id_validator;
  QualConsistencyValidator core_validator;

  if (id)
  {
    id_validator.init();
    nerrors = id_validator.validate(*doc);
    total_errors += nerrors;
    if (nerrors > 0)
    {
      log->add(id_validator.getFailures());
      if (log->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) > 0)
      {
        return total_errors;
      }
    }
  }

  if (core)
  {
    core_validator.init();
    nerrors = core_validator.validate(*doc);
    total_errors += nerrors;
    if (nerrors > 0)
    {
      log->add(core_validator.getFailures());
      if (log->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) > 0)
      {
        return total_errors;
      }
    }
  }

  return total_errors;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the Qual attributes in the top-level element.
 */
void
QualSBMLDocumentPlugin::readAttributes(const XMLAttributes& attributes,
                                       const ExpectedAttributes&
                                         expectedAttributes)
{
  if (getSBMLDocument() != NULL && getSBMLDocument()->getLevel() < 3)
  {
    return;
  }

  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs = log->getNumErrors();
  XMLTriple tripleReqd("required", mURI, getPrefix());
  bool assigned = attributes.readInto(tripleReqd, mRequired);

  if (assigned == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("qual", QualAttributeRequiredMustBeBoolean,
        getPackageVersion(), getLevel(), getVersion());
    }
    else
    {
      log->logPackageError("qual", QualAttributeRequiredMissing,
        getPackageVersion(), getLevel(), getVersion());
    }
  }
  else
  {
    mIsSetRequired = true;
    if (mRequired != false)
    {
      log->logPackageError("qual", QualAttributeRequiredMustHaveValue,
        getPackageVersion(), getLevel(), getVersion());
    }
  }
}

/** @endcond */




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END


