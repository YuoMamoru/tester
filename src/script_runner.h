#ifndef YUOMAMO_TESTER_SCRIPT_RUNNER_H_
#define YUOMAMO_TESTER_SCRIPT_RUNNER_H_

#include <string>
#include "runner.h"

class ScriptRunner : public Runner{
protected:
    virtual std::string script_command() const = 0;
    virtual std::string execute_command() const;
public:
    ScriptRunner(std::string source_file, std::string testcase_file);
};

class RubyRunner : public ScriptRunner{
protected:
    virtual std::string script_command() const;
public:
    RubyRunner(std::string source_file, std::string testcase_file);
    virtual Language language() const;
};

class JavaScriptRunner : public ScriptRunner{
protected:
    virtual std::string script_command() const;
public:
    JavaScriptRunner(std::string source_file, std::string testcase_file);
    virtual Language language() const;
};

#endif // YUOMAMO_TESTER_SCRIPT_RUNNER_H_
