#ifndef YUOMAMO_TESTER_RUNNER_H_
#define YUOMAMO_TESTER_RUNNER_H_

#include <string>
#include "language.h"

class Runner{
  public:
    Runner(const char* sourceFile, const char* testcaseFile);
    virtual ~Runner();
  private:
    Runner();
    Runner(const Runner&);
    void operator=(const Runner&);
  public:
    virtual int compile() const;
    virtual int execute() const;
    virtual int cleanup() const;
    void run() const;
    std::string sourceFile() const;
    std::string testcaseFile() const;
    virtual int timeLimit() const;
    void setTimeLimit(int timeLimitSecond);
    virtual Language language() const;
  protected:
    virtual std::string commandToExecute() const = 0;
  private:
    char* sourceFile_;
    char* testcaseFile_;
    int timeLimit_;
};

#endif // YUOMAMO_TESTER_RUNNER_H_
