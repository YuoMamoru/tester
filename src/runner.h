#ifndef YUOMAMO_TESTER_RUNNER_H_
#define YUOMAMO_TESTER_RUNNER_H_

#include <string>
#include "language.h"

class Runner{
  public:
    Runner(std::string sourceFile, std::string testcaseFile);
    virtual int compile() const;
    virtual int execute() const;
    virtual int cleanup() const;
    void run() const;
    std::string sourceFile() const;
    std::string testcaseFile() const;
    virtual Language language() const;
  protected:
    virtual std::string commandToExecute() const = 0;
  private:
    std::string sourceFile_;
    std::string testcaseFile_;
};

#endif // YUOMAMO_TESTER_RUNNER_H_
