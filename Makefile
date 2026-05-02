# 1. Detect the Operating System
ifeq ($(OS),Windows_NT)
    # Windows-specific settings
    PLATFORM = WINDOWS
    EXT = .exe
    RM = del /Q
    # Raylib paths for your Windows setup
    LDFLAGS = -L. -lraylib -lopengl32 -lgdi32 -lwinmm -lshcore
else
    # Linux/Unix-specific settings
    PLATFORM = LINUX
    EXT =
    RM = rm -f
    # Raylib usually lives in standard system paths on Linux
    LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

# 2. Use those variables in your build rules
TARGET = build/my_game$(EXT)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) *.o $(TARGET)