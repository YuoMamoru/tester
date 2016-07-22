#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include <cstdlib>
#include "language.h"
#include "runner.h"

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
}

Runner::Runner(const char* sourceFile, const char* testcaseFile)
      : timeLimit_(3){
    sourceFile_ = new char[strlen(sourceFile) + 1];
    testcaseFile_ = new char[strlen(testcaseFile) + 1];
    strcpy(sourceFile_, sourceFile);
    strcpy(testcaseFile_, testcaseFile);
}
Runner::~Runner(){
    delete[] sourceFile_;
    delete[] testcaseFile_;
}
int Runner::compile() const{
    return 0;
}
int Runner::execute() const{
    printf("Executing...\n");
    int pipeToChild[2];
    int pipeFromChild[2];
    if(pipe(pipeToChild) < 0){
        perror("popen");
        exit(EXIT_FAILURE);
    }
    if(pipe(pipeFromChild) < 0){
        perror("popen");
        close(pipeToChild[0]);
        close(pipeToChild[1]);
        exit(EXIT_FAILURE);
    }
    if((pid = fork()) < 0){
        perror("fork");
        close(pipeToChild[0]);
        close(pipeToChild[1]);
        close(pipeFromChild[0]);
        close(pipeFromChild[1]);
        exit(EXIT_FAILURE);
    }
    if(pid == 0){
        close(pipeToChild[1]);
        close(pipeFromChild[0]);
        dup2(pipeToChild[0], fileno(stdin));
        dup2(pipeFromChild[1], fileno(stdout));
        close(pipeToChild[0]);
        close(pipeFromChild[1]);
        if(execlp("sh", "sh", "-c", commandToExecute().c_str(), NULL) < 0){
            perror("execute");
            exit(EXIT_FAILURE);
        }
    }
    else{
        signal(SIGALRM, stopChildProcess);
        alarm(timeLimit());
        write(pipeToChild[1], "message\n12\n", 12);
        close(pipeToChild[1]);
        int status;
        if(waitpid(pid, &status, WUNTRACED) < 0){
            alarm(0);
            perror("waitpid");
            close(pipeFromChild[0]);
            exit(EXIT_FAILURE);
        }
        alarm(0);
        if(WIFEXITED(status)){
            char buff[255];
            read(pipeFromChild[0], buff, 255);
            return WEXITSTATUS(status);
        }
        else{
            return status;
        }
    }
    return 0;
}
int Runner::cleanup() const{
    return 0;
}
void Runner::run() const{
    if(compile() != 0){
        fprintf(stderr, "Failed compile.\n");
        exit(EXIT_FAILURE);
    }
    execute();
    cleanup();
}
std::string Runner::sourceFile() const{
    return std::string(sourceFile_);
}
std::string Runner::testcaseFile() const{
    return std::string(testcaseFile_);
}
Language Runner::language() const{
    return Unknown;
}
int Runner::timeLimit() const{
    return timeLimit_;
}
void Runner::setTimeLimit(int timeLimitSecond){
    timeLimit_ = timeLimitSecond;
}
