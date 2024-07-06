# sagitmalka10@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = Catan

SRCSTST = Model/Tile.cpp \
       Model/Player.cpp \
       Model/Road.cpp \
       Model/Node.cpp \
       Model/Board.cpp \
       Model/DevelopmentCard.cpp \
       Model/DevelopmentCardDeck.cpp \
       Controler/Game.cpp \
       tests.cpp
       
SRCS = main.cpp \
       Model/Tile.cpp \
       Model/Player.cpp \
       Model/Road.cpp \
       Model/Node.cpp \
       Model/Board.cpp \
       Model/DevelopmentCard.cpp \
       Model/DevelopmentCardDeck.cpp \
       Controler/Game.cpp

HDRS = Model/Tile.hpp \
       Model/Player.hpp \
       Model/Road.hpp \
       Model/Node.hpp \
       Model/Board.hpp \
       Model/DevelopmentCard.hpp \
       Model/Constants.hpp \
       Model/Card.hpp \
       Model/CardDeck.hpp \
       Model/DevelopmentCardDeck.hpp \
       Controler/Game.hpp

OBJS = $(SRCS:.cpp=.o)

OBGSTST = $(SRCSTST:.cpp=.o)

all: $(TARGET)

test: $(OBGSTST)
	$(CXX) $(CXXFLAGS) -o test $(OBGSTST)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
