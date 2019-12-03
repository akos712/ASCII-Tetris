#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct ls {
	int data;
	struct ls *next;
} node;

/*typedef struct db{
    char nev[10];
    int score;
    char seed[32];
    struct db *next;

}database;*/
int Jatekter[][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1}};
int alakzat=0;
int rotation=0;
int point=0;
char name[10];
char *seedlanc;
int timer=0;
int speed=50;
int gameover=0;
int sum=0;
node* ListAdd(node ** p, int i){
node *l=(node*)malloc(sizeof(node));
l->next=*p;
*p=l;
l->data=i;
return l;
}
void ListRemove(node ** p) {
    if (p) {
        node *n = *p;
	*p = (*p)->next;
	free(n);
    }
}
/*database* DatabaseAdd(database ** p, int sc,char n[10],char s[32]){
database *l=(database*)malloc(sizeof(database));
l->next=*p;
*p=l;
l->score=sc;
//l->nev=n;
//l->seed=s;
return l;
}*/
char* OpenSeed(){
    node *seed=NULL;
    int len=0;
    sum=time(0);
    FILE *fajl;
    fajl=fopen("seed.txt","r");
    char c;
    if(fajl==NULL){
        srand(sum);

        return;
    }
    else{

        while(1){
        c=fgetc(fajl);
        if(c==EOF){

            break;
        }
        ListAdd(&seed,c);


        len++;
        }
    }
    fclose(fajl);
    seedlanc=(char*)malloc(len*sizeof(c));


    for(int i=0;i<len;i++){
        seedlanc[i]=seed->data;
        seed=seed->next;

    }


    for(int i=0;i<len;i++){
        sum=sum+(int)seedlanc[i]*(len-i)*10;
    }
    srand(sum);
    ListRemove(seed);
    return seedlanc;
    }


void Over(){
Sleep(2000);
system("cls");
printf("Game Over");
SaveDatabase();
getch();
free(seedlanc);

}
void SaveDatabase(){
FILE *fajl;
    fajl=fopen("database.txt","a");
    fprintf(fajl,"%s",name);
    fprintf(fajl,"\n");
    fprintf(fajl,"%d",point);
    fprintf(fajl,"\n");
    fprintf(fajl, "%d",sum);
    fclose(fajl);
}

void RotationI(){
    int x,y,b;
        b=0;
        for(int i=0;i<16;i++){
            for(int j=0;j<10;j++){
                if(Jatekter[i][j]==2){
                    x=j;
                    y=i;
                    b=1;

                    break;
                }
            }
            if(b==1){
            break;
        }

    }
    switch(rotation){
case 0:

        if(Jatekter[0][x]==2){break;}
        if(Jatekter[1][x]==2){break;}


    if(Jatekter[y+1][x+2]!=1 && Jatekter[y][x+2]!=1&&Jatekter[y-1][x+2]!=1&&Jatekter[y-2][x+2]!=1){
       Clear();
       Jatekter[y+1][x+2]=2;
       Jatekter[y][x+2]=2;
       Jatekter[y-1][x+2]=2;
       Jatekter[y-2][x+2]=2;
        rotation=1;
    }
    break;
case 1:

        if(Jatekter[y][0]==2){break;}
        if(Jatekter[y][1]==2){break;}
        if(Jatekter[y][9]==2){break;}


    if(Jatekter[y+2][x]!=1 && Jatekter[y+2][x+1]!=1&&Jatekter[y-2][x-1]!=1&&Jatekter[y+2][x+2]!=1){
       Clear();
       Jatekter[y+2][x]=2;
       Jatekter[y+2][x+1]=2;
       Jatekter[y+2][x-1]=2;
       Jatekter[y+2][x-2]=2;
        rotation=0;
    }
    break;
    }



}
void RandAlakzat(){
if(alakzat==0){
    switch(rand()%6){
    case 0: gameover=createI();break;
    case 1: gameover=createO();break;
    case 2: gameover=createJ();break;
    case 3: gameover=createL();break;
    case 4: gameover=createT();break;
    case 5: gameover=createZ();break;
    case 6: gameover=createS();break;

    }

}
}
void RotationJ(){



    int x,y,b;
    b=0;
    for(int i=0;i<16;i++){
        for(int j=0;j<10;j++){
            if(Jatekter[i][j]==2){
                x=j;
                y=i;
                b=1;

                break;
            }
        }
        if(b==1){
        break;
        }

    }
    switch(rotation){

case 0:

    if(Jatekter[y][x+1]!=1 && Jatekter[y][x+2]!=1 &&Jatekter[y+1][x+1]!=1 && Jatekter[y+2][x+1]!=1 ){
        Clear();
        Jatekter[y][x+1]=2;
        Jatekter[y][x+2]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y+2][x+1]=2;
        rotation=1;


    }
    break;
case 1:

    if(Jatekter[y][0]==2){break;}
    if(Jatekter[y][9]==2){break;}
    if(Jatekter[y+1][x]!=1 && Jatekter[y+1][x-1]!=1 &&Jatekter[y+1][x+1]!=1 && Jatekter[y+2][x+1]!=1){
        Clear();
        Jatekter[y+1][x]=2;
        Jatekter[y+1][x-1]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y+2][x+1]=2;
        rotation=2;


    }
    break;
