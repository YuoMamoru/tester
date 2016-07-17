using namespace std;

class IlRunner : public CompilerRunner{
protected:
    virtual string vm_command() const = 0;
    virtual string compile_command() const;
    virtual string execute_command() const;
public:
    IlRunner(string source_file, string testcase_file);
};

class JavaRunner : public IlRunner{
protected:
    virtual string vm_command() const;
    virtual string execute_file() const;
    virtual string compiler() const;
public:
    JavaRunner(string source_file, string testcase_file);
    virtual Language language() const;
};

class CSharpRunner : public IlRunner{
protected:
    virtual string vm_command() const;
    virtual string execute_file() const;
    virtual string compiler() const;
public:
    CSharpRunner(string source_file, string testcase_file);
    virtual Language language() const;
};
