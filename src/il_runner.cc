#include <string>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"
#include "il_runner.h"

IlRunner::IlRunner(const char* sourceFile, const char* testcaseFile)
      : CompilerRunner(sourceFile, testcaseFile){
    setTimeLimit(5);
}
std::string IlRunner::commandToExecute() const{
    return virtualMachine() + " " + executableFile();
}
std::string IlRunner::commandToCompile() const{
    return compiler() + " " + sourceFile();
}

JavaRunner::JavaRunner(const char* sourceFile, const char* testcaseFile)
      : IlRunner(sourceFile, testcaseFile){}
Language JavaRunner::language() const{
    return Java;
}
std::string JavaRunner::virtualMachine() const{
    return std::string("java");
}
std::string JavaRunner::executableFile() const{
    return CompilerRunner::executableFile() + ".class";
}
std::string JavaRunner::compiler() const{
    return std::string("javac");
}

CSharpRunner::CSharpRunner(const char* sourceFile, const char* testcaseFile)
      : IlRunner(sourceFile, testcaseFile){}
Language CSharpRunner::language() const{
    return CSharp;
}
std::string CSharpRunner::virtualMachine() const{
    return std::string("mono");
}
std::string CSharpRunner::executableFile() const{
    return CompilerRunner::executableFile() + ".exe";
}
std::string CSharpRunner::compiler() const{
    return std::string("msc");
}
