#ifndef YUOMAMO_TESTER_COMPILER_TESTER_H_
#define YUOMAMO_TESTER_COMPILER_TESTER_H_

#include <string>
#include "tester.h"

class CompilerTester : public Tester{
  public:
    CompilerTester(const char* sourceFile, const char* testcaseFile);
    virtual ~CompilerTester();
  private:
    CompilerTester();
    CompilerTester(const CompilerTester&);
    void operator=(const CompilerTester&);
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

class CTester : public CompilerTester{
  public:
    CTester(const char* sourceFile, const char* testcaseFile);
  private:
    CTester();
    CTester(const CTester&);
    void operator=(const CTester&);
  public:
    virtual std::string language() const;
  protected:
    virtual std::string compiler() const;
};

class CPlusPlusTester : public CompilerTester{
  public:
    CPlusPlusTester(const char* sourceFile, const char* testcaseFile);
  private:
    CPlusPlusTester();
    CPlusPlusTester(const CPlusPlusTester&);
    void operator=(const CPlusPlusTester&);
    virtual std::string language() const;
  protected:
    virtual std::string compiler() const;
};

#endif // YUOMAMO_TESTER_COMPILER_TESTER_H_
