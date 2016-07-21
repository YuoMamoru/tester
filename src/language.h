#ifndef YUOMAMO_TESTER_LANGUAGE_H_
#define YUOMAMO_TESTER_LANGUAGE_H_

#include <string>

enum Language{
    C, CPlusPlus, Java, Ruby, CSharp, JavaScript, Unknown = 0xFFFF
};
Language removeExtension(std::string fileName, std::string& name);

#endif // YUOMAMO_TESTER_LANGUAGE_H_
