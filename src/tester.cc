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
        _args.push_back(std::string(argv[i]));
    _lang = remove_extension(_args[1], _target);
}
std::string Tester::tester_file() const{
    return _args[0];
}
std::string Tester::source_file() const{
    return _args[1];
}
Language Tester::language() const{
    return _lang;
}
std::string Tester::testcase_file() const{
    return _target + ".txt";
}

Runner* create_runner(Language language, std::string source_file, std::string testcase_file){
    switch(language){
    case C:
        return new CRunner(source_file, testcase_file);
    case CPlusPlus:
        return new CPlusPlusRunner(source_file, testcase_file);
    case Java:
        return new JavaRunner(source_file, testcase_file);
    case Ruby:
        return new RubyRunner(source_file, testcase_file);
    case CSharp:
        return new CSharpRunner(source_file, testcase_file);
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
    Runner* runner = create_runner(args.language(), args.source_file(), args.testcase_file());
//    std::cout << runner->test() << std::endl << args.testcase_file() << std::endl;
    runner->run();
}
