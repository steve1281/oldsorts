========================================================================
    CONSOLE APPLICATION : Sorts Project Overview
========================================================================

  My notes:

  Back in 1989 I did a demo program, written in K&R C, for showing sorts...
  Recently (Feb 2017) I stumbled on the sources, and got them working again
  in visual studio 2015 C++. The original code would have been designed to
  compile on a VAX 11/750 and an EGA capable IBM PC 286.

  If you look at the source for the sorts, past me referred to text books where the
  sorts came from; my C book, Algorithms book, an old Pascal book, etc. Keep in mind
  that 1989 predated (my) access to the internet... so books!
    Algorithms - Algorithms, 2nd Edition by Sedgewick, Robert
    Data Structures Using Pascal, 2nd Edition,  Aaron M. Tenenbaum, Moshe J. Augenstein.
    The C programming Language 2nd Edition, Dennis Ritchie
    The C programming Language 1st Edition, B.W. Kernighan, D.M. Ritchie (odd that I used both)
    Also, the VT100 User Guide :-)
  
  Oh, you will need to set, in your project->properties->preprocessor:
  _CRT_SECURE_NO_WARNINGS
  
  Or its going to complain. The rest of the twiddling is captures in headers and three new method
  calls.
  
  (If you see Escape codes on the screen means you are not supporting vt100 emulation;
  this code requires win10.)
  
  So what happens is, you will be asked for a sample size, whether we should read the data
  from a file or generate it on the fly.  You will then get a menu with three basic options:
  1-7 demo a sort, 8 - display the numbers in the sample, and 9 just display the sample.
  


-------------------------------------------------------------------------------
M$ notes:

AppWizard has created this Sorts application for you.

This file contains a summary of what you will find in each of the files that
make up your Sorts application.


Sorts.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

Sorts.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Sorts.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Sorts.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
