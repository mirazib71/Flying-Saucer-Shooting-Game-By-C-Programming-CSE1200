# include "iGraphics.h"
# include "bitmap_viewer.h"
# include <stdio.h>
# include <stdlib.h>
# include <windows.h>

struct flyingsaucer
{
 char image[20] = "saucer.bmp";
 double life = 80;
 double x = 200;
 double y = 200;
}player;

struct enemy
{
 char image[20] = "spaceship.bmp";
 double life = 20;
 double x;
 double y;
 int state=1;
}enemy_arr[20];

struct object
{
 char image[20] = "newmet.bmp";
 char image2[20] = "flash.bmp";
 char image3[20] = "newmet1.bmp";
 char image4[20] = "newmet2.bmp";
 char image5[20] = "newmet3.bmp";
 int state=1;
 double x;
 double y;
}object_arr[20];


struct speedline
{
 char image[20] = "speedline.bmp";
 double x;
 double y;
}speedline_arr[20];

struct missile
{
 char image[20] = "laser.bmp";
 double x = -110;
 double y = -220;

 void launch()
 {
   iShowBMPAlternative2(x+=9.5, y, image, 0);
 }

}missile_arr[40];

struct scores
{
 int score;
 char name[30];
}highscore_list[20];

struct scores displayList[20];

struct record
{
 char score[20];
}records[20];

struct lifeobject
{
 char image[20] = "green.bmp";
 int x;
 int y;
}oob, green_arr[5];


int menubar = 240;
int screen;
int menu=1;
int play=0;

