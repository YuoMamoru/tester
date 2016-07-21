#include <string>
#include "language.h"

Language removeExtension(std::string fileName, std::string& name){
    for(int i = fileName.length(); i > 0; i--){
        if(fileName[i-1] != '.')
            continue;
        name = std::string(fileName.substr(0, i - 1));
        std::string extension = fileName.substr(i, fileName.length() - i);
        if(extension == "c")
            return C;
        else if(extension == "cc" || extension == "cpp")
            return CPlusPlus;
        else if(extension == "java")
            return Java;
        else if(extension == "rb")
            return Ruby;
        else if(extension == "cs")
            return CSharp;
        else if(extension == "js")
            return JavaScript;
        else
            return Unknown;
    }
    name = std::string(fileName);
    return Unknown;
}
