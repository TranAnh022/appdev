#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"
#include "sound.h"

int main(void){
	Position cur = getscreensize();	// get screensize
	char postdata[100];
	sprintf(postdata, "row=%d&col=%d&id=e1900305",cur.row,cur.col);
	sendpost(URL, postdata);
	gotoXY(1,1);
	printf("Screen size :row=%d, col=%d\n",cur.row, cur.col);

	printf("Press any key to continue\n");
	getchar();	//wait for the user to press a key
	getchar();

	int ff,bb ;
	float step = (float)cur.col/cur.row;
	for(int i=1; i<=cur.row;i++){
		ff =(i+1)%8+BLACK;
		bb =(i+2)%8+BLACK;
		setcolors(ff,bg(bb));
		clearscreen();
		drawrect(10,10,5,30);
		gotoXY(cur.row-i, (i-1)*step+1);
		printf("HELLO\n");
		usleep(250000);
	}
/*	for(int i =0;i <20 ; i++){
		setcolors(RED, GREEN);
		clearscreen();
		gotoXY(1,4*i);
		printf("HELLO\n");
		//sleep(1);
		usleep(500000);
}
	for( int i=1;i<10;i++){
		setcolors(RED,GREEN);
		clearscreen();
		gotoXY(2*i,76);
		printf("HELLO\n");
		usleep(500000);
			}
	for( int i =19; i>0;i--){
		setcolors(RED,GREEN);
		clearscreen();
		gotoXY(18,4*i);
		printf("HELLO\n");
		usleep(500000);
}
	for(int  i = 9;i>=0;i--){
		setcolors(RED,GREEN);
		clearscreen();
		gotoXY(2*i,1);
		printf("HELLO\n");
		usleep(500000);
}

*/

/*	for(int i=0;i <=10 ;i++){
		clearscreen();
		setcolors(GREEN,BLACK);
		gotoXY(25-i*2.5,4*i);
		printf("HELLO\n");

		setcolors(RED,BLACK);
		gotoXY(i*2.5,4*i);
		drawbox();
		usleep(500000);

}
	for(int i=0 ; i<=10; i++){
		clearscreen();
		setcolors(GREEN,BLACK);
		clearscreen();
		gotoXY(i*2.5,4*i+40);
		printf("HELLO\n");

		setcolors(RED,BLACK);
		gotoXY(25-i*2.5,4*i+40);
		drawbox();
		usleep(500000);


}
/*
//	printf("The following message will be BLUE"
	setfgcolor(BLUE);
	gotoXY(14,35);
	printf("e1900305\n");
	getchar();	//wait for the user to press a key
	drawbar(30,30);
	drawbar(50,30);

*/
	getchar();	//after drawing bars,wait for a key
	resetcolors();
	clearscreen();
	printf("this text is displayed in default color \n");
	getchar();
	FILE *fp= fopen("test.wav", "r");	//open the wav file in read-only
	WAVheader h =readwavhdr(fp);
	fclose(fp);
	displaywavhdr(h);
}

