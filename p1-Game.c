#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void red();
void green();
void yellow();
void purple();
void reset();
void UPkey();
void Downkey();
void Leftkey();
void Rightkey();
void displayRules();
void displayMatrix();
void game(int,char*);
void RandomNumberGenerator();
void checkWin();
void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

int a[4][4];
int currentEmptyCol=3;
int currentEmptyRow=3;
int newEmptyRow;
int newEmptyCol;
 int moves ;
int main() {
    int keyPress;
    char name[50];
    fflush(stdin);
    purple();
    printf("\nYour Name Please: ");
    reset();
   
    scanf("%[^\n]s", name);
     clear();
    fflush(stdin);
    displayRules();
   // printf("\n press any key: ");
   // scanf("%d",&keyPress);
    keyPress=getchar();
    game(keyPress,name);
    return 0;
}
void game(int keyPress,char *str)
{
   moves =5;
   clear();
   yellow();
   printf("\nHello %s,",str);
   reset();
   red();
   printf("\nMoves Remaining : %d (Press'e' or 'E' to exit the game)\n",moves);
   reset();
   RandomNumberGenerator();
 
int ch1, ch2;
//printf("PRESS A KEY TO CONTINUE \n");

ch1 = getch();
while(ch1!=101 && moves>=1){
ch2 = 0;
if (ch1 == 0xE0 ||ch1 == 0) { 
ch2 = getch();
// determine what it was
switch(ch2)
{
case 72: {
    UPkey();
    checkWin();
     break;
}
case 80: {
    Downkey();
    checkWin();
     break;
}
case 75: {
    Leftkey();
    checkWin();
    break;
}
case 77: {
    Rightkey();
    checkWin();
    break;
}
default:
printf("\nSOME OTHER SCROLL KEY PRESSED: Press only Arrow keys to move in all directions\n"); break;
}
}
ch1 = getch();
}
if(!moves)
{
    int replaychoice;
    purple();
    printf("\nSorry...YOU LOST!. Better Luck Next Time\n");
    reset();
    green();
    printf("\nPress 'y' if you want to try your luck again\n");
    reset();
    fflush(stdin);
replaychoice = getchar();
if(replaychoice=='y') game('y',str);
}
}
void RandomNumberGenerator()
{
  srand(time(NULL));
  int rand_array[15] = {0};
  int vektor[15];   
  int i=0, rnd;
 // char space=32;
while(i<15) {
    rnd = rand() % 15+ 1;
    if ( rand_array[rnd-1] == 0 ) {
        vektor[i++] = rnd;
        rand_array[rnd-1] = 1;
    }
}
vektor[15]=32;

int p=0,q=0,m=0;
for(p=0;p<4;p++){
    for(q=0;q<4;q++)
    {
        a[p][q]=vektor[m++];
    }
}
printf("\n---------------------\n");
for(p=0;p<4;p++){
    for(q=0;q<4;q++)
    {
        if(a[p][q]==32)printf("|%3c ",a[p][q]);
       else printf("|%3d ",a[p][q]);
    }
    printf("|\n");
}
printf("---------------------\n");


}
void Downkey()
{
    int temp;
     moves--;
    if(currentEmptyRow >0){
    newEmptyRow = currentEmptyRow -1;
    newEmptyCol = currentEmptyCol;
    //swap vektor[currentEmpty] and vektor[newEmpty]
    temp = a[newEmptyRow][newEmptyCol];
    a[newEmptyRow][newEmptyCol]=a[currentEmptyRow][currentEmptyCol];
    a[currentEmptyRow][currentEmptyCol] =temp;
    //Change the position of current empty location
    currentEmptyRow = newEmptyRow;

     displayMatrix();
    }

}
void UPkey()
{
    int temp;
     moves--;
    if(currentEmptyRow<3){
    newEmptyRow = currentEmptyRow +1;
    newEmptyCol = currentEmptyCol;
    //swap vektor[currentEmpty] and vektor[newEmpty]
    temp = a[newEmptyRow][newEmptyCol];
    a[newEmptyRow][newEmptyCol]=a[currentEmptyRow][currentEmptyCol];
    a[currentEmptyRow][currentEmptyCol] =temp;
    //Change the position of current empty location
    currentEmptyRow = newEmptyRow;

     displayMatrix();
    }

}