int e=0;
int i=0;
int n=0;
int s=0;
int o=0;
int j=0;
int m=0;
int k=0;
int launch =0;
int l =0;
int c=0;
int smokeduration[20] = {80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80, 80, 80, 80};
int stateControl[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int instruction;
int highscore;
int pause;
//int e1=1, e2=1, e3=1;
int b=0;
int over=0;
int wt=0;
int ob=1;
int namescreen=0;
char userName[30] = {};
int uN=0;
double bar=490;
int hlist=0;

FILE *fp;

char rr[40];
int r;

int score = 0;
char score_string[30]={'0'};
int saved=0;
int ns_pos = 1000;
int g;
char ch;
int p=0;
char ranking[5];
int e1=0, e2=1, e3=2;
int renew=0;
bool flag;
double expX1, expY1;
double expX2, expY2;
double expX3, expY3;
int z; int orbcontrol=2;
bool showOrb = true;

double enemy_y[20] = {200, 350, 80, 400, 200, 80, 100, 400, 250, 100, 300, 400, 200, 60,400, 200, 350, 100, 400, 250};
double speedlines_y[20] = {100, 200, 250, 150, 300, 350,400, 50};
double random_x[20] = {1050, 1040, 1020, 1045, 1015, 1027, 1048, 1030, 1037, 1033, 1050, 1040, 1020, 1045, 1015, 1027, 1048, 1030, 1037, 1033};

double green_randomx[5] = {200, 500, 700, 300, 850};
double green_randomy[5] = {450, 50, 300, 100, 400};

double speedlines_x[5] = {200, 150, 450, 400, 100};
double obstacle_y[5] = {100,200,300,400, 500};

#define constant_x 1050;

/**************************************************************************************/


void my_utoa(int dataIn, char* bffr, int radix){
int temp_dataIn;
temp_dataIn = dataIn;
int stringLen=1;

while ((int)temp_dataIn/radix != 0){
    temp_dataIn = (int)temp_dataIn/radix;
    stringLen++;
}
//printf("stringLen = %d\n", stringLen);
temp_dataIn = dataIn;
do{
    *(bffr+stringLen-1) = (temp_dataIn%radix)+'0';
    temp_dataIn = (int) temp_dataIn / radix;
}while(stringLen--);}


/**************************************************************************************/

void mainMenu()
{
 iShowBMPAlternative(0,0, "mainmenu.bmp");

 iSetColor(200,200,200);
 iFilledRectangle(466, menubar, 120, 25);

 iSetColor(0, 200,200);

 iText(470, 245, "Start", GLUT_BITMAP_HELVETICA_18);
 iText(470, 220, "Instructions", GLUT_BITMAP_HELVETICA_18);
 iText(470, 195, "High Scores", GLUT_BITMAP_HELVETICA_18);
 iText(470, 170, "Quit", GLUT_BITMAP_HELVETICA_18);

 menu =1;
 instruction=0; highscore=0;
}

void orbs()
{
 for(z=0; z<5; z++){
    green_arr[z].x = green_randomx[rand()%5];
    green_arr[z].y = green_randomy[rand()%5];
 }
}


void chooseOption()
{
 if(menubar==240)
    screen = 7;
 else if(menubar==215)
    screen =  2;
 else if(menubar==190)
    screen =  3;
 else if(menubar==165)
   exit(0);
 menu=0;
}

void instructions();
void highscores();
void gameStart();

void playgame();
void pausemenu();
void gameOver();

void showScreen()
{
  switch(screen){
   case  1: { play=1; playgame(); break;}
   case  2: { instruction=1; instructions();  break;}
   case  3: { highscore=1; highscores(); break;}
   case  5: {pause=1; pausemenu(); break;}
   case  6: {over=1; gameOver(); break;}
   case 7: {namescreen=1; gameStart(); break;}
   default: mainMenu();
  }

}
void gameStart()
{
 iShowBMPAlternative(0,0, "maxred.bmp");
 iText(300,300, "Enter your name: ", GLUT_BITMAP_TIMES_ROMAN_24);
 if(rand()%2==0)
 iText(bar, 300, "|", GLUT_BITMAP_TIMES_ROMAN_24);

 iText(492, 300, userName, GLUT_BITMAP_TIMES_ROMAN_24);

 menu =0;

}

void instructions()
{
 if(instruction==1)
 iShowBMPAlternative(0,0, "mod.bmp");
}


void highscores()
{
 if(highscore==1){
 iShowBMPAlternative(0,0, "ambientnight.bmp");

 for(g=0; g<=p; g++){
 my_utoa(displayList[g].score, records[g].score, 10);
}

 iSetColor(400,300,0);
 iText(0,0, rr, GLUT_BITMAP_HELVETICA_18);

 ns_pos = 300;
 for(g=0; g<=p; g++){
 iText(250, ns_pos, "#" , GLUT_BITMAP_HELVETICA_18);
 iText(300, ns_pos, displayList[g].name, GLUT_BITMAP_HELVETICA_18);
 iText(400, ns_pos, records[g].score, GLUT_BITMAP_HELVETICA_18);
 ns_pos-=50;
 }
 //iText(300, 300, displayList[2].name, GLUT_BITMAP_HELVETICA_18);
 //iText(400, 300, records[2].score, GLUT_BITMAP_HELVETICA_18);
 }
}

void pausemenu()
{

}


void collisionAlternative();
void bringEnemyAlternative();
void bringEnemy();
void speedlines();
void bringObstacles();
void launchMissiles();
void collision();
void my_utoa();
void displayScore();
void playerCollision();
void objectCollision();
void playerCollisionAlternative();
void updateScore();

void orbChange()
{
 orbcontrol = rand()%5;
 showOrb = true;
}



void orbPoints()
{
 if(green_arr[orbcontrol].x>=player.x && green_arr[orbcontrol].x<=player.x+110 && green_arr[orbcontrol].y>=player.y && green_arr[orbcontrol].y<=player.y+110 )
 {updateScore();
  showOrb = false;
 }

}

void playgame()
{

 if(pause==0){
  iShowBMPAlternative(0,0, "hs.bmp");

  if(showOrb){
  iShowBMPAlternative2(green_arr[orbcontrol].x--, green_arr[orbcontrol].y, green_arr[orbcontrol].image, 0);
  }

  iShowBMPAlternative2(player.x, player.y, player.image, 0);

  iSetColor(200,38,20);
  iRectangle(81, 480, 80, 25);

  iSetColor(0,300,0);
  iFilledRectangle(80, 480.5, player.life, 24);

  //PlaySound("1.wav", NULL, SND_ASYNC);

 //bringEnemy();
   orbPoints();
  bringEnemyAlternative();

 speedlines();

 bringObstacles();

 if(launch==1){
    for(l=0; l<=m; l++){
      missile_arr[l].launch();
    }
 }

 //collision();
 collisionAlternative();
 //playerCollision();
 playerCollisionAlternative();
 //objectCollision();

 displayScore();



 }
 else{
    iClear();
    iShowBMPAlternative(0,0, "hsp.bmp");
    iSetColor(0,300,200);
    iText(450,300, "PAUSED", GLUT_BITMAP_TIMES_ROMAN_24);
    if(rand()%2==0){
    iText(400,200, "Press P to return to game.", GLUT_BITMAP_HELVETICA_18);
    }
 }
}

void initializeEnemy();
void stateControlReset();


void bringEnemyAlternative()
{
    if(enemy_arr[e1].state==1){
     iShowBMPAlternative2(enemy_arr[e1].x-=25, enemy_arr[e1].y, enemy_arr[e1].image, 0);
    }
    if(enemy_arr[e2].state==1){
     iShowBMPAlternative2(enemy_arr[e2].x-=25, enemy_arr[e2].y, enemy_arr[e2].image, 0);
    }
    if(enemy_arr[e3].state==1){
     iShowBMPAlternative2(enemy_arr[e3].x-=25, enemy_arr[e3].y, enemy_arr[e3].image, 0);
    }

     if(enemy_arr[e1].x<0) e1+=3;
     if(enemy_arr[e2].x<0) e2+=3;
     if(enemy_arr[e3].x<0) e3+=3;

     if(e3>=17) {
             e1=0; e2=1; e3=2;
             initializeEnemy();
             stateControlReset();
     }

}

void bringEnemy()
{
    if(enemy_arr[e].state==1){
     iShowBMPAlternative2(enemy_arr[e].x-=25, enemy_arr[e].y, enemy_arr[e].image, 0);
    }
    if(enemy_arr[e+1].state==1){
     iShowBMPAlternative2(enemy_arr[e+1].x-=25, enemy_arr[e+1].y, enemy_arr[e+1].image, 0);
    }
    if(enemy_arr[e+2].state==1){
     iShowBMPAlternative2(enemy_arr[e+2].x-=25, enemy_arr[e+2].y, enemy_arr[e+2].image, 0);
    }

     if(enemy_arr[e].x<0) e++;
     if(enemy_arr[e+1].x<0) e++;
     if(enemy_arr[e+2].x<0) e++;

     if(e==18) {
            e=0;
            //initializeEnemy();
            //stateControlReset();
     }
}

void initializeSpeedlines();

void speedlines()
{
  iShowBMPAlternative2(speedline_arr[s].x-=2, speedline_arr[s].y, speedline_arr[s].image, 0);
  iShowBMPAlternative2(speedline_arr[s+1].x--, speedline_arr[s+1].y, speedline_arr[s+1].image, 0);
  iShowBMPAlternative2(speedline_arr[s+2].x-=1.5, speedline_arr[s+2].y, speedline_arr[s+1].image, 0);
  iShowBMPAlternative2(speedline_arr[s+3].x-=3, speedline_arr[s+3].y, speedline_arr[s+1].image, 0);
  iShowBMPAlternative2(speedline_arr[s+4].x--, speedline_arr[s+4].y, speedline_arr[s+1].image, 0);

  if(speedline_arr[s+1].x<0) s+=5;

  if(s==15) {
        s=0;
      initializeSpeedlines();
  }
}

void initializeEnemy()
{
  for(i=0; i<20; i++){
    //enemy_arr[i].x = constant_x;
    enemy_arr[i].x = random_x[rand()%20];
    enemy_arr[i].state = 1;
  }

  for(i=0; i<20; i++){
    enemy_arr[i].y = enemy_y[i];
  }
}

void stateControlReset()
{
  for(int i=0; i<20; i++)
  {
    stateControl[i]= 1;
  }
}

void initializeSpeedlines()
{
  for(n=0; n<20; n++){
    speedline_arr[n].x = speedlines_x[rand()%5];
  }

  for(n=0; n<20; n++){
    speedline_arr[n].y = speedlines_y[rand()%8];
  }
}

void initializeObstacles();

void bringObstacles()
{
 if(ob==1){
 iShowBMPAlternative2(object_arr[o].x-=3, object_arr[o].y, object_arr[o].image, 0);
 iShowBMPAlternative2(object_arr[o+1].x-=2, object_arr[o+1].y, object_arr[o+1].image, 0);
 iShowBMPAlternative2(object_arr[o+2].x-=4, object_arr[o+2].y, object_arr[o+2].image, 0);
 iShowBMPAlternative2(object_arr[o+3].x-=1, object_arr[o+3].y, object_arr[o+3].image, 0);
 //iShowBMPAlternative2(object_arr[o+4].x-=0.5, object_arr[o+4].y, object_arr[o+4].image, 0);
 ob++;
 }
 else if(ob==2){
 iShowBMPAlternative2(object_arr[o].x-=3, object_arr[o].y, object_arr[o].image, 0);
 iShowBMPAlternative2(object_arr[o+1].x-=1, object_arr[o+1].y, object_arr[o+1].image3, 0);
 iShowBMPAlternative2(object_arr[o+2].x-=4, object_arr[o+2].y, object_arr[o+2].image3, 0);
 iShowBMPAlternative2(object_arr[o+3].x-=2, object_arr[o+3].y, object_arr[o+3].image3, 0);
 //iShowBMPAlternative2(object_arr[o+4].x-=0.5, object_arr[o+4].y, object_arr[o+4].image3, 0);
 ob++;
}
else if(ob==3){
 iShowBMPAlternative2(object_arr[o].x-=1, object_arr[o].y, object_arr[o].image4, 0);
 iShowBMPAlternative2(object_arr[o+1].x-=4, object_arr[o+1].y, object_arr[o+1].image4, 0);
 iShowBMPAlternative2(object_arr[o+2].x-=2, object_arr[o+2].y, object_arr[o+2].image4, 0);
 iShowBMPAlternative2(object_arr[o+3].x-=3, object_arr[o+3].y, object_arr[o+3].image4, 0);
 //iShowBMPAlternative2(object_arr[o+4].x-=0.5, object_arr[o+4].y, object_arr[o+4].image4, 0);
 ob++;
}
else{
 iShowBMPAlternative2(object_arr[o].x-=3, object_arr[o].y, object_arr[o].image5, 0);
 iShowBMPAlternative2(object_arr[o+1].x-=1, object_arr[o+1].y, object_arr[o+1].image5, 0);
 iShowBMPAlternative2(object_arr[o+2].x-=4, object_arr[o+2].y, object_arr[o+2].image5, 0);
 iShowBMPAlternative2(object_arr[o+3].x-=2, object_arr[o+3].y, object_arr[o+3].image5, 0);
 //iShowBMPAlternative2(object_arr[o+4].x-=0.5, object_arr[o+4].y, object_arr[o+4].image5, 0);
 ob=1;
}
 if(object_arr[o].x<0) o+=4;
 if(o==16){
    o=0;
    initializeObstacles();
 }
}

void initializeObstacles()
{
  for(j=0; j<20; j++){
    object_arr[j].x = random_x[rand()%13];
  }

  for(j=0; j<20; j++){
    object_arr[j].y = obstacle_y[rand()%5];
  }

}

void initializeMissiles();



void initializeMissiles()
{
 missile_arr[m].x = player.x+64;
 missile_arr[m].y = player.y+32;


 if(m>=39) m=0;
}

void setSmokeDuration()
{
 smokeduration[0] = 10;
 smokeduration[1] = 10;
 smokeduration[2] = 10;
}

void updateScore();


void collisionAlternative()
{
 for(c=0; c<=m; c++){
    if(missile_arr[c].x>=enemy_arr[e1].x && missile_arr[c].x<=enemy_arr[e1].x+100 && missile_arr[c].y<=enemy_arr[e1].y+100 && missile_arr[c].y>=enemy_arr[e1].y)
        {
         if(smokeduration[0]>0 && enemy_arr[e1].state==0){
         iShowBMPAlternative2(enemy_arr[e1].x--, enemy_arr[e1].y, "explosion.bmp", 0);
         updateScore();
         }

         if(stateControl[e1]==1){
         enemy_arr[e1].state = 0;
         stateControl[e1]=0;
         iShowBMPAlternative2(enemy_arr[e1].x--, enemy_arr[e1].y, "explosion.bmp", 0);
         e1+=3;
         }

         smokeduration[0]--;
        }

    if(missile_arr[c].x>=enemy_arr[e2].x && missile_arr[c].x<=enemy_arr[e2].x+100 && missile_arr[c].y<=enemy_arr[e2].y+100 && missile_arr[c].y>=enemy_arr[e2].y)
        {

         if(smokeduration[1]>0 && enemy_arr[e2].state==0){
         iShowBMPAlternative2(enemy_arr[e2].x--, enemy_arr[e2].y, "explosion.bmp", 0);
         updateScore();
         }

         if(stateControl[e2]==1){
         enemy_arr[e2].state = 0;
         stateControl[e2]=0;
         iShowBMPAlternative2(enemy_arr[e2].x--, enemy_arr[e2].y, "explosion.bmp", 0);
         e2+=3;
        }

        smokeduration[1]--;

        }



    if(missile_arr[c].x>=enemy_arr[e3].x && missile_arr[c].x<=enemy_arr[e3].x+100 && missile_arr[c].y<=enemy_arr[e3].y+100 && missile_arr[c].y>=enemy_arr[e3].y)
        {

         if(smokeduration[2]>0 && enemy_arr[e2].state==0){
         iShowBMPAlternative2(enemy_arr[e3].x--, enemy_arr[e3].y, "explosion.bmp", 0);
         updateScore();
         }

         if(stateControl[e3]==1){
         enemy_arr[e3].state = 0;
         stateControl[e3]=0;
         iShowBMPAlternative2(enemy_arr[e3].x--, enemy_arr[e3].y, "explosion.bmp", 0);
         e3+=3;
         }

         smokeduration[2]--;
        }

 }

    if(smokeduration[0]<=0 && smokeduration[1]<=0 && smokeduration[2]<=0)
        {
         setSmokeDuration();
        }
}





void collision()
{
 for(c=0; c<=m; c++){
    if(enemy_arr[e].state==1 && smokeduration[e]>0 && missile_arr[c].x>=enemy_arr[e].x && missile_arr[c].x<=enemy_arr[e].x+100 && missile_arr[c].y<=enemy_arr[e].y+100 && missile_arr[c].y>=enemy_arr[e].y)
        {
         iShowBMPAlternative2(enemy_arr[e].x--, enemy_arr[e].y, "explosion.bmp", 0);
         if(stateControl[e]==1){
         enemy_arr[e].state = 0;
         stateControl[e]=0;
         }
         smokeduration[e]--;

         updateScore();
        }
    else if (smokeduration[e]>0 && enemy_arr[e].state==0)
    {
     iShowBMPAlternative2(enemy_arr[e].x--, enemy_arr[e].y, "explosion.bmp", 0);
      smokeduration[e]--;
    }

    if(enemy_arr[e+1].state==1 && smokeduration[e+1]>0 && missile_arr[c].x>=enemy_arr[e+1].x && missile_arr[c].x<=enemy_arr[e+1].x+100 && missile_arr[c].y<=enemy_arr[e+1].y+100 && missile_arr[c].y>=enemy_arr[e+1].y)
        {
         iShowBMPAlternative2(enemy_arr[e+1].x--, enemy_arr[e+1].y, "explosion.bmp", 0);
         if(stateControl[e+1]==1){
         enemy_arr[e+1].state = 0;
         stateControl[e+1]=0;
         }
         smokeduration[e+1]--;
         updateScore();
        }
        else if (smokeduration[e+1]>0 && enemy_arr[e+1].state==0)
    {
     iShowBMPAlternative2(enemy_arr[e].x--, enemy_arr[e].y, "explosion.bmp", 0);
      smokeduration[e+1]--;
    }
    if(enemy_arr[e+1].state==1 && smokeduration[e+2]>0 && missile_arr[c].x>=enemy_arr[e+2].x && missile_arr[c].x<=enemy_arr[e+2].x+100 && missile_arr[c].y<=enemy_arr[e+2].y+100 && missile_arr[c].y>=enemy_arr[e+2].y)
        {
         iShowBMPAlternative2(enemy_arr[e+2].x--, enemy_arr[e+2].y, "explosion.bmp", 0);

         if(stateControl[e+2]==1){
         enemy_arr[e+2].state = 0;
         stateControl[e+2]=0;
         }

         smokeduration[e+2]--;
         updateScore();
        }
        else if (smokeduration[e+2]>0 && enemy_arr[e+2].state==0)
    {
     iShowBMPAlternative2(enemy_arr[e].x--, enemy_arr[e].y, "explosion.bmp", 0);
      smokeduration[e+2]--;
    }
    }

    /*if(smokeduration[0]==0){
         smokeduration[0]--;
    }
    if(smokeduration[1]==0) {
          smokeduration[1]--;
    }
    if(smokeduration[2]==0) {
         smokeduration[2]--;
    }

    if(smokeduration[0]<=0 && smokeduration<=0 && smokeduration[2]<=0)
        {
         setSmokeDuration();
         e+=3;
        }
        */
}


void playerCollisionAlternative()
{
 if(enemy_arr[e1].state==1 && player.x+120>=enemy_arr[e1].x && player.x<=enemy_arr[e1].x && (player.y<=enemy_arr[e1].y && player.y+90>=enemy_arr[e1].y || player.y>=enemy_arr[e1].y && player.y<=enemy_arr[e1].y+100))
 {
   iShowBMPAlternative2(player.x+60, player.y+60, "flash.bmp", 0);
   player.life-=4;
 }
 if(enemy_arr[e2].state==1 && player.x+120>=enemy_arr[e2].x && player.x<=enemy_arr[e2].x && (player.y<=enemy_arr[e2].y && player.y+90>=enemy_arr[e2].y|| player.y>=enemy_arr[e2].y && player.y<=enemy_arr[e2].y+100))
 {
   iShowBMPAlternative2(player.x+60, player.y+60, "flash.bmp", 0);
   player.life-=4;
 }
 if(enemy_arr[e3].state==1 && player.x+120>=enemy_arr[e3].x && player.x<=enemy_arr[e3].x && (player.y<=enemy_arr[e3].y && player.y+90>=enemy_arr[e3].y || player.y>=enemy_arr[e3].y && player.y<=enemy_arr[e3].y+100))
 {
   iShowBMPAlternative2(player.x+60, player.y+60, "flash.bmp", 0);
   player.life-=4;
 }

}


void playerCollision()
{
 if(player.x+120>=enemy_arr[e].x && player.x<=enemy_arr[e].x && (player.y<=enemy_arr[e].y && player.y+90>=enemy_arr[e].y || player.y>=enemy_arr[e].y && player.y<=enemy_arr[e].y+100))
 {
   iShowBMPAlternative2(player.x+60, player.y+60, "flash.bmp", 0);
   player.life-=6;
 }
 if(player.x+120>=enemy_arr[e+1].x && player.x<=enemy_arr[e+1].x && (player.y<=enemy_arr[e+1].y && player.y+90>=enemy_arr[e+1].y|| player.y>=enemy_arr[e+1].y && player.y<=enemy_arr[e+1].y+100))
 {
   iShowBMPAlternative2(player.x+60, player.y+60, "flash.bmp", 0);
   player.life-=6;
 }
 if(player.x+120>=enemy_arr[e+2].x && player.x<=enemy_arr[e+2].x && (player.y<=enemy_arr[e+2].y && player.y+90>=enemy_arr[e+2].y || player.y>=enemy_arr[e+2].y && player.y<=enemy_arr[e+2].y+100))
 {
   iShowBMPAlternative2(player.x+60, player.y+60, "flash.bmp", 0);
   player.life-=6;
 }

}

/*void objectCollision()
{
 for(b=0; b<o; b++){
  if(player.x+100<=object_arr[b].x && player.x<=object_arr[b].x+120 && player.y<=object_arr[b].y+120 && player.y>=object_arr[b].y)
  {
   iShowBMPAlternative2(object_arr[b].x, object_arr[b].y, "flash.bmp", 0);
   player.life-=2;
  }
}
}
*/


void gameBackgrounds()
{
 iShowBMPAlternative(0,0, ".bmp");
 iShowBMPAlternative(0,0, ".bmp");
 iShowBMPAlternative(0,0, ".bmp");
 iShowBMPAlternative(0,0, ".bmp");
}

void updateScore()
{
  score++;
  my_utoa(score, score_string, 10);
}

void displayScore()
{
  iSetColor(0,0,500);
  iText(20, 480, score_string, GLUT_BITMAP_HELVETICA_18);
}

void fileWrite();
void saveScore();

void gameOver()
{
 if(over==1){
 iShowBMPAlternative(0,0, "gameover.bmp");
 iSetColor(600, 0, 0);

 if(rand()%2==0){
 iText(450, 450, "GAME OVER", GLUT_BITMAP_HELVETICA_18);
 }
 iText(830, 450, "Score: ", GLUT_BITMAP_HELVETICA_18);
 iText(920, 450, score_string, GLUT_BITMAP_HELVETICA_18);
 play =0;

 //fileWrite();

 if(saved==0){
    saveScore();
    saved =1;
 }

 }
}


/*************************************************************/

void iDraw() {

      if(pause==0){
        iClear();}


       showScreen();
       //chooseOptions() called by pressing enter
      if(player.life<=0) screen=6;
}


void iMouseMove(int mx, int my)
{
printf("x = %d, y= %d\n",mx,my);

}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}


