#need all: or else it would only build test1.x

all: idtest1.x idtest2.x

idtest1.x: id.o idtest1.o
        g++ -W -Wall -Wextra -I. -otest1.x idtest1.o id.o

idtest2.x: id.o idtest2.o
        g++ -W -Wall -Wextra -I. -otest2.x idtest2.o id.o

idtest1.o: idtest1.cpp
        g++ -c -W -Wall -Wextra -I. idtest1.cpp

idtest2.o: idtest2.cpp
        g++ -c -W -Wall -Wextra -I. idtest2.cpp

id.o: id.h id.cpp
        g++ -c -W -Wall -Wextra -I. id.cpp