case 2:


    if(Jatekter[y][x+1]!=1 && Jatekter[y-1][x+1]!=1 &&Jatekter[y+1][x+1]!=1 && Jatekter[y+1][x]!=1){
        Clear();
        Jatekter[y][x+1]=2;
        Jatekter[y-1][x+1]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y+1][x]=2;
        rotation=3;


    }
    break;
case 3:
    if(Jatekter[y][0]==2){break;}
    if(Jatekter[y][9]==2){break;}
    if(Jatekter[y][x-1]!=1 && Jatekter[y+1][x-1]!=1 &&Jatekter[y+1][x+1]!=1 && Jatekter[y+1][x]!=1){
        Clear();
        Jatekter[y][x-1]=2;
        Jatekter[y+1][x-1]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y+1][x]=2;
        rotation=0;
    }
    break;


    }
}
void RotationL(){



    int x,y,b;
    b=0;
    for(int i=0;i<16;i++){
        for(int j=0;j<10;j++){
            if(Jatekter[i][j]==2){
                x=j;
                y=i;
                b=1;

                break;
            }
        }
        if(b==1){
        break;
        }

    }
    switch(rotation){

case 0:

    if(Jatekter[y][x-1]!=1 && Jatekter[y+1][x-1]!=1 &&Jatekter[y+2][x-1]!=1 && Jatekter[y+2][x]!=1 ){
        Clear();
        Jatekter[y][x-1]=2;
        Jatekter[y+1][x-1]=2;
        Jatekter[y+2][x+-1]=2;
        Jatekter[y+2][x]=2;
        rotation=1;


    }
    break;
case 1:

    if(Jatekter[y][0]==2){break;}
    if(Jatekter[y][9]==2){break;}
    if(Jatekter[y+1][x]!=1 && Jatekter[y+1][x-1]!=1 &&Jatekter[y+1][x+1]!=1 && Jatekter[y+2][x-1]!=1){
        Clear();
        Jatekter[y+1][x]=2;
        Jatekter[y+1][x-1]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y+2][x-1]=2;
        rotation=2;


    }
    break;
case 2:


    if(Jatekter[y-1][x]!=1 && Jatekter[y-1][x+1]!=1 &&Jatekter[y][x+1]!=1 && Jatekter[y+1][x+1]!=1){
        Clear();
        Jatekter[y-1][x+1]=2;
        Jatekter[y-1][x]=2;
        Jatekter[y][x+1]=2;
        Jatekter[y+1][x+1]=2;
        rotation=3;


    }
    break;
case 3:
    if(Jatekter[y][0]==2){break;}
    if(Jatekter[y][9]==2){break;}
    if(Jatekter[y][x+2]!=1 && Jatekter[y+1][x]!=1 &&Jatekter[y+1][x+1]!=1 && Jatekter[y+1][x+2]!=1){
        Clear();
        Jatekter[y][x+2]=2;
        Jatekter[y+1][x+2]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y+1][x]=2;
        rotation=0;
    }
    break;


    }
}

