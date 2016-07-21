#ifndef COMPILER_RUNNER_H_
#define COMPILER_RUNNER_H_

using namespace std;

class CompilerRunner : public Runner{
    string _execute_file;

protected:
    virtual string execute_file() const;
    virtual string compiler() const = 0;
    virtual string compile_command() const;
    virtual string execute_command() const;
    virtual string cleanup_command() const;

public:
    CompilerRunner(string source_file, string testcase_file);
    virtual int compile() const;
    virtual int cleanup() const;
};

class CRunner : public CompilerRunner{
protected:
    virtual string compiler() const;
public:
    CRunner(string source_file, string testcase_file);
    virtual Language language() const;
};

class CPlusPlusRunner : public CompilerRunner{
protected:
    virtual string compiler() const;
public:
    CPlusPlusRunner(string source_file, string testcase_file);
    virtual Language language() const;
};

#endif //  COMPILER_RUNNER_H_
