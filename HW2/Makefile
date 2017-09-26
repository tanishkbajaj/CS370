# List of files
C_SRCS = Vowels.c Consonants.c Initiator.c Other.c
C_OBJS = Vowels.o Consonants.o Initiator.o Other.o
#C_HEADERS
OBJS = ${C_OBJS}
EXE = Vowels
EXE2 = Consonants
EXE3 = Initiator
EXE4 = Other
#Compiler and loader commands and flags
GCC = gcc
GCC_FLAGS = -g -std=c11 -Wall -c -I.
LD_FLAGS = -g -std=c11 -Wall -I.
#Compile .c files to .o files
.c.o:
	$(GCC) $(GCC_FLAGS) $<
#Target is the executable
all: Vowels Consonants Other Initiator
Vowels: Vowels.o
	$(GCC) $(LD_FLAGS) Vowels.o -o $(EXE)
Consonants: Consonants.o
	$(GCC) $(LD_FLAGS) Consonants.o -o $(EXE2)
Other: Other.o
	$(GCC) $(LD_FLAGS) Other.o -o $(EXE4)
Initiator: Initiator.o
	$(GCC) $(LD_FLAGS) Initiator.o -o $(EXE3)
#Recompile C objects if headers change
$(C_OBJS): ${C_HEADERS}
#Clean up the directory
clean:
	rm -f *.o *~ $(EXE) $(EXE2) $(EXE3) $(EXE4)
