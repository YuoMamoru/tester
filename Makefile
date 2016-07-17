#!/usr/bin/make
TARGET = tester
CXX = g++
CXXFLAGS = -O2 -g -Wall
LDFLAGS = -lm
SRCS = $(shell ls *.cc)
OBJS = $(SRCS:.cc=.o)

.PHONY: all clean
.SUFFIXES: .cc .o

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

all: $(TARGET)

clean:
	$(RM) $(OBJS) $(TARGET)

.cc.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $^
