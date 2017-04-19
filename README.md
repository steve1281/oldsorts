# oldsorts

##  Overview/History

  Back in 1989 I did a demo program, written in K&R C, for showing sorts...
  Recently (Feb 2017) I stumbled on the sources, and got them working again
  in visual studio 2015 C++. The original code would have been designed to
  compile on a VAX 11/750 and an EGA capable IBM PC 286. This code works on
  PC with windows 10.

## References (sort of)
  If you look at the source for the sorts, past me referred to text books where the
  sorts came from; my C book, Algorithms book, an old Pascal book, etc. Keep in mind
  that 1989 predated (my) access to the internet... so books!
  
  * Algorithms - Algorithms, 2nd Edition by Sedgewick, Robert
  * Data Structures Using Pascal, 2nd Edition,  Aaron M. Tenenbaum, Moshe J. Augenstein.
  * The C programming Language 2nd Edition, Dennis Ritchie
  * The C programming Language 1st Edition, B.W. Kernighan, D.M. Ritchie (odd that I used both)
  * The VT100 User Guide

## Setup 
You will need to set, in your project->properties->preprocessor:
    _CRT_SECURE_NO_WARNINGS
Or its going to complain. The rest of the twiddling is captures in headers and three new method calls.
(If you see Escape codes on the screen means you are not supporting vt100 emulation; this code requires win10.)

## Usage
You will be asked for a sample size, whether we should read the data from a file or generate it on the fly.  You will then get a menu   with three basic options:  1-7 demo a sort, 8 - display the numbers in the sample, and 9 just display the sample.
