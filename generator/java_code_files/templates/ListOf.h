#ifndef ListOf_h
#define ListOf_h


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/SBMLTypeCodes.h>


#ifdef __cplusplus


#include <vector>
#include <algorithm>
#include <functional>

#include <sbml/SBase.h>

LIBSBML_CPP_NAMESPACE_BEGIN

class SBMLVisitor;


/** @cond doxygenLibsbmlInternal */
/**
 * Used by ListOf::get() to lookup an SBase based by its id.
 */
#ifndef SWIG
template<class CNAME>
struct SBMLIdEq : public std::unary_function<SBase*, bool>
{
  const std::string& id;

  SBMLIdEq (const std::string& id) : id(id) { }
  bool operator() (SBase* sb) 
       { return static_cast <CNAME*> (sb)->getId() == id; }
};
#endif /* SWIG */
/** @endcond */


class LIBSBML_EXTERN ListOf : public SBase
{
public:

  /**
   * Creates a new ListOf object.
   *
   * @param level the SBML Level; if not assigned, defaults to the
   * value of SBML_DEFAULT_LEVEL.
   *
   * @param version the Version within the SBML Level; if not assigned,
   * defaults to the value of SBML_DEFAULT_VERSION.
   */
  ListOf (unsigned int level   = SBML_DEFAULT_LEVEL,
          unsigned int version = SBML_DEFAULT_VERSION);


  /**
   * Creates a new ListOf with a given SBMLNamespaces object.
   *
   * @param sbmlns the set of SBML namespaces that this ListOf should
   * contain.
   */
  ListOf (SBMLNamespaces* sbmlns);


  /**
   * Destroys this ListOf and the items inside it.
   */
  virtual ~ListOf ();


  /**
   * Copy constructor; creates a copy of this ListOf.
   *
   * @param orig the ListOf instance to copy.
   */
  ListOf (const ListOf& orig);


  /**
   * Assignment operator for ListOf.
   */
  ListOf& operator=(const ListOf& rhs);



  /** @cond doxygenLibsbmlInternal */
  /**
   * Accepts the given SBMLVisitor.
   *
   * @param v the SBMLVisitor instance to be used.
   *
   * @return the result of calling <code>v.visit()</code>, which indicates
   * whether the Visitor would like to visit the next item in the
   * list.
   */
  virtual bool accept (SBMLVisitor& v) const;
  /** @endcond */


  /**
   * Creates and returns a deep copy of this ListOf object.
   *
   * @return the (deep) copy of this ListOf object.
   */
  virtual ListOf* clone () const;


  /**
   * Adds an item to the end of this ListOf's list of items.
   *
   * This method makes a clone of the @p item handed to it.  This means that
   * when the ListOf object is destroyed, the original items will not be
   * destroyed.  For a method with an alternative ownership behavior, see the
   * ListOf::appendAndOwn(@if java SBase@endif) method.
   *
   * @param item the item to be added to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see appendAndOwn(SBase* disownedItem)
   * @see appendFrom(const ListOf* list)
   */
  int append (const SBase* item);


  /**
   * Adds an item to the end of this ListOf's list of items.
   *
   * This method does not clone the @p disownedItem handed to it; instead, it assumes
   * ownership of it.  This means that when the ListOf is destroyed, the item
   * will be destroyed along with it.  For a method with an alternative
   * ownership behavior, see the ListOf::append(SBase* item) method.
   *
   * @param disownedItem the item to be added to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see append(const SBase* item)
   * @see appendFrom(const ListOf* list)
   */
  int appendAndOwn (SBase* disownedItem);


  /**
   * Adds a clone of a list of items to this ListOf's list.
   *
   * Note that because this clones the objects handed to it, the original
   * items will not be destroyed when this ListOf object is destroyed.
   *
   * @param list a list of items to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see append(const SBase* item)
   * @see appendAndOwn(SBase* disownedItem)
   */
  virtual int appendFrom (const ListOf* list);


  /**
   * Inserts an item at a given position in this ListOf's list of items.
   *
   * This variant of the method makes a clone of the @p item handed to it.
   * This means that when the ListOf is destroyed, the original @p item will
   * <em>not</em> be destroyed.
   *
   * @param location the location in the list where to insert the item.
   * @param item the item to be inserted to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see insertAndOwn(int location, SBase* item)
   */
  int insert (int location, const SBase* item);


  /**
   * Inserts an item at a given position in this ListOf's list of items.
   *
   * This variant of the method does not make a clone of the @p disownedItem handed to it.
   * This means that when the ListOf is destroyed, the original @p item
   * <em>will</em> be destroyed.
   *
   * @param location the location where to insert the item
   * @param disownedItem the item to be inserted to the list
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see insert(int location, const SBase* item)
   */
  int insertAndOwn(int location, SBase* disownedItem);


  /**
   * Get an item from the list.
   *
   * @param n the index number of the item to get.
   *
   * @return the <em>n</em>th item in this ListOf items, or a null pointer if
   * the index number @p n refers to a nonexistent position in this list.
   *
   * @see size()
   */
  virtual const SBase* get (unsigned int n) const;


