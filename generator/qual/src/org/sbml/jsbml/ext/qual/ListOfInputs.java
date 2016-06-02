/*
 * $Id: ListOfInputs.java 2465 2016-06-02 13:40:03Z deviser $
 * $URL:
 * /home/john1990/Dropbox/GitHub/SBML/deviser/generator/qual/src/org/sbml/jsbml/ext/qualListOfInputs.java
 * $
 * ----------------------------------------------------------------------------
 * This file is part of JSBML. Please visit <http://sbml.org/Software/JSBML>
 * for the latest version of JSBML and more information about SBML.
 *
 * Copyright (C) 2009-2016 jointly by the following organizations:
 * 1. The University of Tuebingen, Germany
 * 2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 * 3. The California Institute of Technology, Pasadena, CA, USA
 * 4. The University of California, San Diego, La Jolla, CA, USA
 * 5. The Babraham Institute, Cambridge, UK
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published b
 * the Free Software Foundation. A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as <http://sbml.org/Software/JSBML/License>.
 * ----------------------------------------------------------------------------
 */
package org.sbml.jsbml.ext.qual

#include <jsbml/packages/qual/jsbml/ListOfInputs.h>
#include <jsbml/packages/qual/validator/QualJSBMLError.h>


using namespace std;

  /**
   * Creates a new ListOfInputs using the given JSBML Level, Version and
   * &ldquo;qual&rdquo; package version.
   */
  public ListOfInputs(unsigned int level,
                       unsigned int version,
                       unsigned int pkgVersion)
    : ListOf(level, version)
  {
    setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));
  }


  /**
   * Creates a new ListOfInputs using the given QualPkgNamespaces object.
   */
  public ListOfInputs(QualPkgNamespaces *qualns)
    : ListOf(qualns)
  {
    setElementNamespace(qualns->getURI());
  }


  /**
   * Copy constructor for ListOfInputs.
   */
  public ListOfInputs(const ListOfInputs& orig)
    : ListOf( orig )
  {
  }


  /**
   * Assignment operator for ListOfInputs.
   */
  public ListOfInputs& operator=(const ListOfInputs& rhs)
  {
    if (&rhs != this)
    {
      ListOf::operator=(rhs);
    }

    return *this;
  }


  /**
   * Creates and returns a deep copy of this ListOfInputs object.
   */
  public ListOfInputs* clone()
  {
    return new ListOfInputs(*this);
  }


  /**
   * Destructor for ListOfInputs.
   */
  public ~ListOfInputs()
  {
  }


  /**
   * Get an Input from the ListOfInputs.
   */
  public Input* get(unsigned int n)
  {
    return static_cast<Input*>(ListOf::get(n));
  }


  /**
   * Get an Input from the ListOfInputs.
   */
  public const Input* get(unsigned int n)
  {
    return static_cast<const Input*>(ListOf::get(n));
  }


  /**
   * Get an Input from the ListOfInputs based on its identifier.
   */
  public Input* get(const std::string& sid)
  {
    return const_cast<Input*>(static_cast<const
      ListOfInputs&>(*this).get(sid));
  }


  /**
   * Get an Input from the ListOfInputs based on its identifier.
   */
  public const Input* get(const std::string& sid)
  {
    vector<SBase*>::const_iterator result;
    result = find_if(mItems.begin(), mItems.end(), IdEq<Input>(sid));
    return (result == mItems.end()) ? 0 : static_cast <const Input*> (*result);
  }


  /**
   * Removes the nth Input from this ListOfInputs and returns a pointer to it.
   */
  public Input* remove(unsigned int n)
  {
    return static_cast<Input*>(ListOf::remove(n));
  }


  /**
   * Removes the Input from this ListOfInputs based on its identifier and
   * returns a pointer to it.
   */
  public Input* remove(const std::string& sid)
  {
    SBase* item = NULL;
    vector<SBase*>::iterator result;

    result = find_if(mItems.begin(), mItems.end(), IdEq<Input>(sid));

    if (result != mItems.end())
    {
      item = *result;
      mItems.erase(result);
    }

    return static_cast <Input*> (item);
  }


  /**
   * Adds a copy of the given Input to this ListOfInputs.
   */
  public int addInput(const Input* i)
  {
    if (i == NULL)
    {
      return LIBSBML_OPERATION_FAILED;
    }
    else if (i->hasRequiredAttributes() == false)
    {
      return LIBSBML_INVALID_OBJECT;
    }
    else if (getLevel() != i->getLevel())
    {
      return LIBSBML_LEVEL_MISMATCH;
    }
    else if (getVersion() != i->getVersion())
    {
      return LIBSBML_VERSION_MISMATCH;
    }
    else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
      SBase*>(i)) == false)
    {
      return LIBSBML_NAMESPACES_MISMATCH;
    }
    else
    {
      append(i);
      return LIBSBML_OPERATION_SUCCESS;
    }
  }


  /**
   * Get the number of Input objects in this ListOfInputs.
   */
  public unsigned int getNumInputs()
  {
    return size();
  }


  /**
   * Creates a new Input object, adds it to this ListOfInputs object and
   * returns the Input object created.
   */
  public Input* createInput()
  {
    Input* i = NULL;

    try
    {
      QUAL_CREATE_NS(qualns, getSBMLNamespaces());
      i = new Input(qualns);
      delete qualns;
    }
    catch (...)
    {
    }

    if (i != NULL)
    {
      appendAndOwn(i);
    }

    return i;
  }


