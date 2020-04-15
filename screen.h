// Usually in the header file, following information are included
// 1. function declarations
// 2. constant definitions
// 3. conditional compilation( will be discussed later)

// constant definitions

#define ESC 0x1B
//#define BLACK 30, instead of using #define , it's better to use enumeration

enum FG{BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10)	// this is called macro definition

#define UNICODE		//for conditional compilation
#define BAR "\u2590"
#define BOX "\u2588"

//#define DEBUG 		// for conditional compilation

typedef struct{		// this struct will define a compound data,which consists of
	int row;		// the number of rows and the number of columns of our screen
	int col;
}Position;


// function declarations
void clearscreen(void);
void setbgcolor(int);
void setfgcolor(int);
void setcolors(int , int);
void resetcolors(void);
void gotoXY(int ,int);
void drawbar(int,int);
void drawbox(void);
void drawrect(int ,int ,int ,int);
Position getscreensize(void);
