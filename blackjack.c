#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "casino.h"
#include <unistd.h>
#include <string.h>

int blackjack_m(void){ //menu blackjack

    int op;
    system("cls");
    printf("BEM VINDO AO BLACKJACK\n\n");
    printf("|1| Jogar\n");
    printf("|2| Sobre o Jogo\n\n");
    printf("|0| Voltar\n\n");
    printf("-> ");
    scanf("%d",&op);
    return op;
}

int blackjack_bet(int balance){ // menu de apostas
    int op,bet;
    system("cls");
    printf("FICHAS DISPONIVEIS: %d\n\n",balance);
    printf("Quanto deseja apostar? ");
    scanf("%d",&bet);
    if(bet == 0) return balance;
    else if(bet < 0 || bet > balance){
        system("cls");
        printf("VALOR INVALIDO!\n\n");
        printf("|0| Voltar");
        printf("-> ");
        scanf("%d",&op);
        blackjack_bet(balance);
    }
    else balance = blackjack_maingame(balance,bet);
    return balance;
}

int blackjack_maingame(int balance, int bet){ // sistema do jogo
    int dl[21],pl[21],r,d=0,p=0,i,dt=0,pt,op,asp=0,asd=0;
    while(1){
        srand(time(NULL));
        
        if(d == 0){ // primeira carta do dealer
            system("cls");
            printf("DEALER: ");
            
            dl[d] = (rand() % 13) + 1;
            
            if(dl[d] == 1) printf("|A|");
            else if(dl[d] == 11) printf("|J|");               
            else if(dl[d] == 12) printf("|Q|");
            else if(dl[d] == 13) printf("|K|");

            else printf("|%d|",dl[d]);
            
            d++;
            
            printf("\n\n\n");
            printf("JOGADOR: \n\n\n");
            printf("|1| Hit\n\n");
            printf("-> ");
            scanf("%d",&op);
        }
        
        else if(p == 0){ // mao do jogador
            while(p != 20){
                srand(time(NULL));
                system("cls");
                printf("DEALER: ");

                if(dl[0] == 1) printf("|A|");
                else if(dl[0] == 11) printf("|J|");               
                else if(dl[0] == 12) printf("|Q|");
                else if(dl[0] == 13) printf("|K|");
                else printf("|%d|",dl[0]);
                
                printf("\n\n\n");

                printf("JOGADOR: ");
                pt = 0;

                pl[p] = (rand() % 13) + 1;
                p++;

                for(i=0;i<p;i++){
                    if(pl[i] == 1){
                        printf("|A| ");
                        pt += 1;
                        asp++;
                    } 
                    else if(pl[i] == 11){
                        printf("|J| ");
                        pt += 10;
                    } 
                    else if(pl[i] == 12){
                        printf("|Q| ");
                        pt += 10;
                    } 
                    else if(pl[i] == 13){
                        printf("|K| ");
                        pt += 10;
                    } 
                    else{
                        printf("|%d| ",pl[i]);
                        pt += pl[i];
                    } 
                }
                
                if(asp > 0){
                   if(pt+10 < 22) printf("- Total: %d ou %d",pt,pt+10); 
                   else printf("- Total: %d",pt);
                }
                else printf("- Total: %d",pt);

                if(pt > 21){ //estouro
                    printf("\n\n");
                    printf("VOCE PERDEU %d fichas!\n",bet);
                    printf("Infelizmente voce passou de 21 pontos.\n\n");
                    printf("|0| Voltar\n\n");
                    printf("-> ");
                    scanf("%d",&op);
                    balance -= bet;
                    return balance;
                }
                
                printf("\n\n\n");

                if(p == 1) printf("|1| Hit\n\n");
                else{
                    printf("|1| Hit\n");
                    printf("|2| Stand\n\n");
                }

                printf("-> ");
                scanf("%d",&op);
                if(op == 2){
                    if(asp > 0 && pt+10 < 22) pt += 10;
                    break;
                }
            }   
        }

        else if(d == 1){ // mao do dealer
            system("cls");
            while(d != 20){
                srand(time(NULL));
                system("cls");
                dt = 0;
                printf("DEALER: ");
                for(i=0;i<d;i++){
                    if(dl[i] == 1){
                        printf("|A| ");
                        dt += 1;
                        asd++;
                    } 
                    else if(dl[i] == 11){
                        printf("|J| ");
                        dt += 10;
                    } 
                    else if(dl[i] == 12){
                        printf("|Q| ");
                        dt += 10;
                    } 
                    else if(dl[i] == 13){
                        printf("|K| ");
                        dt += 10;
                    } 
                    else{
                        printf("|%d| ",dl[i]);
                        dt += dl[i];
                    } 
                }
                if(asd > 0){
                   if(dt+10 < 22) printf("- Total: %d ou %d",dt,dt+10); 
                   else printf("- Total: %d",dt);
                }
                else printf("- Total: %d",dt);

                printf("\n\n\n");
                printf("JOGADOR: ");
                for(i=0;i<p;i++){
                    if(pl[i] == 1) printf("|A| ");
                    else if(pl[i] == 11) printf("|J| ");               
                    else if(pl[i] == 12) printf("|Q| ");
                    else if(pl[i] == 13) printf("|K| ");
                    else printf("|%d| ",pl[i]);
                } 
                printf("- Total: %d\n\n",pt);
                
                if(asd > 0){
                    if(dt+10 >= 17 && dt+10 <= 21){
                        dt += 10;
                        printf("O DEALER PAROU!\n");
                        sleep(3);
                        break;
                    }
                    else if(dt >= 17 && dt <= 21){
                        printf("O DEALER PAROU!\n");
                        sleep(3);
                        break;
                    }
                    else if(dt > 21){
                        printf("O DEALER PERDEU!\n");
                        printf("Parabens! Voce ganhou %d fichas!\n\n",bet);
                        printf("|0| Voltar\n\n");
                        printf("-> ");
                        scanf("%d",&op);
                        balance += bet;
                        return balance;
                    }
                }
                else{
                    if(dt >= 17 && dt <= 21){
                        printf("O DEALER PAROU!\n");
                        sleep(3);
                        break;
                    }   
                    if(dt > 21){
                        printf("O DEALER PERDEU!\n");
                        printf("Parabens! Voce ganhou %d fichas!\n\n",bet);
                        printf("|0| Voltar\n\n");
                        printf("-> ");
                        scanf("%d",&op);
                        balance += bet;
                        return balance;
                    }
                }
                
                printf("O DEALER ESTA JOGANDO\n");

                dl[d] = (rand() % 13) + 1;
                d++;

                sleep(3);
            }
        }

        else{ // resultado
            system("cls");
            printf("O DEALER FICOU COM: %d\n\n",dt);
            printf("O JOGADOR FICOU COM: %d\n\n",pt);
            if(dt == pt){
                printf("O JOGO FICOU EMPATADO!\n");
                printf("Voce recebeu suas fichas de volta!\n\n");
                printf("|0| Voltar\n\n");
                printf("-> ");
                scanf("%d",&op);
                return balance;
            }

            else if(dt > pt){
                printf("O DEALER VENCEU!\n");
                printf("Voce perdeu %d fichas.\n\n",bet);
                printf("|0| Voltar\n\n");
                printf("-> ");
                scanf("%d",&op);
                balance -= bet;
                return balance;
            }

            else if(pt > dt){
                printf("VOCE VENCEU!\n");
                printf("Voce ganhou %d fichas!\n\n",bet);
                printf("|0| Voltar\n\n");
                printf("-> ");
                scanf("%d",&op);
                balance += bet;
                return balance;
            }
        }
    }
}

