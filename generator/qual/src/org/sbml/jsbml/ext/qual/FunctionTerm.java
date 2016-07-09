# Generated by org.mangosdk.spi.processor.SpiProcessor (0.2.4)
# Sat, 9 Jul 2016 11:06:31 +0400
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
* @param orig the FunctionTerm instance to copy.
* @param resultLevel
* @param version
* @return
* @return the resultLevel
* @return {@code true} if the unset of the resultLevel attribute was
* @see org.sbml.jsbml.AbstractMathContainer
* @since 1.2
* @version $Rev: 2465 $
* Copyright (C) 2009-2016 jointly by the following organizations:
* Generated serial version identifier.
* This file is part of JSBML. Please visit <http://sbml.org/Software/JSBML>
* This library is free software; you can redistribute it and/or modify it
* and also available online as <http://sbml.org/Software/JSBML/License>.
* for the latest version of JSBML and more information about SBML.
* in the file named "LICENSE.txt" included with this software distribution
* see java.lang.Object
* successful
* the Free Software Foundation. A copy of the license agreement is provided
* under the terms of the GNU Lesser General Public License as published b
*/
/*
/* (non-Javadoc)
/* Assignment operator for FunctionTerm.
/* hashcode method for FunctionTerm.
/**
@Override
FunctionTerm obj = (FunctionTerm) object;
Integer oldResultLevel = resultLevel;
Integer oldResultLevel = this.resultLevel;
boolean equals = super.equals(object);
boolean isAttributeRead = super.readAttribute(attributeName, prefix, value);
equals &= (obj.getMath() == getMath());
equals &= (obj.getResultLevel() == getResultLevel());
equals &= obj.isSetMath() == isSetMath();
equals &= obj.isSetResultLevel() == isSetResultLevel();
final int prime = 8643143;
firePropertyChange(QualConstants.resultLevel, oldResultLevel,
hashCode += prime * getResultLevel();
if (equals && isSetMath()) {
if (equals && isSetResultLevel()) {
if (equals) {
if (getLevelAndVersion().compareTo(Integer.valueOf(3), Integer.valueOf(1)) < 0) {
if (isSetResultLevel()) {
if (orig.isSetMath()) {
if (orig.isSetResultLevel()) {
import java.util.Map;
import org.sbml.jsbml.*;
import org.sbml.jsbml.util.*;
import org.sbml.jsbml.util.filters.*;
initDefaults();
int hashCode = super.hashCode();
math = null;
package org.sbml.jsbml.ext.qual;
packageName = QualConstants.shortLabel;
private Integer resultLevel;
private static final long serialVersionUID = 40170095699187089L;
public FunctionTerm clone() {
public FunctionTerm() {
public FunctionTerm(FunctionTerm orig) {
public FunctionTerm(String id) {
public FunctionTerm(String id, String name, int level, int version) {
public FunctionTerm(String id, int level, int version) {
public FunctionTerm(int level, int version) {
public String toString() {
public boolean equals(Object object) {
public boolean isSetResultLevel() {
public boolean readAttribute(String attributeName, String prefix, String value) {
public boolean unsetResultLevel() {
public class FunctionTerm extends AbstractMathContainer {
public int getResultLevel() {
public int hashCode() {
public void initDefaults() {
public void setResultLevel(int resultLevel) {
resultLevel = null;
resultLevel);
return "FunctionTerm [id = " + getId() + ", name = " + getName() + "]";
return equals;
return false;
return hashCode;
return isAttributeRead;
return new FunctionTerm(this);
return resultLevel != null;
return resultLevel.intValue();
return true;
setMath(orig.getMath());
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
