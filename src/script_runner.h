#ifndef YUOMAMO_TESTER_SCRIPT_RUNNER_H_
#define YUOMAMO_TESTER_SCRIPT_RUNNER_H_

#include <string>
#include "runner.h"

class ScriptRunner : public Runner{
  public:
    ScriptRunner(std::string sourceFile, std::string testcaseFile);
  protected:
    virtual std::string interpreter() const = 0;
    virtual std::string commandToExecute() const;
};

class RubyRunner : public ScriptRunner{
  public:
    RubyRunner(std::string sourceFile, std::string testcaseFile);
    virtual Language language() const;
  protected:
    virtual std::string interpreter() const;
};

class JavaScriptRunner : public ScriptRunner{
  public:
    JavaScriptRunner(std::string sourceFile, std::string testcaseFile);
    virtual Language language() const;
  protected:
    virtual std::string interpreter() const;
};

#endif // YUOMAMO_TESTER_SCRIPT_RUNNER_H_
