# Generated by org.mangosdk.spi.processor.SpiProcessor (0.2.4)
# Sat, 9 Jul 2016 11:06:31 +0400
*
* (non-Javadoc)
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
* @param orig the Transition instance to copy.
* @param version
* @see org.sbml.jsbml.NamedSBase
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
* the Free Software Foundation. A copy of the license agreement is provided
* under the terms of the GNU Lesser General Public License as published b
*/
/*
/* (non-Javadoc)
/* Assignment operator for Transition.
/* hashcode method for Transition.
/**
@Override
Transition obj = (Transition) object;
boolean equals = super.equals(object);
boolean isAttributeRead = super.readAttribute(attributeName, prefix, value);
equals &= (obj.getFunctionTerm() == getFunctionTerm());
equals &= (obj.getInput() == getInput());
equals &= (obj.getOutput() == getOutput());
equals &= obj.isSetFunctionTerm() == isSetFunctionTerm();
equals &= obj.isSetInput() == isSetInput();
equals &= obj.isSetOutput() == isSetOutput();
final int prime = 628063;
functionTerm = null;
if (equals && isSetFunctionTerm()) {
if (equals && isSetInput()) {
if (equals && isSetOutput()) {
if (equals) {
if (getLevelAndVersion().compareTo(Integer.valueOf(3), Integer.valueOf(1)) < 0) {
if (orig.isSetFunctionTerm()) {
if (orig.isSetInput()) {
if (orig.isSetOutput()) {
import java.text.MessageFormat;
import java.util.Map;
import org.sbml.jsbml.*;
import org.sbml.jsbml.util.*;
import org.sbml.jsbml.util.filters.*;
initDefaults();
input = null;
int hashCode = super.hashCode();
output = null;
package org.sbml.jsbml.ext.qual;
packageName = QualConstants.shortLabel;
private static final long serialVersionUID = 5394337909138983L;
public String toString() {
public Transition clone() {
public Transition() {
public Transition(String id) {
public Transition(String id, String name, int level, int version) {
public Transition(String id, int level, int version) {
public Transition(Transition orig) {
public Transition(int level, int version) {
public boolean equals(Object object) {
public boolean isIdMandatory() {
public boolean readAttribute(String attributeName, String prefix, String value) {
public class Transition extends AbstractNamedSBase implements UniqueNamedSBase {
public int hashCode() {
public void initDefaults() {
return "Transition [id = " + getId() + ", name = " + getName() + "]";
return equals;
return false;
return hashCode;
return isAttributeRead;
return new Transition(this);
setFunctionTerm(orig.getFunctionTerm());
setInput(orig.getInput());
setOutput(orig.getOutput());
setPackageVersion(-1);
super();
super(id);
super(id, name, level, version);
super(orig);
this(id, null, level, version);
this(null, null, level, version);
throw new LevelVersionError(getElementName(), level, version);
}
}  }
