#include <string>
#include "language.h"
#include "runner.h"
#include "script_runner.h"

ScriptRunner::ScriptRunner(const char* sourceFile, const char* testcaseFile)
      : Runner(sourceFile, testcaseFile){
    setTimeLimit(16);
}
std::string ScriptRunner::commandToExecute() const{
    return interpreter() + " " + sourceFile();
}

RubyRunner::RubyRunner(const char* sourceFile, const char* testcaseFile)
      : ScriptRunner(sourceFile, testcaseFile){}
Language RubyRunner::language() const{
    return Ruby;
}
std::string RubyRunner::interpreter() const{
    return std::string("ruby");
}

JavaScriptRunner::JavaScriptRunner(const char* sourceFile,
                                   const char* testcaseFile)
      : ScriptRunner(sourceFile, testcaseFile){}
Language JavaScriptRunner::language() const{
    return JavaScript;
}
std::string JavaScriptRunner::interpreter() const{
    return std::string("node");
}

PerlRunner::PerlRunner(const char* sourceFile, const char* testcaseFile)
      : ScriptRunner(sourceFile, testcaseFile){}
Language PerlRunner::language() const{
    return Perl;
}
std::string PerlRunner::interpreter() const{
    return std::string("perl");
}