void bj_about(void){ //sobre o blackjack
    int op;
    system("cls");
    
    printf("COMO FUNCIONA O BLACKJACK?\n");
    
    printf("O jogo e bem simples, voce joga conta o 'Dealer' e seu objetivo e ter uma mao maior que ele.\n");
    printf("Porem existem algumas regras de devem ser seguidas:\n\n");
    printf(" 1 - Caso sua mao ultrapasse os 21 pontos voce perde automaticamente.\n");
    printf(" 2 - Caso o 'Dealer' atinja 17 pontos ou mais ele para obrigatoriamente.\n");
    printf(" 3 - Caso o 'Dealer' ultrapasse os 21 pontos, voce ganha.\n");
    printf(" 4 - Caso haja empate entre voce e o 'Dealer' as fichas sao retornadas.\n\n");
    
    printf("PONTUACAO DAS CARTAS:\n\n");
    printf(" A - O As vale 1 ou 11, dependendo da escolha do jogador.\n");
    printf(" J Q K - Todas as figuras valem 10.\n");
    printf(" 2 a 10 - Valem seus respectivos valores.\n\n");

    printf("ACOES DURANTE O JOGO:\n\n");
    printf(" Hit - Voce recebe mais uma carta do 'Dealer'.\n");
    printf(" Stand - Caso esteja satisfeito com a sua mao, voce para.\n");
    printf(" Double - Se estiver confiante voce dobra a aposta e recebe apenas uma carta.\n");
    printf(" Split - Voce recebeu cartas iguais e deseja dividir entre montes, cada monte e uma nova aposta.\n\n");

    printf("|0| Voltar\n\n");
    printf("-> ");
    scanf("%d",&op);
}