#ifndef YUOMAMO_TESTER_IL_RUNNER_H_
#define YUOMAMO_TESTER_IL_RUNNER_H_

#include <string>
#include "compiler_runner.h"

class IlRunner : public CompilerRunner{
  public:
    IlRunner(std::string sourceFile, std::string testcaseFile);
  protected:
    virtual std::string virtualMachine() const = 0;
    virtual std::string commandToCompile() const;
    virtual std::string commandToExecute() const;
};

class JavaRunner : public IlRunner{
  public:
    JavaRunner(std::string sourceFile, std::string testcaseFile);
    virtual Language language() const;
  protected:
    virtual std::string virtualMachine() const;
    virtual std::string executableFile() const;
    virtual std::string compiler() const;
};

class CSharpRunner : public IlRunner{
  public:
    CSharpRunner(std::string sourceFile, std::string testcaseFile);
    virtual Language language() const;
  protected:
    virtual std::string virtualMachine() const;
    virtual std::string executableFile() const;
    virtual std::string compiler() const;
};

#endif // YUOMAMO_TESTER_IL_RUNNER_H_
