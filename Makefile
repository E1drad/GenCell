CC=g++
CFLAGS=-c -Wall -Wextra -std=c++11
LDFLAGS=
SOURCES=Apparence.cpp Carte.cpp Cellule.cpp Entite.cpp Systeme.cpp Main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=GenCell
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.o	