void iPassiveMouseMove(int mx,int my)
{
}



void iKeyboard(unsigned char key)
{
   if(key == '\r' && menu==1){
     chooseOption();
   }

   if( key == ' ')
   {
     initializeMissiles();
     launch =1;
     m++;

   }

   if( key == 'z' && play!=1)
   {
     screen = 4;
     wt=1;
   }

   if( key == 'p' && play==1)
   {
     pause=!pause;
   }

   if(key != '\r' && key !='\b' && namescreen==1)
    {
      userName[uN++] = key;
      bar+=12.75;
    }
   else if ( key==' ' && namescreen==1)
   {
     userName[uN++] = key;
      bar+=6;
   }
   else if (key=='\b' && namescreen==1)
   {
     userName[--uN] = ' ';
     bar-=6;
     uN++;
   }

   if(key == '\r' && namescreen==1)
   {
    screen = 1;
   }



}


void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
      exit(0);
	}

    if(key == GLUT_KEY_UP && menu==1)
	{
		 menubar+=25;
        if(menubar>240) menubar = 165;
	}

	if(key == GLUT_KEY_DOWN && menu==1)
	{
		 menubar-=25;
        if(menubar<165) menubar = 240;
	}


	if(key == GLUT_KEY_LEFT && play==1)
	{
      player.x-=5.5;
	}

	if(key == GLUT_KEY_RIGHT && play==1)
	{
      player.x+=5.5;
	}

	if(key == GLUT_KEY_UP && play==1)
	{
      player.y+=5.5;
	}

	if(key == GLUT_KEY_DOWN && play==1)
	{
      player.y-=5.5;
	}

}

void fileWrite()
{
 fp = fopen("Scores.txt", "w");
 fprintf(fp, "Your last score: %s", score_string);
 fclose(fp);
}

void saveScore()
{
 strcpy(highscore_list[hlist].name, userName);
 highscore_list[hlist].score = score;
 fp = fopen("Highscores.dat", "a");
 fwrite(&highscore_list[hlist], sizeof(highscore_list[hlist]), 1, fp);
 //hlist++;
 fclose(fp);
}

void readScore()
{
  fp = fopen("Highscores.dat", "r");


  fread(&displayList[p], sizeof(displayList[p]), 6, fp);
  p=6;
  /*while(fread(&displayList[p], sizeof(displayList[p]),1, fp)==1){
   p++;
  }
  */
  //fread(&displayList[2], sizeof(displayList[2]), 1, fp);
}

void changeOB()
{
 ob++;
 if(ob>4) ob=0;
}

int main() {

    initializeEnemy();
    orbs();
    readScore();
    //iSetTimer(0.001, changeOB);

    iSetTimer(10000, orbChange);
	iInitialize(1024, 512 , "FlySaucer");
	return 0;
}
