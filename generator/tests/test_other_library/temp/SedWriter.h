/**
 * @file SedWriter.h
 * @brief Definition of the SedWriter class.
 * @author DEVISER
 *
 * @class 
 * @sbmlbrief{} TODO:Definition of the SedWriter class.
 */


#ifndef SedWriter_h
#define SedWriter_h


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <iosfwd>
#include <string>

LIBSEDML_CPP_NAMESPACE_BEGIN

class SedDocument;


class LIBSEDML_EXTERN SedWriter
{
public:

  /**
   * Creates a new SedWriter.
   *
   * The libSed SedWriter objects offer methods for writing Sed in
   * XML form to files and text strings.
   */
  SedWriter  ();


  /**
   * Destroys this SedWriter.
   */
  ~SedWriter ();


  /**
   * Sets the name of this program, i.e., the program that is about to
   * write out the SedDocument.
   *
   * If the program name and version are set (see
   * SedWriter::setProgramVersion(@if java String@endif)), the
   * following XML comment, intended for human consumption, will be written
   * at the beginning of the XML document:
   * @verbatim
 <!-- Created by <program name> version <program version>
 on yyyy-MM-dd HH:mm with libSed version <libsedml version>. -->
 @endverbatim
   *
   * If the program name and version are not set at some point before
   * calling the writeSedML() methods, no such comment is written out.
   *
   * @param name the name of this program (where "this program" refers to
   * program in which libSed is embedded, not libSed itself!)
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * 
   * @see setProgramVersion(const std::string& version)
   */
  int setProgramName (const std::string& name);


  /**
   * Sets the version of this program, i.e., the program that is about to
   * write out the SedDocument.
   *
   * If the program version and name are set (see
   * SedWriter::setProgramName(@if java String@endif)), the
   * following XML comment, intended for human consumption, will be written
   * at the beginning of the document:
   * @verbatim
 <!-- Created by <program name> version <program version>
 on yyyy-MM-dd HH:mm with libSed version <libsedml version>. -->
 @endverbatim
   *
   * If the program version and name are not set at some point before
   * calling the writeSedML() methods, no such comment is written out.
   *
   * @param version the version of this program (where "this program"
   * refers to program in which libSed is embedded, not libSed itself!)
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @see setProgramName(const std::string& name)
   */
  int setProgramVersion (const std::string& version);


  /**
   * Writes the given Sed document to filename.
   *
   * @htmlinclude assuming-compressed-file.html
   *
   * @param d the Sed document to be written
   *
   * @param filename the name or full pathname of the file where the Sed
   * is to be written. 
   *
   * @return @c true on success and @c false if the filename could not be
   * opened for writing.
   *
   * @note @htmlinclude note-writing-zipped-files.html
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  bool writeSedML (const SedDocument* d, const std::string& filename);


  /**
   * Writes the given Sed document to the output stream.
   *
   * @param d the Sed document to be written
   *
   * @param stream the stream object where the Sed is to be written.
   *
   * @return @c true on success and @c false if one of the underlying
   * parser components fail (rare).
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  bool writeSedML (const SedDocument* d, std::ostream& stream);


  /** @cond doxygenLibsedmlInternal */

  /**
   * Writes the given Sed document to an in-memory string and returns a
   * pointer to it.
   *
   * The string is owned by the caller and should be freed (with @c free())
   * when no longer needed.
   *
   * @param d the Sed document to be written
   *
   * @return the string on success and @c 0 if one of the underlying parser
   * components fail.
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  char* writeToString (const SedDocument* d);

  /** @endcond */

  /**
   * Writes the given Sed document to filename.
   *
   * @htmlinclude assuming-compressed-file.html
   *
   * @param d the Sed document to be written
   *
   * @param filename the name or full pathname of the file where the Sed
   * is to be written. 
   *
   * @return @c true on success and @c false if the filename could not be
   * opened for writing.
   *
   * @note @htmlinclude note-writing-zipped-files.html
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  bool writeSedMLToFile (const SedDocument* d, const std::string& filename);


  /**
   * Writes the given Sed document to an in-memory string and returns a
   * pointer to it.
   *
   * The string is owned by the caller and should be freed (with @c free())
   * when no longer needed.
   *
   * @param d the Sed document to be written
   *
   * @return the string on success and @c 0 if one of the underlying parser
   * components fail.
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  char* writeSedMLToString (const SedDocument* d);

#ifndef SWIG
  /**
   * Writes the given Sed document to an in-memory string and returns it.
   *
   * @param d the Sed document to be written
   *
   * @return the string on success or an empty string, 
   *         if one of the underlying parser
   *         components fail.
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  std::string writeSedMLToStdString(const SedDocument* d);
#endif
  

  /**
   * Predicate returning @c true if this copy of libSed has been linked
   * with the <em>zlib</em> library.
   *
   * LibSed supports reading and writing files compressed with either
   * bzip2 or zip/gzip compression.  The facility depends on libSed having
   * been compiled with the necessary support libraries.  This method
   * allows a calling program to inquire whether that is the case for the
   * copy of libSed it is using.
   *
   * @return @c true if libSed is linked with zlib, @c false otherwise.
   *
   * @copydetails doc_note_static_methods
   *
   * @see @if clike hasBzip2() @else SedWriter::hasBzip2() @endif@~
   */
  static bool hasZlib();


