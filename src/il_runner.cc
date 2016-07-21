#include <string>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"
#include "il_runner.h"

IlRunner::IlRunner(std::string source_file, std::string testcase_file)
      : CompilerRunner(source_file, testcase_file){}
std::string IlRunner::compile_command() const{
    return compiler() + " " + source_file();
}
std::string IlRunner::execute_command() const{
    return vm_command() + " " + execute_file();
}

JavaRunner::JavaRunner(std::string source_file, std::string testcase_file)
      : IlRunner(source_file, testcase_file){}
std::string JavaRunner::vm_command() const{
    return "java";
}
std::string JavaRunner::execute_file() const{
    return CompilerRunner::execute_file() + ".class";
}
std::string JavaRunner::compiler() const{
    return std::string("javac");
}
Language JavaRunner::language() const{
    return Java;
}

CSharpRunner::CSharpRunner(std::string source_file, std::string testcase_file)
      : IlRunner(source_file, testcase_file){}
std::string CSharpRunner::vm_command() const{
    return "mono";
}
std::string CSharpRunner::execute_file() const{
    return CompilerRunner::execute_file() + ".exe";
}
std::string CSharpRunner::compiler() const{
    return std::string("msc");
}
Language CSharpRunner::language() const{
    return CSharp;
}
