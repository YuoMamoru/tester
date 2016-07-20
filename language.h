#ifndef LANGUAGE_H_
#define LANGUAGE_H_

using namespace std;

enum Language{
    C, CPlusPlus, Java, Ruby, CSharp, JavaScript, Unknown = 0xFFFF
};
Language remove_extension(string file_name, string& name);

#endif // LANGUAGE_H_
