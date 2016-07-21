#ifndef YUOMAMO_TESTER_COMPILER_RUNNER_H_
#define YUOMAMO_TESTER_COMPILER_RUNNER_H_

#include <string>
#include "language.h"
#include "runner.h"

class CompilerRunner : public Runner{
  public:
    CompilerRunner(std::string sourceFile, std::string testcaseFile);
    virtual int compile() const;
    virtual int cleanup() const;
  protected:
    virtual std::string executableFile() const;
    virtual std::string compiler() const = 0;
    virtual std::string commandToCompile() const;
    virtual std::string commandToExecute() const;
    virtual std::string commandToCleanup() const;
  private:
    std::string executableFile_;
};

class CRunner : public CompilerRunner{
  public:
    CRunner(std::string sourceFile, std::string testcaseFile);
    virtual Language language() const;
  protected:
    virtual std::string compiler() const;
};

class CPlusPlusRunner : public CompilerRunner{
  public:
    CPlusPlusRunner(std::string sourceFile, std::string testcaseFile);
    virtual Language language() const;
  protected:
    virtual std::string compiler() const;
};

#endif // YUOMAMO_TESTER_COMPILER_RUNNER_H_
