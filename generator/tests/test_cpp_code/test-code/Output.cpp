/**
 * @file: Output.cpp
 * @brief: Implementation of Output.
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
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
#include <sbml/packages/qual/sbml/Output.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Output using the given SBML @p level, @ p version and package
 * version values.
 */
Output::Output(unsigned int level,
               unsigned int version,
               unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mQualitativeSpecies ("")
  , mTransitionEffect (TRANSITION_OUTPUT_EFFECT_UNKNOWN)
  , mName ("")
  , mOutputLevel (SBML_INT_MAX)
  , mIsSetOutputLevel (false)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new Output using the given QualPkgNamespaces object.
 */
Output::Output(QualPkgNamespaces *qualns)
  : SBase(qualns)
  , mId ("")
  , mQualitativeSpecies ("")
  , mTransitionEffect (TRANSITION_OUTPUT_EFFECT_UNKNOWN)
  , mName ("")
  , mOutputLevel (SBML_INT_MAX)
  , mIsSetOutputLevel (false)
{
  setElementNamespace(qualns->getURI());
  loadPlugins(qualns);
}


/*
 * Copy constructor for Output.
 */
Output::Output(const Output& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mQualitativeSpecies ( orig.mQualitativeSpecies )
  , mTransitionEffect ( orig.mTransitionEffect )
  , mName ( orig.mName )
  , mOutputLevel ( orig.mOutputLevel )
  , mIsSetOutputLevel ( orig.mIsSetOutputLevel )
{
}


/*
 * Assignment operator for Output.
 */
Output&
Output::operator=(const Output& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mQualitativeSpecies = rhs.mQualitativeSpecies;
    mTransitionEffect = rhs.mTransitionEffect;
    mName = rhs.mName;
    mOutputLevel = rhs.mOutputLevel;
    mIsSetOutputLevel = rhs.mIsSetOutputLevel;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Output object.
 */
Output*
Output::clone() const
{
  return new Output(*this);
}


/*
 * Destructor for Output.
 */
Output::~Output()
{
}


/*
 * Returns the value of the "id" attribute of this Output.
 */
const std::string&
Output::getId() const
{
  return mId;
}


/*
 * Returns the value of the "qualitativeSpecies" attribute of this Output.
 */
const std::string&
Output::getQualitativeSpecies() const
{
  return mQualitativeSpecies;
}


/*
 * Returns the value of the "transitionEffect" attribute of this Output.
 */
TransitionOutputEffect_t
Output::getTransitionEffect() const
{
  return mTransitionEffect;
}


/*
 * Returns the value of the "transitionEffect" attribute of this Output.
 */
const std::string&
Output::getTransitionEffectAsString() const
{
  return TransitionOutputEffect_toString(mTransitionEffect);
}


/*
 * Returns the value of the "name" attribute of this Output.
 */
const std::string&
Output::getName() const
{
  return mName;
}


/*
 * Returns the value of the "outputLevel" attribute of this Output.
 */
int
Output::getOutputLevel() const
{
  return mOutputLevel;
}


/*
 * Predicate returning @c true or @c false depending on whether this Output's
 * "id" attribute has been set.
 */
bool
Output::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this Output's
 * "qualitativeSpecies" attribute has been set.
 */
bool
Output::isSetQualitativeSpecies() const
{
  return (mQualitativeSpecies.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this Output's
 * "transitionEffect" attribute has been set.
 */
bool
Output::isSetTransitionEffect() const
{
  return (mTransitionEffect != TRANSITION_OUTPUT_EFFECT_UNKNOWN);
}


/*
 * Predicate returning @c true or @c false depending on whether this Output's
 * "name" attribute has been set.
 */
bool
Output::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this Output's
 * "outputLevel" attribute has been set.
 */
bool
Output::isSetOutputLevel() const
{
  return mIsSetOutputLevel;
}


/*
 * Sets the value of the "id" attribute of this Output.
 */
int
Output::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "qualitativeSpecies" attribute of this Output.
 */
int
Output::setQualitativeSpecies(const std::string& qualitativeSpecies)
{
  if (!(SyntaxChecker::isValidInternalSId(qualitativeSpecies)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mQualitativeSpecies = qualitativeSpecies;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "transitionEffect" attribute of this Output.
 */
int
Output::setTransitionEffect(const TransitionOutputEffect_t transitionEffect)
{
  if (TransitionOutputEffect_isValidTransitionOutputEffect(transitionEffect) ==
    0)
  {
    mTransitionEffect = TRANSITION_OUTPUT_EFFECT_UNKNOWN;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTransitionEffect = transitionEffect;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "transitionEffect" attribute of this Output.
 */
int
Output::setTransitionEffect(const std::string& transitionEffect)
{
  if
    (TransitionOutputEffect_isValidTransitionOutputEffectString(transitionEffect)
      == 0)
  {
    mTransitionEffect = TRANSITION_OUTPUT_EFFECT_UNKNOWN;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTransitionEffect = transitionEffect;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "name" attribute of this Output.
 */
int
Output::setName(const std::string& name)
{
  mName = name;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "outputLevel" attribute of this Output.
 */
int
Output::setOutputLevel(int outputLevel)
{
  mOutputLevel = outputLevel;
  mIsSetOutputLevel = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this Output.
 */
int
Output::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "qualitativeSpecies" attribute of this Output.
 */
int
Output::unsetQualitativeSpecies()
{
  mQualitativeSpecies.erase();

  if (mQualitativeSpecies.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "transitionEffect" attribute of this Output.
 */
int
Output::unsetTransitionEffect()
{
  mTransitionEffect = TRANSITION_OUTPUT_EFFECT_UNKNOWN;
  return LIBSBML_OPERATION_SUCESS;
}


/*
 * Unsets the value of the "name" attribute of this Output.
 */
int
Output::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "outputLevel" attribute of this Output.
 */
int
Output::unsetOutputLevel()
{
  mOutputLevel = SBML_INT_MAX;
  mIsSetOutputLevel = false;

  if (isSetOutputLevel() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * @copydoc doc_renamesidref_common
 */
void
Output::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetQualitativeSpecies() && mQualitativeSpecies == oldid)
  {
    setQualitativeSpecies(newid);
  }
}


/*
 * Returns the XML name of this Output object.
 */
const std::string&
Output::getElementName() const
{
  static const string name = "output";
  return name;
}


/*
 * Returns the libSBML typcode of this Output object.
 */
int
Output::getTypeCode() const
{
  return SBML_QUAL_OUTPUT;
}


/*
 * Predicate returning @c true if all the required attributes for this Output
 * object have been set.
 */
bool
Output::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetQualitativeSpecies() == false)
  {
    allPresent = false;
  }

  if (isSetTransitionEffect() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Output::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);
  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Output::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Output::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Output::enablePackageInternal(const std::string& pkgURI,
                              const std::string& pkgPrefix,
                              bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
Output::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("qualitativeSpecies");

  attributes.add("transitionEffect");

  attributes.add("name");

  attributes.add("outputLevel");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Output::readAttributes(const XMLAttributes& attributes,
                       const ExpectedAttributes& expectedAttributes)

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Output::writeAttributes(XMLOutputStream& stream) const

/** @endcond */




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END

