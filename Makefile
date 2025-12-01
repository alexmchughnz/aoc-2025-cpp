DAY = $(shell printf '%02d' ${day})
BUILD_DIR := ./bin
SOURCE_DIR := ./src

CPPSTD := -std=c++17
CPPFLAGS := -Wpedantic -Wall -Wextra -Wformat -Werror

.PHONY: all
all: build run

.PHONY: run
run:
	${BUILD_DIR}/day${DAY}

.PHONY: build
build:
	mkdir -p ${BUILD_DIR}

	g++ ${CPPSTD} ${CPPFLAGS} \
	-o ${BUILD_DIR}/day${DAY} \
	${SOURCE_DIR}/day${DAY}.cpp


.PHONY: clean
clean: # Cleans the build directory
	rm -rf build/*
