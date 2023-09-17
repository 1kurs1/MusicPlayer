CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
INC = -I../headers/

ConfuseEditor: ../src/*.cpp ../headers/core/*.hpp ../glad/glad.h ../glad/glad.c
	clang++ $(CFLAGS) $(INC) -o ConfuseEditor ../src/*.cpp ../glad/glad.c $(LDFLAGS)

.PHONY: run clean

run: ConfuseEditor
	./ConfuseEditor

clean: rm -f ConfuseEditor