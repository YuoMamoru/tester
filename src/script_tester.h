#ifndef YUOMAMO_TESTER_SCRIPT_TESTER_H_
#define YUOMAMO_TESTER_SCRIPT_TESTER_H_

#include <string>
#include "tester.h"

class ScriptTester : public Tester{
  public:
    ScriptTester(const char* sourceFile, const char* testcaseFile);
  private:
    ScriptTester();
    ScriptTester(const ScriptTester&);
    void operator=(const ScriptTester&);
  protected:
    virtual std::string interpreter() const = 0;
    virtual std::string commandToExecute() const;
};

class RubyTester : public ScriptTester{
  public:
    RubyTester(const char* sourceFile, const char* testcaseFile);
  private:
    RubyTester();
    RubyTester(const RubyTester&);
    void operator=(const RubyTester&);
  public:
    virtual std::string language() const;
  protected:
    virtual std::string interpreter() const;
};

class JavaScriptTester : public ScriptTester{
  public:
    JavaScriptTester(const char* sourceFile, const char* testcaseFile);
  private:
    JavaScriptTester();
    JavaScriptTester(const JavaScriptTester&);
    void operator=(const JavaScriptTester&);
  public:
    virtual std::string language() const;
  protected:
    virtual std::string interpreter() const;
};

class PerlTester : public ScriptTester{
  public:
    PerlTester(const char* sourceFile, const char* testcaseFile);
  private:
    PerlTester();
    PerlTester(const PerlTester&);
    void operator=(const PerlTester&);
  public:
    virtual std::string language() const;
  protected:
    virtual std::string interpreter() const;
};

#endif // YUOMAMO_TESTER_SCRIPT_TESTER_H_
