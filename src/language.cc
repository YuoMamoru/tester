#include <string>
#include "language.h"

Language remove_extension(std::string file_name, std::string& name){
    for(int i = file_name.length(); i > 0; i--){
        if(file_name[i-1] != '.')
            continue;
        name = std::string(file_name.substr(0, i - 1));
        std::string extension = file_name.substr(i, file_name.length() - i);
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
    name = std::string(file_name);
    return Unknown;
}
