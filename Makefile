#!/usr/bin/make
TARGET = tester
CXX = g++
CXXFLAGS = -O2 -g -Wall
SRCDIR = ./src
OBJDIR = ./obj
SRCS = $(shell ls $(SRCDIR)/*.cc)
HEADERS = $(shell ls $(SRCDIR)/*.h)
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cc=.o)))
GCHS = $(addprefix $(OBJDIR)/, $(notdir $(HEADERS:.h=.h.gch)))

.PHONY: all header clean
.SUFFIXES: .cc .h .o .h.gch

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

all: $(TARGET)

header: $(GCHS)

clean:
	rm -rf $(OBJDIR) $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@if [ ! -d $(OBJDIR) ]; then \
		echo "mkdir $(OBJDIR)";mkdir -p $(OBJDIR); \
	fi
	$(CXX) $(CXXFLAGS) -o $@ -c $^

$(OBJDIR)/%.h.gch: $(SRCDIR)/%.h
	@if [ ! -d $(OBJDIR) ]; then \
		echo "mkdir $(OBJDIR)";mkdir -p $(OBJDIR); \
	fi
	$(CXX) $(CXXFLAGS) -o $@ $^
