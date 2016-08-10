/*
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
package org.sbml.jsbml.ext.qual;

import java.text.MessageFormat;
import java.util.Locale;
import java.util.Map;
import javax.swing.tree.TreeNode;

import org.sbml.jsbml.*;
import org.sbml.jsbml.util.*;
import org.sbml.jsbml.util.filters.*;
import org.sbml.jsbml.xml.XMLNode;

/**
 * @author Deviser
 * @version $Rev: 2465 $
 * @since 1.2
 * @date $Date: $
 */
public class FunctionTerm extends AbstractMathContainer {

  /**
   * Generated serial version identifier.
   */
  private static final long serialVersionUID = 70029477126819993L;
  /**
   *
   */
  private Integer resultLevel;
  /**
   *
   */
  private ASTNode math;

  /**
   *  
   */
  public FunctionTerm() {
    super();
    initDefaults();
  }

  /**
   * @param level
   * @param version
   */
  public FunctionTerm(int level, int version) {
    super(level, version);
    initDefaults();
  }

  /**
   * @param orig the FunctionTerm instance to copy.
   */
  public FunctionTerm(FunctionTerm orig) {
    super(orig);

    if (orig.isSetResultLevel()) {
      setResultLevel(orig.getResultLevel());
    }
    if (orig.isSetMath()) {
      setMath(orig.getMath().clone());
    }
  }

  /**
   *  
   */
  public void initDefaults() {
    setPackageVersion(-1);
    packageName = QualConstants.shortLabel;
    resultLevel = null;
  }

  /* (non-Javadoc)
   * @see java.lang.Object#equals(java.lang.Object)
   */
  @Override
  public boolean equals(Object object) {
    boolean equals = super.equals(object);

    if (equals) {
      FunctionTerm obj = (FunctionTerm) object;

      equals &= obj.isSetResultLevel() == isSetResultLevel();
      if (equals && isSetResultLevel()) {
        equals &= (obj.getResultLevel() == getResultLevel());
      }
      equals &= obj.isSetMath() == isSetMath();
      if (equals && isSetMath()) {
        equals &= (obj.getMath() == getMath());
      }
    }
    return equals;
  }

  /**
   * (non-Javadoc)
   */
  public FunctionTerm clone() {
    return new FunctionTerm(this);
  }

  /**
   * Returns the value of {@link resultLevel}.
   *  
   * @return the value of {@link resultLevel}.
   */
  public int getResultLevel() {
    if (isSetResultLevel()) {
      return resultLevel.intValue();
    }
    throw new PropertyUndefinedError(QualConstants.resultLevel, this);
  }

  /**
   * Returns whether {@link resultLevel} is set.
   *  
   * @return whether {@link resultLevel} is set.
   */
  public boolean isSetResultLevel() {
    return this.resultLevel != null;
  }

  /**
   * Sets the value of resultLevel
   *  
   * @param resultLevel the value of resultLevel to be set.
   */
  public boolean setResultLevel(int resultLevel) {
    if (resultLevel != this.resultLevel) {
      Integer oldResultLevel = this.resultLevel;
      this.resultLevel = resultLevel;
      firePropertyChange(QualConstants.resultLevel, oldResultLevel,
        this.resultLevel);
      return true;
    }
    return false;
  }

  /**
   * Unsets the variable resultLevel.
   *  
   * @return {@code true} if resultLevel was set before, otherwise {@code
   * false}.
   */
  public boolean unsetResultLevel() {
    if (isSetResultLevel()) {
      Integer oldResultLevel = resultLevel;
      resultLevel = null;
      firePropertyChange(QualConstants.resultLevel, oldResultLevel,
        resultLevel);
      return true;
    }
    return false;
  }

  /**
   * Returns the value of {@link math}.
   *  
   * @return the value of {@link math}.
   */
  public ASTNode getMath() {
    return math;
  }

  /**
   * Returns whether {@link math} is set.
   *  
   * @return whether {@link math} is set.
   */
  public boolean isSetMath() {
    return math != null;
  }

  /**
   * Sets the value of math
   *  
   * @param math the value of math to be set.
   */
  public void setMath(ASTNode math) {
    ASTNode oldMath = this.math;

    this.math = math;

    if (oldMath != null) {
      oldMath.fireNodeRemovedEvent();
    }
    if (this.math != null) {
      firePropertyChange(TreeNodeChangeEvent.math, oldMath, math);
    }
  }

  /**
   * Unsets the variable math.
   *  
   * @return {@code true} if math was set before, otherwise {@code false}.
   */
  public void unsetMath() {
    setMath(null);
  }

  /* hashcode method for FunctionTerm.
   */
  @Override
  public int hashCode() {
    final int prime = 3492877;

    int hashCode = super.hashCode();

    if (isSetResultLevel()) {
      hashCode += prime * getResultLevel();
    }
    return hashCode;
  }

  /* (non-Javadoc)
   * see java.lang.Object#toString()
   */
  @Override
  public String toString() {
    StringBuilder builder = new StringBuilder();
    builder.append("FunctionTerm [");
    builder.append("resultLevel = ");
    builder.append(resultLevel);
    builder.append(", ");
    builder.append("math = ");
    builder.append(math);
    builder.append("isSetMath = ");
    builder.append(isSetMath());
    builder.append("]");
    return builder.toString();
  }

  /* (non-Javadoc)
   * @see org.sbml.jsbml.AbstractNamedSBase#readAttribute(java.lang.String,
   */
  @Override
  public boolean readAttribute(String attributeName, String prefix, String value) {
    boolean isAttributeRead = super.readAttribute(attributeName, prefix, value);

    return isAttributeRead;
  }

  /* (non-Javadoc)
   * @see org.sbml.jsbml.AbstractNamedSBase#writeXMLAttributes()
   */
  @Override
  public Map <String, String> writeXMLAttributes() {
    Map <String, String> attributes = super.writeXMLAttributes();

    if (isSetResultLevel()) {
      attributes.put(QualConstants.shortLabel + ":" + QualConstants.resultLevel,
        Integer.toString(getResultLevel()));
    }
    return attributes;
  }

}