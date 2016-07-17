#include <string>
#include <iostream>
#include <stdio.h>
#include "language.h"
#include "runner.h"
using namespace std;

Runner::Runner(string source_file, string testcase_file){
    _source_file = source_file;
    _testcase_file = testcase_file;
}
string Runner::source_file() const{
    return _source_file;
}
string Runner::testcase_file() const{
    return _testcase_file;
}
Language Runner::language() const{
    return Unknown;
}
int Runner::compile() const{
    return 0;
}
int Runner::execute() const{
    FILE* fp;
    char buf[1024];
    if((fp = popen(execute_command().c_str(), "r")) != NULL){
        fputs("test0\n", fp);
        fputs("test1\n", fp);
        cout << language() << ": executing...\n";
        while(fgets(buf, sizeof(buf), fp) != NULL){
            cout << buf << endl;
        }
        cout << language() << ": executing...\n";
        return pclose(fp);
    }
    return -1;
}
int Runner::cleanup() const{
    return 0;
}
void Runner::run() const{
    cout << "compiling..." << endl;
    compile();
    cout << "executing..." << endl;
    execute();
}
