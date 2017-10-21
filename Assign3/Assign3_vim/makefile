#Author: Molly Arwoood
#Date: 7-12-16
#Description; makefile for LabAbMain.cpp 

CXX =g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -g

SOURCES = CreatureMain.cpp HarryPotter.cpp BlueMen.cpp Gollum.cpp Medusa.cpp ReptilePeople.cpp Creature.cpp DiceAssign3Mod.cpp
OBJECTS = ${SOURCES:.cpp = .o}
EXECUTABLE = CreatureMain

all: ${SOURCES} ${EXECUTABLE}

${EXECUTABLE}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@

.cpp.o:
	${CXX} ${CXXFLAGS} $< -o $@

clean: 
	rm -f *.o Creature HarryPotter BlueMen Gollum ReptilePeople Medusa DiceAssign3Mod
