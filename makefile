#target: dependencies
#	rule to build
#
# Work cited: https://askubuntu.com/questions/433943/how-to-clean-executable-using-make-clean
# 	      https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

CXX = g++

CXXFLAGS = -std=c++0x

CXXFLAGS += -g
CXXFLAGS += -Wall 

#CXXFLAGS += -O3
#CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time

OBJS = antMain.o ant.o antBoard.o antMenu.o antValidate.o
SRCS = antMain.cpp ant.cpp antBoard.cpp antMenu.cpp antValidate.cpp
HEADERS = antMain.cpp ant.cpp antBoard.cpp antMenu.cpp antValidate.cpp

antMain: ${OBJS}
	${CXX} ${CXXFLAGS} -o antMain antMain.o ant.o antBoard.o antMenu.o antValidate.o

antMain.o: antMain.cpp ${HEADERS}
	 ${CXX} ${CXXFLAGS} -c antMain.cpp

ant.o: ant.hpp

antBoard.o: antBoard.hpp

antMenu.o: antMenu.hpp

antValidate.o: antValidate.hpp

clean: ${OBJS}
	-rm *.o ${OBJS} antMain
