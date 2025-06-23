#include<graphics.h>
int main()
{
    //Tasnim Hassan Mohammed , sec:6
    initwindow(700,700,"chess game",0,0);

    for(int x=1;x<=8;x+=1){
    for(int y=1;y<=8;y+=1){
    if((x+y)%2==0){
    setfillstyle(SOLID_FILL,WHITE);
    } else{
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    } bar(x*60,y*60,(x+1)*60,(y+1)*60);
    }}

    readimagefile("rook_black_1.ico",60,60,120,120);
    readimagefile("knight_black_1.ico",110,60,195,120);
    readimagefile("bishop_black_1.ico",180,60,120,120);
    readimagefile("king_black_1.ico",230,60,150,120);
    readimagefile("queen_black_1.ico",280,60,190,120);
    readimagefile("bishop_black_1.ico",350,60,270,120);
    readimagefile("knight_black_1.ico",405,60,320,120);
    readimagefile("rook_black_1.ico",470,60,400,120);
    for(int o=1;o<=8;o++){
    readimagefile("pawn_black_1.ico",o*60,125,o*60+60,175);
    }

    readimagefile("rook_white_1.ico",60,480,120,540);
    readimagefile("knight_white_1.ico",110,480,190,540);
    readimagefile("bishop_white_1.ico",180,480,250,540);
    readimagefile("king_white_1.ico",230,480,300,540);
    readimagefile("queen_white_1.ico",290,480,360,540);
    readimagefile("bishop_white_1.ico",360,480,410,540);
    readimagefile("knight_white_1.ico",415,480,480,540);
    readimagefile("rook_white_1.ico",480,480,550,540);
    for(int q=1;q<=8;q++){
    readimagefile("pawn_white_1.ico",q*60,420,q*60+60,480);
    }
    char letter[8]="A";
    for(int t=80;t<=510;t+=60){
        outtextxy(t,550,letter);
        outtextxy(t,40,letter);
        letter[0]++;
       }
    char number[8]="1";
    for(int m=80;m<=510;m+=60){
     outtextxy(40,m,number);
     outtextxy(550,m,number);
     number[0]++;
    }

    system("pause");
    return 0;
}
