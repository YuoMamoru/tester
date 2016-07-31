#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"

CompilerRunner::CompilerRunner(const char* sourceFile, const char* testcaseFile)
      : Runner(sourceFile, testcaseFile){
    const char* ext = strrchr(sourceFile, '.');
    if(ext == NULL){
        executableFile_ = new char[strlen(sourceFile) + 1];
        strcpy(executableFile_, sourceFile);
    }
    else{
        executableFile_ = new char[(ext - sourceFile) + 1];
        strncpy(executableFile_, sourceFile, (ext - sourceFile));
        executableFile_[ext - sourceFile] = '\0';
    }
}
CompilerRunner::~CompilerRunner(){
    delete[] executableFile_;
}
int CompilerRunner::compile() const{
    printf("Compiling...\n");
    return system(commandToCompile().c_str());
}
int CompilerRunner::cleanup() const{
    return system(commandToCleanup().c_str());
}
std::string CompilerRunner::executableFile() const{
    return executableFile_;
}
std::string CompilerRunner::commandToCompile() const{
    return compiler() + " -o " + executableFile() + " " + sourceFile();
}
std::string CompilerRunner::commandToExecute() const{
    return std::string("./") + executableFile();
}
std::string CompilerRunner::commandToCleanup() const{
    return std::string("rm ") + executableFile();
}

CRunner::CRunner(const char* sourceFile, const char* testcaseFile)
      : CompilerRunner(sourceFile, testcaseFile){}
Language CRunner::language() const{
    return C;
}
std::string CRunner::compiler() const{
    return std::string("gcc");
}

CPlusPlusRunner::CPlusPlusRunner(const char* sourceFile,
                                 const char* testcaseFile)
      : CompilerRunner(sourceFile, testcaseFile){}
Language CPlusPlusRunner::language() const{
    return CPlusPlus;
}
std::string CPlusPlusRunner::compiler() const{
    return std::string("g++");
}
