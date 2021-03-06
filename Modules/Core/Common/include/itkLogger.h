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
#ifndef __itkLogger_h
#define __itkLogger_h

#include "itkLoggerBase.h"

namespace itk
{
/** \class Logger
 *   \brief Class Logger is meant for logging information during a run.
 *
 * \author Hee-Su Kim, Compute Science Dept. Kyungpook National University,
 *                     ISIS Center, Georgetown University.
 *
 *
 *  \ingroup OSSystemObjects LoggingObjects
 * \ingroup ITK-Common
 */

class ITKCommon_EXPORT Logger:public LoggerBase
{
public:
  typedef Logger                     Self;
  typedef LoggerBase                 Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(Logger, Object);

  /** New macro for creation of through a Smart Pointer */
  itkNewMacro(Self);
protected:

  /** Constructor */
  Logger() {}

  /** Destructor */
  virtual ~Logger() {}
private:
  Logger(const Self &);         //purposely not implemented
  void operator=(const Self &); //purposely not implemented
};                              // class Logger
} // namespace itk

#endif  // __itkLogger_h
