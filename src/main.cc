#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "runner.h"
#include "compiler_runner.h"
#include "il_runner.h"
#include "script_runner.h"

namespace{

enum Language{
    C, CPlusPlus, Java, Ruby, CSharp, JavaScript, Perl, Unknown = -1
};

void printHelp(){
    printf("Tester - Test Tool (compiled %s %s)\n", __DATE__, __TIME__);
    printf("\n");
    printf("Usaage: tester [options] [programfile]\n");
    printf("  -l <language>     specify the programming language. support following\n");
    printf("                    languages: C, C++, Java, JavaScript (or js), C#, Ruby, Perl\n");
    printf("  -t <filename>     specify file name that describes the test-cases\n");
    printf("  -h                show this message\n");
}

char* toLower(char* str){
    for(char* p = str; *p; p++)
        *p = tolower(*p);
    return str;
}

Language determineLanguage(const char* language, const char* sourceFileName){
    if(language == NULL){
        const char* extension = strrchr(sourceFileName, '.');
        if(extension == NULL)
            return Unknown;
        extension++;
        if(strcasecmp(extension, "c") == 0)
            return C;
        if(strcasecmp(extension, "cc") == 0 ||
              strcasecmp(extension, "cpp") == 0)
            return CPlusPlus;
        if(strcasecmp(extension, "java") == 0)
            return Java;
        if(strcasecmp(extension, "rb") == 0)
            return Ruby;
        if(strcasecmp(extension, "cs") == 0)
            return CSharp;
        if(strcasecmp(extension, "js") == 0)
            return JavaScript;
        if(strcasecmp(extension, "pl") == 0)
            return Perl;
        return Unknown;
    }
    if(strcasecmp(language, "c") == 0)
        return C;
    if(strcasecmp(language, "c++") == 0)
        return CPlusPlus;
    if(strcasecmp(language, "java") == 0)
        return Java;
    if(strcasecmp(language, "ruby") == 0)
        return Ruby;
    if(strcasecmp(language, "c#") == 0)
        return CSharp;
    if(strcasecmp(language, "javascript") == 0 ||
          strcasecmp(language, "js") == 0)
        return JavaScript;
    if(strcmp(language, "perl") == 0)
        return Perl;
    return Unknown;
}

Runner* createRunner(const char* sourceFileName,
                     const char* language,
                     const char* testcaseFileName){
    char* fileName = NULL;
    if(testcaseFileName == NULL){
        fileName = new char[strlen(sourceFileName) + 5];
        strcpy(fileName, sourceFileName);
        char* dotPos = strrchr(fileName, '.');
        if(dotPos == NULL){
            dotPos = fileName + strlen(sourceFileName);
        }
        strcpy(dotPos, ".txt");
    }
    const char* test = testcaseFileName == NULL ? fileName : testcaseFileName;
    switch(determineLanguage(language, sourceFileName)){
      case C:
        return new CRunner(sourceFileName, test);
      case CPlusPlus:
        return new CPlusPlusRunner(sourceFileName, test);
      case Java:
        return new JavaRunner(sourceFileName, test);
      case Ruby:
        return new RubyRunner(sourceFileName, test);
      case CSharp:
        return new CSharpRunner(sourceFileName, test);
      case JavaScript:
        return new JavaScriptRunner(sourceFileName, test);
      case Perl:
        return new PerlRunner(sourceFileName, test);
      default:
        fprintf(stderr, "Cannet determine a programming language\n");
        return NULL;
    }
}

}

int main(int argc, char** argv){
    if(argc < 2){
        printHelp();
        return 0;
    }
    char* language = NULL;
    char* testcaseFileName = NULL;
    int opt;
    while((opt = getopt(argc, argv, "l:t:e::h")) != -1){
        switch(opt){
          case 'l':
            language = optarg;
            toLower(language);
            break;
          case 't':
            testcaseFileName = optarg;
            break;
          case 'h':
            printHelp();
            return 0;
          default:
            return 1;
        }
    }
    if(optind >= argc){
        fprintf(stderr, "No target file.\n");
        return 1;
    }
    char* sourceFileName = argv[optind];
    Runner* runner = createRunner(sourceFileName, language, testcaseFileName);
    if(runner == NULL)
        return 1;
    runner->run();
    delete runner;
    return 0;
}
