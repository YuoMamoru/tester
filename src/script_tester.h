#ifndef YUOMAMO_TESTER_SCRIPT_RUNNER_H_
#define YUOMAMO_TESTER_SCRIPT_RUNNER_H_

#include <string>
#include "runner.h"

class ScriptRunner : public Runner{
  public:
    ScriptRunner(const char* sourceFile, const char* testcaseFile);
  private:
    ScriptRunner();
    ScriptRunner(const ScriptRunner&);
    void operator=(const ScriptRunner&);
  protected:
    virtual std::string interpreter() const = 0;
    virtual std::string commandToExecute() const;
};

class RubyRunner : public ScriptRunner{
  public:
    RubyRunner(const char* sourceFile, const char* testcaseFile);
  private:
    RubyRunner();
    RubyRunner(const RubyRunner&);
    void operator=(const RubyRunner&);
  public:
    virtual Language language() const;
  protected:
    virtual std::string interpreter() const;
};

class JavaScriptRunner : public ScriptRunner{
  public:
    JavaScriptRunner(const char* sourceFile, const char* testcaseFile);
  private:
    JavaScriptRunner();
    JavaScriptRunner(const JavaScriptRunner&);
    void operator=(const JavaScriptRunner&);
  public:
    virtual Language language() const;
  protected:
    virtual std::string interpreter() const;
};

class PerlRunner : public ScriptRunner{
  public:
    PerlRunner(const char* sourceFile, const char* testcaseFile);
  private:
    PerlRunner();
    PerlRunner(const PerlRunner&);
    void operator=(const PerlRunner&);
  public:
    virtual Language language() const;
  protected:
    virtual std::string interpreter() const;
};

#endif // YUOMAMO_TESTER_SCRIPT_RUNNER_H_
