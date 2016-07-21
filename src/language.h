#ifndef YUOMAMO_TESTER_LANGUAGE_H_
#define YUOMAMO_TESTER_LANGUAGE_H_

#include <string>

enum Language{
    C, CPlusPlus, Java, Ruby, CSharp, JavaScript, Unknown = 0xFFFF
};
Language remove_extension(std::string file_name, std::string& name);

#endif // YUOMAMO_TESTER_LANGUAGE_H_