  /**
   * Predicate returning @c true if this copy of libSed has been linked
   * with the <em>bzip2</em> library.
   *
   * LibSed supports reading and writing files compressed with either
   * bzip2 or zip/gzip compression.  The facility depends on libSed having
   * been compiled with the necessary support libraries.  This method
   * allows a calling program to inquire whether that is the case for the
   * copy of libSed it is using.
   *
   * @return @c true if libSed is linked with bzip2, @c false otherwise.
   *
   * @copydetails doc_note_static_methods
   *
   * @see @if clike hasZlib() @else SedWriter::hasZlib() @endif@~
   */
  static bool hasBzip2();


 protected:
  /** @cond doxygenLibsedmlInternal */
  std::string mProgramName;
  std::string mProgramVersion;

  /** @endcond */
};

#ifndef SWIG

/**
 * Writes the given Sed document to an in-memory string that is returned.
 *
 * @param d the Sed document to be written
 *
 * @return the string on success or an empty string, 
 *         if one of the underlying parser
 *         components fail.
 * 
 */
LIBSEDML_EXTERN
std::string writeSedMLToStdString(const SedDocument* d);

#endif

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */


LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


#ifndef SWIG


/**
 * Creates a new SedWriter and returns a pointer to it.
 *
 * @memberof SedWriter_t
 */
LIBSEDML_EXTERN
SedWriter_t *
SedWriter_create (void);

/**
 * Frees the given SedWriter.
 *
 * @memberof SedWriter_t
 */
LIBSEDML_EXTERN
void
SedWriter_free (SedWriter_t *sw);

/**
 * Sets the name of this program. i.\ e.\ the one about to write out the
 * SedDocument.  If the program name and version are set
 * (setProgramVersion()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libSed version <libsedml version>. -->
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof SedWriter_t
 */
LIBSEDML_EXTERN
int
SedWriter_setProgramName (SedWriter_t *sw, const char *name);

/**
 * Sets the version of this program. i.\ e.\ the one about to write out the
 * SedDocument.  If the program version and name are set
 * (setProgramName()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libSed version <libsedml version>. -->
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof SedWriter_t
 */
LIBSEDML_EXTERN
int
SedWriter_setProgramVersion (SedWriter_t *sw, const char *version);

/**
 * Writes the given Sed document to filename.
 *
 * @htmlinclude assuming-compressed-file.html
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 * If the filename ends with @em .zip, a filename that will be added to the
 * zip archive file will end with @em .xml or @em .sedml. For example, the filename
 * in the zip archive will be @em test.xml if the given filename is @em test.xml.zip
 * or @em test.zip. Also, the filename in the archive will be @em test.sedml if the
 * given filename is @em test.sedml.zip.
 *
 * @note To write a gzip/zip file, libSed needs to be configured and
 * linked with the <a target="_blank" href="http://www.zlib.net/">zlib</a> library at
 * compile time.  It also needs to be linked with the <a target="_blank"
 * href="">bzip2</a> library to write files in @em bzip2 format.  (Both
 * of these are the default configurations for libSed.)  Errors about
 * unreadable files will be logged and this method will return @c false
 * if a compressed filename is given and libSed was @em not linked with
 * the corresponding required library.
 *
 * @note SedWriter_hasZlib() and SedWriter_hasBzip2() can be used to
 * check whether libSed has been linked with each library.
 *
 * @return non-zero on success and zero if the filename could not be opened
 * for writing.
 *
 * @memberof SedWriter_t
 */
LIBSEDML_EXTERN
int
SedWriter_writeSedML ( SedWriter_t         *sw,
                       const SedDocument_t *d,
                       const char           *filename );

