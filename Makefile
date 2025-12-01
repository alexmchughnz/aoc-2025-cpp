DAY = $(shell date +%d)
DAY_NUM = $(shell printf '%02d' $(DAY))
DAY_NAME = day$(DAY_NUM)

BUILD_DIR := ./bin
SOURCE_DIR := ./src

CPP_STD := -std=c++17
CPP_FLAGS := -Wpedantic -Wall -Wextra -Wformat -Werror


.PHONY: all
all: build run

.PHONY: day
.SILENT: day
day:
	echo "*** Day $(DAY) ***"

.PHONY: scaffold
scaffold: day
	@mkdir -p $(SOURCE_DIR)/$(DAY_NAME)

	@aoc download \
	--day $(DAY) \
	--input-file $(SOURCE_DIR)/$(DAY_NAME)/input.txt \
	--puzzle-file $(SOURCE_DIR)/$(DAY_NAME)/$(DAY_NAME).md \
	--overwrite

	touch $(SOURCE_DIR)/$(DAY_NAME)/$(DAY_NAME).cpp

.PHONY: build
.SILENT: build
build: day
	mkdir -p $(BUILD_DIR)

	g++ $(CPP_STD) $(CPP_FLAGS) \
	-o $(BUILD_DIR)/$(DAY_NAME) \
	$(SOURCE_DIR)/$(DAY_NAME)/$(DAY_NAME).cpp

.PHONY: run
.SILENT: run
run: day
	$(BUILD_DIR)/$(DAY_NAME)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*
