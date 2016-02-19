#!/bin/bash
#
#This script formats the code in the src/ subdirectory according
#to the google c++ coding style guide.
#In order to be able to execute this script successfully you should have astyle
#installed on your machine.
#
#Under Ubuntu you can get astyle with the following command:
#
#    sudo apt-get install astyle
#
#
#Author:Johannes Werner

AFLAGS="-t -v -r -xC100 -A14"

#format all .cc files
printf "\nFormatting all *.cc files...\n\n"
astyle ${AFLAGS} "src/*.cpp" 
astyle ${AFLAGS} "test/*.cpp" 


#format all header files
printf "\n\nFormatting all header files...\n\n"
astyle ${AFLAGS} "src/*.h" 
astyle ${AFLAGS} "test/*.h" 

#delete all *.orig files created by astyle
printf "\n\nDeleting all temporary files...\n"
find src/ -name '*.orig' -delete
printf "Done.\n"
