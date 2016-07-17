#include <string>
#include "language.h"
using namespace std;

Language remove_extension(string file_name, string& name){
    for(int i = file_name.length(); i > 0; i--){
        if(file_name[i-1] != '.')
            continue;
        name = string(file_name.substr(0, i - 1));
        string extension = file_name.substr(i, file_name.length() - i);
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
    name = string(file_name);
    return Unknown;
}
