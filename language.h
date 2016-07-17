using namespace std;

enum Language{
    C, CPlusPlus, Java, Ruby, CSharp, JavaScript, Unknown = 0xFFFF
};
Language remove_extension(string file_name, string& name);
