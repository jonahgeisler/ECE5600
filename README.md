# Sample Code Structure

- example.cpp is an example executable file with the main function, which can be used as a basis in Project 1 and 2.

- framio.cpp (frameio.h) and framio2.cpp (frameio2.h) define the same class frameio. They are kind of redundant. However, frameio files have more explanations, while framio2 files are more advanced. Here, we use frameio2 in all projects. But you can check frameio files for a detailed explanation.

- util.cpp is a helper file with multiple help functions.

- chksum.cpp can help in Project 3 for IP packet checksum calculation.

- tcp_test.cpp can be used in Project 4 for the TCP socket server side.

# Compiling Code

Compiling the code should be simple. CMake is used under the hood, but is wrapped with a Makefile.  To compile your code, run make in the root directory.  This will also compile the example executables.

     make

To do a clean build run:

    make clean

# Submitting code

There is a target created for help submitting lab assignments. The target is called "submission."  There are also two variables that will help.  They are NAME and NUMBER.  Set NAME to your last name and, if you have a lab partner, your artner's last name (i.e curtis_lloyd or lloyd).  Set NUMBER to the number of the lab assignment.  First lab is 0. Save the variables in your bashrc or set them each time you run the submission target.

    NAME=curtis_lloyd NUMBER=0 make submission

This will copy your executable "stack" to the artifact directory.  It will also create a tar file (curtis_lloyd_lab0.tar.gz) that can be submitted to Canvas.
