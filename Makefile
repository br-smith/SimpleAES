CXX	= g++ -std=c++11
CXXFLAGS	= -g -Wall
OBJS		= SimplifiedAES.o KeyExpansion.o Word.o Key.o
KEY		= KeyExpansion.o Word.o Key.o
AES		= SimplifiedAES.o Word.o Key.o
KEYPROG		= KeyExpan
AESPROG		= AESMain
PROG		= SimpleAES

all:	$(PROG)

$(PROG):	$(OBJS)
	$(CXX) -o $(PROG) $(OBJS)

key: 		$(KEY)
	$(CXX) -o $(KEYPROG) $(KEY)

aes:		$(AES)
	$(CXX) -o $(AESPROG) $(AES)

clean:	$(RM) -f $(PROG) core *.o
