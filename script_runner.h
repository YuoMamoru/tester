#ifndef SCRIPT_RUNNER_H_
#define SCRIPT_RUNNER_H_

using namespace std;

class ScriptRunner : public Runner{
protected:
    virtual string script_command() const = 0;
    virtual string execute_command() const;
public:
    ScriptRunner(string source_file, string testcase_file);
};

class RubyRunner : public ScriptRunner{
protected:
    virtual string script_command() const;
public:
    RubyRunner(string source_file, string testcase_file);
    virtual Language language() const;
};

class JavaScriptRunner : public ScriptRunner{
protected:
    virtual string script_command() const;
public:
    JavaScriptRunner(string source_file, string testcase_file);
    virtual Language language() const;
};

#endif // SCRIPT_RUNNER_H_
