using namespace std;

class ArgParser{
    vector<string> _args;
    Language _lang;
    string _target;

public:
    ArgParser(int argc, char** argv);
    string tester_file() const;
    string source_file() const;
    Language language() const;
    string testcase_file() const;
};

Runner* create_runner(Language language, string source_file, string testcase_file);
