#include <string>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"
#include "il_runner.h"

IlRunner::IlRunner(std::string sourceFile, std::string testcaseFile)
      : CompilerRunner(sourceFile, testcaseFile){}
std::string IlRunner::commandToExecute() const{
    return virtualMachine() + " " + executableFile();
}
std::string IlRunner::commandToCompile() const{
    return compiler() + " " + sourceFile();
}

JavaRunner::JavaRunner(std::string sourceFile, std::string testcaseFile)
      : IlRunner(sourceFile, testcaseFile){}
Language JavaRunner::language() const{
    return Java;
}
std::string JavaRunner::virtualMachine() const{
    return "java";
}
std::string JavaRunner::executableFile() const{
    return CompilerRunner::executableFile() + ".class";
}
std::string JavaRunner::compiler() const{
    return std::string("javac");
}

CSharpRunner::CSharpRunner(std::string sourceFile, std::string testcaseFile)
      : IlRunner(sourceFile, testcaseFile){}
Language CSharpRunner::language() const{
    return CSharp;
}
std::string CSharpRunner::virtualMachine() const{
    return "mono";
}
std::string CSharpRunner::executableFile() const{
    return CompilerRunner::executableFile() + ".exe";
}
std::string CSharpRunner::compiler() const{
    return std::string("msc");
}
