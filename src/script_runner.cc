#include <string>
#include "language.h"
#include "runner.h"
#include "script_runner.h"

ScriptRunner::ScriptRunner(std::string source_file, std::string testcase_file)
      : Runner(source_file, testcase_file){}
std::string ScriptRunner::execute_command() const{
    return script_command() + " " + source_file();
}

RubyRunner::RubyRunner(std::string source_file, std::string testcase_file)
      : ScriptRunner(source_file, testcase_file){}
std::string RubyRunner::script_command() const{
    return "ruby";
}
Language RubyRunner::language() const{
    return Ruby;
}

JavaScriptRunner::JavaScriptRunner(std::string source_file, std::string testcase_file)
      : ScriptRunner(source_file, testcase_file){}
std::string JavaScriptRunner::script_command() const{
    return "node";
}
Language JavaScriptRunner::language() const{
    return JavaScript;
}
