#ifndef YUOMAMO_TESTER_IL_TESTER_H_
#define YUOMAMO_TESTER_IL_TESTER_H_

#include <string>
#include "compiler_tester.h"

class IlTester : public CompilerTester{
  public:
    IlTester(const char* sourceFile, const char* testcaseFile);
  private:
    IlTester();
    IlTester(const IlTester&);
    void operator=(const IlTester&);
  protected:
    virtual std::string virtualMachine() const = 0;
    virtual std::string commandToCompile() const;
    virtual std::string commandToExecute() const;
};

class JavaTester : public IlTester{
  public:
    JavaTester(const char* sourceFile, const char* testcaseFile);
    virtual std::string language() const;
  private:
    JavaTester();
    JavaTester(const JavaTester&);
    void operator=(const JavaTester&);
  protected:
    virtual std::string commandToCleanup() const;
    virtual std::string virtualMachine() const;
    virtual std::string compiler() const;
};

class CSharpTester : public IlTester{
  public:
    CSharpTester(const char* sourceFile, const char* testcaseFile);
  private:
    CSharpTester();
    CSharpTester(const CSharpTester&);
    void operator=(const CSharpTester&);
  public:
    virtual std::string language() const;
  protected:
    virtual std::string virtualMachine() const;
    virtual std::string executableFile() const;
    virtual std::string compiler() const;
};

#endif // YUOMAMO_TESTER_IL_TESTER_H_
