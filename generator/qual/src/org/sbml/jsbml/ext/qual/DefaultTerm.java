# Generated by org.mangosdk.spi.processor.SpiProcessor (0.2.4)
# Sun, 3 Jul 2016 01:27:03 +0400
*
* ----------------------------------------------------------------------------
* 1. The University of Tuebingen, Germany
* 2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
* 3. The California Institute of Technology, Pasadena, CA, USA
* 4. The University of California, San Diego, La Jolla, CA, USA
* 5. The Babraham Institute, Cambridge, UK
* @author Deviser
* @date $Date: $
* @param id
* @param level
* @param name
* @param orig the DefaultTerm instance to copy.
* @param resultLevel
* @param version
* @return
* @return the resultLevel
* @return {@code true} if the unset of the resultLevel attribute was
* @since 1.2
* @version $Rev: 2465 $
* Copyright (C) 2009-2016 jointly by the following organizations:
* Generated serial version identifier.
* This file is part of JSBML. Please visit <http://sbml.org/Software/JSBML>
* This library is free software; you can redistribute it and/or modify it
* and also available online as <http://sbml.org/Software/JSBML/License>.
* for the latest version of JSBML and more information about SBML.
* in the file named "LICENSE.txt" included with this software distribution
* successful
* the Free Software Foundation. A copy of the license agreement is provided
* under the terms of the GNU Lesser General Public License as published b
*/
/*
/* (non-Javadoc)
/**
@Override
Integer oldResultLevel = resultLevel;
Integer oldResultLevel = this.resultLevel;
firePropertyChange(QualConstants.resultLevel, oldResultLevel,
if (getLevelAndVersion().compareTo(Integer.valueOf(3), Integer.valueOf(1)) < 0) {
if (isSetResultLevel()) {
if (orig.isSetResultLevel()) {
import java.util.Map;
import org.sbml.jsbml.*;
import org.sbml.jsbml.util.*;
import org.sbml.jsbml.util.filters.*;
initDefaults();
package org.sbml.jsbml.ext.qual;
packageName = QualConstants.shortLabel;
private Integer resultLevel;
private static final long serialVersionUID = -6048861420699176889L;
public DefaultTerm clone() {
public DefaultTerm() {
public DefaultTerm(DefaultTerm orig) {
public DefaultTerm(String id) {
public DefaultTerm(String id, String name, int level, int version) {
public DefaultTerm(String id, int level, int version) {
public DefaultTerm(int level, int version) {
public boolean isSetResultLevel() {
public boolean unsetResultLevel() {
public class DefaultTerm extends AbstractMathContainer {
public int getResultLevel() {
public void initDefaults() {
public void setResultLevel(int resultLevel) {
resultLevel = null;
resultLevel);
return false;
return new DefaultTerm(this);
return resultLevel != null;
return resultLevel.intValue();
return true;
setPackageVersion(-1);
setResultLevel(orig.getResultLevel());
super();
super(id);
super(id, name, level, version);
super(orig);
this(id, null, level, version);
this(null, null, level, version);
this.resultLevel = resultLevel;
this.resultLevel);
throw new LevelVersionError(getElementName(), level, version);
throw new PropertyUndefinedError(QualConstants.resultLevel, this);
}
}  }
} else {
