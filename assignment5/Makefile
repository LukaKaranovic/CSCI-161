#Makefile for CSCI 161 Assignment 6

CC = g++
WFLAG = -Wall
CFLAG = -c
OFLAG = -o
IFLAG = -I
DFLAG = -ggdb

SOURCE = src
INCLUDE = include
OBJECT = build
BINARY = bin
RESOURCE = resource
TEST = test
EXAMPLE = example


all: ${BINARY}/arraymap ${BINARY}/linkedmap ${BINARY}/map \
	${TEST}/${BINARY}/dynamicarraytest \
	${TEST}/${BINARY}/arraymaptest \
	${TEST}/${BINARY}/linkedmaptest \
	${TEST}/${BINARY}/maptest

${BINARY}/map: ${OBJECT}/mapmain.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/map ${OBJECT}/mapmain.o


${BINARY}/arraymap: ${OBJECT}/arraymapmain.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/arraymap ${OBJECT}/arraymapmain.o

${BINARY}/linkedmap: ${OBJECT}/linkedmapmain.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/linkedmap ${OBJECT}/linkedmapmain.o


${TEST}/${BINARY}/maptest: ${TEST}/${OBJECT}/maptest.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/maptest \
		${TEST}/${OBJECT}/maptest.o -lboost_unit_test_framework 



${TEST}/${BINARY}/arraymaptest: ${TEST}/${OBJECT}/arraymaptest.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/arraymaptest \
		${TEST}/${OBJECT}/arraymaptest.o -lboost_unit_test_framework 


${TEST}/${BINARY}/linkedmaptest: ${TEST}/${OBJECT}/linkedmaptest.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/linkedmaptest \
		${TEST}/${OBJECT}/linkedmaptest.o -lboost_unit_test_framework 


${TEST}/${BINARY}/dynamicarraytest: ${TEST}/${OBJECT}/dynamicarraytest.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/dynamicarraytest \
		${TEST}/${OBJECT}/dynamicarraytest.o -lboost_unit_test_framework 



