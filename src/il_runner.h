#ifndef YUOMAMO_TESTER_IL_RUNNER_H_
#define YUOMAMO_TESTER_IL_RUNNER_H_

#include <string>
#include "compiler_runner.h"

class IlRunner : public CompilerRunner{
  public:
    IlRunner(const char* sourceFile, const char* testcaseFile);
  private:
    IlRunner();
    IlRunner(const IlRunner&);
    void operator=(const IlRunner&);
  protected:
    virtual std::string virtualMachine() const = 0;
    virtual std::string commandToCompile() const;
    virtual std::string commandToExecute() const;
};

class JavaRunner : public IlRunner{
  public:
    JavaRunner(const char* sourceFile, const char* testcaseFile);
    virtual Language language() const;
  private:
    JavaRunner();
    JavaRunner(const JavaRunner&);
    void operator=(const JavaRunner&);
  protected:
    virtual std::string commandToCleanup() const;
    virtual std::string virtualMachine() const;
    virtual std::string compiler() const;
};

class CSharpRunner : public IlRunner{
  public:
    CSharpRunner(const char* sourceFile, const char* testcaseFile);
  private:
    CSharpRunner();
    CSharpRunner(const CSharpRunner&);
    void operator=(const CSharpRunner&);
  public:
    virtual Language language() const;
  protected:
    virtual std::string virtualMachine() const;
    virtual std::string executableFile() const;
    virtual std::string compiler() const;
};

#endif // YUOMAMO_TESTER_IL_RUNNER_H_
