# should work directly on both GNU/Linux and Windows (g++)
CC = g++
EXECUTABLE = blockanoid
CC_FLAGS = -w
LIB_FLAGS = -lraylib
INCLUDE_DIR = include
SRC_DIR = src
SRC := $(wildcard $(SRC_DIR)/*.cpp) 
OBJS := $(patsubst %.cpp, %.o, $(SRC))

all: $(OBJS)
	$(CC) $(OBJS) $(LIB_FLAGS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CC) -c $< -I./$(INCLUDE_DIR) $(CC_FLAGS) -o $@

.PHONY: clean

clean:
	rm $(EXECUTABLE) $(OBJS)