${OBJECT}/mapmain.o: ${SOURCE}/mapmain.cpp ${SOURCE}/arraymap.cpp ${SOURCE}/linkedmap.cpp ${SOURCE}/dynamicarray.cpp \
	${INCLUDE}/map.h ${INCLUDE}/dynamicarray.h ${INCLUDE}/keyvalue.h ${INCLUDE}/singlelinkedlistnode.h
	${CC} ${WFLAG} ${DFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/mapmain.o ${SOURCE}/mapmain.cpp


${OBJECT}/arraymapmain.o: ${SOURCE}/arraymapmain.cpp ${SOURCE}/arraymap.cpp ${SOURCE}/dynamicarray.cpp \
	${INCLUDE}/map.h ${INCLUDE}/dynamicarray.h ${INCLUDE}/keyvalue.h
	${CC} ${WFLAG} ${DFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/arraymapmain.o ${SOURCE}/arraymapmain.cpp


${OBJECT}/linkedmapmain.o: ${SOURCE}/linkedmapmain.cpp ${SOURCE}/linkedmap.cpp ${SOURCE}/dynamicarray.cpp \
	${INCLUDE}/map.h ${INCLUDE}/dynamicarray.h ${INCLUDE}/keyvalue.h ${INCLUDE}/singlelinkedlistnode.h
	${CC} ${WFLAG} ${DFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/linkedmapmain.o ${SOURCE}/linkedmapmain.cpp



${TEST}/${OBJECT}/maptest.o: ${TEST}/${SOURCE}/maptest.cpp ${SOURCE}/arraymap.cpp ${SOURCE}/linkedmap.cpp \
	${SOURCE}/dynamicarray.cpp ${INCLUDE}/map.h ${INCLUDE}/dynamicarray.h ${TEST}/${INCLUDE}/maptest.h
	${CC} ${WFLAG} ${DFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${SOURCE} ${IFLAG} ${TEST}/${INCLUDE}\
		${OFLAG} ${TEST}/${OBJECT}/maptest.o ${TEST}/${SOURCE}/maptest.cpp

${TEST}/${OBJECT}/arraymaptest.o: ${TEST}/${SOURCE}/arraymaptest.cpp ${SOURCE}/arraymap.cpp \
	${SOURCE}/dynamicarray.cpp ${INCLUDE}/map.h ${INCLUDE}/dynamicarray.h ${TEST}/${INCLUDE}/arraymaptest.h
	${CC} ${WFLAG} ${DFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${SOURCE} ${IFLAG} ${TEST}/${INCLUDE}\
		${OFLAG} ${TEST}/${OBJECT}/arraymaptest.o ${TEST}/${SOURCE}/arraymaptest.cpp
	
${TEST}/${OBJECT}/linkedmaptest.o: ${TEST}/${SOURCE}/linkedmaptest.cpp ${SOURCE}/linkedmap.cpp \
	${SOURCE}/dynamicarray.cpp ${INCLUDE}/map.h ${INCLUDE}/dynamicarray.h ${TEST}/${INCLUDE}/linkedmaptest.h
	${CC} ${WFLAG} ${DFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${SOURCE} ${IFLAG} ${TEST}/${INCLUDE}\
		${OFLAG} ${TEST}/${OBJECT}/linkedmaptest.o ${TEST}/${SOURCE}/linkedmaptest.cpp


${TEST}/${OBJECT}/dynamicarraytest.o: ${TEST}/${SOURCE}/dynamicarraytest.cpp ${SOURCE}/dynamicarray.cpp \
	${INCLUDE}/dynamicarray.h ${TEST}/${INCLUDE}/dynamicarraytest.h
	${CC} ${WFLAG} ${DFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${SOURCE} ${IFLAG} ${TEST}/${INCLUDE}\
		${OFLAG} ${TEST}/${OBJECT}/dynamicarraytest.o ${TEST}/${SOURCE}/dynamicarraytest.cpp
	
.PHONY: clean \
	run run-map run-array-map run-linked-map \
	run-example run-example-map run-example-array-map run-example-linked-map \
	test test-dynamic-array test-array-map test-linked-map test-map \
	test-example test-example-dynamic-array \
	test-example-array-map test-example-linked-map test-example-map


clean:
	rm -rf ${OBJECT}/* ${BINARY}/* ${TEST}/${OBJECT}/* ${TEST}/${BINARY}/*


run-array-map: ${BINARY}/arraymap
	${BINARY}/arraymap

run-linked-map: ${BINARY}/linkedmap
	${BINARY}/linkedmap

run-map: ${BINARY}/map
	${BINARY}/map


run: run-array-map run-linked-map run-map


run-example-array-map: ${EXAMPLE}/${BINARY}/arraymap
	${EXAMPLE}/${BINARY}/arraymap

run-example-linked-map: ${EXAMPLE}/${BINARY}/linkedmap
	${EXAMPLE}/${BINARY}/linkedmap

run-example-map: ${EXAMPLE}/${BINARY}/map
	${EXAMPLE}/${BINARY}/map


run-example: run-example-array-map run-example-linked-map run-example-map



test-dynamic-array: ${TEST}/${BINARY}/dynamicarraytest
	${TEST}/${BINARY}/dynamicarraytest --log_level=all

test-array-map: ${TEST}/${BINARY}/arraymaptest
	${TEST}/${BINARY}/arraymaptest --log_level=all

test-linked-map: ${TEST}/${BINARY}/linkedmaptest
	${TEST}/${BINARY}/linkedmaptest --log_level=all

test-map: ${TEST}/${BINARY}/maptest
	${TEST}/${BINARY}/maptest --log_level=all

test: test-dynamic-array test-array-map test-linked-map test-map




test-example-dynamicarray: ${TEST}/${EXAMPLE}/${BINARY}/dynamicarraytest
	${TEST}/${EXAMPLE}/${BINARY}/dynamicarraytest --log_level=all

test-example-array-map: ${TEST}/${EXAMPLE}/${BINARY}/arraymaptest
	${TEST}/${EXAMPLE}/${BINARY}/arraymaptest --log_level=all

test-example-linked-map: ${TEST}/${EXAMPLE}/${BINARY}/linkedmaptest
	${TEST}/${EXAMPLE}/${BINARY}/linkedmaptest --log_level=all

test-example-map: ${TEST}/${EXAMPLE}/${BINARY}/maptest
	${TEST}/${EXAMPLE}/${BINARY}/maptest --log_level=all

test-example: test-example-dynamic-array \
	test-example-array-map test-example-linked-map test-example-map

