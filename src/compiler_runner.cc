#include <string>
#include <stdlib.h>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"

CompilerRunner::CompilerRunner(std::string source_file, std::string testcase_file)
      : Runner(source_file, testcase_file){
    remove_extension(this->source_file(), _execute_file);
}
std::string CompilerRunner::execute_file() const{
    return _execute_file;
}
std::string CompilerRunner::compile_command() const{
    return compiler() + " -o " + execute_file() + " " + source_file();
}
std::string CompilerRunner::execute_command() const{
    return "./" + execute_file();
}
std::string CompilerRunner::cleanup_command() const{
    return "rm " + execute_file();
}
int CompilerRunner::compile() const{
    return system(compile_command().c_str());
}
int CompilerRunner::cleanup() const{
    return system(cleanup_command().c_str());
}

CRunner::CRunner(std::string source_file, std::string testcase_file)
      : CompilerRunner(source_file, testcase_file){}
std::string CRunner::compiler() const{
    return std::string("gcc");
}
Language CRunner::language() const{
    return C;
}

CPlusPlusRunner::CPlusPlusRunner(std::string source_file, std::string testcase_file)
      : CompilerRunner(source_file, testcase_file){}
std::string CPlusPlusRunner::compiler() const{
    return std::string("g++");
}
Language CPlusPlusRunner::language() const{
    return CPlusPlus;
}
