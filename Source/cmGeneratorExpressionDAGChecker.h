/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2012 Stephen Kelly <steveire@gmail.com>

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmGeneratorExpressionDAGChecker_h
#define cmGeneratorExpressionDAGChecker_h

#include "cmStandardIncludes.h"

#include "cmGeneratorExpressionEvaluator.h"

//----------------------------------------------------------------------------
struct cmGeneratorExpressionDAGChecker
{
  cmGeneratorExpressionDAGChecker(const cmListFileBacktrace &backtrace,
                                  const std::string &target,
                                  const std::string &property,
                                  const GeneratorExpressionContent *content,
                                  cmGeneratorExpressionDAGChecker *parent);

  enum Result {
    DAG,
    SELF_REFERENCE,
    CYCLIC_REFERENCE,
    ALREADY_SEEN
  };

  Result check() const;

  void reportError(cmGeneratorExpressionContext *context,
                   const std::string &expr);

  bool EvaluatingLinkLibraries();
  bool EvaluatingIncludeDirectories() const;
  bool EvaluatingCompileDefinitions() const;

private:
  Result checkGraph() const;

private:
  const cmGeneratorExpressionDAGChecker * const Parent;
  const std::string Target;
  const std::string Property;
  std::map<cmStdString, std::set<cmStdString> > Seen;
  const GeneratorExpressionContent * const Content;
  const cmListFileBacktrace Backtrace;
  Result CheckResult;
};

#endif
