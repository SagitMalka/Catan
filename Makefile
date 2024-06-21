# Makefile for the Catan project

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Project name
TARGET = Catan

# Source and header files
SRCS = main.cpp \
       Model/Tile.cpp \
       Model/Player.cpp \
       Model/Road.cpp \
       Model/Node.cpp \
       Model/Board.cpp \
       Model/ResourceCard.cpp \
       Model/DevelopmentCard.cpp \
       Model/CardDeck.cpp \
       Model/ResourceCardDeck.cpp \
       Model/DevelopmentCardDeck.cpp \
       Model/Game.cpp

HDRS = Model/Resource.hpp \
       Model/Tile.hpp \
       Model/Player.hpp \
       Model/Road.hpp \
       Model/Node.hpp \
       Model/Board.hpp \
       Model/ResourceCard.hpp \
       Model/DevelopmentCard.hpp \
       Model/Constants.hpp \
       Model/Card.hpp \
       Model/CardDeck.hpp \
       Model/ResourceCardDeck.hpp \
       Model/DevelopmentCardDeck.hpp \
       Model/Game.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
