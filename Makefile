# should work directly on both GNU/Linux and Windows (g++ through mingw)
CC = g++
EXECUTABLE = blokanoid
CC_FLAGS = -w --std=c++17
LINK_FLAGS = -shared
LIB_FLAGS = -lraylib

# default directories
SRC_DIR = src
OBJ_DIR = objs

# files that're gonna get read/produced by either the compiler or linker
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRC)))
DEPS := $(patsubst %.o, %.d, $(OBJS))

all: $(OBJ_DIR) $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(EXECUTABLE)

-include $(DEPS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp 
	$(CC) $(CC_FLAGS) $(LINK_FLAGS) $(LIB_FLAGS) -MD -o $@ $<


$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm $(EXECUTABLE) $(OBJS) $(DEPS)

