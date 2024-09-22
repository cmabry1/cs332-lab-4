FILE = readfile

build: $(FILE).c
	# next line compiles with all warnings on, debug info, and links math lib
	gcc -o readfile readfile.c

.PHONY: db
db:
	gdb -tui $(FILE)

run:
	./$(FILE)
