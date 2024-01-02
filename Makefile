# Fichiers a compiler
CFILES = main.c
# Parametres compilateur
CFLAGS = -Wall -Wextra -g
# Nom de l'executable
BINFILE = sae101

# Instructions de compilation
$(BINFILE): $(CFILES)
    $(CC) $(CFLAGS) $(CFILES) -o $(BINFILE)

# Instructions de compilation statique
.PHONY: static
static: $(CFILES)
    $(CC) -static $(CFLAGS) $(CFILES) -o $(BINFILE)

# Instructions pour enlever les fichiers compiles
.PHONY: clean run
clean:
    rm $(BINFILE)

# Instructions pour executer le programme
run: $(BINFILE)
    ./$(BINFILE)