  /**
   * Get an item from the list.
   *
   * @param n the index number of the item to get.
   * 
   * @return the <em>n</em>th item in this ListOf items, or a null pointer if
   * the index number @p n refers to a nonexistent position in this list.
   *
   * @see size()
   */
  virtual SBase* get (unsigned int n);


  /**
   * Returns the first child element it can find with a specific "id"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param id string representing the "id" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given identifier.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element found with the given meta-identifier.
   *
   * @param metaid string representing the "metaid" attribute of the object
   * to find.
   *
   * @return the first element found with the given @p metaid, or @c NULL if
   * no such object is found.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects.
   *
   * The values returned include all children of the objects in this ListOf
   * list, nested to an arbitrary depth.
   *
   * @return a List of pointers to all child objects.
   */
  virtual List* getAllElements();


  /**
   * Removes all items in this ListOf object.
   *
   * If parameter @p doDelete is @c true (default), all items in this ListOf
   * object are deleted and cleared, and thus the caller doesn't have to
   * delete those items.  Otherwise, all items are cleared only from this
   * ListOf object; the caller is still responsible for deleting the actual
   * items.  (In the latter case, callers are advised to store pointers to
   * all items elsewhere before calling this function.)
   *
   * @param doDelete if @c true (default), all items are deleted and cleared.
   * Otherwise, all items are just cleared and not deleted.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  void clear (bool doDelete = true);


  /**
   * Removes all items in this ListOf object and deletes its properties too.
   *
   * This performs a call to clear() with an argument of @c true (thus removing
   * all the child objects in the list), followed by calls to various libSBML
   * <code>unset<em>Foo</em></code> methods to delete everything else: CVTerm
   * objects, model history objects, etc.
   *
   * @if cpp Implementations of subclasses of ListOf may need to override
   * this method if different handling of child objects is needed.@endif@~
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int removeFromParentAndDelete();


  /**
   * Removes the <em>n</em>th item from this ListOf list of items and returns
   * it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the item to remove
   *
   * @see size()
   */
  virtual SBase* remove (unsigned int n);


  /**
   * Returns number of items in this ListOf list.
   *
   * @return the number of items in this ListOf items.
   */
  unsigned int size () const;


  /** @cond doxygenLibsbmlInternal */
  /**
   * Sets the parent SBMLDocument of this SBML object.
   *
   * @param d the SBMLDocument that should become the parent of this
   * ListOf.
   */
  virtual void setSBMLDocument (SBMLDocument* d);
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Sets this SBML object to child SBML objects (if any).
   * (Creates a child-parent relationship by the parent)
   *
   * Subclasses must override this function if they define
   * one ore more child elements.
   * Basically, this function needs to be called in
   * constructor, copy constructor and assignment operator.
   *
   * @if cpp
   * @see setSBMLDocument()
   * @see enablePackageInternal()
   * @endif
   */
  virtual void connectToChild ();
  /** @endcond */


  /**
   * Returns the libSBML type code for this object, namely,
   * @sbmlconstant{SBML_LIST_OF, SBMLTypeCode_t}.
   * 
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_LIST_OF, SBMLTypeCode_t} (default).
   *
   * @note The various ListOf classes mostly differ from each other in what they
   * contain.  Hence, one must call getItemTypeCode() to fully determine the
   * class of this SBML object.
   *
   * @see getItemTypeCode()
   * @see getElementName()
   */
  virtual int getTypeCode () const;


  /**
   * Get the type code of the objects contained in this ListOf.
   *
   * Classes that inherit from the ListOf class should override this method
   * to return the SBML type code for the objects contained in this ListOf.
   * If they do not, this method will return
   * @sbmlconstant{SBML_UNKNOWN, SBMLTypeCode_t}
   *
   * @return The ListOf base class contains no SBML objects, and therefore
   * this method returns @sbmlconstant{SBML_UNKNOWN, SBMLTypeCode_t}.
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode () const;


  /**
   * Returns the XML element name of this object, which for ListOf, is
   * always @c "listOf".
   *
   * @return the XML name of this element.
   */
  virtual const std::string& getElementName () const;


  /** @cond doxygenLibsbmlInternal */
  /**
   * Subclasses should override this method to write out their contained
   * SBML objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.
   */
  virtual void writeElements (XMLOutputStream& stream) const;
  /** @endcond */


protected:
  /** @cond doxygenLibsbmlInternal */
  typedef std::vector<SBase*>           ListItem;
  typedef std::vector<SBase*>::iterator ListItemIter;

  /**
   * Subclasses should override this method to get the list of
   * expected attributes.
   * This function is invoked from corresponding readAttributes()
   * function.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  
  /**
   * Subclasses should override this method to read values from the given
   * XMLAttributes set into their specific fields.  Be sure to call your
   * parents implementation of this method as well.
   */
  virtual void readAttributes (const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes);

