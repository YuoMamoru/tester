#include <string>
#include <stdlib.h>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"
using namespace std;

CompilerRunner::CompilerRunner(string source_file, string testcase_file) : Runner(source_file, testcase_file){
    remove_extension(this->source_file(), _execute_file);
}
string CompilerRunner::execute_file() const{
    return _execute_file;
}
string CompilerRunner::compile_command() const{
    return compiler() + " -o " + execute_file() + " " + source_file();
}
string CompilerRunner::execute_command() const{
    return "./" + execute_file();
}
string CompilerRunner::cleanup_command() const{
    return "rm " + execute_file();
}
int CompilerRunner::compile() const{
    return system(compile_command().c_str());
}
int CompilerRunner::cleanup() const{
    return system(cleanup_command().c_str());
}

CRunner::CRunner(string source_file, string testcase_file)
    : CompilerRunner(source_file, testcase_file){}
string CRunner::compiler() const{
    return string("gcc");
}
Language CRunner::language() const{
    return C;
}

CPlusPlusRunner::CPlusPlusRunner(string source_file, string testcase_file)
    : CompilerRunner(source_file, testcase_file){}
string CPlusPlusRunner::compiler() const{
    return string("g++");
}
Language CPlusPlusRunner::language() const{
    return CPlusPlus;
}
