#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include "language.h"
#include "runner.h"

Runner::Runner(std::string source_file, std::string testcase_file){
    _source_file = source_file;
    _testcase_file = testcase_file;
}
std::string Runner::source_file() const{
    return _source_file;
}
std::string Runner::testcase_file() const{
    return _testcase_file;
}
Language Runner::language() const{
    return Unknown;
}
int Runner::compile() const{
    return 0;
}
int Runner::execute() const{
    int pipe_to_child[2];
    int pipe_from_child[2];
    if(pipe(pipe_to_child) < 0){
        perror("popen");
        exit(EXIT_FAILURE);
    }
    if(pipe(pipe_from_child) < 0){
        perror("popen");
        close(pipe_to_child[0]);
        close(pipe_to_child[1]);
        exit(EXIT_FAILURE);
    }
    int pid = fork();
    if(pid < 0){
        perror("fork");
        close(pipe_to_child[0]);
        close(pipe_to_child[1]);
        close(pipe_from_child[0]);
        close(pipe_from_child[1]);
        exit(EXIT_FAILURE);
    }
    if(pid == 0){
        close(pipe_to_child[1]);
        close(pipe_from_child[0]);
        dup2(pipe_to_child[0], fileno(stdin));
        dup2(pipe_from_child[1], fileno(stdout));
        close(pipe_to_child[0]);
        close(pipe_from_child[1]);
        if(execlp("sh", "sh", "-c", execute_command().c_str(), NULL) < 0){
            perror("execute");
            exit(EXIT_FAILURE);
        }
    }
    write(pipe_to_child[1], "send message\n", 13);
    write(pipe_to_child[1], "send mesg\n", 10);
    close(pipe_to_child[1]);
    char buff[255];
    read(pipe_from_child[0], buff, 255);
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
