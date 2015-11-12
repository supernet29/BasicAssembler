
tester.out : tester.o StringControlTools.o DisjunctInstruction.o InstructionReader.o BinaryInstruction.o InstructionParser.o LabelCode.o MRI.o NonMRI.o
	g++ -o tester.out tester.o StringControlTools.o DisjunctInstruction.o InstructionReader.o BinaryInstruction.o InstructionParser.o LabelCode.o MRI.o NonMRI.o

tester.o : StringControlTools.h DisjunctInstruction.h InstructionReader.h tester.cpp BinaryInstruction.h InstructionParser.h MRI.h NonMRI.h
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

MRI.o : LabelCode.h MRI.h MRI.cpp
	g++ -c MRI.cpp

NonMRI.o : LabelCode.h NonMRI.h NonMRI.cpp
	g++ -c NonMRI.cpp

clean :
	rm *.o tester.out
