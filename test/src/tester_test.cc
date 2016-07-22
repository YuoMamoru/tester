#include <string>
#include <gtest/gtest.h>
#include "language.h"
#include "tester.h"

TEST(TesterTest, CFile){
    char* argv[2] = {(char *)"tester", (char*)"source_file.c"};
    Tester tester(2, argv);
    EXPECT_EQ(std::string("source_file.c"), tester.sourceFile());
    EXPECT_EQ(std::string("source_file.txt"), tester.testcaseFile());
    EXPECT_EQ(C, tester.runner()->language());
}

TEST(TesterTest, RubyFile){
    char* argv[2] = {(char*)"tester", (char*)"source_file.rb"};
    Tester tester(2, argv);
    EXPECT_EQ(std::string("source_file.rb"), tester.sourceFile());
    EXPECT_EQ(std::string("source_file.txt"), tester.testcaseFile());
    EXPECT_EQ(Ruby, tester.runner()->language());
}
