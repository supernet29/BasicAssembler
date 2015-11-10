
tester : tester.o StringControlTools.o DisjunctInstruction.o InstructionReader.o
	g++ -o tester.out tester.o StringControlTools.o DisjunctInstruction.o InstructionReader.o

tester.o : StringControlTools.h DisjunctInstruction.h InstructionReader.h tester.cpp
	g++ -c tester.cpp

StringControlTools.o : StringControlTools.h StringControlTools.cpp
	g++ -c StringControlTools.cpp

DisjunctInstruction.o : DisjunctInstruction.h DisjunctInstruction.cpp
	g++ -c DisjunctInstruction.cpp

InstructionReader.o : DisjunctInstruction.h InstructionReader.h StringControlTools.h InstructionReader.cpp
	g++ -c InstructionReader.cpp

clean :
	rm *.o tester.out
