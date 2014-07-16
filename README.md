Shape-Creator
=============

Based on instructions given in .txt file shapes are drawn on console.


Written by: Shannon Simpson

The program will first ask for the file name that will be read in as input. Once the program reads in the file, 
it will parse the commands from this file.

The program will generate a two-dimensional vector of characters based on the commands.
The program will then output the vector to the console and repeat for the duration of the file.

Input to the program will consist of raw text in a series of words, numbers, or symbols. 

The commands used will be:
# rows – Generate the two-dimensional vector with the specified number of rows 
          (note that “#” will be replaced with an integer)
          
# columns – Generate the two-dimensional vector with the specified number of columns 
          (note that “#” will be replaced with an integer)
          
all c – Use the specified character (“c” will be replaced with a non-space, non-numeric character) 
        to build the multi-dimensional vector. 
        If this command is not issued in the sequence for one output, assume the “*” character.
        
triangular – build the two-dimensional vector in a triangular style; 
            each row will have a number of columns equal to its ordinal position in the vector 
            (note! The first row should have one column, not zero!)
            
outer – Any interior character in the multi-dimensional vector 
      (i.e., one not on an edge of the rectangle or triangle “drawn” by outputting the characters) 
      is a space. Note – this part is likely to be the most difficult to implement logically.
alphabetical – Build the vectors with the first drawn character “A”, and go down the alphabet from there.

go – Using the instructions given, build the multi-dimensional vector and write it out to the screen.
