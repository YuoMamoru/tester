#ifndef YUOMAMO_TESTER_RUNNER_H_
#define YUOMAMO_TESTER_RUNNER_H_

#include <string>
#include "language.h"

class Runner{
  public:
    Runner(std::string source_file, std::string testcase_file);
    virtual int compile() const;
    virtual int execute() const;
    virtual int cleanup() const;
    void run() const;
    std::string source_file() const;
    std::string testcase_file() const;
    virtual Language language() const;
  protected:
    virtual std::string execute_command() const = 0;
  private:
    std::string _source_file;
    std::string _testcase_file;
};

#endif // YUOMAMO_TESTER_RUNNER_H_
