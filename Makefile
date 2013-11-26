pro2.exe: pro2.o revista.o biblioteca.o estructura.o
	g++ -o pro2.exe pro2.o revista.o biblioteca.o estructura.o
pro2.o: pro2.cpp
	g++ -c pro2.cpp -D_GLIBCXX_DEBUG
revista.o: revista.cpp revista.hpp
	g++ -c revista.cpp -D_GLIBCXX_DEBUG
biblioteca.o: biblioteca.cpp biblioteca.hpp revista.o
	g++ -c biblioteca.cpp -D_GLIBCXX_DEBUG
estructura.o: estructura.cpp  estructura.hpp
	g++ -c estructura.cpp -D_GLIBCXX_DEBUG

clean: 
	rm *.o
	rm *.exe
