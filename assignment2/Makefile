#Makefile of CSCI 161 Assignment 2

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


all: ${BINARY}/singlelinkedlist ${BINARY}/doublelinkedlist ${TEST}/${BINARY}/singlelinkedlisttest ${TEST}/${BINARY}/doublelinkedlisttest

${BINARY}/singlelinkedlist: ${OBJECT}/singlelinkedlistmain.o ${OBJECT}/singlelinkedlist.o 
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/singlelinkedlist ${OBJECT}/singlelinkedlistmain.o ${OBJECT}/singlelinkedlist.o 

${BINARY}/doublelinkedlist: ${OBJECT}/doublelinkedlistmain.o ${OBJECT}/doublelinkedlist.o 
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/doublelinkedlist ${OBJECT}/doublelinkedlistmain.o ${OBJECT}/doublelinkedlist.o 

${TEST}/${BINARY}/singlelinkedlisttest: ${TEST}/${OBJECT}/singlelinkedlisttest.o ${TEST}/${OBJECT}/arraytest.o \
		${OBJECT}/singlelinkedlist.o 
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/singlelinkedlisttest ${TEST}/${OBJECT}/singlelinkedlisttest.o \
		${TEST}/${OBJECT}/arraytest.o ${OBJECT}/singlelinkedlist.o -lboost_unit_test_framework  


${TEST}/${BINARY}/doublelinkedlisttest: ${TEST}/${OBJECT}/doublelinkedlisttest.o ${TEST}/${OBJECT}/arraytest.o \
		${OBJECT}/doublelinkedlist.o 
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/doublelinkedlisttest ${TEST}/${OBJECT}/doublelinkedlisttest.o \
		${TEST}/${OBJECT}/arraytest.o ${OBJECT}/doublelinkedlist.o -lboost_unit_test_framework  

${OBJECT}/singlelinkedlistmain.o: ${SOURCE}/singlelinkedlistmain.cpp ${INCLUDE}/singlelinkedlist.h 
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/singlelinkedlistmain.o ${SOURCE}/singlelinkedlistmain.cpp

${OBJECT}/doublelinkedlistmain.o: ${SOURCE}/doublelinkedlistmain.cpp ${INCLUDE}/doublelinkedlist.h 
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/doublelinkedlistmain.o ${SOURCE}/doublelinkedlistmain.cpp

${OBJECT}/singlelinkedlist.o: ${SOURCE}/singlelinkedlist.cpp ${INCLUDE}/singlelinkedlist.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/singlelinkedlist.o ${SOURCE}/singlelinkedlist.cpp

${OBJECT}/doublelinkedlist.o: ${SOURCE}/doublelinkedlist.cpp ${INCLUDE}/doublelinkedlist.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/doublelinkedlist.o ${SOURCE}/doublelinkedlist.cpp



${TEST}/${OBJECT}/arraytest.o: ${TEST}/${SOURCE}/arraytest.cpp ${TEST}/${INCLUDE}/arraytest.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${TEST}/${INCLUDE} ${OFLAG} ${TEST}/${OBJECT}/arraytest.o \
		${TEST}/${SOURCE}/arraytest.cpp


${TEST}/${OBJECT}/singlelinkedlisttest.o: ${TEST}/${SOURCE}/singlelinkedlisttest.cpp 
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${TEST}/${INCLUDE} ${OFLAG} ${TEST}/${OBJECT}/singlelinkedlisttest.o \
		${TEST}/${SOURCE}/singlelinkedlisttest.cpp


${TEST}/${OBJECT}/doublelinkedlisttest.o: ${TEST}/${SOURCE}/doublelinkedlisttest.cpp 
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${TEST}/${INCLUDE} ${OFLAG} ${TEST}/${OBJECT}/doublelinkedlisttest.o \
		${TEST}/${SOURCE}/doublelinkedlisttest.cpp




.PHONY: clean \
		run run-single-linked-list run-double-linked-list \
		run-example run-example-single_linked_list run-example-double_linked_list\
        test test-single-linked-list test-double-linked-list \
		test-example test-example-single-linked-list test-example-double-linked-list


clean:
	rm -rf ${OBJECT}/* ${BINARY}/* ${TEST}/${OBJECT}/* ${TEST}/${BINARY}/*
	rm -f ${RESOURCE}/output*.txt ${TEST}/${RESOURCE}/output*.txt



run-single-linked-list: ${BINARY}/singlelinkedlist ${RESOURCE}/input.txt
	${BINARY}/singlelinkedlist ${RESOURCE}/input.txt ${RESOURCE}/output-single.txt

run-double-linked-list: ${BINARY}/doublelinkedlist ${RESOURCE}/input.txt
	${BINARY}/doublelinkedlist ${RESOURCE}/input.txt ${RESOURCE}/output-double.txt

run: run-single-linked-list run-double-linked-list


run-example-single-linked-list: ${EXAMPLE}/${BINARY}/singlelinkedlist ${RESOURCE}/input.txt
	${EXAMPLE}/${BINARY}/singlelinkedlist ${RESOURCE}/input.txt ${RESOURCE}/output-single.txt

run-example-double-linked-list: ${EXAMPLE}/${BINARY}/doublelinkedlist ${RESOURCE}/input.txt
	${EXAMPLE}/${BINARY}/doublelinkedlist ${RESOURCE}/input.txt ${RESOURCE}/output-double.txt

run-example: run-example-single-linked-list run-example-double-linked-list


test-single-linked-list: ${TEST}/${BINARY}/singlelinkedlisttest ${RESOURCE}/input.txt
	${TEST}/${BINARY}/singlelinkedlisttest --log_level=all --run_test=*/single_linked_list

test-double-linked-list: ${TEST}/${BINARY}/singlelinkedlisttest ${RESOURCE}/input.txt
	${TEST}/${BINARY}/doublelinkedlisttest --log_level=all --run_test=*/double_linked_list


test: test-single-linked-list test-double-linked-list



test-example-single-linked-list: ${TEST}/${EXAMPLE}/${BINARY}/singlelinkedlisttest ${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/singlelinkedlisttest --log_level=all --run_test=*/single_linked_list

test-example-double-linked-list: ${TEST}/${EXAMPLE}/${BINARY}/doublelinkedlisttest ${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/doublelinkedlisttest --log_level=all --run_test=*/double_linked_list


test-example: test-example-single-linked-list test-example-double-linked-list
