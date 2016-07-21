#ifndef YUOMAMO_TESTER_COMPILER_RUNNER_H_
#define YUOMAMO_TESTER_COMPILER_RUNNER_H_

#include <string>
#include "language.h"
#include "runner.h"

class CompilerRunner : public Runner{
    std::string _execute_file;

protected:
    virtual std::string execute_file() const;
    virtual std::string compiler() const = 0;
    virtual std::string compile_command() const;
    virtual std::string execute_command() const;
    virtual std::string cleanup_command() const;

public:
    CompilerRunner(std::string source_file, std::string testcase_file);
    virtual int compile() const;
    virtual int cleanup() const;
};

class CRunner : public CompilerRunner{
protected:
    virtual std::string compiler() const;
public:
    CRunner(std::string source_file, std::string testcase_file);
    virtual Language language() const;
};

class CPlusPlusRunner : public CompilerRunner{
protected:
    virtual std::string compiler() const;
public:
    CPlusPlusRunner(std::string source_file, std::string testcase_file);
    virtual Language language() const;
};

#endif // YUOMAMO_TESTER_COMPILER_RUNNER_H_
