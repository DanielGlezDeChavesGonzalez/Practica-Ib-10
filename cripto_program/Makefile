CC = g++           # The C++ compiler command
CFLAGS = -Wall     # The C++ compiler options 

cripto_program: cripto.o funciones_cripto.o 
		$(CC) -o cripto cripto.o funciones_cripto.o

# The clean target removes all of the executable files
# and object files produced by the build process
clean:
	rm -f *.o
	rm -f cripto