/**
 * Writes the given Sed document to filename.
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 * If the filename ends with @em .zip, a filename that will be added to the
 * zip archive file will end with @em .xml or @em .sedml. For example, the filename
 * in the zip archive will be @em test.xml if the given filename is @em test.xml.zip
 * or @em test.zip. Also, the filename in the archive will be @em test.sedml if the
 * given filename is @em test.sedml.zip.
 *
 * @note To create a gzip/zip file, libSed needs to be linked with zlib at 
 * compile time. Also, libSed needs to be linked with bzip2 to create a bzip2 file.
 * File unwritable error will be logged and @c zero will be returned if a compressed 
 * file name is given and libSed is not linked with the required library.
 * SedWriter_hasZlib() and SedWriter_hasBzip2() can be used to check whether
 * libSed was linked with the library at compile time.
 *
 * @return non-zero on success and zero if the filename could not be opened
 * for writing.
 *
 * @memberof SedWriter_t
 */
LIBSEDML_EXTERN
int
SedWriter_writeSedMLToFile ( SedWriter_t         *sw,
                       const SedDocument_t *d,
                       const char           *filename );


/**
 * Writes the given Sed document to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @return the string on success and @c NULL if one of the underlying parser
 * components fail (rare).
 *
 * @memberof SedWriter_t
 */
LIBSEDML_EXTERN
char *
SedWriter_writeSedMLToString (SedWriter_t *sw, const SedDocument_t *d);


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * libSed is linked with zlib at compile time.
 *
 * @return @c non-zero if zlib is linked, @c zero otherwise.
 *
 * @memberof SedWriter_t
 */
LIBSEDML_EXTERN
int
SedWriter_hasZlib ();


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * libSed is linked with bzip2 at compile time.
 *
 * @return @c non-zero if bzip2 is linked, @c zero otherwise.
 *
 * @memberof SedWriter_t
 */
LIBSEDML_EXTERN
int
SedWriter_hasBzip2 ();

#endif  /* !SWIG */


/**
 * Writes the given Sed document @p d to the file named by @p filename.
 * This convenience function is functionally equivalent to:
 *
 *   SedWriter_writeSedML(SedWriter_create(), d, filename);
 *
 * @htmlinclude assuming-compressed-file.html
 *
 * @param d the SedDocument object to be written out in XML format
 * 
 * @param filename a string giving the path to a file where the XML
 * content is to be written.
 *
 * @return @c 1 on success and @c 0 (zero) if @p filename could not be
 * written.  Some possible reasons for failure include (a) being unable to
 * open the file, and (b) using a filename that indicates a compressed Sed
 * file (i.e., a filename ending in <code>&quot;.zip&quot;</code> or
 * similar) when the compression functionality has not been enabled in
 * the underlying copy of libSed.
 *
 * @see SedWriter::hasZlib()
 * @see SedWriter::hasBzip2()
 *
 * @if conly
 * @memberof SedWriter_t
 * @endif
 */
LIBSEDML_EXTERN
int
writeSedML (const SedDocument_t *d, const char *filename);


/**
 * Writes the given Sed document @p d to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.  This convenience function is
 * functionally equivalent to:
 *
 *   SedWriter_writeSedMLToString(SedWriter_create(), d);
 *
 * but does not require the caller to create an SedWriter object first.
 *
 * @param d an SedDocument object to be written out in XML format
 *
 * @return the string on success and @c NULL if one of the underlying parser
 * components fail.
 *
 * @if clike @warning Note that the string is owned by the caller and
 * should be freed after it is no longer needed.@endif@~
 *
 * @if conly
 * @memberof SedWriter_t
 * @endif
 */
LIBSEDML_EXTERN
char *
writeSedMLToString (const SedDocument_t *d);


/**
 * Writes the given Sed document @p d to the file @p filename.
 * This convenience function is functionally equivalent to:
 *
 *   SedWriter_writeSedMLToFile(SedWriter_create(), d, filename);
 *
 * but that does not require the caller to create an SedWriter object first.
 *
 * @htmlinclude assuming-compressed-file.html
 * 
 * @param d an SedDocument object to be written out in XML format
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be written.
 *
 * @return @c 1 on success and @c 0 (zero) if @p filename could not be
 * written.  Some possible reasons for failure include (a) being unable to
 * open the file, and (b) using a filename that indicates a compressed Sed
 * file (i.e., a filename ending in <code>&quot;.zip&quot;</code> or
 * similar) when the compression functionality has not been enabled in
 * the underlying copy of libSed.
 *
 * @if clike @warning Note that the string is owned by the caller and
 * should be freed (with the normal string <code>free()</code> C++
 * function) after it is no longer needed.@endif@~
 *
 * @see SedWriter::hasZlib()
 * @see SedWriter::hasBzip2()
 *
 * @if conly
 * @memberof SedWriter_t
 * @endif
 */
LIBSEDML_EXTERN
int
writeSedMLToFile (const SedDocument_t *d, const char *filename);


END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* SedWriter_h */