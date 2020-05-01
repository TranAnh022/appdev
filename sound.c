#include <stdio.h>
#include "sound.h"
#include <math.h>
#include "screen.h"
#include "comm.h"
// function definitions
WAVheader readwavhdr(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1,fp);
	return myh;
}

void displaywavhdr(WAVheader h){
	for(int i =0;i<4;i++)
		printf("%c",h.chunkID[i]);
	printf("\n");
	printf("Chunk size: %d\n",h.chunkSize);
	printf("Number of channels: %d\n", h.numChannels);
	printf("Sample rate: %d\n",h.sampleRate);
	printf("Block align: %d\n",h.BlockAlign);
	printf("Bits per sample: %d\n", h.bitsPerSample);
	// -- to be continued
	double duration;
	duration =(double) h.subchunk2Size/h.byteRate;
	printf("Duration: %f seconds\n", duration);

}
void wavdata(WAVheader h, FILE *fp){
	// in this function we will read sound sample from the opened file
	// the sample are calculated into decubel value using Root Mean Square
	// (RMS) formula. We will display a 5-sec recorded sound into bar chart
	// our sound file users samples rateof 16000,for 5 seconds, there are
	// 5*16000= 80000 samples, we want to display them into 160 bars
	int peaks=0, flag=0;
	double max = 0.0;
	short samples[500];		// to read 500 samples from wav file
	for(int i=0; i<160;i++){
		fread(samples, sizeof(samples),1,fp);
		double sum = 0.0;
		for(int j=0; j <500;j++){
			sum = sum +samples[j]*samples[j];
		}
		double re = sqrt(sum/500);

#ifdef SDEBUG
		printf("db[%d] = %f\n",i+1,20*log10(re));
#else
		//displaybar for re value
		if(20*log10(re) >60){
			setfgcolor(RED);
			if(flag==0){
				flag=1;
				peaks++;
			}
		}
		else{
			setfgcolor(WHITE);
			flag =0;
		}
		drawbar(i+1,(int)20*log10(re)/3);
		//drawbar(i+1,(int) 20*log10(re)/3));

#endif
	if(20*log10(re)>max){
		max = 20*log10(re);
}
}
	// display sampel rate, duration no
	gotoXY(1,1); printf("Sample Rate: %d\n",h.sampleRate);
	gotoXY(1,75);printf("Duration: %f s\n",(float)h.subchunk2Size/h.byteRate);
	gotoXY(1,150); printf("Peaks: %d\n",peaks);
	char postdata[100];
	sprintf(postdata, "peaks=%d&max=%f\n",peaks,max);
	sendpost(URL, postdata);

}
