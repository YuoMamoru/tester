#ifndef YUOMAMO_TESTER_COMPILER_RUNNER_H_
#define YUOMAMO_TESTER_COMPILER_RUNNER_H_

#include <string>
#include "language.h"
#include "runner.h"

class CompilerRunner : public Runner{
  public:
    CompilerRunner(const char* sourceFile, const char* testcaseFile);
    virtual ~CompilerRunner();
  private:
    CompilerRunner();
    CompilerRunner(const CompilerRunner&);
    void operator=(const CompilerRunner&);
  public:
    virtual int compile() const;
    virtual int cleanup() const;
  protected:
    virtual std::string executableFile() const;
    virtual std::string compiler() const = 0;
    virtual std::string commandToCompile() const;
    virtual std::string commandToExecute() const;
    virtual std::string commandToCleanup() const;
  private:
    char* executableFile_;
};

class CRunner : public CompilerRunner{
  public:
    CRunner(const char* sourceFile, const char* testcaseFile);
  private:
    CRunner();
    CRunner(const CRunner&);
    void operator=(const CRunner&);
  public:
    virtual Language language() const;
  protected:
    virtual std::string compiler() const;
};

class CPlusPlusRunner : public CompilerRunner{
  public:
    CPlusPlusRunner(const char* sourceFile, const char* testcaseFile);
  private:
    CPlusPlusRunner();
    CPlusPlusRunner(const CPlusPlusRunner&);
    void operator=(const CPlusPlusRunner&);
    virtual Language language() const;
  protected:
    virtual std::string compiler() const;
};

#endif // YUOMAMO_TESTER_COMPILER_RUNNER_H_
