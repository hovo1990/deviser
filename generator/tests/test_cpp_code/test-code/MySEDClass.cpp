/**
 * @file MySEDClass.cpp
 * @brief Implementation of the MySEDClass class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
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
 */
#include <sedml/MySEDClass.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new MySEDClass using the given SEDML Level and @ p version values.
 */
MySEDClass::MySEDClass(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mId ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new MySEDClass using the given SedNamespaces object @p sedmlns.
 */
MySEDClass::MySEDClass(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mId ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for MySEDClass.
 */
MySEDClass::MySEDClass(const MySEDClass& orig)
  : SedBase( orig )
  , mId ( orig.mId )
{
}


/*
 * Assignment operator for MySEDClass.
 */
MySEDClass&
MySEDClass::operator=(const MySEDClass& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mId = rhs.mId;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this MySEDClass object.
 */
MySEDClass*
MySEDClass::clone() const
{
  return new MySEDClass(*this);
}


/*
 * Destructor for MySEDClass.
 */
MySEDClass::~MySEDClass()
{
}


/*
 * Returns the value of the "id" attribute of this MySEDClass.
 */
const std::string&
MySEDClass::getId() const
{
  return mId;
}


/*
 * Predicate returning @c true if this MySEDClass's "id" attribute is set.
 */
bool
MySEDClass::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this MySEDClass.
 */
int
MySEDClass::setId(const std::string& id)
{
  mId = id;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this MySEDClass.
 */
int
MySEDClass::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this MySEDClass object.
 */
const std::string&
MySEDClass::getElementName() const
{
  static const string name = "fred";
  return name;
}


/*
 * Returns the libSEDML type code for this MySEDClass object.
 */
int
MySEDClass::getTypeCode() const
{
  return MY_TEST_TYPE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * MySEDClass object have been set.
 */
bool
MySEDClass::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
MySEDClass::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
MySEDClass::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
MySEDClass::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
MySEDClass::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
MySEDClass::readAttributes(
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes&
                             attributes,
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER
                             ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(SedUnknownCoreAttribute);
      log->logError(TestMySEDClassAllowedAttributes, level, version, details);
    }
  }

  // 
  // id SId (use = "optional" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<MySEDClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(TestIdSyntaxRule, level, version, "The id '" + mId + "' does not "
        "conform to the syntax.");
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
MySEDClass::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new MySEDClass_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
MySEDClass_t *
MySEDClass_create(unsigned int level, unsigned int version)
{
  return new MySEDClass(level, version);
}


/*
 * Creates and returns a deep copy of this MySEDClass_t object.
 */
LIBSEDML_EXTERN
MySEDClass_t*
MySEDClass_clone(const MySEDClass_t* msedc)
{
  if (msedc != NULL)
  {
    return static_cast<MySEDClass_t*>(msedc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this MySEDClass_t object.
 */
LIBSEDML_EXTERN
void
MySEDClass_free(MySEDClass_t* msedc)
{
  if (msedc != NULL)
  {
    delete msedc;
  }
}


/*
 * Returns the value of the "id" attribute of this MySEDClass_t.
 */
LIBSEDML_EXTERN
const char *
MySEDClass_getId(const MySEDClass_t * msedc)
{
  if (msedc == NULL)
  {
    return NULL;
  }

  return msedc->getId().empty() ? NULL : safe_strdup(msedc->getId().c_str());
}


/*
 * Predicate returning @c 1 if this MySEDClass_t's "id" attribute is set.
 */
LIBSEDML_EXTERN
int
MySEDClass_isSetId(const MySEDClass_t * msedc)
{
  return (msedc != NULL) ? static_cast<int>(msedc->isSetId()) : 0;
}


/*
 * Sets the value of the "id" attribute of this MySEDClass_t.
 */
LIBSEDML_EXTERN
int
MySEDClass_setId(MySEDClass_t * msedc, const char * id)
{
  return (msedc != NULL) ? msedc->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this MySEDClass_t.
 */
LIBSEDML_EXTERN
int
MySEDClass_unsetId(MySEDClass_t * msedc)
{
  return (msedc != NULL) ? msedc->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * MySEDClass_t object have been set.
 */
LIBSEDML_EXTERN
int
MySEDClass_hasRequiredAttributes(const MySEDClass_t * msedc)
{
  return (msedc != NULL) ? static_cast<int>(msedc->hasRequiredAttributes()) :
    0;
}




LIBSEDML_CPP_NAMESPACE_END


