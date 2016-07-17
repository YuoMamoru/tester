#include <string>
#include <vector>
#include <iostream>
#include "language.h"
#include "runner.h"
#include "compiler_runner.h"
#include "il_runner.h"
#include "script_runner.h"
#include "tester.h"
using namespace std;

ArgParser::ArgParser(int argc, char** argv){
    for(int i = 0; i < argc; i++)
        _args.push_back(string(argv[i]));
    _lang = remove_extension(_args[1], _target);
}
string ArgParser::tester_file() const{
    return _args[0];
}
string ArgParser::source_file() const{
    return _args[1];
}
Language ArgParser::language() const{
    return _lang;
}
string ArgParser::testcase_file() const{
    return _target + ".txt";
}

Runner* create_runner(Language language, string source_file, string testcase_file){
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
        cout << "no target.\n";
        return 0;
    }
    ArgParser args(argc, argv);
    Runner* runner = create_runner(args.language(), args.source_file(), args.testcase_file());
//    cout << runner->test() << endl << args.testcase_file() << endl;
    runner->run();
}
