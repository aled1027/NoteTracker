
CXX = g++
CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

# directories containing headers
# for some reason this needs to be the full path?
INCLUDES = -I/home/alex/Dropbox/programming/n-copy/source
SRCS =	Note.cpp Logger.cpp Database.cpp Interface.cpp noteTracker.cpp 
LIBS = -Wno-write-strings -lsqlite3
OBJS =	$(SRCS:.cpp=.o) 
MAIN = 	noteTracker

all:	$(MAIN)  clean 

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@ 

$(MAIN): $(OBJS)
	$(CXX) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

clean:
	-mv *.o objs

# I think this should also have makedepend, but I couldn't get that to work. 

# Some notes
# things to consider adding:
#	Execpath
#	Incpath
# 	Objpath
# $@ gets the name of current target
