#include <iostream>
#include "runner.h"
#include "tester.h"

int main(int argc, char** argv){
    if(argc < 2){
        std::cout << "no target.\n";
        return 0;
    }
    Tester tester(argc, argv);
    Runner* runner = tester.runner();
//    std::cout << runner->test() << std::endl << args.testcaseFile() << std::endl;
    runner->run();
}
