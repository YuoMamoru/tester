#include <string>
#include "script_tester.h"

ScriptTester::ScriptTester(const char* sourceFile, const char* testcaseFile)
      : Tester(sourceFile, testcaseFile){
    setTimeLimit(16);
}
std::string ScriptTester::commandToExecute() const{
    return interpreter() + " " + sourceFile();
}

RubyTester::RubyTester(const char* sourceFile, const char* testcaseFile)
      : ScriptTester(sourceFile, testcaseFile){}
std::string RubyTester::language() const{
    return std::string("Ruby");
}
std::string RubyTester::interpreter() const{
    return std::string("ruby");
}

JavaScriptTester::JavaScriptTester(const char* sourceFile,
                                   const char* testcaseFile)
      : ScriptTester(sourceFile, testcaseFile){}
std::string JavaScriptTester::language() const{
    return std::string("JavaScript");
}
std::string JavaScriptTester::interpreter() const{
    return std::string("node");
}

PerlTester::PerlTester(const char* sourceFile, const char* testcaseFile)
      : ScriptTester(sourceFile, testcaseFile){}
std::string PerlTester::language() const{
    return std::string("Perl");
}
std::string PerlTester::interpreter() const{
    return std::string("perl");
}
