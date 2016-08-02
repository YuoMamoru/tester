#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "tester.h"
#include "compiler_tester.h"

CompilerTester::CompilerTester(const char* sourceFile, const char* testcaseFile)
      : Tester(sourceFile, testcaseFile){
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
CompilerTester::~CompilerTester(){
    delete[] executableFile_;
}
int CompilerTester::compile() const{
    printf("Compiling...\n");
    return system(commandToCompile().c_str());
}
int CompilerTester::cleanup() const{
    return system(commandToCleanup().c_str());
}
std::string CompilerTester::executableFile() const{
    return executableFile_;
}
std::string CompilerTester::commandToCompile() const{
    return compiler() + " -o " + executableFile() + " " + sourceFile();
}
std::string CompilerTester::commandToExecute() const{
    return std::string("./") + executableFile();
}
std::string CompilerTester::commandToCleanup() const{
    return std::string("rm ") + executableFile() + ".o " + executableFile();
}

CTester::CTester(const char* sourceFile, const char* testcaseFile)
      : CompilerTester(sourceFile, testcaseFile){}
std::string CTester::language() const{
    return std::string("C");
}
std::string CTester::compiler() const{
    return std::string("gcc");
}

CPlusPlusTester::CPlusPlusTester(const char* sourceFile,
                                 const char* testcaseFile)
      : CompilerTester(sourceFile, testcaseFile){}
std::string CPlusPlusTester::language() const{
    return std::string("C++");
}
std::string CPlusPlusTester::compiler() const{
    return std::string("g++");
}

PascalTester::PascalTester(const char* sourceFile, const char* testcaseFile)
      : CompilerTester(sourceFile, testcaseFile){}
std::string PascalTester::language() const{
    return std::string("Pascal");
}
std::string PascalTester::compiler() const{
    return std::string("fpc");
}
std::string PascalTester::commandToCompile() const{
    return compiler() + " " + sourceFile();
}
