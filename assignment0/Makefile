#Makefile for CSCI 161 Assignment 0
# @author: Humayun Kbair, Instructor, CSCI 161, VIU
# @version: 1.0.0
# @date: August 01, 2021
#
#For convenience, this Makefile declares necessary Make variables and uses them frequently.
#The default target of this Makefile builds all the regular and the test executables.
#It has individual target to build individual executable, regular or test.
#Individual executable target builds the corresponding executable by linking appropriate object files.
#It also has individual target to build individual object file compiling indiviudal source code.
#It also provides many PHONY targets to accomplish non-building tasks, such as removing old
#object and executable files, running a specific executable, and testing a specific code.



#Declaring Make variables that will be used in this make file frequently.
#Every occurance of a variable in this make file will be replaced by its defined value
#For example, every occurance of '${CC}' will be replaced by 'g++'.
#Variable ${CC} gets the compiler to be used to compile and build the application.
#Variable ${WFLAG} gets the warnning option to be used with the compiler
#Variable ${CFLAG} gets the compile option to be used with the compiler
#Variable ${OFLAG} gets the output option to be used with the compiler
#Variable ${DFLAG} gets the debug option to be used with the compiler
#Variable ${IFLAG} gets the include option to be used with the compiler
#
#Varibale ${SOURCE} gets the source path 
#Variable ${INCLUDE} gets the include path
#Variable ${OBJEC} gets the object path
#Variable ${BINARY} gets the binary path
#Variable ${TEST} gets the test path
#
CC = g++
WFLAG = -Wall
CFLAG = -c
OFLAG = -o
DFLAG = -ggdb
IFLAG = -I

SOURCE=src
INCLUDE=include
OBJECT=build
BINARY=bin
TEST=test



#Defualt target to build all the executables in both 'bin' and 'test/bin' folders.
#The targets to build all the executables of this project are the dependencies of this default target.
#It builds all the executables by going through this dependencies.
#
all: ${BINARY}/greetingcsci160 ${BINARY}/greetingcsci161 \
	${TEST}/${BINARY}/testgreetingcsci160 ${TEST}/${BINARY}/testgreetingcsci161




#Make target to build 'greetingcsci160' executable in the 'bin' folder.
#Executable 'greetingcsci160' is built by linking 'main.o' and 'greetings_csci160.o' object files of 'build' folder.
#
${BINARY}/greetingcsci160: ${OBJECT}/main.o ${OBJECT}/greetings_csci160.o
	${CC} ${WFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BINARY}/greetingcsci160 \
		${OBJECT}/main.o ${OBJECT}/greetings_csci160.o



#Make target to build 'greetingcsci161' executable in the 'bin' folder.
#Executable 'greetingcsci161' is built by linking 'main.o' and 'greetings_csci161.o' object files of 'build' folder.
#
${BINARY}/greetingcsci161: ${OBJECT}/main.o ${OBJECT}/greetings_csci161.o
	${CC} ${WFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BINARY}/greetingcsci161 \
		${OBJECT}/main.o ${OBJECT}/greetings_csci161.o



#Make target to build 'testgreetingcsci160' executable in the 'test/bin' folder.
#Executable 'testgreetingcsci160' is built by linking 'testgreetings.o' object file of 'test/build' folder and 
#'greetings_csci160.o' object file of 'build' folder.
#
${TEST}/${BINARY}/testgreetingcsci160: ${TEST}/${OBJECT}/testgreetings.o ${OBJECT}/greetings_csci160.o
	${CC} ${WFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} -lboost_unit_test_framework \
		${OFLAG} ${TEST}/${BINARY}/testgreetingcsci160 \
		${TEST}/${OBJECT}/testgreetings.o ${OBJECT}/greetings_csci160.o



