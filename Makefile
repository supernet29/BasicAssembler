
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

BinaryInstruction.o : BinaryInstruction.h BinaryInstruction.cpp
	g++ -c BinaryInstruction.cpp

InstructionParser.o : DisjunctInstruction.h LabelCode.h StringControlTools.h BinaryInstruction.h InstructionParser.h InstructionParser.cpp
	g++ -c InstructionParser.cpp

LabelCode.o : LabelCode.h LabelCode.cpp
	g++ -c LabelCode.cpp

clean :
	rm *.o tester.out
