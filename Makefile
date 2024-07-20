# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = graph_algorithms

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Source files, explicitly excluding SSSP_DAG.cpp and TopologicalSort.cpp
SRCS = $(filter-out \
	$(SRCDIR)/easyAlgorithms.cpp \
    $(SRCDIR)/SSSP_DAG.cpp \
    $(SRCDIR)/dungeonProblem.cpp \
    $(SRCDIR)/TopologicalSort.cpp, \
    $(wildcard $(SRCDIR)/*.cpp))

# Object files based on the updated list of source files
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

# Default rule
all: $(TARGET)
	@echo "Build successful!"

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Linking complete!"

# Rule to compile source files to object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCDIR)
	@echo "Compiled $<"

# Rule to clean the directory
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Cleaned up!"

# Phony targets
.PHONY: all clean