/**
 * Used by ListOfInputs::get() to lookup an Input based on its
 * QualitativeSpecies.
 */
struct IdEqQS : public std::unary_function<SBase*, bool>
{
  const string& id;
   
  IdEqQS (const string& id) : id(id) { }
  bool operator() (SBase* sb)
  {
  return (static_cast<Input*>(sb)->getQualitativeSpecies() == id);
  }
};


  /**
   * Get an Input from the ListOfInputs based on the QualitativeSpecies to
   * which it refers.
   */
  public const Input* getByQualitativeSpecies(const std::string& sid)
  {
    vector<SBase*>::const_iterator result;
    result = find_if(mItems.begin(), mItems.end(), IdEqQS(sid));
    return (result == mItems.end()) ? 0 : static_cast <const Input*> (*result);
  }


  /**
   * Get an Input from the ListOfInputs based on the QualitativeSpecies to
   * which it refers.
   */
  public Input* getByQualitativeSpecies(const std::string& sid)
  {
    return const_cast<Input*>(static_cast<const
      ListOfInputs&>(*this).getByQualitativeSpecies(sid));
  }


  /**
   * Returns the XML element name of this ListOfInputs object.
   */
  public const std::string& getElementName()
  {
    static const string name = "listOfInputs";
    return name;
  }


  /**
   * Returns the libJSBML type code for this ListOfInputs object.
   */
  public int getTypeCode()
  {
    return JSBML_LIST_OF;
  }


  /**
   * Returns the libJSBML type code for the JSBML objects contained in this
   * ListOfInputs object.
   */
  public int getItemTypeCode()
  {
    return SBML_QUAL_INPUT;
  }


  /**
   * Predicate returning @c true if all the required attributes for this
   * ListOfInputs object have been set.
   */
  public bool hasRequiredAttributes()
  {
    bool allPresent = ListOf::hasRequiredAttributes();

    return allPresent;
  }



  /** @cond doxygenJSBMLInternal */

  /**
   * Creates a new Input in this ListOfInputs
   */
  public SBase* createObject(XMLInputStream& stream)
  {
    const std::string& name = stream.peek().getName();
    SBase* object = NULL;
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());

    if (name == "input")
    {
      object = new Input(qualns);
      appendAndOwn(object);
    }

    delete qualns;
    return object;
  }

  /** @endcond */



  /** @cond doxygenJSBMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  public void addExpectedAttributes(ExpectedAttributes& attributes)
  {
    ListOf::addExpectedAttributes(attributes);
  }

  /** @endcond */



  /** @cond doxygenJSBMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  public void readAttributes(const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
  {
    unsigned int level = getLevel();
    unsigned int version = getVersion();
    unsigned int pkgVersion = getPackageVersion();
    unsigned int numErrs;
    bool assigned = false;
    SBMLErrorLog* log = getErrorLog();

    ListOf::readAttributes(attributes, expectedAttributes);
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("qual", QualUnknown, pkgVersion, level, version,
          details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("qual", QualUnknown, pkgVersion, level, version,
          details);
      }
    }
  }

  /** @endcond */



  /** @cond doxygenJSBMLInternal */

  /**
   * Writes the attributes to the stream
   */
  public void writeAttributes(XMLOutputStream& stream)
  {
    ListOf::writeAttributes(stream);

    SBase::writeExtensionAttributes(stream);
  }

  /** @endcond */



  /** @cond doxygenJSBMLInternal */

  /**
   * Writes the namespace for the Qual package
   */
  public void writeXMLNS(XMLOutputStream& stream)
  {
    XMLNamespaces xmlns;
    std::string prefix = getPrefix();

    if (prefix.empty())
    {
      const XMLNamespaces* thisxmlns = getNamespaces();
      if (thisxmlns && thisxmlns->hasURI(QualExtension::getXmlnsL3V1V1()))
      {
        xmlns.add(QualExtension::getXmlnsL3V1V1(), prefix);
      }
    }

    stream << xmlns;
  }

  /** @endcond */


