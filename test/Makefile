#!/usr/bin/make
TARGET = test
CXX = g++
CXXFLAGS = -O2 -g -Wall
SRCDIR = ../src
OBJDIR = ../obj
TESTSRCDIR = ./src
TESTOBJDIR = ./obj
GTESTDIR = ../googletest
SRCS = $(filter-out $(SRCDIR)/main.cc, $(shell ls $(SRCDIR)/*.cc))
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cc=.o)))
TESTFILES = $(shell ls $(TESTSRCDIR)/*.cc)
TESTOBJS = $(addprefix $(TESTOBJDIR)/, $(notdir $(TESTFILES:.cc=.o)))
GTESTLIBS = $(shell ls $(GTESTDIR)/*.a)

.PHONY: all header clean
.SUFFIXES: .cc .h .o .h.gch

all: $(TARGET)

clean:
	rm -rf $(OBJDIR) $(TESTOBJDIR) $(TARGET)

$(TARGET): $(OBJS) $(TESTOBJS) $(GTESTLIBS)
	$(CXX) -o $(TARGET) -pthread $(OBJS) $(TESTOBJS) $(GTESTLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@if [ ! -d $(OBJDIR) ]; then \
		echo "mkdir $(OBJDIR)";mkdir -p $(OBJDIR); \
	fi
	$(CXX) $(CXXFLAGS) -o $@ -c $^

$(TESTOBJDIR)/%.o: $(TESTSRCDIR)/%.cc
	@if [ ! -d $(TESTOBJDIR) ]; then \
		echo "mkdir $(TESTOBJDIR)";mkdir -p $(TESTOBJDIR); \
	fi
	$(CXX) $(CXXFLAGS) -I$(GTESTDIR)/include -I$(SRCDIR) -o $@ -c $^
