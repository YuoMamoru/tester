#ifndef YUOMAMO_TESTER_IL_RUNNER_H_
#define YUOMAMO_TESTER_IL_RUNNER_H_

#include <string>
#include "compiler_runner.h"

class IlRunner : public CompilerRunner{
protected:
    virtual std::string vm_command() const = 0;
    virtual std::string compile_command() const;
    virtual std::string execute_command() const;
public:
    IlRunner(std::string source_file, std::string testcase_file);
};

class JavaRunner : public IlRunner{
protected:
    virtual std::string vm_command() const;
    virtual std::string execute_file() const;
    virtual std::string compiler() const;
public:
    JavaRunner(std::string source_file, std::string testcase_file);
    virtual Language language() const;
};

class CSharpRunner : public IlRunner{
protected:
    virtual std::string vm_command() const;
    virtual std::string execute_file() const;
    virtual std::string compiler() const;
public:
    CSharpRunner(std::string source_file, std::string testcase_file);
    virtual Language language() const;
};

#endif // YUOMAMO_TESTER_IL_RUNNER_H_
