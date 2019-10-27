# Defend Your Code
**Team members:** Mathew Jett, Hung Auduong<br>
**Shortcomings:** None that we could think of.<br>

**Email:** 	hauduong@eagles.ewu.edu, matthew.jett@eagles.ewu.edu

### Part 1:
    Part one is written in .Net Core and should be able to run on all platform.
    Run the code on visual studio.
    If there are any errors in the input, it'll output the error with the 
    exception explanation and reprompt the user to input starting from the last
    checkpoint.
    checkpoints:
        name
        number
        file input
        password

### Part 2:
    Part 2 is written in C with linux environment
    
    gcc (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
    Copyright (C) 2015 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    To run the code, make sure you're current directory is where the source code lies.
    then run a make. that should compile and run the code.
    if ./main cant run due to permission issue, delete the executable
    in the source folder then run make again. this should create a new
    executable and be able to run the code.

We designed our code to hold of on writing reading and writing
until the end so that user cant manually open the file and try to change
the integrity, since we figured it should be the most updated version
of the file. This is the same for both C# and C implementation.
