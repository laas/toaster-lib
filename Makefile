SHELL=/bin/sh
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

CXX=g++
CFLAGS=-O6 -fomit-frame-pointer
CPPFLAGS=-I../include -I/usr/include/ -I/home/gmilliez/devel/boost_1_56_0
LDFLAGS= -L/usr/lib/i386-linux-gnu/ -L/usr/local/lib
RM=/bin/rm -f

############################################################

TARGET=toaster-lib

OBJ = \
./src/Agent.o \
./src/Entity.o \
./src/MovableObject.o \
./src/Robot.o \
./src/Area.o \
./src/Human.o \
./src/Object.o \
./src/StaticObject.o \
./src/CircleArea.o \
./src/Joint.o \
./src/RectangleArea.o \
./test/mainTest.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ $(OBJ) $(LDFLAGS)
#-ldl

############################################################


clean:
	$(RM) $(OBJ)
	$(RM) $(TARGET) 

distclean:
	$(RM) *.o
	$(RM) $(TARGET)


./src/Agent.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) Agent.cpp
./src/Entity.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) Entity.cpp
./src/MovableObject.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) MovableObject.cpp
./src/Robot.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) Robot.cpp
./src/Area.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) Area.cpp
./src/Human.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) Human.cpp
./src/Object.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) Object.cpp
./src/StaticObject.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) StaticObject.cpp
./src/CircleArea.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) CircleArea.cpp
./src/Joint.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) Joint.cpp
./src/RectangleArea.o:
	cd ./src; $(CXX) -c $(CPPFLAGS) RectangleArea.cpp
./test/mainTest.o:
	cd ./test; $(CXX) -c $(CPPFLAGS) mainTest.cpp

