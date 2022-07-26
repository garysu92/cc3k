CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = program
OBJECTS = main.o floor.o Entities/playablecharacter.o Cells/space.o Cells/door.o Cells/cell.o Cells/tile.o Cells/wall.o Cells/stair.o Cells/passage.o Enemies/goblin.o Enemies/dragon.o Enemies/merchant.o Enemies/phoenix.o Enemies/troll.o Enemies/vampire.o Enemies/werewolf.o Entities/enemy.o Potions/potion.o Potions/ba.o Potions/bd.o Potions/ph.o Potions/rh.o Potions/wa.o Potions/wd.o Treasure/smallgold.o Treasure/normalgold.o Treasure/dragongold.o Treasure/treasure.o TempEffects/woundattack.o TempEffects/wounddefense.o TempEffects/boostattack.o TempEffects/boostdefense.o TempEffects/tempeffect.o Display/mapDisplay.o cc3kgamerunner.o dungeon.o Races/dwarf.o Races/elf.o Races/human.o Races/orc.o randnum.o Display/actionDisplay.o Races/developerop.o Races/developerup.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
