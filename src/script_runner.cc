#include <string>
#include "language.h"
#include "runner.h"
#include "script_runner.h"
using namespace std;

ScriptRunner::ScriptRunner(string source_file, string testcase_file)
    : Runner(source_file, testcase_file){}
string ScriptRunner::execute_command() const{
    return script_command() + " " + source_file();
}

RubyRunner::RubyRunner(string source_file, string testcase_file)
    : ScriptRunner(source_file, testcase_file){}
string RubyRunner::script_command() const{
    return "ruby";
}
Language RubyRunner::language() const{
    return Ruby;
}

JavaScriptRunner::JavaScriptRunner(string source_file, string testcase_file)
    : ScriptRunner(source_file, testcase_file){}
string JavaScriptRunner::script_command() const{
    return "node";
}
Language JavaScriptRunner::language() const{
    return JavaScript;
}
