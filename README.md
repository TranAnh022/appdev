#appdev for I-IT-1N1&2
----------------------------------------------------------------------------
-----------------------Application Development 2020-------------------------
----------------------------------------------------------------------------

This projects is made in course "Application Development 2020' for us to
understand what tools and measures will be used in an software application
development. 

List of Contents
1. Configuration instructions
2. Installation instructions
3. Operating instructions
4. File manifest.
5. Copyright and Licensing information
6. Contact information
7. Credits and acknowlegedements

1. Configuration instructions
	In  this section we would give users information of how to confiuge
	the operating symtem, software enviroment, libaries, ect. to run
	this application :
		Firstly, we need to create new folders name "appdev" and "public".Then,Finding 
		the sound file and convert it into .wav file.Finally,Download the sound file 
		that you just converted into the "appdev" folder.


2. Installation instructions
	In this section we should give users information of how to install this
	application , what files not includes in this package should be added.
	what command/operation should be used to install this application.
		Fllowing the order below: 
			1.Download the source code of the application from https://github.com/TranAnh022/appdev. 
			2.Open "Download" folder and copy the ZIP file(appdev-master) then paste to the 
			 "appdev" folder
			3.Open the "appdev" folder and extract the ZIP file(include 13 files).
			4.Move the "2.php" file to the "public" folder.
			5.We should make sure that the "appdev" file should be contained .wav file
			 and 11 source code files  
3. Operating instructions
	In this section we should give users information of how to run this 
	application, e.g, what command-line arguments can be given and what
	do they mean.
		Fllowing the order below:
			1.Open command window
			2.Type your user's name and password to enter the server
			3.Typing the command "cd appdev" to go to application file.
			4.Then using command "make" to compile all ".c" files to ".o" files. The 
			 screen should show five ".o" files and one "sound" file
			5.Using the command "./sound" to excute the application
			6.The sound wave indicates in the screen and displayed 
			 with its data on the top of the screen.
4. File manifest
	We should list all the files of this application at heare with short 
	descriptions.
	
	List of files:
	READEME.md		this file.
	screen.c		contains screen manipulation functions
	screen.h		contains sonstant definitions and function declarations of	
					screen.c
	testcrul.c		contains main function to implement curl
	testscreen.c	contains main function to run animation on screen
	comm.c			contains function for client-server communication
	comm.h			contains function declaration used in comm.c
	makefile		contains linking rule, compiling rule, cleaning rule and 
					archiving rule use; used to compile .c file into .o files
					for execution

5 Copyright
	This application follow GPLv2 copyright.
