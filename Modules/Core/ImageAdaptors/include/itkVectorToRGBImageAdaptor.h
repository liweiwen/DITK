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
#ifndef __itkVectorToRGBImageAdaptor_h
#define __itkVectorToRGBImageAdaptor_h

#include "itkImageAdaptor.h"
#include "itkVectorToRGBPixelAccessor.h"

namespace itk
{
/** \class VectorToRGBImageAdaptor
 * \brief Presents an image of pixel type Vector as being and image of
 * RGBPixel type.
 *
 * \ingroup ImageAdaptors
 *
 * \ingroup ITK-ImageAdaptors
 */
template< class TImage >
class ITK_EXPORT VectorToRGBImageAdaptor:public
  ImageAdaptor< TImage,
                Accessor::VectorToRGBPixelAccessor<
                  typename TImage::PixelType::ValueType
                  > >
{
public:
  /** Standard class typedefs. */
  typedef VectorToRGBImageAdaptor Self;
  typedef ImageAdaptor< TImage,
                        Accessor::VectorToRGBPixelAccessor<
                          typename TImage::PixelType::ValueType
                          >  > Superclass;

  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(VectorToRGBImageAdaptor, ImageAdaptor);

  /** PixelContainer typedef support. Used to construct a container for
   * the pixel data. */
  typedef typename Superclass::PixelContainer             PixelContainer;
  typedef typename Superclass::PixelContainerPointer      PixelContainerPointer;
  typedef typename Superclass::PixelContainerConstPointer PixelContainerConstPointer;
protected:
  VectorToRGBImageAdaptor() {}
  virtual ~VectorToRGBImageAdaptor() {}
private:
  VectorToRGBImageAdaptor(const Self &); //purposely not implemented
  void operator=(const Self &);          //purposely not implemented
};
} // end namespace itk

#endif
