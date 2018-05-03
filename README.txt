Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 5: Building a Database with BSTs


Source Files:

MainSimulation.cpp
SimulateDatabase.cpp
BST.cpp
tree_node.cpp
Person.cpp
Student.cpp
Faculty.cpp
GenStack.cpp



Notes:


When entering ID #s, do not enter any number outside the integer limit. Please stick to the given boundaries. Most any integers will work, but ones outside the integer storage limit ~ +-2billion will sometimes cause infinite loops.


When [12] is called, the student is left without an advisor. But I am going to implement it so the advisor's successor becomes the student's new advisor (I asked my classmate Murphy about this problem and she said Rene recommended this idea).
If the student's advisor does not have a successor, I set the student's advisor to 0 and print a message to add an advisor. (call 11)


References Used:


Creating substring from a string:
https://stackoverflow.com/questions/10532384/how-to-remove-a-particular-substring-from-a-string

http://www.cplusplus.com/reference/string/string/erase/


Working with Vectors:
http://www.cplusplus.com/reference/vector/vector/clear/

https://stackoverflow.com/questions/5607589/right-way-to-split-an-stdstring-into-a-vectorstring


Stringstreams:
http://www.cplusplus.com/reference/sstream/stringstream/stringstream/

https://stackoverflow.com/questions/19223360/implicit-instantiation-of-undefined-template-stdbasic-stringchar-stdchar



Running the Project:


1. Unzip submitted compression file
2. Make sure any files you want to use as input are placed in the unzipped directory
3. Navigate to this directory containing the Makefile, all source and header files, and your input file
4. While in the directory with Makefile, type ‘make’ as a terminal command
5. Run the newly made executable DatabaseBST with your input file as the command line argument


