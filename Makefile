# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = graph_algorithms

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

# Default rule
all: $(TARGET)
	@echo "Build successful!"

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Linking complete!"

# Rule to compile source files to object files
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/graph.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCDIR)
	@echo "Compiled $<"

# Rule to clean the directory
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Cleaned up!"

# Phony targets
.PHONY: all clean