/**
 * @file Member.cpp
 * @brief Implementation of the Member class.
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
#include <sbml/packages/groups/sbml/Member.h>
#include <sbml/packages/groups/sbml/ListOfMembers.h>
#include <sbml/packages/groups/validator/GroupsSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Member using the given SBML Level, Version and
 * &ldquo;groups&rdquo; package version.
 */
Member::Member(unsigned int level,
               unsigned int version,
               unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mName ("")
  , mIdRef ("")
  , mMetaIdRef ("")
{
  setSBMLNamespacesAndOwn(new GroupsPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new Member using the given GroupsPkgNamespaces object.
 */
Member::Member(GroupsPkgNamespaces *groupsns)
  : SBase(groupsns)
  , mId ("")
  , mName ("")
  , mIdRef ("")
  , mMetaIdRef ("")
{
  setElementNamespace(groupsns->getURI());
  loadPlugins(groupsns);
}


/*
 * Copy constructor for Member.
 */
Member::Member(const Member& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mName ( orig.mName )
  , mIdRef ( orig.mIdRef )
  , mMetaIdRef ( orig.mMetaIdRef )
{
}


/*
 * Assignment operator for Member.
 */
Member&
Member::operator=(const Member& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mName = rhs.mName;
    mIdRef = rhs.mIdRef;
    mMetaIdRef = rhs.mMetaIdRef;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Member object.
 */
Member*
Member::clone() const
{
  return new Member(*this);
}


/*
 * Destructor for Member.
 */
Member::~Member()
{
}


/*
 * Returns the value of the "id" attribute of this Member.
 */
const std::string&
Member::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this Member.
 */
const std::string&
Member::getName() const
{
  return mName;
}


/*
 * Returns the value of the "idRef" attribute of this Member.
 */
const std::string&
Member::getIdRef() const
{
  return mIdRef;
}


/*
 * Returns the value of the "metaIdRef" attribute of this Member.
 */
const std::string&
Member::getMetaIdRef() const
{
  return mMetaIdRef;
}


/*
 * Predicate returning @c true if this Member's "id" attribute is set.
 */
bool
Member::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this Member's "name" attribute is set.
 */
bool
Member::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Predicate returning @c true if this Member's "idRef" attribute is set.
 */
bool
Member::isSetIdRef() const
{
  return (mIdRef.empty() == false);
}


/*
 * Predicate returning @c true if this Member's "metaIdRef" attribute is set.
 */
bool
Member::isSetMetaIdRef() const
{
  return (mMetaIdRef.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this Member.
 */
int
Member::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "name" attribute of this Member.
 */
int
Member::setName(const std::string& name)
{
  mName = name;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "idRef" attribute of this Member.
 */
int
Member::setIdRef(const std::string& idRef)
{
  if (!(SyntaxChecker::isValidInternalSId(idRef)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mIdRef = idRef;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "metaIdRef" attribute of this Member.
 */
int
Member::setMetaIdRef(const std::string& metaIdRef)
{
  mMetaIdRef = metaIdRef;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this Member.
 */
int
Member::unsetId()
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
 * Unsets the value of the "name" attribute of this Member.
 */
int
Member::unsetName()
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
 * Unsets the value of the "idRef" attribute of this Member.
 */
int
Member::unsetIdRef()
{
  mIdRef.erase();

  if (mIdRef.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "metaIdRef" attribute of this Member.
 */
int
Member::unsetMetaIdRef()
{
  mMetaIdRef.erase();

  if (mMetaIdRef.empty() == true)
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
Member::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetIdRef() && mIdRef == oldid)
  {
    setIdRef(newid);
  }
}


/*
 * Returns the XML element name of this Member object.
 */
const std::string&
Member::getElementName() const
{
  static const string name = "member";
  return name;
}


/*
 * Returns the libSBML type code for this Member object.
 */
int
Member::getTypeCode() const
{
  return SBML_GROUPS_MEMBER;
}


/*
 * Predicate returning @c true if all the required attributes for this Member
 * object have been set.
 */
bool
Member::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Member::writeElements(XMLOutputStream& stream) const
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
Member::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Member::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Member::enablePackageInternal(const std::string& pkgURI,
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
Member::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("name");

  attributes.add("idRef");

  attributes.add("metaIdRef");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Member::readAttributes(const XMLAttributes& attributes,
                       const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (static_cast<ListOfMembers*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("groups", GroupsGroupLOMembersAllowedAttributes,
          pkgVersion, level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("groups",
          GroupsGroupLOMembersAllowedCoreAttributes, pkgVersion, level, version,
            details);
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("groups", GroupsMemberAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("groups", GroupsMemberAllowedCoreAttributes,
        pkgVersion, level, version, details);
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
      logEmptyString(mId, level, version, "<Member>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(GroupsIdSyntaxRule, level, version, "The id '" + mId + "' does "
        "not conform to the syntax.");
    }
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<Member>");
    }
  }

  // 
  // idRef SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("idRef", mIdRef);

  if (assigned == true)
  {
    if (mIdRef.empty() == true)
    {
      logEmptyString(mIdRef, level, version, "<Member>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mIdRef) == false)
    {
      logError(GroupsMemberIdRefMustBeSBase, level, version, "The attribute "
        "idRef='" + mIdRef + "' does not conform to the syntax.");
    }
  }

  // 
  // metaIdRef IDREF (use = "optional" )
  // 

  assigned = attributes.readInto("metaIdRef", mMetaIdRef);

  if (assigned == true)
  {
    if (mMetaIdRef.empty() == true)
    {
      logEmptyString(mMetaIdRef, level, version, "<Member>");
    }
    else if (SyntaxChecker::isValidXMLID(mMetaIdRef) == false)
    {
      logError(GroupsMemberMetaIdRefMustBeID, level, version, "The attribute "
        "metaIdRef='" + mMetaIdRef + "' does not conform to the syntax.");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Member::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }

  if (isSetIdRef() == true)
  {
    stream.writeAttribute("idRef", getPrefix(), mIdRef);
  }

  if (isSetMetaIdRef() == true)
  {
    stream.writeAttribute("metaIdRef", getPrefix(), mMetaIdRef);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Member_t using the given SBML Level, Version and
 * &ldquo;groups&rdquo; package version.
 */
LIBSBML_EXTERN
Member_t *
Member_create(unsigned int level,
              unsigned int version,
              unsigned int pkgVersion)
{
  return new Member(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Member_t object.
 */
LIBSBML_EXTERN
Member_t*
Member_clone(const Member_t* m)
{
  if (m != NULL)
  {
    return static_cast<Member_t*>(m->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Member_t object.
 */
LIBSBML_EXTERN
void
Member_free(Member_t* m)
{
  if (m != NULL)
  {
    delete m;
  }
}


/*
 * Returns the value of the "id" attribute of this Member_t.
 */
LIBSBML_EXTERN
const char *
Member_getId(const Member_t * m)
{
  if (m == NULL)
  {
    return NULL;
  }

  return m->getId().empty() ? NULL : safe_strdup(m->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this Member_t.
 */
LIBSBML_EXTERN
const char *
Member_getName(const Member_t * m)
{
  if (m == NULL)
  {
    return NULL;
  }

  return m->getName().empty() ? NULL : safe_strdup(m->getName().c_str());
}


/*
 * Returns the value of the "idRef" attribute of this Member_t.
 */
LIBSBML_EXTERN
const char *
Member_getIdRef(const Member_t * m)
{
  if (m == NULL)
  {
    return NULL;
  }

  return m->getIdRef().empty() ? NULL : safe_strdup(m->getIdRef().c_str());
}


/*
 * Returns the value of the "metaIdRef" attribute of this Member_t.
 */
LIBSBML_EXTERN
const char *
Member_getMetaIdRef(const Member_t * m)
{
  if (m == NULL)
  {
    return NULL;
  }

  return m->getMetaIdRef().empty() ? NULL :
    safe_strdup(m->getMetaIdRef().c_str());
}


/*
 * Predicate returning @c 1 if this Member_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
Member_isSetId(const Member_t * m)
{
  return (m != NULL) ? static_cast<int>(m->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this Member_t's "name" attribute is set.
 */
LIBSBML_EXTERN
int
Member_isSetName(const Member_t * m)
{
  return (m != NULL) ? static_cast<int>(m->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 if this Member_t's "idRef" attribute is set.
 */
LIBSBML_EXTERN
int
Member_isSetIdRef(const Member_t * m)
{
  return (m != NULL) ? static_cast<int>(m->isSetIdRef()) : 0;
}


/*
 * Predicate returning @c 1 if this Member_t's "metaIdRef" attribute is set.
 */
LIBSBML_EXTERN
int
Member_isSetMetaIdRef(const Member_t * m)
{
  return (m != NULL) ? static_cast<int>(m->isSetMetaIdRef()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Member_t.
 */
LIBSBML_EXTERN
int
Member_setId(Member_t * m, const char * id)
{
  return (m != NULL) ? m->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this Member_t.
 */
LIBSBML_EXTERN
int
Member_setName(Member_t * m, const char * name)
{
  return (m != NULL) ? m->setName(name) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "idRef" attribute of this Member_t.
 */
LIBSBML_EXTERN
int
Member_setIdRef(Member_t * m, const char * idRef)
{
  return (m != NULL) ? m->setIdRef(idRef) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "metaIdRef" attribute of this Member_t.
 */
LIBSBML_EXTERN
int
Member_setMetaIdRef(Member_t * m, const char * metaIdRef)
{
  return (m != NULL) ? m->setMetaIdRef(metaIdRef) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Member_t.
 */
LIBSBML_EXTERN
int
Member_unsetId(Member_t * m)
{
  return (m != NULL) ? m->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this Member_t.
 */
LIBSBML_EXTERN
int
Member_unsetName(Member_t * m)
{
  return (m != NULL) ? m->unsetName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "idRef" attribute of this Member_t.
 */
LIBSBML_EXTERN
int
Member_unsetIdRef(Member_t * m)
{
  return (m != NULL) ? m->unsetIdRef() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "metaIdRef" attribute of this Member_t.
 */
LIBSBML_EXTERN
int
Member_unsetMetaIdRef(Member_t * m)
{
  return (m != NULL) ? m->unsetMetaIdRef() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this Member_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Member_hasRequiredAttributes(const Member_t * m)
{
  return (m != NULL) ? static_cast<int>(m->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


