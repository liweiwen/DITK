/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkSphereSpatialFunction_h
#define __itkSphereSpatialFunction_h

#include "itkInteriorExteriorSpatialFunction.h"

namespace itk
{
/** \class SphereSpatialFunction
 * \brief Spatial function implementation of a sphere
 *
 * Implements a function that returns 0 for points inside or on the surface
 * of a sphere, 1 for points outside the sphere
 *
 * \ingroup SpatialFunctions
 * \ingroup ITK-Common
 */
template< unsigned int VImageDimension = 3, typename TInput = Point< double, VImageDimension > >
class ITK_EXPORT SphereSpatialFunction:
  public InteriorExteriorSpatialFunction< VImageDimension, TInput >
{
public:
  /** Standard class typedefs. */
  typedef SphereSpatialFunction< VImageDimension, TInput >           Self;
  typedef InteriorExteriorSpatialFunction< VImageDimension, TInput > Superclass;
  typedef SmartPointer< Self >                                       Pointer;
  typedef SmartPointer< const Self >                                 ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(SphereSpatialFunction, InteriorExteriorSpatialFunction);

  /** Input type for the function. */
  typedef typename Superclass::InputType InputType;

  /** Output type for the function. */
  typedef typename Superclass::OutputType OutputType;

  /** Evaluates the function at a given position */
  OutputType Evaluate(const InputType & position) const;

  /** Get and set the center of the sphere. */
  itkGetConstMacro(Center, InputType);
  itkSetMacro(Center, InputType);

  /** Get and set the radius of the sphere */
  itkGetConstMacro(Radius, double);
  itkSetMacro(Radius, double);
protected:
  SphereSpatialFunction();
  virtual ~SphereSpatialFunction();
  void PrintSelf(std::ostream & os, Indent indent) const;

private:
  SphereSpatialFunction(const Self &); //purposely not implemented
  void operator=(const Self &);        //purposely not implemented

  /** The center of the sphere (of the same type as Input). */
  InputType m_Center;

  /** The radius of the sphere. */
  double m_Radius;
};
} // end namespace itk

// Define instantiation macro for this template.
#define ITK_TEMPLATE_SphereSpatialFunction(_, EXPORT, TypeX, TypeY)     \
  namespace itk                                                         \
  {                                                                     \
  _( 2 ( class EXPORT SphereSpatialFunction< ITK_TEMPLATE_2 TypeX > ) ) \
  namespace Templates                                                   \
  {                                                                     \
  typedef SphereSpatialFunction< ITK_TEMPLATE_2 TypeX >                 \
  SphereSpatialFunction##TypeY;                                       \
  }                                                                     \
  }

#if ITK_TEMPLATE_EXPLICIT
#include "Templates/itkSphereSpatialFunction+-.h"
#endif

#if ITK_TEMPLATE_TXX
#include "itkSphereSpatialFunction.txx"
#endif

#endif
