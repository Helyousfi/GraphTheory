# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = graph_algorithms

# Directories
SRCDIR = src
INCDIR = include

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(SRCDIR)/%.o)

# Default rule
all: $(TARGET)

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files to object files
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/graph.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCDIR)

# Rule to clean the directory
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