void RotationZ(){
int x,y,b;
        b=0;
        for(int i=0;i<16;i++){
            for(int j=0;j<10;j++){
                if(Jatekter[i][j]==2){
                    x=j;
                    y=i;
                    b=1;

                    break;
                }
            }
            if(b==1){
            break;
        }

    }
    switch(rotation){
case(0):
    if(Jatekter[0][x]==2){break;}
    if(Jatekter[y-1][x+2]!=1&&Jatekter[y][x+1]!=1&&Jatekter[y][x+2]!=1&&Jatekter[y+1][x+1]!=1){
        Clear();
        Jatekter[y-1][x+2]=2;
        Jatekter[y][x+1]=2;
        Jatekter[y][x+2]=2;
        Jatekter[y+1][x+1]=2;
        rotation=1;


    }
    break;
case(1):
    if(Jatekter[y+2][0]==2){break;}
    if(Jatekter[y+1][9]==2){break;}
    if(Jatekter[y+1][x-2]!=1&&Jatekter[y+1][x-1]!=1&&Jatekter[y+2][x]!=1&&Jatekter[y+2][x-1]!=1){
        Clear();
        Jatekter[y+2][x-1]=2;
        Jatekter[y+1][x-2]=2;
        Jatekter[y+1][x-1]=2;
        Jatekter[y+2][x]=2;
        rotation=0;

    }
     break;
    }

}
void RotationS(){
    int x,y,b;
        b=0;
        for(int i=0;i<16;i++){
            for(int j=0;j<10;j++){
                if(Jatekter[i][j]==2){
                    x=j;
                    y=i;
                    b=1;

                    break;
                }
            }
            if(b==1){
            break;
        }

    }
    switch(rotation){
case 0:
    if(Jatekter[0][x]==2){break;}
    if(Jatekter[y][x]!=1&&Jatekter[y][x+1]!=1&&Jatekter[y-1][x]!=1&&Jatekter[y+1][x+1]!=1){
        Clear();
        Jatekter[y][x]=2;
        Jatekter[y][x+1]=2;
        Jatekter[y-1][x]=2;
        Jatekter[y+1][x+1]=2;
        rotation=1;


    }
    break;
case 1:
    if(Jatekter[y+1][0]==2){break;}
    if(Jatekter[y+1][x]!=1&&Jatekter[y+1][x+1]!=1&&Jatekter[y+2][x-1]!=1&&Jatekter[y+2][x]!=1){
        Clear();
        Jatekter[y+1][x]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y+2][x-1]=2;
        Jatekter[y+2][x]=2;
        rotation=0;
    }
    break;
    }
}
void RotationT(){
     int x,y,b;
        b=0;
        for(int i=0;i<16;i++){
            for(int j=0;j<10;j++){
                if(Jatekter[i][j]==2){
                    x=j;
                    y=i;
                    b=1;

                    break;
                }
            }
            if(b==1){
            break;
        }

    }
    switch(rotation){
case 0:

    if(Jatekter[y][x]!=1&&Jatekter[y+1][x+1]!=1&&Jatekter[y+1][x]!=1&&Jatekter[y+2][x]!=1){
        Clear();
        Jatekter[y][x]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y+1][x]=2;
        Jatekter[y+2][x]=2;
        rotation=1;
    }
    break;
case 1:
    if(Jatekter[y][0]==2){break;}
    if(Jatekter[y][9]==2){break;}
     if(Jatekter[y+1][x]!=1&&Jatekter[y+2][x]!=1&&Jatekter[y+1][x-1]!=1&&Jatekter[y+1][x+1]!=1){
        Clear();
        Jatekter[y+1][x]=2;
        Jatekter[y+2][x]=2;
        Jatekter[y+1][x-1]=2;
        Jatekter[y+1][x+1]=2;
        rotation=2;
    }
    break;
case 2:
     if(Jatekter[y][x]!=1&&Jatekter[y+1][x+1]!=1&&Jatekter[y][x+1]!=1&&Jatekter[y-1][x+1]!=1){
        Clear();
        Jatekter[y][x]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y][x+1]=2;
        Jatekter[y-1][x+1]=2;
        rotation=3;
    }
    break;
case 3:
    if(Jatekter[y][0]==2){break;}
    if(Jatekter[y][9]==2){break;}
     if(Jatekter[y][x]!=1&&Jatekter[y+1][x+1]!=1&&Jatekter[y+1][x-1]!=1&&Jatekter[y+1][x]!=1){
        Clear();
        Jatekter[y][x]=2;
        Jatekter[y+1][x+1]=2;
        Jatekter[y+1][x-1]=2;
        Jatekter[y+1][x]=2;
        rotation=0;
    }
    break;
    }
}
int createI(){
    alakzat=1;
    rotation=0;
    //game over detektalas
    for(int i=0;i<10;i++){
        if(Jatekter[1][i]==1){
            Jatekter[0][3]=2;
            Jatekter[0][4]=2;
            Jatekter[0][5]=2;
            Jatekter[0][6]=2;
            return 1;
        }
    }
    Jatekter[0][3]=2;
    Jatekter[0][4]=2;
    Jatekter[0][5]=2;
    Jatekter[0][6]=2;
}

