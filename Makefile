DAY = $(shell date +%d)
DAY_NUM = $(shell printf '%02d' $(DAY))
DAY_NAME = day$(DAY_NUM)

EXAMPLE = false

BUILD_DIR := ./bin
SOURCE_DIR := ./src

CPPSTD := -std=c++17
CXXFLAGS := -Wpedantic -Wall -Wextra -Wformat -Werror
CPPFLAGS := -D DAY_NAME=\"$(DAY_NAME)\" \
			-D EXAMPLE=$(EXAMPLE) \

.PHONY: all
all: build run

.PHONY: day
.SILENT: day
day:
	echo "*** Day $(DAY) ***"

.PHONY: update
.SILENT: update
update: day
	mkdir -p $(SOURCE_DIR)/$(DAY_NAME)

	aoc download \
	--day $(DAY) \
	--input-file $(SOURCE_DIR)/$(DAY_NAME)/input.txt \
	--puzzle-file $(SOURCE_DIR)/$(DAY_NAME)/$(DAY_NAME).md \
	--overwrite

.PHONY: scaffold
scaffold: update
	cp $(SOURCE_DIR)/template.cpp $(SOURCE_DIR)/$(DAY_NAME)/$(DAY_NAME).cpp
	touch $(SOURCE_DIR)/$(DAY_NAME)/example.txt

.PHONY: build
.SILENT: build
build: day
	mkdir -p $(BUILD_DIR)

	g++ $(CPPSTD) $(CPPFLAGS) $(CXXFLAGS) \
	-o $(BUILD_DIR)/$(DAY_NAME) \
	$(SOURCE_DIR)/$(DAY_NAME)/$(DAY_NAME).cpp

.PHONY: run
.SILENT: run
run: day
	$(BUILD_DIR)/$(DAY_NAME)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*
