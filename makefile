CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
#List of dependencies...
OBJS =	Logger.o Note.o Interface.o main.o
LIBS = -Wno-write-strings
TARGET =		main
$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)
all:	$(TARGET)
clean:
		rm -f $(OBJS) $(TARGET)
run:	$(TARGET)
		./$(TARGET)
