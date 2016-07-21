#include <string>
#include <vector>
#include <iostream>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"
#include "il_runner.h"
#include "script_runner.h"
#include "tester.h"

Tester::Tester(int argc, char** argv){
    for(int i = 0; i < argc; i++)
        args_.push_back(std::string(argv[i]));
    lang_ = removeExtension(args_[1], target_);
}
Tester::~Tester(){}
std::string Tester::testerFile() const{
    return args_[0];
}
std::string Tester::sourceFile() const{
    return args_[1];
}
std::string Tester::testcaseFile() const{
    return target_ + ".txt";
}
Language Tester::language() const{
    return lang_;
}

Runner* createRunner(Language language, std::string sourceFile, std::string testcaseFile){
    switch(language){
    case C:
        return new CRunner(sourceFile.c_str(), testcaseFile.c_str());
    case CPlusPlus:
        return new CPlusPlusRunner(sourceFile.c_str(), testcaseFile.c_str());
    case Java:
        return new JavaRunner(sourceFile.c_str(), testcaseFile.c_str());
    case Ruby:
        return new RubyRunner(sourceFile.c_str(), testcaseFile.c_str());
    case CSharp:
        return new CSharpRunner(sourceFile.c_str(), testcaseFile.c_str());
    default:
        return NULL;
    }
}

int main(int argc, char** argv){
    if(argc < 2){
        std::cout << "no target.\n";
        return 0;
    }
    Tester args(argc, argv);
    Runner* runner = createRunner(args.language(), args.sourceFile(), args.testcaseFile());
//    std::cout << runner->test() << std::endl << args.testcaseFile() << std::endl;
    runner->run();
}
