CC = clang++
HOMEBREW_INC = /opt/homebrew/include
RAYLIB_LIB = /opt/homebrew/lib
LOCAL_INC = include
CFLAGS = -Wall -Wextra -ffast-math -funroll-loops -O2 -std=c++17

apple:
	$(CC) src/main.cpp $(CFLAGS) -I$(HOMEBREW_INC) -I$(LOCAL_INC) -L$(RAYLIB_LIB) -lraylib -o ./raycube