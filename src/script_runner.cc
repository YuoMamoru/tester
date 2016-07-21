#include <string>
#include "language.h"
#include "runner.h"
#include "script_runner.h"

ScriptRunner::ScriptRunner(std::string sourceFile, std::string testcaseFile)
      : Runner(sourceFile, testcaseFile){}
std::string ScriptRunner::commandToExecute() const{
    return interpreter() + " " + sourceFile();
}

RubyRunner::RubyRunner(std::string sourceFile, std::string testcaseFile)
      : ScriptRunner(sourceFile, testcaseFile){}
Language RubyRunner::language() const{
    return Ruby;
}
std::string RubyRunner::interpreter() const{
    return "ruby";
}

JavaScriptRunner::JavaScriptRunner(std::string sourceFile, std::string testcaseFile)
      : ScriptRunner(sourceFile, testcaseFile){}
Language JavaScriptRunner::language() const{
    return JavaScript;
}
std::string JavaScriptRunner::interpreter() const{
    return "node";
}
