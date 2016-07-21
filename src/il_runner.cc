#include <string>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"
#include "il_runner.h"
using namespace std;

IlRunner::IlRunner(string source_file, string testcase_file)
    : CompilerRunner(source_file, testcase_file){}
string IlRunner::compile_command() const{
    return compiler() + " " + source_file();
}
string IlRunner::execute_command() const{
    return vm_command() + " " + execute_file();
}

JavaRunner::JavaRunner(string source_file, string testcase_file)
    : IlRunner(source_file, testcase_file){}
string JavaRunner::vm_command() const{
    return "java";
}
string JavaRunner::execute_file() const{
    return CompilerRunner::execute_file() + ".class";
}
string JavaRunner::compiler() const{
    return string("javac");
}
Language JavaRunner::language() const{
    return Java;
}

CSharpRunner::CSharpRunner(string source_file, string testcase_file)
    : IlRunner(source_file, testcase_file){}
string CSharpRunner::vm_command() const{
    return "mono";
}
string CSharpRunner::execute_file() const{
    return CompilerRunner::execute_file() + ".exe";
}
string CSharpRunner::compiler() const{
    return string("msc");
}
Language CSharpRunner::language() const{
    return CSharp;
}
