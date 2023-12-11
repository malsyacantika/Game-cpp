#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    char mv;
    char repeat='y';
    int highscore=0;
    while (repeat=='y'){
    int score=0;
    bool wasit=true;
    int x=9;
    int obstacle[3]; 
    int block[3]; 
    obstacle[0]=10;
    obstacle[1]=18;
    obstacle[2]=27; 
    for (int i=0;i<3;i++)
    {
        obstacle[i]=(rand()-1)%12+2;
    }
    string map[20][30];
    for (int i=0;i<20;i++)
    {
        for (int j=0;j<30;j++)
        {
            if ( i==0 || i==19|| j==29 || j==0)
                map[i][j]="* ";
            else
                map[i][j]="  ";
        }
    }
    while (wasit == true)
    {
        for (int i =0;i<3;i++)
        {
            for (int j=1;j<20;j++)
            {
                map[j][obstacle[i]]="  ";
            }
        }
        for (int i=0;i<3;i++) 
        {
            obstacle[i]++;
        }
        for (int i =0;i<3;i++) 
        {
            for (int j=1;j<20;j++)
            {
                map[j][obstacle[i]]="* ";
            }
        }
        for (int i=0;i<3;i++) 
        {
            map[obstacle[i]][obstacle[i]]="  ";
            map[obstacle[i]+1][obstacle[i]]="  ";
            map[obstacle[i]+2][obstacle[i]]="  ";
            map[obstacle[i]+3][obstacle[i]]="  ";
            map[obstacle[i]+4][obstacle[i]]="  ";
        }
        for (int i=0;i<3;i++)
        {
            if (obstacle[i]==1)
                {obstacle[i]=28;
                obstacle[i]=(rand()-1)%12+2;
                }
        }
        map[x][3]="  ";
        if (kbhit())
        {
            mv=getch();
            x=x-3;
        }
        x++;
        if(x<1)
            x=1;
        for (int i=0;i<3;i++)
        {
            if (obstacle[i]==3)
                if (map[x][3]=="  ")
                    score=score+1;
                if (map[x][3]=="* ")
                    wasit=false;
        }
        map[x][5]="@ ";
        for (int i=1;i<100;i++)
        {
            map[i][1]="  ";
        }
        for (int i=0;i<100;i++)
        {
            for (int j=0;j<30;j++)
            {
                cout << map[i][j];
            }
        cout <<endl;
        }
        cout << "Score = "<<score;
    Sleep (100);
    system ("cls");
    }
    cout << "Score = " <<score<<endl;
    if (highscore<score)
        highscore=score;
    cout << "Highscore= "<<highscore<<endl;
    cout << "retry?(y/n) = "; cin >>repeat;}
    return 0;
}
