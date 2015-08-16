all: nocsd-gtk-module.c
	gcc $(shell pkg-config --cflags --libs gtk+-3.0) -std=gnu11 -fPIC -shared nocsd-gtk-module.c -o nocsd-gtk-module.so
