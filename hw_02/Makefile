CXX = g++
CXXFLAGS = -O2 -Wall -Werror -std=c++03 -Iinclude -lncurses
LDFLAGS = -lncurses

EXE = main
TEST = board_test
SRCDIR = src
BINDIR = bin
TESTDIR = test

OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(wildcard $(SRCDIR)/*.cpp))
OBJECTS1 = $(patsubst $(TESTDIR)/%.cpp,$(BINDIR)/%.o,$(wildcard $(TESTDIR)/*.cpp))
all: $(EXE)

$(EXE): $(BINDIR) $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXE) $(LDFLAGS)
	
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

include $(wildcard $(BINDIR)/*.d)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR) $(EXE)

$(TEST): $(BINDIR) $(OBJECTS1) $(BINDIR)/Board.o
	$(CXX) $(OBJECTS1) bin/Board.o -o $(TEST) $(LDFLAGS)
	
$(BINDIR)/%.o: $(TESTDIR)/%.cpp $(SRCDIR)/Board.cpp
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

$(BINDIR)/Board.o:  $(SRCDIR)/Board.cpp
	$(CXX) $(CXXFLAGS) -c -MMD -o $(BINDIR)/Board.o $(SRCDIR)/Board.cpp

.PHONY: clean all