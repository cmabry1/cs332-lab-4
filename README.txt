This code will take two different files, check if they are different, and append the second file to the first. leaving the second file unchanged
To compile the program, run the following command:
make sure that the makefile is in the same repository
gcc -Wall -o readfile readfile.c 

To run the file make sure to use the command:
./readfile file1 file2

Where file1 is the file to which the contents of the file2 can be appended:

type this in the terminal before using the code to create the files needed for the code to append:
echo "Hello World! This is file one!" > file1
echo "Hello World! This is file two!" > file2
./readfile file1 file2 
cat file 1 #this is to read the appended version of file 1

This code will read file1 as with;
"Hello World! This is file one!" 
"Hello World! This is file two"