  /**
   * Subclasses should override this method to write their XML attributes
   * to the XMLOutputStream.  Be sure to call your parents implementation
   * of this method as well.  For example:
   *
   *   SBase::writeAttributes(stream);
   *   stream.writeAttribute( "id"  , mId   );
   *   stream.writeAttribute( "name", mName );
   *   ...
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;

  virtual bool isValidTypeForList(SBase * item);

  ListItem mItems;

  /** @endcond */
};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */


#ifndef SWIG

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * Creates a new instance of a ListOf_t structure.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * ListOf_t structure.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ListOf_t structure.
 *
 * @return a pointer to the newly-created ListOf_t structure.
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
ListOf_t *
ListOf_create (unsigned int level, unsigned int version);


/**
 * Frees the given ListOf_t structure.
 *
 * This function assumes each item in the list is derived from SBase_t.
 *
 * @param lo the ListOf_t structure to be freed.
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
void
ListOf_free (ListOf_t *lo);


/**
 * Creates a deep copy of the given ListOf_t structure.
 *
 * @param lo the ListOf_t structure to be copied.
 *
 * @return a (deep) copy of the given ListOf_t structure, or a null
 * pointer if a failure occurred.
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
ListOf_t *
ListOf_clone (const ListOf_t *lo);


/**
 * Adds a copy of a given item to the end of a ListOf_t list.
 *
 * @param lo the ListOf_t structure to which the @p item should be appended.
 * @param item the item to append to the list.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see ListOf_appendAndOwn()
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
int
ListOf_append (ListOf_t *lo, const SBase_t *item);


/**
 * Adds the given item to the end of a ListOf_t list.
 *
 * @param lo the ListOf_t structure to which the @p disownedItem should be appended.
 * @param disownedItem the item to append to the list.
 *
 * Unlike ListOf_append(), this function does not copy the @p disownedItem.
 * The given @p lo list will contain the original item.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see ListOf_append()
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
int
ListOf_appendAndOwn (ListOf_t *lo, SBase_t *disownedItem);


/**
 * Adds clones a list of items from one list to another.
 *
 * @param lo the ListOf_t list to which @p list will be appended.
 * @param list the list of items to append to @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
int
ListOf_appendFrom (ListOf_t *lo, ListOf_t *list);


/**
 * Inserts a copy of an item into a ListOf_t list at a given position.
 *
 * @param lo the list into which @p item will be inserted.
 * @param location the starting index for the @p item in the @p lo list.
 * @param item the item to append to insert into @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
int
ListOf_insert (ListOf_t *lo, int location, const SBase_t *item);


/**
 * Inserts an item into a ListOf_t list at a given position.
 *
 * Unlike ListOf_insert(), this function does not clone @p disownedItem before
 * inserting it into @p lo, which means that @p lo becomes the owner.
 *
 * @param lo the list into which @p disownedItem will be inserted.
 * @param location the starting index for the @p disownedItem in the @p lo list.
 * @param disownedItem the item to append to insert into @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
int
ListOf_insertAndOwn (ListOf_t *lo, int location, SBase_t *disownedItem);


/**
 * Returns the <em>n</em>th item of a given list.
 *
 * @param lo the list from which to retrieve the item.
 * @param n the index of the item to retrieve.
 *
 * @return the <em>n</em>th item in this ListOf items, or a null pointer if
 * the index number @p n refers to a nonexistent position in @p lo.
 *
 * @see ListOf_size()
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
SBase_t *
ListOf_get (ListOf_t *lo, unsigned int n);


/**
 * Removes all items in this ListOf_t structure.
 *
 * If @p doDelete is true (non-zero), all items in this ListOf_t structure
 * are both deleted and cleared, and thus the caller doesn't have to delete
 * those items.  Otherwise, if @p doDelete is false (zero), all items are
 * only cleared from this ListOf_t structure and the caller is responsible
 * for deleting all items.  (In the latter case, callers are advised to store
 * pointers to all items elsewhere before calling this function.)
 *
 * @param lo the ListOf_t structure to clear
 * @param doDelete whether to delete the items.
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
void
ListOf_clear (ListOf_t *lo, int doDelete);


/**
 * Removes the <em>n</em>th item from this ListOf_t list and returns it.
 *
 * The caller owns the returned item and is responsible for deleting it.
 *
 * @param lo the list from which the item should be removed.
 * @param n the index number of the item to remove.
 *
 * @return the item removed, or a null pointer if no item existed at the
 * index @p n.
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
SBase_t *
ListOf_remove (ListOf_t *lo, unsigned int n);


/**
 * Returns the number of items in this ListOf_t items.
 *
 * @param lo the ListOf_t structure to count.
 *
 * @return the number of items in @p lo.
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
unsigned int
ListOf_size (const ListOf_t *lo);


/**
 * Get the type code of the objects contained in the given ListOf_t
 * structure.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @param lo the ListOf_t whose item type codes are sought.
 *
 * @return the type code corresponding to the objects in @p lo,
 * or @sbmlconstant{SBML_UNKNOWN, SBMLTypeCode_t}.
 *
 * @memberof ListOf_t
 */
LIBSBML_EXTERN
int
ListOf_getItemTypeCode (const ListOf_t *lo);


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /* !SWIG */
#endif  /* ListOf_h */

