#ifndef YUOMAMO_TESTER_SCRIPT_RUNNER_H_
#define YUOMAMO_TESTER_SCRIPT_RUNNER_H_

#include <string>
#include "runner.h"

class ScriptRunner : public Runner{
  public:
    ScriptRunner(std::string source_file, std::string testcase_file);
  protected:
    virtual std::string script_command() const = 0;
    virtual std::string execute_command() const;
};

class RubyRunner : public ScriptRunner{
  public:
    RubyRunner(std::string source_file, std::string testcase_file);
    virtual Language language() const;
  protected:
    virtual std::string script_command() const;
};

class JavaScriptRunner : public ScriptRunner{
  public:
    JavaScriptRunner(std::string source_file, std::string testcase_file);
    virtual Language language() const;
  protected:
    virtual std::string script_command() const;
};

#endif // YUOMAMO_TESTER_SCRIPT_RUNNER_H_
