#ifndef YUOMAMO_TESTER_TESTER__H_
#define YUOMAMO_TESTER_TESTER__H_

#include <string>
#include <vector>
#include "language.h"
#include "runner.h"

class Tester{
  public:
    Tester(int argc, char** argv);
    virtual ~Tester();
  private:
    Tester();
    Tester(const Tester&);
    void operator=(const Tester&);
  public:
    std::string testerFile() const;
    std::string sourceFile() const;
    std::string testcaseFile() const;
    Language language() const;
  private:
    std::vector<std::string> args_;
    Language lang_;
    std::string target_;
};

Runner* createRunner(Language language, std::string sourceFile, std::string testcaseFile);

#endif // YUOMAMO_TESTER_TESTER__H_
