using namespace std;

class Runner{
    string _source_file;
    string _testcase_file;

protected:
    virtual string execute_command() const = 0;

public:
    Runner(string source_file, string testcase_file);
    string source_file() const;
    string testcase_file() const;
    virtual Language language() const;
    virtual int compile() const;
    virtual int execute() const;
    virtual int cleanup() const;
    void run() const;
};
