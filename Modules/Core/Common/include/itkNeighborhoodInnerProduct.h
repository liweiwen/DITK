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
#ifndef __itkNeighborhoodInnerProduct_h
#define __itkNeighborhoodInnerProduct_h

#include "itkNeighborhoodIterator.h"
#include "itkConstSliceIterator.h"
#include "itkImageBoundaryCondition.h"

namespace itk
{
/** \class NeighborhoodInnerProduct
 *
 * This class defines the inner product operation between an
 * itk::Neighborhood and and itk::NeighborhoodOperator.  The
 * operator() method is overloaded to support various types of
 * neighborhoods as well as inner products with slices of
 * neighborhoods.
 *
 * \tparam TImage         Type of image on which the class operates.
 * \tparam TOperator      The value type of the operator (defaults to
 * the image pixel type).
* \tparam TComputation   The value type used as the return type of the
 * inner product calculation (defaults to the operator type).
 *
 * \ingroup Operators
 * \ingroup ITK-Common
 */

template< class TImage, class TOperator = ITK_TYPENAME TImage::PixelType, class TComputation = TOperator >
class ITK_EXPORT NeighborhoodInnerProduct
{
public:
  /** Standard typedefs */
  typedef NeighborhoodInnerProduct Self;

  /** Capture some typedefs from the template parameters. */
  typedef typename TImage::PixelType ImagePixelType;
  typedef TOperator                  OperatorPixelType;
  typedef TComputation               OutputPixelType;

  /** Capture some typedefs from the template parameters. */
  itkStaticConstMacro(ImageDimension, unsigned int, TImage::ImageDimension);

  /** Operator typedef */
  typedef Neighborhood< OperatorPixelType,
                        itkGetStaticConstMacro(ImageDimension) > OperatorType;

  typedef Neighborhood< ImagePixelType,
                        itkGetStaticConstMacro(ImageDimension) > NeighborhoodType;

  /** Reference oeprator. */
  OutputPixelType operator()(const std::slice & s,
                             const ConstNeighborhoodIterator< TImage > & it,
                             const OperatorType & op) const;

  OutputPixelType operator()(const ConstNeighborhoodIterator< TImage > & it,
                             const OperatorType & op) const
  {
    return this->operator()(std::slice(0, it.Size(), 1), it, op);
  }

  OutputPixelType operator()(const std::slice & s,
                             const NeighborhoodType & N,
                             const OperatorType & op) const;

  OutputPixelType operator()(const NeighborhoodType & N,
                             const OperatorType & op) const
  {
    return this->operator()(std::slice(0, N.Size(), 1), N, op);
  }
};
} // end namespace itk

// Define instantiation macro for this template.
#define ITK_TEMPLATE_NeighborhoodInnerProduct(_, EXPORT, TypeX, TypeY)     \
  namespace itk                                                            \
  {                                                                        \
  _( 3 ( class EXPORT NeighborhoodInnerProduct< ITK_TEMPLATE_3 TypeX > ) ) \
  namespace Templates                                                      \
  {                                                                        \
  typedef NeighborhoodInnerProduct< ITK_TEMPLATE_3 TypeX >                 \
  NeighborhoodInnerProduct##TypeY;                                       \
  }                                                                        \
  }

#if ITK_TEMPLATE_EXPLICIT
#include "Templates/itkNeighborhoodInnerProduct+-.h"
#endif

#if ITK_TEMPLATE_TXX
#include "itkNeighborhoodInnerProduct.txx"
#endif

/*
#ifndef ITK_MANUAL_INSTANTIATION
#include "itkNeighborhoodInnerProduct.txx"
#endif
*/

#endif
