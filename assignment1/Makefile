#Makefile of CSCI 161 Assignment1

CC = g++ 
WFLAG = -Wall
CFLAG = -c
DFLAG = -ggdb
IFLAG = -I
OUTFLAG = -o
SOURCE=src
INCLUDE=include
BUILD = build
BINARY = bin
RESOURCE = resource
TEST = test
EXAMPLE = example


all: ${BINARY}/sort_bubble ${BINARY}/sort_selection ${BINARY}/sort_insertion \
	${BINARY}/sort_merge ${BINARY}/sort_quick \
	${TEST}/${BINARY}/sort_bubble_test ${TEST}/${BINARY}/sort_selection_test \
	${TEST}/${BINARY}/sort_insertion_test ${TEST}/${BINARY}/sort_merge_test \
	${TEST}/${BINARY}/sort_quick_test



${BINARY}/sort_bubble: ${BUILD}/main.o ${BUILD}/utility.o ${BUILD}/sort_bubble.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_bubble ${BUILD}/main.o ${BUILD}/utility.o ${BUILD}/sort_bubble.o


${BINARY}/sort_selection:${BUILD}/main.o ${BUILD}/utility.o ${BUILD}/sort_selection.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_selection ${BUILD}/main.o ${BUILD}/utility.o ${BUILD}/sort_selection.o


${BINARY}/sort_insertion: ${BUILD}/main.o ${BUILD}/utility.o ${BUILD}/sort_insertion.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_insertion ${BUILD}/main.o ${BUILD}/utility.o ${BUILD}/sort_insertion.o


${BINARY}/sort_merge: ${BUILD}/main.o ${BUILD}/utility.o ${BUILD}/sort_merge.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_merge ${BUILD}/main.o ${BUILD}/utility.o ${BUILD}/sort_merge.o


${BINARY}/sort_quick: ${BUILD}/main.o  ${BUILD}/utility.o ${BUILD}/sort_quick.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_quick ${BUILD}/main.o ${BUILD}/utility.o ${BUILD}/sort_quick.o



