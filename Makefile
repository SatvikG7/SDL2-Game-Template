CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb
CXX_FLAGS_RELEASE := -std=c++17 -O3

BIN		:= bin

DEBUG	:= debug
RELEASE	:= release
SRC		:= src
INCLUDE	:= include
LIB		:= lib
ASSETS	:= assets
LIBRARIES	:= -lmingw32 -lSDL2 -lSDL2main -lSDL2_image
EXECUTABLE_DEBUG	:= main
EXECUTABLE_RELEASE := main


all: clean $(BIN)/$(DEBUG)/$(EXECUTABLE_DEBUG)

run: all
	./$(BIN)/$(DEBUG)/$(EXECUTABLE_DEBUG)

$(BIN)/$(DEBUG)/$(EXECUTABLE_DEBUG): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/$(DEBUG)/$(EXECUTABLE_DEBUG).exe

release: $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS_RELEASE) -I$(INCLUDE) -L$(LIB) $^ -o $(BIN)/$(RELEASE)/$(EXECUTABLE_RELEASE).exe $(LIBRARIES)

res: assets/*.png
	rm -rf $(BIN)/$(DEBUG)/$(ASSETS) $(BIN)/$(RELEASE)/$(ASSETS)
	mkdir $(BIN)/$(DEBUG)/$(ASSETS) $(BIN)/$(RELEASE)/$(ASSETS)
	cp -r $^ $(BIN)/$(DEBUG)/$(ASSETS)/
	cp -r $^ $(BIN)/$(RELEASE)/$(ASSETS)/