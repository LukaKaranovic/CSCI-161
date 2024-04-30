#Makefile for CSCI 161 Assignment 3

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


all: ${BINARY}/singlelinkedlist ${BINARY}/binarysearchtree ${TEST}/${BINARY}/singlelinkedlisttest \
		${TEST}/${BINARY}/binarysearchtreetest 


${BINARY}/singlelinkedlist: ${OBJECT}/singlelinkedlistmain.o ${OBJECT}/singlelinkedlist.o \
						${OBJECT}/binarysearchtree.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/singlelinkedlist ${OBJECT}/singlelinkedlistmain.o \
		${OBJECT}/singlelinkedlist.o ${OBJECT}/binarysearchtree.o


${BINARY}/binarysearchtree: ${OBJECT}/binarysearchtreemain.o ${OBJECT}/singlelinkedlist.o \
						${OBJECT}/binarysearchtree.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/binarysearchtree ${OBJECT}/binarysearchtreemain.o \
		${OBJECT}/singlelinkedlist.o ${OBJECT}/binarysearchtree.o


${TEST}/${BINARY}/singlelinkedlisttest: ${TEST}/${OBJECT}/singlelinkedlisttest.o ${OBJECT}/singlelinkedlist.o 
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/singlelinkedlisttest ${TEST}/${OBJECT}/singlelinkedlisttest.o \
		${OBJECT}/singlelinkedlist.o -lboost_unit_test_framework 



${TEST}/${BINARY}/binarysearchtreetest: ${TEST}/${OBJECT}/binarysearchtreetest.o \
		${OBJECT}/singlelinkedlist.o ${OBJECT}/binarysearchtree.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${TEST}/${BINARY}/binarysearchtreetest \
		${TEST}/${OBJECT}/binarysearchtreetest.o \
		${OBJECT}/singlelinkedlist.o ${OBJECT}/binarysearchtree.o \
		-lboost_unit_test_framework 


${OBJECT}/singlelinkedlistmain.o: ${SOURCE}/singlelinkedlistmain.cpp ${INCLUDE}/singlelinkedlist.h 
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/singlelinkedlistmain.o ${SOURCE}/singlelinkedlistmain.cpp



${OBJECT}/binarysearchtreemain.o: ${SOURCE}/binarysearchtreemain.cpp ${INCLUDE}/singlelinkedlist.h \
					${INCLUDE}/binarysearchtree.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/binarysearchtreemain.o ${SOURCE}/binarysearchtreemain.cpp



${TEST}/${OBJECT}/binarysearchtreetest.o: ${TEST}/${SOURCE}/binarysearchtreetest.cpp ${INCLUDE}/singlelinkedlist.h \
		${INCLUDE}/binarysearchtree.h ${TEST}/${INCLUDE}/binarysearchtreetest.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${TEST}/${INCLUDE} ${OFLAG} ${TEST}/${OBJECT}/binarysearchtreetest.o \
		${TEST}/${SOURCE}/binarysearchtreetest.cpp


${TEST}/${OBJECT}/singlelinkedlisttest.o:  ${TEST}/${SOURCE}/singlelinkedlisttest.cpp \
				${TEST}/${INCLUDE}/singlelinkedlisttest.h ${INCLUDE}/singlelinkedlist.h
		${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${IFLAG} ${TEST}/${INCLUDE} ${OFLAG} ${TEST}/${OBJECT}/singlelinkedlisttest.o \
			${TEST}/${SOURCE}/singlelinkedlisttest.cpp



${OBJECT}/singlelinkedlist.o: ${SOURCE}/singlelinkedlist.cpp ${INCLUDE}/singlelinkedlist.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/singlelinkedlist.o ${SOURCE}/singlelinkedlist.cpp



${OBJECT}/binarysearchtree.o: ${SOURCE}/binarysearchtree.cpp ${INCLUDE}/binarysearchtree.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/binarysearchtree.o ${SOURCE}/binarysearchtree.cpp

.PHONY: clean \
	run run-single-linked-list run-binary-search-tree\
	run-example run-example-single-linked-list run-binary-search-tree\
	test test-single-linked-list test-binary-search-tree \
	test-example test-example-single-linked-list test-example-binary-search-tree



clean:
	rm -rf ${OBJECT}/* ${BINARY}/* ${TEST}/${OBJECT}/* ${TEST}/${BINARY}/*


run: run-single-linked-list run-binary-search-tree

run-single-linked-list: ${BINARY}/singlelinkedlist ${RESOURCE}/listinput.txt
	${BINARY}/singlelinkedlist

run-binary-search-tree: ${BINARY}/binarysearchtree
	${BINARY}/binarysearchtree


run-example-single-linked-list: ${EXAMPLE}/${BINARY}/singlelinkedlist ${RESOURCE}/listinput.txt
	${EXAMPLE}/${BINARY}/singlelinkedlist

run-example-binary-search-tree: ${EXAMPLE}/${BINARY}/binarysearchtree
	${EXAMPLE}/${BINARY}/binarysearchtree

run-example: run-example-single-linked-list run-example-binary-search-tree


test-single-linked-list: ${TEST}/${BINARY}/singlelinkedlisttest ${RESOURCE}/listinput.txt
	${TEST}/${BINARY}/singlelinkedlisttest --log_level=all --run_test=*/single_linked_list

test-binary-search-tree: ${TEST}/${BINARY}/binarysearchtreetest ${RESOURCE}/listinput.txt
	${TEST}/${BINARY}/binarysearchtreetest --log_level=all --run_test=*/binary_search_tree

test: test-single-linked-list test-binary-search-tree


test-example-single-linked-list: ${TEST}/${EXAMPLE}/${BINARY}/singlelinkedlisttest ${RESOURCE}/listinput.txt
	${TEST}/${EXAMPLE}/${BINARY}/singlelinkedlisttest --log_level=all --run_test=*/single_linked_list

test-example-binary-search-tree: ${TEST}/${EXAMPLE}/${BINARY}/binarysearchtreetest ${RESOURCE}/listinput.txt
	${TEST}/${EXAMPLE}/${BINARY}/binarysearchtreetest --log_level=all --run_test=*/binary_search_tree

test-example: test-example-single-linked-list test-example-binary-search-tree
