CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -Wno-conversion-null -Wno-deprecated-declarations -I../include -I/home/giuseppe/Desktop/condivisa/Polimi/Corsi_Dottorato/PACS/pacs-examples/Extras/json/include


SRCS= $(wildcard *.cpp)
OBJS= $(SRCS:.cpp=.o)
EXEC= main
.phony= clean 
.DEFAULT_GOAL = all
all: $(EXEC)

$(OBJS): $(SRCS) 
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $(SRCS)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

clean:
	$(RM) *.o
