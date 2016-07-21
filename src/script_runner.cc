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
Language RubyRunner::language() const{
    return Ruby;
}
std::string RubyRunner::script_command() const{
    return "ruby";
}

JavaScriptRunner::JavaScriptRunner(std::string source_file, std::string testcase_file)
      : ScriptRunner(source_file, testcase_file){}
Language JavaScriptRunner::language() const{
    return JavaScript;
}
std::string JavaScriptRunner::script_command() const{
    return "node";
}
