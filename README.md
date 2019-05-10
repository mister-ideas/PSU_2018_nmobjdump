# Subject
The goal of this project is to code a my_nm program with the exact same beahaviour as the nm system command, and an my_objdump program with the exact same behaviour as the objdump -f -s system command. You must handle a variable number of parameters. The display produced MUST be the same as the one on your dump.

The programs must work with the following:
* relocatable files .o & .a
* shared files .so
* executable files

# Forbidden functions
* exec... functions family from the libC

# Building
$ make

# Usage
$ ./my_nm [file_path]


$ ./my_objdump [file_path]

# Mark
**16,66/20**