void Rightkey()
{
   
    int temp;
     moves--;
    if(currentEmptyCol>0){
    newEmptyCol = currentEmptyCol-1;
    newEmptyRow = currentEmptyRow;
    //swap vektor[currentEmpty] and vektor[newEmpty]
    temp = a[newEmptyRow][newEmptyCol];
    a[newEmptyRow][newEmptyCol]=a[currentEmptyRow][currentEmptyCol];
    a[currentEmptyRow][currentEmptyCol] =temp;
    //Change the position of current empty location
    currentEmptyCol = newEmptyCol;

     displayMatrix();
    }

}

void Leftkey()
{
    
    int temp;
     moves--;
    if(currentEmptyCol<3){
    newEmptyCol = currentEmptyCol+1;
    newEmptyRow = currentEmptyRow;
    //swap vektor[currentEmpty] and vektor[newEmpty]
    temp = a[newEmptyRow][newEmptyCol];
    a[newEmptyRow][newEmptyCol]=a[currentEmptyRow][currentEmptyCol];
    a[currentEmptyRow][currentEmptyCol] =temp;
    //Change the position of current empty location
    currentEmptyCol = newEmptyCol;

     displayMatrix();
    }

}


void displayRules()
{
    clear();
    yellow();
    printf("\t  \t \t Welcome to 'MATRIX SORTING GAME'\t\t\t");
    reset();
    red();
    printf("\t  \t \t    RULES OF THIS GAME \t \t \n");
    
    printf("1. You can move only 1 step at a time by arrow key\n");
    reset();
    printf("\tMove Up \t: by Up arrow key\n\tMove Down\t: by Down arrow key\n\tMove Left\t: by Left arrow key\n\tMove Right\t: by Right arrow key\n");
    red();
    printf("\n2. You can move number at empty position only\n\n3. For each valid move\t: Your total number of moves will be decreased by 1\n\n4. Winning situation: Number in a 4*4 matrix should be in order from 1 to 15");
    reset();
    printf("\n\n\t\tWinning Situation:");
    yellow();
    printf("\n-------------");
    printf("\n|1 |2 |3 |4 |\n|5 |6 |7 |8 |\n|9 |10|11|12|\n|13|14|15|  |");
    printf("\n-------------");
    reset();
    green();
    printf("\n You can exit the game at any time by pressing 'E' or 'e'\n So try to win in minimum no of move\n\n \t\t\tHappy Gaming,\tGood Luck\n\n Enter any key to start.....");
    reset();
}
void displayMatrix()
{
    int p,q;
    printf("\n---------------------\n");
    for(p=0;p<4;p++){
    for(q=0;q<4;q++)
    {
        if(a[p][q]==32)printf("|%3c ",a[p][q]);
       else printf("|%3d ",a[p][q]);
    }
    printf("|\n");
}
printf("---------------------\n");
red();
printf("Moves Left: %d\n",moves);
reset();
}
void checkWin()
{
    int p,q,flag=1;

for(p=0;p<4;p++){
    for(q=0;q<3;q++)
    {
        
        if((a[p][q]!=32)&&(a[p][q]>a[p][q+1])) flag=0;
        if((a[p][q+1]!=32) && ((q+1) == 3))
        {
            if((p<3)&&(a[p][q+1]>a[p+1][0])) flag =0;
        }
       
    }
    }

    if(flag){
     printf("\nCongratulations, You Won...\n");

/* Now print the sorted array*/
for(p=0;p<4;p++){
    for(q=0;q<4;q++)
    {
        if(a[p][q]==32)printf("|%3c ",a[p][q]);
       else printf("|%3d ",a[p][q]);
    }
    printf("|\n");
}

     printf("\nPress 'y' if you wish to again play the game or press 'e' to Exit\n");
    }

}
void red()
{
    printf("\033[1;31m");
}
void reset()
{
    printf("\033[0m");
}
void green()
{
    printf("\033[1;32m");
}
void yellow()
{
    printf("\033[1;33m");
}
void purple()
{
    printf("\033[1;35m");
}