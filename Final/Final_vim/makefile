
#Author: Molly Arwood
#Date: 8-6-16
#Class: CS_162_400_SU2016
#FinalProject

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

SOURCES = Apartment.cpp BlueMenYou.cpp Creature.cpp DiceAssign3Mod.cpp FinalMain.cpp House.cpp Lawyer.cpp List.cpp MedusaBoss.cpp Person.cpp ReptilePeople.cpp Retire.cpp School.cpp Space.cpp Work.cpp 
OBJECTS = ${SOURCES:.cpp = .o}
EXECUTABLES = FinalMain

all:
	${CXX} ${CXXFLAGS} -o $@

${EXECUTABLES}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@

.cpp.o:
	${CXX} ${CXXFLAGS} $< -o $@

clean:
	rm -f *.o Apartment BlueMenYou Creature DiceAssign3Mod FinalMain House Lawyer List MedusaBoss Person ReptilePeople Retire School Space Work
