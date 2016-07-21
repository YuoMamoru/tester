#include <string>
#include <stdlib.h>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"

CompilerRunner::CompilerRunner(std::string sourceFile, std::string testcaseFile)
      : Runner(sourceFile, testcaseFile){
    removeExtension(this->sourceFile(), executableFile_);
}
int CompilerRunner::compile() const{
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
    return "./" + executableFile();
}
std::string CompilerRunner::commandToCleanup() const{
    return "rm " + executableFile();
}

CRunner::CRunner(std::string sourceFile, std::string testcaseFile)
      : CompilerRunner(sourceFile, testcaseFile){}
Language CRunner::language() const{
    return C;
}
std::string CRunner::compiler() const{
    return std::string("gcc");
}

CPlusPlusRunner::CPlusPlusRunner(std::string sourceFile, std::string testcaseFile)
      : CompilerRunner(sourceFile, testcaseFile){}
Language CPlusPlusRunner::language() const{
    return CPlusPlus;
}
std::string CPlusPlusRunner::compiler() const{
    return std::string("g++");
}
