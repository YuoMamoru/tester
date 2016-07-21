#!/usr/bin/make
TARGET = tester
CXX = g++
CXXFLAGS = -O2 -g -Wall
SRCDIR = ./src
SRCS = $(shell ls $(SRCDIR)/*.cc)
HEADERS = $(shell ls $(SRCDIR)/*.h)
OBJS = $(SRCS:.cc=.o)
GCHS = $(HEADERS:.h=.h.gch)

.PHONY: all header clean
.SUFFIXES: .cc .h .o .h.gch

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

all: $(TARGET)

header: $(GCHS)

clean:
	$(RM) $(OBJS) $(GCHS) $(TARGET)

.cc.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $^

.h.h.gch:
	$(CXX) $(CXXFLAGS) -o $@ $^