#Make target to build 'testgreetingcsci161' executable in the 'test/bin' folder.
#Executable 'testgreetingcsci161' is built by linking 'testgreetings.o' object file of 'test/build' folder and 
#'greetings_csci161.o' object file of 'build' folder.
#
${TEST}/${BINARY}/testgreetingcsci161: ${TEST}/${OBJECT}/testgreetings.o ${OBJECT}/greetings_csci161.o
	${CC} ${WFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} -lboost_unit_test_framework \
		${OFLAG} ${TEST}/${BINARY}/testgreetingcsci161 \
		${TEST}/${OBJECT}/testgreetings.o ${OBJECT}/greetings_csci161.o



#Make target to build 'main.o' object file in 'build' folder from 'main.cpp' file in 'src' folder.
#
${OBJECT}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/greetings.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/main.o ${SOURCE}/main.cpp



#Make target to build 'greatings_csci160.o' object file in 'build' folder from 'greetings_csci160.cpp' file in 'src' folder.
#
${OBJECT}/greetings_csci160.o: ${SOURCE}/greetings_csci160.cpp ${INCLUDE}/greetings.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/greetings_csci160.o \
		${SOURCE}/greetings_csci160.cpp



#Make target to build 'greatings_csci161.o' object file in 'build' folder from 'greetings_csci161.cpp' file in 'src' folder.
#
${OBJECT}/greetings_csci161.o: ${SOURCE}/greetings_csci161.cpp ${INCLUDE}/greetings.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECT}/greetings_csci161.o \
		${SOURCE}/greetings_csci161.cpp



#Make target to build 'testgreatings.o' object file in 'test/build' folder from 'testgreetings.cpp' file in 'test/src' folder.
#
${TEST}/${OBJECT}/testgreetings.o: ${TEST}/${SOURCE}/testgreetings.cpp ${INCLUDE}/greetings.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${TEST}/${OBJECT}/testgreetings.o \
		${TEST}/${SOURCE}/testgreetings.cpp



#Declaring all the phony targets to inform Make that these targets are not file.
#Phony targets are always executed. They are not file, i.e., no semantics of being up to date. 
#
.PHONY: clean run run-greeting-csci160 run-greeting-csci161 test test-greeting-csci160 test-greeting-csci161



#Target to remove all the object and executable files from all 'bin' and 'build' folders.
#There are two 'bin' folders in this project 'bin' and 'test/bin'.
#There are two 'build' folders in this project 'build' and 'test/build'.
#
clean:
	rm -rf ${OBJECT}/* 
	rm -rf ${BINARY}/* 
	rm -rf ${TEST}/${OBJECT}/* 
	rm -rf ${TEST}/${BINARY}/*



#Target to run 'greetingcsci160' executable from 'bin' folder.
#
run-greeting-csci160: ${BINARY}/greetingcsci160
	${BINARY}/greetingcsci160



#Target to run 'greetingcsci161' executable from 'bin' folder.
#
run-greeting-csci161: ${BINARY}/greetingcsci161
	${BINARY}/greetingcsci161



#Target to run both 'greetingcsci160' and 'greetingcsci161' executables from 'bin' folder one after another 
#
run: run-greeting-csci160 run-greeting-csci161 



#Target to test 'greetings_csci160.cpp' code of 'src' folder by running 'testgreetingcsci160' test executable 
#from 'test/bin' folder
#
test-greeting-csci160: ${TEST}/${BINARY}/testgreetingcsci160
	${TEST}/${BINARY}/testgreetingcsci160 --log_level=all



#Target to test 'greetings_csci161.cpp' code of 'src' folder by running 'testgreetingcsci161' test executable 
#from 'test/bin' folder
#
test-greeting-csci161: ${TEST}/${BINARY}/testgreetingcsci161
	${TEST}/${BINARY}/testgreetingcsci161 --log_level=all



#Target to test both 'greetings_csci160.cpp' and 'greetings_csci161.cpp' codes of 'src' folder by running 
#'testgreetingcsci160' and 'testgreetingscsci161' test executables from 'test/bin' folder one after another
#
test: test-greeting-csci160 test-greeting-csci161