${TEST}/${BINARY}/sort_bubble_test: ${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_bubble.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG} ${TEST}/${BINARY}/sort_bubble_test \
		${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_bubble.o \
		-lboost_unit_test_framework 

${TEST}/${BINARY}/sort_selection_test: ${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_selection.o
	${CC} ${WFLAG} ${DFLAG}  ${OUTFLAG} ${TEST}/${BINARY}/sort_selection_test \
		${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_selection.o \
		-lboost_unit_test_framework 

${TEST}/${BINARY}/sort_insertion_test: ${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_insertion.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG} ${TEST}/${BINARY}/sort_insertion_test \
		${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_insertion.o \
		-lboost_unit_test_framework 

${TEST}/${BINARY}/sort_merge_test: ${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_merge.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG} ${TEST}/${BINARY}/sort_merge_test \
		${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_merge.o \
		-lboost_unit_test_framework 

${TEST}/${BINARY}/sort_quick_test: ${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_quick.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG} ${TEST}/${BINARY}/sort_quick_test \
		${TEST}/${BUILD}/assignment1test.o ${BUILD}/utility.o ${BUILD}/sort_quick.o \
		-lboost_unit_test_framework 




${BUILD}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/sort.h ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG}  ${INCLUDE} ${OUTFLAG} ${BUILD}/main.o ${SOURCE}/main.cpp

${TEST}/${BUILD}/assignment1test.o: ${TEST}/${SOURCE}/assignment1test.cpp ${INCLUDE}/sort.h ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG}  ${INCLUDE} ${OUTFLAG} ${TEST}/${BUILD}/assignment1test.o ${TEST}/${SOURCE}/assignment1test.cpp


${BUILD}/utility.o: ${SOURCE}/utility.cpp ${INCLUDE}/utility.h ${INCLUDE}/sort.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG}  ${BUILD}/utility.o ${SOURCE}/utility.cpp

${BUILD}/sort_bubble.o: ${SOURCE}/sort_bubble.cpp ${INCLUDE}/sort.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${BUILD}/sort_bubble.o ${SOURCE}/sort_bubble.cpp

${BUILD}/sort_selection.o: ${SOURCE}/sort_selection.cpp ${INCLUDE}/sort.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${BUILD}/sort_selection.o ${SOURCE}/sort_selection.cpp

${BUILD}/sort_insertion.o: ${SOURCE}/sort_insertion.cpp ${INCLUDE}/sort.h
		${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${BUILD}/sort_insertion.o ${SOURCE}/sort_insertion.cpp


${BUILD}/sort_merge.o: ${SOURCE}/sort_merge.cpp ${INCLUDE}/sort.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${BUILD}/sort_merge.o ${SOURCE}/sort_merge.cpp


${BUILD}/sort_quick.o: ${SOURCE}/sort_quick.cpp ${INCLUDE}/sort.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${BUILD}/sort_quick.o ${SOURCE}/sort_quick.cpp


.PHONY: clean \
	run run-sort-bubble run-sort-insertion run-sort-merge run-sort-quick run-sort-selection \
	run-example run-example-sort-bubble run-example-sort-insertion run-example-sort-merge \
	run-example-sort-quick run-example-sort-selection \
	test test-sort-bubble test-utility test-sort-insertion test-sort-merge \
	test-sort-quick test-sort-selection \
	test-example test-example-sort-bubble test-example-utility test-example-sort-insertion \
	test-example-sort-merge \
	test-example-sort-quick test-example-sort-selection



clean:
	rm -r ${BUILD}/* ${BINARY}/* ${TEST}/${BUILD}/* ${TEST}/${BINARY}/* 
	rm ${RESOURCE}/output*.txt
	rm ${TEST}/${RESOURCE}/testoutput.txt
	

run-sort-bubble: ${BINARY}/sort_bubble ${RESOURCE}/input.txt
	${BINARY}/sort_bubble ${RESOURCE}/input.txt ${RESOURCE}/output_bubble.txt

run-sort-selection: ${BINARY}/sort_selection ${RESOURCE}/input.txt
	${BINARY}/sort_selection ${RESOURCE}/input.txt ${RESOURCE}/output_selection.txt
	
run-sort-insertion: ${BINARY}/sort_insertion ${RESOURCE}/input.txt
	${BINARY}/sort_insertion ${RESOURCE}/input.txt ${RESOURCE}/output_insertion.txt

run-sort-merge: ${BINARY}/sort_merge ${RESOURCE}/input.txt
	${BINARY}/sort_merge ${RESOURCE}/input.txt ${RESOURCE}/output_merge.txt

run-sort-quick: ${BINARY}/sort_quick ${RESOURCE}/input.txt
	${BINARY}/sort_quick ${RESOURCE}/input.txt ${RESOURCE}/output_quick.txt

run: run-sort-bubble run-sort-selection run-sort-insertion run-sort-merge run-sort-quick



run-example-sort-bubble: ${EXAMPLE}/${BINARY}/sort_bubble ${RESOURCE}/input.txt
	${EXAMPLE}/${BINARY}/sort_bubble ${RESOURCE}/input.txt ${RESOURCE}/output_bubble.txt

run-example-sort-selection: ${EXAMPLE}/${BINARY}/sort_selection ${RESOURCE}/input.txt
	${EXAMPLE}/${BINARY}/sort_selection ${RESOURCE}/input.txt ${RESOURCE}/output_selection.txt
	
run-example-sort-insertion: ${EXAMPLE}/${BINARY}/sort_insertion ${RESOURCE}/input.txt
	${EXAMPLE}/${BINARY}/sort_insertion ${RESOURCE}/input.txt ${RESOURCE}/output_insertion.txt

run-example-sort-merge: ${EXAMPLE}/${BINARY}/sort_merge ${RESOURCE}/input.txt
	${EXAMPLE}/${BINARY}/sort_merge ${RESOURCE}/input.txt ${RESOURCE}/output_merge.txt

run-example-sort-quick: ${EXAMPLE}/${BINARY}/sort_quick ${RESOURCE}/input.txt
	${EXAMPLE}/${BINARY}/sort_quick ${RESOURCE}/input.txt ${RESOURCE}/output_quick.txt

run-example: run-example-sort-bubble run-example-sort-selection run-example-sort-insertion \
	run-example-sort-merge run-example-sort-quick



test-sort-bubble: ${TEST}/${BINARY}/sort_bubble_test ${RESOURCE}/input.txt
	${TEST}/${BINARY}/sort_bubble_test --log_level=all --run_test=assignment1_test_sort

test-utility: ${TEST}/${BINARY}/sort_bubble_test ${RESOURCE}/input.txt
	${TEST}/${BINARY}/sort_bubble_test --log_level=all --run_test=assignment1_test_utility

test-sort-selection: ${TEST}/${BINARY}/sort_selection_test ${RESOURCE}/input.txt
	${TEST}/${BINARY}/sort_selection_test --log_level=all --run_test=assignment1_test_sort

test-sort-insertion: ${TEST}/${BINARY}/sort_insertion_test ${RESOURCE}/input.txt
	${TEST}/${BINARY}/sort_insertion_test --log_level=all --run_test=assignment1_test_sort

test-sort-merge: ${TEST}/${BINARY}/sort_merge_test ${RESOURCE}/input.txt
	${TEST}/${BINARY}/sort_merge_test --log_level=all --run_test=assignment1_test_sort

test-sort-quick: ${TEST}/${BINARY}/sort_quick_test ${RESOURCE}/input.txt
	${TEST}/${BINARY}/sort_quick_test --log_level=all --run_test=assignment1_test_sort

test: test-sort-bubble test-sort-insertion test-sort-merge \
	test-sort-quick test-sort-selection test-utility 



test-example-sort-bubble: ${TEST}/${EXAMPLE}/${BINARY}/sort_bubble_test ${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/sort_bubble_test --log_level=all --run_test=assignment1_test_sort

test-example-utility: ${TEST}/${EXAMPLE}/${BINARY}/sort_bubble_test ${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/sort_bubble_test --log_level=all --run_test=assignment1_test_utility

test-example-sort-selection: ${TEST}/${EXAMPLE}/${BINARY}/sort_selection_test ${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/sort_selection_test --log_level=all --run_test=assignment1_test_sort

test-example-sort-insertion: ${TEST}/${EXAMPLE}/${BINARY}/sort_insertion_test ${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/sort_insertion_test --log_level=all --run_test=assignment1_test_sort

test-example-sort-merge: ${TEST}/${EXAMPLE}/${BINARY}/sort_merge_test ${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/sort_merge_test --log_level=all --run_test=assignment1_test_sort

test-example-sort-quick: ${TEST}/${EXAMPLE}/${BINARY}/sort_quick_test ${RESOURCE}/input.txt
	${TEST}/${EXAMPLE}/${BINARY}/sort_quick_test --log_level=all --run_test=assignment1_test_sort

test-example: test-example-sort-bubble test-example-sort-selection \
	test-example-sort-insertion test-example-sort-merge test-example-sort-quick \
	test-example-utility 



	

