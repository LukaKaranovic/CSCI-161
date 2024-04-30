#Makefile for CSCI 161 Assignment 4

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

all: ${BINARY}/dynamicarray ${BINARY}/simpleset \
	${TEST}/${BINARY}/dynamicarraytest ${TEST}/${BINARY}/simplesettest

${BINARY}/dynamicarray: ${OBJECT}/dynamicarraymain.o ${OBJECT}/dynamicarray.o \
		${OBJECT}/utility.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/dynamicarray ${OBJECT}/dynamicarraymain.o  \
		${OBJECT}/dynamicarray.o ${OBJECT}/utility.o


${BINARY}/simpleset: ${OBJECT}/simplesetmain.o ${OBJECT}/simpleset.o ${OBJECT}/dynamicarray.o \
		${OBJECT}/utility.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/simpleset ${OBJECT}/simplesetmain.o ${OBJECT}/simpleset.o \
		${OBJECT}/dynamicarray.o ${OBJECT}/utility.o


${TEST}/${BINARY}/dynamicarraytest: ${TEST}/${OBJECT}/dynamicarraytests.o ${OBJECT}/dynamicarray.o \
		${OBJECT}/utility.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/dynamicarraytest \
		${TEST}/${OBJECT}/dynamicarraytests.o  ${OBJECT}/dynamicarray.o ${OBJECT}/utility.o \
		-lboost_unit_test_framework 


${TEST}/${BINARY}/simplesettest: ${TEST}/${OBJECT}/simplesettests.o ${OBJECT}/simpleset.o \
		${OBJECT}/dynamicarray.o ${OBJECT}/utility.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/simplesettest \
		${TEST}/${OBJECT}/simplesettests.o ${OBJECT}/simpleset.o \
		${OBJECT}/dynamicarray.o ${OBJECT}/utility.o -lboost_unit_test_framework 



${OBJECT}/dynamicarraymain.o: ${SOURCE}/dynamicarraymain.cpp ${INCLUDE}/dynamicarray.h \
		${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/dynamicarraymain.o ${SOURCE}/dynamicarraymain.cpp


${OBJECT}/simplesetmain.o: ${SOURCE}/simplesetmain.cpp ${INCLUDE}/simpleset.h ${INCLUDE}/dynamicarray.h \
	${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/simplesetmain.o ${SOURCE}/simplesetmain.cpp


${TEST}/${OBJECT}/dynamicarraytests.o: ${TEST}/${SOURCE}/dynamicarraytests.cpp ${INCLUDE}/dynamicarray.h \
		${INCLUDE}/utility.h ${TEST}/${INCLUDE}/dynamicarraytest.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${TEST}/${INCLUDE} ${OFLAG} ${TEST}/${OBJECT}/dynamicarraytests.o \
		${TEST}/${SOURCE}/dynamicarraytests.cpp


${TEST}/${OBJECT}/simplesettests.o: ${TEST}/${SOURCE}/simplesettests.cpp ${INCLUDE}/simpleset.h \
	${INCLUDE}/dynamicarray.h ${INCLUDE}/utility.h ${TEST}/${INCLUDE}/simplesettest.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${TEST}/${INCLUDE} ${OFLAG} ${TEST}/${OBJECT}/simplesettests.o \
		${TEST}/${SOURCE}/simplesettests.cpp

${OBJECT}/simpleset.o: ${SOURCE}/simpleset.cpp ${INCLUDE}/simpleset.h ${INCLUDE}/dynamicarray.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/simpleset.o ${SOURCE}/simpleset.cpp


${OBJECT}/dynamicarray.o: ${SOURCE}/dynamicarray.cpp  ${INCLUDE}/dynamicarray.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/dynamicarray.o ${SOURCE}/dynamicarray.cpp

${OBJECT}/utility.o: ${SOURCE}/utility.cpp  ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/utility.o ${SOURCE}/utility.cpp


.PHONY: clean \
	run run-dynamic-array run-simple-set \
	test test-dynamic-array test-simple-set \
	run-example run-example-dynamic-array run-example-simple-set \
	test-example test-example-dynamic-array test-example-simple-set


clean:
	rm -rf ${OBJECT}/* ${BINARY}/* ${TEST}/${OBJECT}/* ${TEST}/${BINARY}/*

run-dynamic-array: ${BINARY}/dynamicarray ${RESOURCE}/fibonacci.txt 
	${BINARY}/dynamicarray

run-simple-set: ${BINARY}/simpleset ${RESOURCE}/primes.txt ${RESOURCE}/fibonacci.txt 
	${BINARY}/simpleset

run: run-dynamic-array run-simple-set

run-example-dynamic-array: ${EXAMPLE}/${BINARY}/dynamicarray ${RESOURCE}/fibonacci.txt 
	${EXAMPLE}/${BINARY}/dynamicarray

run-example-simple-set: ${EXAMPLE}/${BINARY}/simpleset ${RESOURCE}/primes.txt ${RESOURCE}/fibonacci.txt 
	${EXAMPLE}/${BINARY}/simpleset

run-example: run-example-dynamic-array run-example-simple-set


test-dynamic-array: ${TEST}/${BINARY}/dynamicarraytest ${TEST}/${RESOURCE}/input.txt
	${TEST}/${BINARY}/dynamicarraytest --log_level=all

test-simple-set: ${TEST}/${BINARY}/simplesettest ${TEST}/${RESOURCE}/input.txt
	${TEST}/${BINARY}/simplesettest --log_level=all

test: test-dynamic-array test-simple-set


test-example-dynamic-array: ${TEST}/${EXAMPLE}/${BINARY}/dynamicarraytest ${TEST}/${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/dynamicarraytest --log_level=all

test-example-simple-set: ${TEST}/${EXAMPLE}/${BINARY}/simplesettest ${TEST}/${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/simplesettest --log_level=all

test-example: test-example-dynamic-array test-example-simple-set
