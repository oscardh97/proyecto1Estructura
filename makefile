main: main.o adtlist.o fsarraylist.o varraylist.o object.o student.o
	g++  main.o fsarraylist.o varraylist.o object.o student.o adtlist.o -o proyecto
	
main.o:	main.cpp adtlist.o fsarraylist.h
	g++ -c main.cpp

fsarraylist.o:	fsarraylist.cpp fsarraylist.h
	g++ -c fsarraylist.cpp

varraylist.o:	varraylist.cpp fsarraylist.h varraylist.h
	g++ -c varraylist.cpp

object.o:	object.cpp fsarraylist.h object.h
	g++ -c object.cpp

student.o:	student.cpp fsarraylist.h student.h object.h
	g++ -c student.cpp

adtlist.o:	adtlist.cpp adtlist.h fsarraylist.h
	g++ -c adtlist.cpp