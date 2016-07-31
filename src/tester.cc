#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <cstdlib>
#include <string>
#include <vector>
#include "tester.h"

namespace{
int pid;
void stopChildProcess(int sig){
    if(pid <= 0){
        return;
    }
    if(kill(pid, SIGINT) < 0){
        perror("kill");
        exit(EXIT_FAILURE);
    }
    printf("Timeout.\n");
    exit(EXIT_SUCCESS);
}

class TimeInterval{
  public:
    TimeInterval(){}
    void start(){
        gettimeofday(&startTime, NULL);
    }
    void stop(){
        gettimeofday(&endTime, NULL);
    }
    double intervalSecond(){
        return (endTime.tv_sec - startTime.tv_sec) +
               (endTime.tv_usec - startTime.tv_usec) * 1e-6;
    }
  private:
    timeval startTime;
    timeval endTime;
};
}

Tester::Tester(const char* sourceFile, const char* testcaseFile)
      : parentRFD_(-1),
        parentWFD_(-1),
        childRFD_(-1),
        childWFD_(-1),
        timeLimit_(3){
    sourceFile_ = new char[strlen(sourceFile) + 1];
    testcaseFile_ = new char[strlen(testcaseFile) + 1];
    strcpy(sourceFile_, sourceFile);
    strcpy(testcaseFile_, testcaseFile);
}
Tester::~Tester(){
    delete[] sourceFile_;
    delete[] testcaseFile_;
}
int Tester::compile() const{
    return 0;
}
int Tester::runTest(const std::string input,
                    const std::string expect,
                    int testNo){
    printf("[Testcase(%d)] ", testNo);
    openFileDescriptor();
    if((pid = fork()) < 0){
        perror("fork");
        close(parentRFD_);
        close(parentWFD_);
        close(childRFD_);
        close(childWFD_);
        exit(EXIT_FAILURE);
    }
    if(pid == 0){
        close(parentRFD_);
        close(parentWFD_);
        dup2(childRFD_, fileno(stdin));
        dup2(childWFD_, fileno(stdout));
        close(childRFD_);
        close(childWFD_);
        if(execlp("sh", "sh", "-c", commandToExecute().c_str(), NULL) < 0){
            perror("execute");
            exit(EXIT_FAILURE);
        }
    }
    int bufferSize = 1024;
    char* outputBuffer = new char[bufferSize];
    double executionSecond = 99.99;
    int ret = communicateChildProcess(outputBuffer,
                                      bufferSize,
                                      &executionSecond,
                                      input.c_str());
    if(strcmp(expect.c_str(), outputBuffer)){
        std::string formattedExpect(expect);
        std::string::size_type pos = formattedExpect.length() - 1;
        while((pos = formattedExpect.rfind("\n", --pos)) != std::string::npos){
            formattedExpect.insert(pos + 1, "                        ");
        }
        std::string formattedOutput(outputBuffer);
        pos = formattedOutput.length() - 1;
        while((pos = formattedOutput.rfind("\n", --pos)) != std::string::npos){
            formattedOutput.insert(pos + 1, "                        ");
        }
        printf("\x1b[31mWrong Answer (%2.3fms):\n", executionSecond);
        printf("                expect: %s", formattedExpect.c_str());
        printf("                output: %s\x1b[39m", formattedOutput.c_str());
    }
    else{
        printf("\x1b[32mPass this test case. (%2.3fms)\x1b[39m\n", executionSecond);
    }
    return ret;
}
void Tester::runTestcases(){
    std::vector<std::pair<const char*, std::string> > testcases;
    int testcaseCount = readTestcase(testcases, testcaseFile().c_str());
    for(int i = 0; i < testcaseCount; i++){
        runTest(testcases[i].first, testcases[i].second, i + 1);
    }
}
int Tester::cleanup() const{
    return 0;
}
void Tester::run(){
    if(compile() != 0){
        fprintf(stderr, "Failed compile.\n");
        exit(EXIT_FAILURE);
    }
    runTestcases();
    cleanup();
}
void Tester::openFileDescriptor(){
    int pipeParentToChild[2];
    int pipeChildToParent[2];
    if(pipe(pipeParentToChild) < 0){
        perror("popen");
        exit(EXIT_FAILURE);
    }
    if(pipe(pipeChildToParent) < 0){
        perror("popen");
        close(pipeParentToChild[0]);
        close(pipeParentToChild[1]);
        exit(EXIT_FAILURE);
    }
    parentRFD_ = pipeChildToParent[0];
    parentWFD_ = pipeParentToChild[1];
    childRFD_ = pipeParentToChild[0];
    childWFD_ = pipeChildToParent[1];
}
int Tester::communicateChildProcess(char* outputBuffer,
                                    int bufferSize,
                                    double* executionSecond,
                                    const char* inputBuffer) const{
    signal(SIGALRM, stopChildProcess);
    alarm(timeLimit());
    TimeInterval timer;
    timer.start();
    close(childRFD_);
    close(childWFD_);
    write(parentWFD_, inputBuffer, strlen(inputBuffer));
    close(parentWFD_);
    int status;
    if(waitpid(pid, &status, WUNTRACED) < 0){
        alarm(0);
        perror("waitpid");
        close(parentRFD_);
        exit(EXIT_FAILURE);
    }
    alarm(0);
    timer.stop();
    *executionSecond = timer.intervalSecond();
    if(WIFEXITED(status)){
        read(parentRFD_, outputBuffer, bufferSize);
        close(parentRFD_);
        return WEXITSTATUS(status);
    }
    else{
        close(parentRFD_);
        return status;
    }
}
size_t Tester::readTestcase(
      std::vector<std::pair<const char*, std::string> >& testcases,
      const char* fileName) const{
    // TODO
    testcases.push_back(
        std::pair<const char*, std::string>(
            "massage\n12\n", std::string("7\n36\n")));
    testcases.push_back(
        std::pair<const char*, std::string>(
            "This is a pen.\n7\n", std::string("14\n21\n")));
    testcases.push_back(
        std::pair<const char*, std::string>(
            "one_line.\n-7\n", std::string("9\n-21\n")));
    return testcases.size();
}
std::string Tester::sourceFile() const{
    return std::string(sourceFile_);
}
std::string Tester::testcaseFile() const{
    return std::string(testcaseFile_);
}
int Tester::timeLimit() const{
    return timeLimit_;
}
void Tester::setTimeLimit(int timeLimitSecond){
    timeLimit_ = timeLimitSecond;
}
