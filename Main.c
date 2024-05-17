#include<stdio.h>
#include<conio.h>

void PrintBoard();
int checkwin();
void system();

char board[]={'0','1','2','3','4','5','6','7','8','9'};

 
void main(){
    int Player=1,input,status=-1;
    PrintBoard();
    

    while (status==-1)
    {
        Player=(Player%2==0) ? 2 : 1;
        char mark=(Player==1)?'x':'o';
        printf("please enter number for player %d\n",Player);
        scanf("%d",&input);
    if(input<1 || input>9){
        printf("invalid input");
    }

    board[input]=mark;
    PrintBoard();

    int result=checkwin();

    if(result==1){
        printf("player %d is the Winner",Player);
        return;
    }else if(result==0){
        printf("draw");
        return;
    }
    Player++;
    }
  
}

void PrintBoard(){
    system("cls");
    printf("\n\n");
    printf("== TIC TAC TOE ==\n\n");
    printf("   |   |   \n");
    printf("%c  | %c | %c \n",board[1],board[2],board[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf("%c  | %c | %c \n",board[4],board[5],board[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf("%c  | %c | %c \n",board[7],board[8],board[9]);
    printf("   |   |   \n");
    printf("\n\n");
}

int checkwin(){

    if(board[1]==board[2] && board[2]==board[3]){
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7]){
        return 1;
    }
    if(board[7]==board[8] && board[8]==board[9]){
        return 1;
    }
    if(board[3]==board[6] && board[6]==board[9]){
        return 1;
    }
    if(board[1]==board[5] && board[5]==board[9]){
        return 1;
    }
    if(board[3]==board[5] && board[5]==board[7]){
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8]){
        return 1;
    }
    if(board[4]==board[5] && board[5]==board[6]){
        return 1;
    }
    

    int count=0;
    for (int i = 1; i <=9; i++)
    {
        if(board[i]=='x' || board[i]=='o'){
            count++;
        }
    }

    if(count==9){
        return 0;
    }
    return -1;
}