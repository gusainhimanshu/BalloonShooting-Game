#include <allegro.h>
#include <unistd.h>
#include <time.h>

void init();
void deinit();
void balloon_image(int *,int *);
void bow_image(int *, int *);
void arrow_image(int *,int *);
void rond(int *, int, int);
void draw_burst(int *,int *);

BITMAP *start, *instructions, *balloon, *bow, *arrow, *burst, *rnd1, *rnd2, *rnd3, *mesg1, *mesg2, *mesg3, *mesg4, *mesg5;      //creating bitmap pointers for sound
SAMPLE *snd1, *snd2, *rund1, *rund2, *rund3,*mesag1, *mesag2, *mesag3, *mesag4;                                                 //creating sample pointers for sound

int count_arrow=6,burstflag=0,flagarrow=0,flagbow=0;
int xa=20,ya=85,xbw=50,ybw=30,xb=580,yb=400,points=0,chkflag=0,rightflag=0,counter_flag=0;
int main() {
	init();

    start=load_bitmap("start.bmp",NULL);                      //loading start image
    instructions=load_bitmap("instructions.bmp",NULL);        //loading instructions image
    balloon=load_bitmap("balloon.bmp",NULL);                  //loading balloon image
    bow=load_bitmap("bow.bmp",NULL);                          //loading bow image
    burst=load_bitmap("burst.bmp",NULL);                      //loading burst image
    arrow=load_bitmap("arrow.bmp",NULL);                      //loading arrow image
    rnd1=load_bitmap("rnd1.bmp",NULL);                      //loading round1 image
    rnd2=load_bitmap("rnd2.bmp",NULL);                      //loading round2 image
    rnd3=load_bitmap("rnd3.bmp",NULL);                      //loading round3 image
    mesg1=load_bitmap("mesg1.bmp",NULL);                      //loading mesg1 image
    mesg2=load_bitmap("mesg2.bmp",NULL);                      //loading mesg2 image
    mesg3=load_bitmap("mesg3.bmp",NULL);                      //loading mesg3 image
    mesg4=load_bitmap("mesg4.bmp",NULL);                      //loading mesg4 image
    mesg5=load_bitmap("mesg5.bmp",NULL);                      //loading mesg4 image
    snd1=load_sample("snd1.wav");                             //loading snd1 sound
    rund1=load_sample("rund1.wav");                           //loading rund1 sound
    rund2=load_sample("rund2.wav");                           //loading rund2 sound
    rund3=load_sample("rund3.wav");                           //loading rund3 sound
    mesag1=load_sample("mesag1.wav");                         //loading mesag1 sound
    mesag2=load_sample("mesag2.wav");                         //loading mesag2 sound
    mesag3=load_sample("mesag3.wav");                         //loading mesag3 sound
    mesag4=load_sample("mesag4.wav");                         //loading mesag4 sound
    
	
    while (!key[KEY_ESC]) {
		
	   clear_to_color(screen,makecol(0,0,0));                 //clearing the image
       blit(start,screen,0,0,0,0,start->w,start->h);          //displaying start on to screen
       play_sample(snd1,255,128,1000,0);                      //playing sound snd1
       blit(balloon,screen,0,0,0,0,balloon->w,balloon->h);    //displaying balloon on to screen
       blit(balloon,screen,0,0,580,0,balloon->w,balloon->h);  //displaying balloon on to screen
       blit(balloon,screen,0,0,0,280,balloon->w,balloon->h);  //displaying balloon on to screen          
       blit(balloon,screen,0,0,580,280,balloon->w,balloon->h);//displaying balloon on to screen
       blit(arrow,screen,0,0,280,20,arrow->w,arrow->h);       //displaying balloon on to screen
       blit(arrow,screen,0,0,280,300,arrow->w,arrow->h);      //displaying balloon on to screen
       
       readkey();                                             //reading a key
      if(key[KEY_ESC])                                             //if escape key is pressed
       exit(-1);                                                   //exit from program
       clear_to_color(screen,makecol(0,0,0));                 //clearing the screen with black color
       blit(instructions,screen,0,0,0,0,instructions->w,instructions->h);	//displaying instructions
       readkey();                                                         //reading a key
       if(key[KEY_ESC])                                            //if escape key is pressed
       exit(-1);
       clear_to_color(screen,makecol(0,0,0));                 //clearing the screen with black color 
       blit(rnd1,screen,0,0,0,0,rnd1->w,rnd1->h);             //displaying the round1 image on to the screen
       play_sample(rund1,255,128,1000,0);                     //playing the sound rund1
       readkey();                                             //reading a key
       if(key[KEY_ESC])                                             //if escape key is pressed
       exit(-1);
       clear_to_color(screen,makecol(0,0,0));                 //clearing the screen with black color 
       balloon_image(&xb,&yb);                                //calling function balloon
       bow_image(&xbw,&ybw);                                  //calling function bow
       arrow_image(&xa,&ya);                                  //calling function arrow     
       textprintf_ex(screen,font,10,450,makecol(255,0,0),-1,"NUMBER OF BALLOONS LEFT: 10");    //printing the no. of balloons left
       textprintf_ex(screen,font,10,460,makecol(255,0,0),-1,"NUMBER OF ARROWS LEFT: 6");       //printing the no. of arrows left
       
       
       rond(&points,10,1);                                      //calling function rond
       clear_keybuf();                                          //clearing keybuf
       if(points<100)                                         //if points scored is less than 100
       {
                     play_sample(mesag1,255,128,1000,0);                         ////playing the sound mesag1                                     
                     clear_to_color(screen,makecol(0,0,0));                      //clearing the screen to black color
                     blit(mesg1,screen,0,0,0,0,mesg1->w,mesg1->h);          //"YOU NEED SOME PRACTICE"    
                     readkey();                                             //reading a key
                     break;                                                 //EXIT
       }       
       clear_to_color(screen,makecol(0,0,0));                               //clearing the screen to black color
       blit(rnd2,screen,0,0,0,0,rnd2->w,rnd2->h);             //displaying round 2 image on to the screen
       play_sample(rund2,255,128,1000,0);                     //playing the sound rund2
       readkey();                                             //reading a key
       if(key[KEY_ESC])                                             //if escape key is pressed
       exit(-1);                                                    //exit from game
       count_arrow=6;                                               //setting count arrow to 6         
       rond(&points,8,2);                                       //entering round 2
       clear_keybuf();                                          //clearing key buffer
       if(points<200)                                         //if points scored is less than 200
       {
                  clear_to_color(screen,makecol(0,0,0));      //clearing the screen to black color
                  blit(mesg2,screen,0,0,0,0,mesg2->w,mesg2->h);              //WELL PLAYED BETTER LUCK NEXT TIME
                  play_sample(mesag2,255,128,1000,0);                        //playing the sound mesag2
                  readkey();                                                 //reading a key
                   break;                                                     //EXIT
       }
                                                                    
       clear_to_color(screen,makecol(0,0,0));                       //clearing the screen to black color
       blit(rnd3,screen,0,0,0,0,rnd3->w,rnd3->h);                 //displaying round 3 image on to the screen
       play_sample(rund3,255,128,1000,0);                         //playing the sound rund1
       readkey();                                                  //reading a key
       if(key[KEY_ESC])                                            //if escape key is pressed
       exit(-1);                                                   //exit from game
       count_arrow=6;                                               //setting the count of arrow to 6        
       rond(&points,6,3);                                        //entering round 3
       clear_keybuf();                                           //clearing key buffer
       if(points>=320)                                         //if points scored is equal to 320
       {
                    clear_to_color(screen,makecol(0,0,0));     //clearing the key buffer
                    blit(mesg4,screen,0,0,0,0,mesg4->w,mesg4->h);               //GOOD SHOOTING BUT MISSED THIS TIME
                    play_sample(mesag4,255,128,1000,0);                         //playing the sound mesag4
                    readkey();                                                  //reading a key
                    if(key[KEY_ESC])                                            //if escape key is pressed
                    exit(-1);                                                   //exit from the game
                    break;                                                      //EXIT
       }
       else                                 
       {
                    clear_to_color(screen,makecol(0,0,0));                      //clearing the screen to black color
                    blit(mesg3,screen,0,0,0,0,mesg3->w,mesg3->h);               //EXCELLENT                                     
                    play_sample(mesag3,255,128,1000,0);                         //playing the sound mesag3
                    readkey();                                                  //reading a key
                    if(key[KEY_ESC])                                            //if escape key is pressed
                    exit(-1);                                                   //exit from the game
                    break;    
       }
  	}
  	clear_keybuf();                                                             //clearing the key buffer
    blit(mesg5,screen,0,0,0,0,mesg5->w,mesg5->h);               //CREDITS
    readkey();                                                  //reading key
	deinit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}
    
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	destroy_bitmap(start);                        //destroying the start bitmap                    
	destroy_bitmap(instructions);                 //destroying the instructions bitmap
	destroy_bitmap(balloon);                      //destroying the balloon bitmap
	destroy_bitmap(bow);                          //destroying the bow bitmap
	destroy_bitmap(arrow);                        //destroying the arrow bitmap
	destroy_bitmap(burst);                        //destroying the burst bitmap
	destroy_bitmap(rnd1);                         //destroying the rnd1 bitmap
	destroy_bitmap(rnd2);                         //destroying the rnd2 bitmap
	destroy_bitmap(rnd3);                         //destroying the rnd3 bitmap
	destroy_bitmap(mesg1);                        //destroying the mesg1 bitmap
	destroy_bitmap(mesg2);                        //destroying the mesg2 bitmap
	destroy_bitmap(mesg3);                        //destroying the mesg3 bitmap
	destroy_bitmap(mesg4);                        //destroying the mesg4 bitmap
    destroy_bitmap(mesg5);                        //destroying the mesg5 bitmap
	destroy_sample(snd1);                         //destroying the snd1 sample(sound)
	destroy_sample(rund1);                         //destroying the rund1 sample(sound)
	destroy_sample(rund2);                         //destroying the rund2 sample(sound)
	destroy_sample(rund3);                         //destroying the rund3 sample(sound)
	destroy_sample(mesag1);                         //destroying the mesag1 sample(sound)
	destroy_sample(mesag2);                         //destroying the mesag2 sample(sound)
	destroy_sample(mesag3);                         //destroying the mesag3 sample(sound)
	destroy_sample(mesag4
    );                         //destroying the mesag4 sample(sound)
	    /* add other deinitializations here */
}