int createO(){


    alakzat=2;
    rotation=0;
    //game over detektalas
    for(int i=0;i<10;i++){
        if(Jatekter[2][i]==1){
                Jatekter[1][4]=2;
                Jatekter[0][4]=2;
                Jatekter[0][5]=2;
                Jatekter[1][5]=2;
            return 1;
        }
    }
    Jatekter[1][4]=2;
    Jatekter[0][4]=2;
    Jatekter[0][5]=2;
    Jatekter[1][5]=2;
}
void textcolor (int color) {
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}
void hidecursor() {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
int createJ(){


    rotation=0;
    alakzat=3;
    //game over detektalas
    for(int i=0;i<10;i++){
        if(Jatekter[2][i]==1){
            Jatekter[0][3]=2;
            Jatekter[1][3]=2;
            Jatekter[1][4]=2;
            Jatekter[1][5]=2;
            return 1;
        }
    }
    Jatekter[0][3]=2;
    Jatekter[1][3]=2;
    Jatekter[1][4]=2;
    Jatekter[1][5]=2;
}
int createL(){


    rotation=0;
    alakzat=4;
    //game over detektalas
    for(int i=0;i<10;i++){
        if(Jatekter[2][i]==1){
            Jatekter[0][5]=2;
            Jatekter[1][3]=2;
            Jatekter[1][4]=2;
            Jatekter[1][5]=2;
            return 1;
        }
    }
    Jatekter[0][5]=2;
    Jatekter[1][3]=2;
    Jatekter[1][4]=2;
    Jatekter[1][5]=2;
}
int createT(){

    alakzat=5;
    rotation=0;
    //game over detektalas
    for(int i=0;i<10;i++){
        if(Jatekter[2][i]==1){
            Jatekter[0][4]=2;
            Jatekter[1][3]=2;
            Jatekter[1][4]=2;
            Jatekter[1][5]=2;
            return 1;
        }
    }
    Jatekter[0][4]=2;
    Jatekter[1][3]=2;
    Jatekter[1][4]=2;
    Jatekter[1][5]=2;
}
int createZ(){

    alakzat=6;
    rotation=0;
    //game over detektalas
    for(int i=0;i<10;i++){
        if(Jatekter[2][i]==1){
            Jatekter[0][4]=2;
            Jatekter[0][3]=2;
            Jatekter[1][4]=2;
            Jatekter[1][5]=2;
            return 1;
        }
    }
    Jatekter[0][4]=2;
    Jatekter[0][3]=2;
    Jatekter[1][4]=2;
    Jatekter[1][5]=2;
}
int createS(){

    alakzat=7;
    rotation=0;
    //game over detektalas
    for(int i=0;i<10;i++){
        if(Jatekter[2][i]==1){
            Jatekter[0][4]=2;
        Jatekter[0][3]=2;
        Jatekter[1][4]=2;
        Jatekter[1][5]=2;
            return 1;
        }
    }
    Jatekter[0][4]=2;
    Jatekter[0][3]=2;
    Jatekter[1][4]=2;
    Jatekter[1][5]=2;
}
int HCollison(){
    for(int i=15;i>=0;i--){
        for (int j=0;j<10;j++){
            if(Jatekter[i][j]==2 && Jatekter[i+1][j]==1){

                Freeze();
                return 1;
            }
        }
    }
   return 0;

}
void Score(){
    int count=0;
for (int i=0;i<16;i++){
    if(Jatekter[i][0]==1&&Jatekter[i][1]==1&&Jatekter[i][2]==1&&Jatekter[i][3]==1&&Jatekter[i][4]==1&&Jatekter[i][5]==1&&Jatekter[i][6]==1&&Jatekter[i][7]==1&&Jatekter[i][8]==1&&Jatekter[i][9]==1){
        count++;
    } }
    switch(count){
case 0:
    point=point;
    break;
case 1:
    point=point+40;
    break;
case 2:
    point=point+100;
    break;
case 3:
    point=point+300;
    break;
case 4:
    point=point+1200;
    break;
    }
for(int a=0;a<count;a++){
    for (int i=0;i<16;i++){
    if(Jatekter[i][0]==1&&Jatekter[i][1]==1&&Jatekter[i][2]==1&&Jatekter[i][3]==1&&Jatekter[i][4]==1&&Jatekter[i][5]==1&&Jatekter[i][6]==1&&Jatekter[i][7]==1&&Jatekter[i][8]==1&&Jatekter[i][9]==1){
        Jatekter[i][0]=0;
        Jatekter[i][1]=0;
        Jatekter[i][2]=0;
        Jatekter[i][3]=0;
        Jatekter[i][4]=0;
        Jatekter[i][5]=0;
        Jatekter[i][6]=0;
        Jatekter[i][7]=0;
        Jatekter[i][8]=0;
        Jatekter[i][9]=0;

        for(int f=i;f>=0;f--){
            for(int j=0;j<10;j++){
                if(Jatekter[f][j]==1){
                    Jatekter[f][j]=0;
                    Jatekter[f+1][j]=1;
                }
            }
        }
        break;
    } }

}
}


void Freeze(){

    alakzat=0;
    for (int i=0;i<16;i++){
        for(int j=0;j<10;j++){
            if(Jatekter[i][j]==2){
                Jatekter[i][j]=1;
            }
        }
    }
}

void Clear(){
    for (int i=0;i<16;i++){
        for(int j=0;j<10;j++){
            if(Jatekter[i][j]==2){
                Jatekter[i][j]=0;
            }
        }
    }
}
void Gravity(){
    if(timer%speed!=0){return;}
    if(timer%2==0 &&speed!=15){
        speed--;
    }
    for(int i=15;i>=0;i=i-1){
        for (int j=0;j<10;j++){
            if(Jatekter[i][j]==2){
                Jatekter[i][j]=0;
                Jatekter[i+1][j]=2;

            }
        }
    }
}
void Down(){
    for(int i=15;i>=0;i=i-1){
        for (int j=0;j<10;j++){
            if(Jatekter[i][j]==2){
                Jatekter[i][j]=0;
                Jatekter[i+1][j]=2;

            }
        }
    }
}

void Left(){
    for (int i=0;i<16;i++){
        if(Jatekter[i][0]==2){
            return;
        }
    }
    for (int i=0;i<16;i++){
        for(int j=0;j<10;j++){
        if(Jatekter[i][j+1]==2 && Jatekter[i][j]==1){
            return;
        }
        }
    }
    for (int i=0;i<16;i++){
        for(int j=0;j<10;j++){
           if(Jatekter[i][j+1]==2){
            Jatekter[i][j]=2;
            Jatekter[i][j+1]=0;
           }
    }
        }
}

void Right(){




    for (int i=0;i<16;i++){
        if(Jatekter[i][9]==2){
            return;
        }
    }
    for (int i=0;i<16;i++){
        for(int j=8;j>=0;j--){
        if(Jatekter[i][j]==2 && Jatekter[i][j+1]==1){

            return;
        }
        }
    }
    for (int i=0;i<16;i++){
        for(int j=9;j>=0;j--){
           if(Jatekter[i][j]==2){
            Jatekter[i][j+1]=2;
            Jatekter[i][j]=0;
           }
    }
        }
}
void Printer(){
for(int i=0;i<12;i++){
    textcolor(15);
    printf("-");
}
for(int i=0;i<16;i++){

        printf("\n");
        textcolor(15);
        printf("|");
    for (int j=0;j<10;j++){
        //printf("%d",Jatekter[i][j]);
        switch(Jatekter[i][j]){
    case 0:
        textcolor(0);
        printf(" ");
        break;
    case 1:
        textcolor(9);
        printf("O");

        break;
    case 2:
        textcolor(4);
        printf("O");

        break;
        }

    }

    textcolor(15);
        printf("|");
        switch(i){
    case 1:
        textcolor(15);
        printf("        Nev: ");
        printf("%s",name);
        break;
    case 2:
        textcolor(15);
        printf("        Pont: ");
        printf("%d",point);
        break;
   /* case 3:
        textcolor(15);
        printf("        Sebesseg: ");
        int szazalek=(50-speed)+(50-speed);
        printf("%d", szazalek);
        printf("%%");

        break;*/
        }

}
printf("\n");
for(int i=0;i<12;i++){
    textcolor(15);
    printf("-");
}
}
void Control(){
    char c;
    if(kbhit()){
    c=getch();
}
    switch(c) {
        case 72:
            switch(alakzat){
    case 1: RotationI();break;
    case 2: break;
    case 3: RotationJ();break;
    case 4: RotationL();break;
    case 5: RotationT();break;
    case 6: RotationZ();break;
    case 7: RotationS();break;
            }

            break;
        case 80:

            Down();

            break;
        case 77:
            Right();
            break;
        case 75:
            Left();
            break;

    }


}
void Gotoxy( int x, int y )
  {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
int main(){
printf("Tetris\n");
printf("Nev: ");
scanf("%s",&name);
system("cls");
hidecursor();

OpenSeed();
while(1){
if(alakzat==0){
    RandAlakzat();
}
Printer();
if(gameover==1){
    Over();
    break;
}
Gravity();
Control();
HCollison();

Score();
Gotoxy(0,0);
//system("cls");
if(timer==99){
    timer=0;
}
timer=timer+1;


}
}

