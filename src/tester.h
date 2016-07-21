#ifndef YUOMAMO_TESTER_TESTER__H_
#define YUOMAMO_TESTER_TESTER__H_

#include <string>
#include <vector>
#include "language.h"
#include "runner.h"

class Tester{
    std::vector<std::string> _args;
    Language _lang;
    std::string _target;

public:
    Tester(int argc, char** argv);
    std::string tester_file() const;
    std::string source_file() const;
    Language language() const;
    std::string testcase_file() const;
};

Runner* create_runner(Language language, std::string source_file, std::string testcase_file);

#endif // YUOMAMO_TESTER_TESTER__H_
