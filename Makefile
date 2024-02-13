

main.o: main.cpp Course.h readFile.h
	g++ -c main.cpp

Course.o: Course.cpp Course.h
	g++ -c Course.cpp

readFile.o: readFile.cpp readFile.h Course.h
	g++ -c readFile.cpp

gpa: main.o Course.o readFile.o 
	g++ -o gpa main.o Course.o readFile.o

test: gpa
	./gpa sample.txt

clean:
	rm -rf *.o gpa