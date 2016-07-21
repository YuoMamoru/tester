#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include "language.h"
#include "runner.h"

Runner::Runner(const char* sourceFile, const char* testcaseFile){
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
    int pid = fork();
    if(pid < 0){
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
    write(pipeToChild[1], "send message\n", 13);
    write(pipeToChild[1], "send mesg\n", 10);
    close(pipeToChild[1]);
    char buff[255];
    read(pipeFromChild[0], buff, 255);
    printf("parent process:\n\n%s", buff);
    return 0;
}
int Runner::cleanup() const{
    return 0;
}
void Runner::run() const{
    std::cout << "compiling..." << std::endl;
    if(compile() != 0){
        std::cerr << "Failed compile." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "executing..." << std::endl;
    execute();
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
