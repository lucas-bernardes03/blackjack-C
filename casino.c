#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "casino.h"
#include <unistd.h>
#include <string.h>

int main(){
    int main_op,game_op,balance,f_op;
    int bj_op,ms_op;

    balance = 0;
    //balance = profile();  WIP

    while(1){
        main_op = menu();
        if(main_op == 0) { //termino do programa
            system("cls");
            printf("\n\nOBRIGADO POR JOGAR!\n\n\n");
            sleep(3);
            system("cls");
            break;
        }
        
        else if(main_op == 1){ //menu de jogos 
            while(1){
                game_op = games_menu();
                if(game_op == 1){
                    while(1){
                        bj_op = blackjack_m();
                        if(bj_op == 1) balance = blackjack_bet(balance);
                        else if(bj_op == 2) bj_about();
                        else if(bj_op == 0) break;
                    }
                } 
                else if(game_op == 2){
                    while(1){
                        ms_op = minesweeper_m();
                        if(ms_op == 0) break;
                    }
                } 
                else if(game_op == 0) break;
            }
        }

        else if(main_op == 2){ //fichas
            while(1){
                f_op = fichas(balance);
                if(f_op == 1) balance += fichas_add(balance);
                else if(f_op == 2) balance -= fichas_trade(balance);
                else if(f_op == 0) break;
            }
        }

        else if(main_op == 3){ //sobre
            casino_about();
        } 
    }

    return 0;
}







