#include <string>
#include <vector>
#include <iostream>
#include "runner.h"
#include "compiler_runner.h"
#include "il_runner.h"
#include "script_runner.h"
#include "tester.h"

Tester::Tester(int argc, char** argv){
    for(int i = 0; i < argc; i++)
        args_.push_back(std::string(argv[i]));
    std::string fileName(args_[1]);
    for(int i = fileName.length(); i > 0; i--){
        if(fileName[i-1] != '.')
            continue;
        target_ = std::string(fileName.substr(0, i - 1));
        std::string extension = fileName.substr(i, fileName.length() - i);
        const char* source = args_[1].c_str();
        const char* testcase = testcaseFile().c_str();
        if(extension == "c")
            runner_ = new CRunner(source, testcase);
        else if(extension == "cc" || extension == "cpp")
            runner_ = new CPlusPlusRunner(source, testcase);
        else if(extension == "java")
            runner_ = new JavaRunner(source, testcase);
        else if(extension == "rb")
            runner_ = new RubyRunner(source, testcase);
        else if(extension == "cs")
            runner_ = new CSharpRunner(source, testcase);
        else if(extension == "js")
            runner_ = new JavaScriptRunner(source, testcase);
        else
            runner_ = NULL;
    }
}
Tester::~Tester(){
    if(runner_ != NULL)
        delete runner_;
}
std::string Tester::testerFile() const{
    return args_[0];
}
std::string Tester::sourceFile() const{
    return args_[1];
}
std::string Tester::testcaseFile() const{
    return target_ + ".txt";
}
Runner* Tester::runner() const{
    return runner_;
}
