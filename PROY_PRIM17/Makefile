check: check_main.o tab.o game.o rules.o vento.o colores.o
	gcc  -Wall -o check check_main.o tab.o game.o rules.o vento.o colores.o `pkg-config --libs gtk+-2.0 --cflags`

check_main.o: check_main.c
	gcc -c check_main.c `pkg-config --cflags gtk+-2.0`

colores.o: colores.c
	gcc -c colores.c `pkg-config --cflags gtk+-2.0`

tab.o: tab.c
	gcc -c tab.c `pkg-config --cflags gtk+-2.0` 

game.o: game.c
	gcc -c game.c `pkg-config --cflags gtk+-2.0`

rules.o: rules.c
	gcc -c rules.c `pkg-config --cflags gtk+-2.0`

vento.o: vento.c
	gcc -c vento.c `pkg-config --cflags gtk+-2.0`

clean:
	rm *.o
