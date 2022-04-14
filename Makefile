main : main.o
	g++ -o main v1.0.cpp inOut.o generate.o rezCalc.o validation.o
main.o :
	g++ -c cppFiles/*.cpp 
clean :
	del main.exe *.o

# mingw32-make