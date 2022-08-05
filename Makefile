CC := gcc
TARGET_EXEC := test
TARGET_LIB := s21_decimal.a

BUILD_DIR := ./build
SRC_DIRS := ./
TEST_SRC_DIRS := ./Executables

SRCS := $(shell find $(SRC_DIRS) -name 's21_*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
TEST_SRCS := $(shell find $(TEST_SRC_DIRS) -name '*.c')
TEST_OBJS := $(TEST_SRCS:%=$(BUILD_DIR)/%.o)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
TEST_FLAGS := `pkg-config --cflags --libs check`

$(TARGET_LIB): $(OBJS)
	ar -rc $@ $(BUILD_DIR)/*/*.o
	ranlib $@

$(TARGET_EXEC): $(BUILD_DIR)/$(TARGET_EXEC)
	-$(BUILD_DIR)/$(TARGET_EXEC)
    
$(BUILD_DIR)/$(TARGET_EXEC): $(TARGET_LIB) $(TEST_OBJS)
	$(CC) $(TEST_OBJS) $(TARGET_LIB) -o $@ $(TEST_FLAGS)
    
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(INC_FLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(TARGET_LIB) $(TARGET_EXEC)