void balloon_image(int *x,int *y)
{
                   blit(balloon,screen,0,0,*x,*y,balloon->w,balloon->h);         //displaying the balloon on to the screen                                
}
void bow_image(int *x,int *y)
{
                   blit(bow,screen,0,0,*x,*y,bow->w,bow->h);                     //displaying the bow on to the screen
}
void arrow_image(int *x,int *y)
{
                   blit(arrow,screen,0,0,*x,*y,arrow->w,arrow->h);               //displaying the arrow on to the screen
}
void draw_burst(int *x,int *y)
{
     
	blit(burst,screen,0,0,*x,*y,burst->w,burst->h);                              //displaying the burst on to the screen
     
}

void rond(int *pnt,int balloon_count,int level)
{
     while(balloon_count!=0 && count_arrow>0)                                                     //till all the balloons are over
     {
                             rightflag=0;                                                         //clearing the rightflag
                             counter_flag=0;                                                      //clearing the counterflag
                             xa=xbw-20;                                                           //initial x coordinaate of arrow
                             ya=ybw+55;                                                           //initial y coordinate of arrrow
                             arrow_image(&xa,&ya);                                                //displaying arrow
                             textprintf_ex(screen,font,10,420,makecol(255,0,0),makecol(255,255,255),"NUMBER OF BALLOONS LEFT: %d",balloon_count);         //displaying the number of balloons left
                             textprintf_ex(screen,font,10,440,makecol(255,0,0),makecol(255,255,255),"NUMBER OF ARROWS LEFT: %d",count_arrow+1);           //displaying the no. of arrows left
                             textprintf_ex(screen,font,10,460,makecol(255,0,0),makecol(255,255,255),"POINTS SCORED:  %d",*pnt);                           //displaying the points scored by player  
                             burstflag=0;                                                                   //clearing the burst flag
                             flagarrow=0;                                                                   //clearing the flag arrow
                             srand(time(NULL));
                             xb=((rand()%7)*100);                                ///taking the initial position of balloon
                             yb=500;
                          
                                                                                 //for setting the randomization of balloon
                             if(xb<400)
                             xb+=300;
                             if(xb>=600)
                             xb-=200;
                             
                                                                     
                             while((burstflag!=1) && ((yb+81)>0) && (count_arrow>=0) )          //looping till balloon burst or balloon reaches up or balloons used up                       //till the balloon is burst
                             {
                                                        if(key[KEY_ESC])                        //if escape key is pressed
                                                        exit(-1);                               //exit from the game
                                                        flagbow=0;
                                                        if(key[KEY_DOWN])
                                                        {
                                                                         flagbow=1;                 //setting bow flag=1
                                                        }        
                                                        if(key[KEY_UP])
                                                        {
                                                                         flagbow=2;                 //setting bow flag=2
                                                        }        
                                                                
                                                        if(flagbow==1)                              //if down key is pressed
                                                        {
                                                                         ybw+=1;                    //moving bow
                                                                         chkflag=1;
                                                                         flagbow==0;
                                                                         clear_to_color(screen,makecol(0,0,0));
                                                                         balloon_image(&xb,&yb);
                                                                         bow_image(&xbw,&ybw);
                                                                         arrow_image(&xa,&ya);               
                                                                         textprintf_ex(screen,font,10,420,makecol(255,0,0),makecol(0,0,0),"NUMBER OF BALLOONS LEFT: %d",balloon_count);      //displaying the number of balloons left
                                                                         textprintf_ex(screen,font,10,440,makecol(255,0,0),makecol(0,0,0),"NUMBER OF ARROWS LEFT: %d",count_arrow);          //displaying the no. of arrows left
                                                                         textprintf_ex(screen,font,10,460,makecol(255,0,0),makecol(0,0,0),"POINTS SCORED: %d ",(*pnt));                      //displaying the points scored by player
                                                        } 
                                                        if(flagbow==2)                               //if up key is pressed
                                                        {
                                                                         ybw-=1;                     //moving bow up
                                                                         chkflag=2;
                                                                         flagbow==0;
                                                                         clear_to_color(screen,makecol(0,0,0));
                                                                         balloon_image(&xb,&yb);
                                                                         bow_image(&xbw,&ybw);
                                                                         arrow_image(&xa,&ya);                 
                                                                         textprintf_ex(screen,font,10,420,makecol(255,0,0),makecol(0,0,0),"NUMBER OF BALLOONS LEFT: %d",balloon_count);
                                                                         textprintf_ex(screen,font,10,440,makecol(255,0,0),makecol(0,0,0),"NUMBER OF ARROWS LEFT: %d",count_arrow);                                                                         
                                                                         textprintf_ex(screen,font,10,460,makecol(255,0,0),makecol(0,0,0),"POINTS SCORED:  %d",(*pnt));
                                                        }       
                                                        if(key[KEY_RIGHT])
                                                        {
                                                                         flagarrow=1;               //setting arrow flag
                                                                         chkflag=0;
                                                                         rightflag=1;
                                                                         if(counter_flag==0)
                                                                         count_arrow--;
 
                                                                         counter_flag=1;
                                                        }
                                                        if((chkflag==1) && (rightflag!=1))
                                                        {
                                                                         ya+=1;                                                        chkflag=0;
                                                        }
                                                        if(chkflag==2 && (rightflag!=1))
                                                        {
                                                                         ya-=1;                                                              chkflag=0;
                                                        }
                                                        if((flagarrow==1)&& (count_arrow>=0))        //if right key is pressed and there are arrows left
                                                        {
                                                                         if(level==1)
                                                                         xa+=2;                      //move arrow
                                                                         if(level==2)
                                                                         xa+=2;
                                                                         if(level==3)
                                                                         xa+=3;
                                                                         clear_to_color(screen,makecol(0,0,0));
                                                                         balloon_image(&xb,&yb);
                                                                         bow_image(&xbw,&ybw);
                                                                         arrow_image(&xa,&ya);             
                                                                         textprintf_ex(screen,font,10,420,makecol(255,0,0),makecol(0,0,0),"NUMBER OF BALLOONS LEFT: %d",balloon_count);         //displaying the number of balloons left
                                                                         textprintf_ex(screen,font,10,440,makecol(255,0,0),makecol(0,0,0),"NUMBER OF ARROWS LEFT: %d",count_arrow);             //displaying the no. of arrows left                                                            
                                                                         textprintf_ex(screen,font,10,460,makecol(255,0,0),makecol(0,0,0),"POINTS SCORED:  %d",(*pnt));                         //displaying the points scored by player
                                                        }
                                                        if(level==1)
                                                        yb-=2;           //moving balloon upwards
                                                        if(level==2)
                                                        yb-=2;
                                                        if(level==3)
                                                        yb-=3;
                                                        clear_to_color(screen,makecol(0,0,0));
                                                        balloon_image(&xb,&yb);
                                                        bow_image(&xbw,&ybw);
                                                        arrow_image(&xa,&ya);               
                                                        textprintf_ex(screen,font,10,420,makecol(255,0,0),makecol(0,0,0),"NUMBER OF BALLOONS LEFT: %d",balloon_count);                          //displaying the no. of balloons left
                                                        textprintf_ex(screen,font,10,440,makecol(255,0,0),makecol(0,0,0),"NUMBER OF ARROWS LEFT: %d",count_arrow);                              //displaying the no. of arrows left
                                                        textprintf_ex(screen,font,10,460,makecol(255,0,0),makecol(0,0,0),"POINTS SCORED:  %d",(*pnt));
                                                        sleep(10);

                                                        if(((xa+76)>xb && (xa+76)<(xb+59)) && ((ya<(yb+70)) && (ya > yb)) || ((xa+30)>xb && ((xa+30)<(xb+59)) && ((ya<(yb+70))&&(ya>yb))))                                            //if coordinates of balloon and arrrow matches
                                                        {                                                        
                                                                         clear_to_color(screen,makecol(0,0,0));                                                                         
                                                                         draw_burst(&xb,&ya);  
                                                                         blit(bow,screen,0,0,xbw,ybw,bow->w,bow->h);
                                                                         bow_image(&xbw,&ybw);
                                                                         sleep(500);
                                                                         arrow_image(&xa,&ya);
                                                                         *pnt+=20;   
                                                                         textprintf_ex(screen,font,10,420,makecol(255,0,0),makecol(0,0,0),"NUMBER OF BALLOONS LEFT: %d",balloon_count);         //displaying the no. of balloons left                                      //displaying the number of balloons left
                                                                         textprintf_ex(screen,font,10,440,makecol(255,0,0),makecol(0,0,0),"NUMBER OF ARROWS LEFT: %d",count_arrow+1);           //displaying the no. of arrows left                                                                                                    //points incremented                 
                                                                         textprintf_ex(screen,font,10,460,makecol(255,0,0),makecol(0,0,0),"POINTS SCORED:  %d",(*pnt));                                                                
                                                                         burstflag=1;
                                                        }
                                                
                                                                  
                             }balloon_count--;                        
     }


}
