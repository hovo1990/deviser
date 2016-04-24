/**
 * @file SedDataGenerator.cpp
 * @brief Implementation of the SedDataGenerator class.
 * @author DEVISER
 */
#include <sedml/SedDataGenerator.h>
#include <sedml/SedListOfDataGenerators.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedDataGenerator using the given SEDML Level and @ p version
 * values.
 */
SedDataGenerator::SedDataGenerator(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mId ("")
  , mName ("")
  , mVariables (level, version)
  , mParameters (level, version)
  , mMath (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedDataGenerator using the given SedNamespaces object @p
 * sedmlns.
 */
SedDataGenerator::SedDataGenerator(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mId ("")
  , mName ("")
  , mVariables (sedmlns)
  , mParameters (sedmlns)
  , mMath (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedDataGenerator.
 */
SedDataGenerator::SedDataGenerator(const SedDataGenerator& orig)
  : SedBase( orig )
  , mId ( orig.mId )
  , mName ( orig.mName )
  , mVariables ( orig.mVariables )
  , mParameters ( orig.mParameters )
  , mMath ( NULL )
{
  if (orig.mMath != NULL)
  {
    mMath = orig.mMath->deepCopy();
  }

  connectToChild();
}


/*
 * Assignment operator for SedDataGenerator.
 */
SedDataGenerator&
SedDataGenerator::operator=(const SedDataGenerator& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mId = rhs.mId;
    mName = rhs.mName;
    mVariables = rhs.mVariables;
    mParameters = rhs.mParameters;
    delete mMath;
    if (rhs.mMath != NULL)
    {
      mMath = rhs.mMath->deepCopy();
    }
    else
    {
      mMath = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedDataGenerator object.
 */
SedDataGenerator*
SedDataGenerator::clone() const
{
  return new SedDataGenerator(*this);
}


/*
 * Destructor for SedDataGenerator.
 */
SedDataGenerator::~SedDataGenerator()
{
  delete mMath;
  mMath = NULL;
}


/*
 * Returns the value of the "id" attribute of this SedDataGenerator.
 */
const std::string&
SedDataGenerator::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this SedDataGenerator.
 */
const std::string&
SedDataGenerator::getName() const
{
  return mName;
}


/*
 * Predicate returning @c true if this SedDataGenerator's "id" attribute is
 * set.
 */
bool
SedDataGenerator::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this SedDataGenerator's "name" attribute is
 * set.
 */
bool
SedDataGenerator::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this SedDataGenerator.
 */
int
SedDataGenerator::setId(const std::string& id)
{
  mId = id;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "name" attribute of this SedDataGenerator.
 */
int
SedDataGenerator::setName(const std::string& name)
{
  mName = name;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this SedDataGenerator.
 */
int
SedDataGenerator::unsetId()
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
 * Unsets the value of the "name" attribute of this SedDataGenerator.
 */
int
SedDataGenerator::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "math" element of this SedDataGenerator.
 */
const ASTNode*
SedDataGenerator::getMath() const
{
  return mMath;
}


/*
 * Returns the value of the "math" element of this SedDataGenerator.
 */
ASTNode*
SedDataGenerator::getMath()
{
  return mMath;
}


/*
 * Predicate returning @c true if this SedDataGenerator's "math" element is
 * set.
 */
bool
SedDataGenerator::isSetMath() const
{
  return (mMath != NULL);
}


/*
 * Sets the value of the "math" element of this SedDataGenerator.
 */
int
SedDataGenerator::setMath(const ASTNode* math)
{
  if (mMath == math)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (math == NULL)
  {
    delete mMath;
    mMath = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (!(math->isWellFormedASTNode()))
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else
  {
    delete mMath;
    mMath = (math != NULL) ? math->deepCopy() : NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "math" element of this SedDataGenerator.
 */
int
SedDataGenerator::unsetMath()
{
  delete mMath;
  mMath = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfVariables from this SedDataGenerator.
 */
const SedListOfVariables*
SedDataGenerator::getListOfVariables() const
{
  return &mVariables;
}


/*
 * Returns the SedListOfVariables from this SedDataGenerator.
 */
SedListOfVariables*
SedDataGenerator::getListOfVariables()
{
  return &mVariables;
}


/*
 * Get a SedVariable from the SedDataGenerator.
 */
SedVariable*
SedDataGenerator::getVariable(unsigned int n)
{
  return mVariables.get(n);
}


/*
 * Get a SedVariable from the SedDataGenerator.
 */
const SedVariable*
SedDataGenerator::getVariable(unsigned int n) const
{
  return mVariables.get(n);
}


/*
 * Adds a copy of the given SedVariable to this SedDataGenerator.
 */
int
SedDataGenerator::addVariable(const SedVariable* sv)
{
  if (sv == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sv->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sv->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sv->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sv)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    mVariables.append(sv);
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of SedVariable objects in this SedDataGenerator.
 */
unsigned int
SedDataGenerator::getNumVariables() const
{
  return mVariables.size();
}


/*
 * Creates a new SedVariable object, adds it to this SedDataGenerator object
 * and returns the SedVariable object created.
 */
SedVariable*
SedDataGenerator::createVariable()
{
  SedVariable* sv = NULL;

  try
  {
    sv = new SedVariable(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sv != NULL)
  {
    mVariables.appendAndOwn(sv);
  }

  return sv;
}


/*
 * Removes the nth SedVariable from this SedDataGenerator and returns a pointer
 * to it.
 */
SedVariable*
SedDataGenerator::removeVariable(unsigned int n)
{
  return mVariables.remove(n);
}


/*
 * Returns the SedListOfParameters from this SedDataGenerator.
 */
const SedListOfParameters*
SedDataGenerator::getListOfParameters() const
{
  return &mParameters;
}


/*
 * Returns the SedListOfParameters from this SedDataGenerator.
 */
SedListOfParameters*
SedDataGenerator::getListOfParameters()
{
  return &mParameters;
}


/*
 * Get a SedParameter from the SedDataGenerator.
 */
SedParameter*
SedDataGenerator::getParameter(unsigned int n)
{
  return mParameters.get(n);
}


/*
 * Get a SedParameter from the SedDataGenerator.
 */
const SedParameter*
SedDataGenerator::getParameter(unsigned int n) const
{
  return mParameters.get(n);
}


/*
 * Adds a copy of the given SedParameter to this SedDataGenerator.
 */
int
SedDataGenerator::addParameter(const SedParameter* sp)
{
  if (sp == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sp->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sp->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sp->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sp)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    mParameters.append(sp);
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of SedParameter objects in this SedDataGenerator.
 */
unsigned int
SedDataGenerator::getNumParameters() const
{
  return mParameters.size();
}


/*
 * Creates a new SedParameter object, adds it to this SedDataGenerator object
 * and returns the SedParameter object created.
 */
SedParameter*
SedDataGenerator::createParameter()
{
  SedParameter* sp = NULL;

  try
  {
    sp = new SedParameter(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sp != NULL)
  {
    mParameters.appendAndOwn(sp);
  }

  return sp;
}


/*
 * Removes the nth SedParameter from this SedDataGenerator and returns a
 * pointer to it.
 */
SedParameter*
SedDataGenerator::removeParameter(unsigned int n)
{
  return mParameters.remove(n);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedDataGenerator::renameSIdRefs(const std::string& oldid,
                                const std::string& newid)
{
  if (isSetMath())
  {
    mMath->renameSIdRefs(oldid, newid);
  }
}


/*
 * Returns the XML element name of this SedDataGenerator object.
 */
const std::string&
SedDataGenerator::getElementName() const
{
  static const string name = "dataGenerator";
  return name;
}


/*
 * Returns the libSEDML type code for this SedDataGenerator object.
 */
int
SedDataGenerator::getTypeCode() const
{
  return SEDML_DATAGENERATOR;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedDataGenerator object have been set.
 */
bool
SedDataGenerator::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedDataGenerator object have been set.
 */
bool
SedDataGenerator::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedDataGenerator::writeElements(XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (isSetMath() == true)
  {
    writeMathML(getMath(), stream, NULL);
  }

  if (getNumVariables() > 0)
  {
    mVariables.write(stream);
  }

  if (getNumParameters() > 0)
  {
    mParameters.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedDataGenerator::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedDataGenerator::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mVariables.setSedDocument(d);

  mParameters.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedDataGenerator::connectToChild()
{
  SedBase::connectToChild();

  mVariables.connectToParent(this);

  mParameters.connectToParent(this);
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedDataGenerator::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mVariables.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mParameters.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedDataGenerator::createObject(XMLInputStream& stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfVariables")
  {
    if (mVariables.size() != 0)
    {
      getErrorLog()->logError(SedmlSedDataGeneratorAllowedElements, getLevel(),
        getVersion());
    }

    obj = &mVariables;
  }
  else if (name == "listOfParameters")
  {
    if (mParameters.size() != 0)
    {
      getErrorLog()->logError(SedmlSedDataGeneratorAllowedElements, getLevel(),
        getVersion());
    }

    obj = &mParameters;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedDataGenerator::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("name");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedDataGenerator::readAttributes(const XMLAttributes& attributes,
                                 const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  if (static_cast<SedListOfDataGenerators*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logError(SedmlLOSedDataGeneratorsAllowedAttributes, level,
          version, details);
      }
    }
  }

  SedBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logError(SedmlSedDataGeneratorAllowedAttributes, level, version,
        details);
    }
  }

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<SedDataGenerator>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(SedmlIdSyntaxRule, level, version, "The id '" + mId + "' does "
        "not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Sedml attribute 'id' is missing from the "
      "<SedDataGenerator> element.";
    log->logError(SedmlSedDataGeneratorAllowedAttributes, level, version,
      message);
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<SedDataGenerator>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
SedDataGenerator::readOtherXML(XMLInputStream& stream)
{
  bool read = false;
  const string& name = stream.peek().getName();

  if (name == "math")
  {
    const XMLToken elem = stream.peek();
    const std::string prefix = checkMathMLNamespace(elem);
    delete mMath;
    mMath = readMathML(stream, prefix);
    read = true;
  }

  if (SedBase::readOtherXML(stream))
  {
    read = true;
  }

  return read;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedDataGenerator::writeAttributes(XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedDataGenerator_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedDataGenerator_t *
SedDataGenerator_create(unsigned int level, unsigned int version)
{
  return new SedDataGenerator(level, version);
}


/*
 * Creates and returns a deep copy of this SedDataGenerator_t object.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDataGenerator_clone(const SedDataGenerator_t* sdg)
{
  if (sdg != NULL)
  {
    return static_cast<SedDataGenerator_t*>(sdg->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedDataGenerator_t object.
 */
LIBSEDML_EXTERN
void
SedDataGenerator_free(SedDataGenerator_t* sdg)
{
  if (sdg != NULL)
  {
    delete sdg;
  }
}


/*
 * Returns the value of the "id" attribute of this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
const char *
SedDataGenerator_getId(const SedDataGenerator_t * sdg)
{
  if (sdg == NULL)
  {
    return NULL;
  }

  return sdg->getId().empty() ? NULL : safe_strdup(sdg->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
const char *
SedDataGenerator_getName(const SedDataGenerator_t * sdg)
{
  if (sdg == NULL)
  {
    return NULL;
  }

  return sdg->getName().empty() ? NULL : safe_strdup(sdg->getName().c_str());
}


/*
 * Predicate returning @c 1 if this SedDataGenerator_t's "id" attribute is set.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetId(const SedDataGenerator_t * sdg)
{
  return (sdg != NULL) ? static_cast<int>(sdg->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this SedDataGenerator_t's "name" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetName(const SedDataGenerator_t * sdg)
{
  return (sdg != NULL) ? static_cast<int>(sdg->isSetName()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setId(SedDataGenerator_t * sdg, const char * id)
{
  return (sdg != NULL) ? sdg->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setName(SedDataGenerator_t * sdg, const char * name)
{
  return (sdg != NULL) ? sdg->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetId(SedDataGenerator_t * sdg)
{
  return (sdg != NULL) ? sdg->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetName(SedDataGenerator_t * sdg)
{
  return (sdg != NULL) ? sdg->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "math" element of this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
const ASTNode_t*
SedDataGenerator_getMath(const SedDataGenerator_t * sdg)
{
  if (sdg == NULL)
  {
    return NULL;
  }

  return (ASTNode_t*)(sdg->getMath());
}


/*
 * Predicate returning @c 1 if this SedDataGenerator_t's "math" element is set.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetMath(const SedDataGenerator_t * sdg)
{
  return (sdg != NULL) ? static_cast<int>(sdg->isSetMath()) : 0;
}


/*
 * Sets the value of the "math" element of this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setMath(SedDataGenerator_t * sdg, const ASTNode_t* math)
{
  return (sdg != NULL) ? sdg->setMath(math) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "math" element of this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetMath(SedDataGenerator_t * sdg)
{
  return (sdg != NULL) ? sdg->unsetMath() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t* containing SedVariable_t objects from this
 * SedDataGenerator_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataGenerator_getListOfVariables(SedDataGenerator_t* sdg)
{
  return (sdg != NULL) ? sdg->getListOfVariables() : NULL;
}


/*
 * Get a SedVariable_t from the SedDataGenerator_t.
 */
LIBSEDML_EXTERN
const SedVariable_t*
SedDataGenerator_getVariable(SedDataGenerator_t* sdg, unsigned int n)
{
  return (sdg != NULL) ? sdg->getVariable(n) : NULL;
}


/*
 * Adds a copy of the given SedVariable_t to this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_addVariable(SedDataGenerator_t* sdg, const SedVariable_t* sv)
{
  return (sdg != NULL) ? sdg->addVariable(sv) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedVariable_t objects in this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDataGenerator_getNumVariables(SedDataGenerator_t* sdg)
{
  return (sdg != NULL) ? sdg->getNumVariables() : SEDML_INT_MAX;
}


/*
 * Creates a new SedVariable_t object, adds it to this SedDataGenerator_t
 * object and returns the SedVariable_t object created.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_createVariable(SedDataGenerator_t* sdg)
{
  return (sdg != NULL) ? sdg->createVariable() : NULL;
}


/*
 * Removes the nth SedVariable_t from this SedDataGenerator_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_removeVariable(SedDataGenerator_t* sdg, unsigned int n)
{
  return (sdg != NULL) ? sdg->removeVariable(n) : NULL;
}


/*
 * Returns a ListOf_t* containing SedParameter_t objects from this
 * SedDataGenerator_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataGenerator_getListOfParameters(SedDataGenerator_t* sdg)
{
  return (sdg != NULL) ? sdg->getListOfParameters() : NULL;
}


/*
 * Get a SedParameter_t from the SedDataGenerator_t.
 */
LIBSEDML_EXTERN
const SedParameter_t*
SedDataGenerator_getParameter(SedDataGenerator_t* sdg, unsigned int n)
{
  return (sdg != NULL) ? sdg->getParameter(n) : NULL;
}


/*
 * Adds a copy of the given SedParameter_t to this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_addParameter(SedDataGenerator_t* sdg,
                              const SedParameter_t* sp)
{
  return (sdg != NULL) ? sdg->addParameter(sp) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedParameter_t objects in this SedDataGenerator_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDataGenerator_getNumParameters(SedDataGenerator_t* sdg)
{
  return (sdg != NULL) ? sdg->getNumParameters() : SEDML_INT_MAX;
}


/*
 * Creates a new SedParameter_t object, adds it to this SedDataGenerator_t
 * object and returns the SedParameter_t object created.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedDataGenerator_createParameter(SedDataGenerator_t* sdg)
{
  return (sdg != NULL) ? sdg->createParameter() : NULL;
}


/*
 * Removes the nth SedParameter_t from this SedDataGenerator_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedDataGenerator_removeParameter(SedDataGenerator_t* sdg, unsigned int n)
{
  return (sdg != NULL) ? sdg->removeParameter(n) : NULL;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * SedDataGenerator_t object have been set.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_hasRequiredAttributes(const SedDataGenerator_t * sdg)
{
  return (sdg != NULL) ? static_cast<int>(sdg->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this
 * SedDataGenerator_t object have been set.
 */
LIBSEDML_EXTERN
int
SedDataGenerator_hasRequiredElements(const SedDataGenerator_t * sdg)
{
  return (sdg != NULL) ? static_cast<int>(sdg->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


