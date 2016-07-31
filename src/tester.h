#ifndef YUOMAMO_TESTER_TESTER_H_
#define YUOMAMO_TESTER_TESTER_H_

#include <string>
#include <vector>

class Tester{
  public:
    Tester(const char* sourceFile, const char* testcaseFile);
    virtual ~Tester();
  private:
    Tester();
    Tester(const Tester&);
    void operator=(const Tester&);
  public:
    virtual int compile() const;
    int runTest(const std::string input, const std::string expect, int testNo);
    void runTestcases();
    virtual int cleanup() const;
    void run();
  private:
    void openFileDescriptor();
    int communicateChildProcess(char* outputBuffer,
                                int bufferSize,
                                double* executionSecond,
                                const char* inputBuffer) const;
    size_t readTestcase(
          std::vector<std::pair<const char*, std::string> >& testcase,
          const char* fileName) const;
  public:
    std::string sourceFile() const;
    std::string testcaseFile() const;
    virtual int timeLimit() const;
    void setTimeLimit(int timeLimitSecond);
    virtual std::string language() const = 0;
  protected:
    virtual std::string commandToExecute() const = 0;
  private:
    char* sourceFile_;
    char* testcaseFile_;
    int parentRFD_;
    int parentWFD_;
    int childRFD_;
    int childWFD_;
    int timeLimit_;
};

#endif // YUOMAMO_TESTER_TESTER_H_
