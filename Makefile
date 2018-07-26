CXX	= g++ -std=c++11
CXXFLAGS	= -g -Wall
OBJS		= KeyExpansion.o Word.o Key.o
PROG		= SimpleAES

all:	$(PROG)

$(PROG):	$(OBJS)
	$(CXX) -o $(PROG) $(OBJS)

clean:;	$(RM) -f $(PROG) core *.o
