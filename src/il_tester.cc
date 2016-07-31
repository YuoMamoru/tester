#include <string>
#include "compiler_tester.h"
#include "il_tester.h"

IlTester::IlTester(const char* sourceFile, const char* testcaseFile)
      : CompilerTester(sourceFile, testcaseFile){
    setTimeLimit(5);
}
std::string IlTester::commandToExecute() const{
    return virtualMachine() + " " + executableFile();
}
std::string IlTester::commandToCompile() const{
    return compiler() + " " + sourceFile();
}

JavaTester::JavaTester(const char* sourceFile, const char* testcaseFile)
      : IlTester(sourceFile, testcaseFile){}
std::string JavaTester::commandToCleanup() const{
    return std::string("rm ") + executableFile() + ".class";
}
std::string JavaTester::language() const{
    return std::string("Java");
}
std::string JavaTester::virtualMachine() const{
    return std::string("java");
}
std::string JavaTester::compiler() const{
    return std::string("javac");
}

CSharpTester::CSharpTester(const char* sourceFile, const char* testcaseFile)
      : IlTester(sourceFile, testcaseFile){}
std::string CSharpTester::language() const{
    return std::string("C#");
}
std::string CSharpTester::virtualMachine() const{
    return std::string("mono");
}
std::string CSharpTester::executableFile() const{
    return CompilerTester::executableFile() + ".exe";
}
std::string CSharpTester::compiler() const{
    return std::string("mcs");
}
