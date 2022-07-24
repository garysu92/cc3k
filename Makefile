CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = program
OBJECTS = main.o floor.o Entities/playablecharacter.o Races/human.o Cells/space.o Cells/door.o Cells/cell.o Cells/tile.o Cells/wall.o Cells/stair.o Cells/passage.o Enemies/goblin.o Enemies/dragon.o Enemies/merchant.o Enemies/phoenix.o Enemies/troll.o Enemies/vampire.o Enemies/werewolf.o Entities/enemy.o Potions/potion.o Treasure/smallgold.o Treasure/normalgold.o Treasure/dragongold.o Treasure/treasure.o TempEffects/woundattack.o Potions/wounddefense.o TempEffects/boostattack.o TempEffects/boostdefense.o TempEffects/tempeffect.o Display/mapDisplay.o cc3kgamerunner.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
