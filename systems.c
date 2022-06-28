#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "casino.h"
#include <unistd.h>
#include <string.h>

int menu(void){  //menu principal
    int op;
    system("cls");
    printf("BEM VINDO AO CASSINO\n\n");
    printf("|1| Jogos\n");
    printf("|2| Fichas\n");
    printf("|3| Sobre o Projeto\n\n");
    printf("|0| Sair\n\n");
    printf("-> ");
    scanf("%d",&op);
    return op;
}

int games_menu(void){ //menu de jogos
    int op;
    system("cls");
    printf("JOGOS DISPONIVEIS\n\n");
    printf("|1| Blackjack\n");
    printf("|2| Minesweeper\n\n");
    printf("|0| Voltar\n\n");
    printf("-> ");
    scanf("%d",&op);
    return op;
}

int minesweeper_m(void){ //menu minesweeper WIP
    int op;
    system("cls");
    printf("WIP\n\n");
    printf("|0| Sair\n\n");
    printf("-> ");
    scanf("%d",&op);
    return op;
}

int fichas(int balance){ //sistema de fichas 
    int op;
    system("cls");
    printf("SEU SALDO DE FICHAS:\n\n");
    printf("    %d Fichas\n\n",balance);
    printf("|1| Adicionar Fichas\n");
    printf("|2| Trocar Fichas\n\n");
    printf("|0| Voltar\n\n");
    printf("-> ");
    scanf("%d",&op);
    return op;
}

int fichas_add(int balance){ //adicionar fichas
    int add,op,tmp;
    system("cls");
    printf("QUANTAS FICHAS DESEJA ADICIONAR? (1 - 1000)\n\n");
    printf("Quantidade: ");
    scanf("%d",&add);
    
    if(add <= 1000 && add > 0){
        system("cls");
        printf("Tem certeza que deseja adicionar %d fichas?\n\n",add);
        printf("|1| Sim\n");
        printf("|2| Nao\n\n");
        scanf("%d",&op);
    }
    else if(add <= 0){
        system("cls");
        printf("VALOR INVALIDO!\n\n");
        printf("|0| Voltar\n\n");
        printf("-> ");
        scanf("%d",&tmp);
        return 0;
    }
    else{
        system("cls");
        printf("VOCE ESTA TENTANDO ADICIONAR FICHAS DEMAIS!\n\n");
        printf("|0| Voltar\n");
        scanf("%d",&tmp);
        return 0;
    }

    if(op == 1){
        system("cls");
        printf("Voce adicionou %d fichas com sucesso!\n\n",add);
        printf("Boas apostas!\n\n");
        printf("|0| Sair\n\n");
        printf("-> ");
        scanf("%d",&op);
        return add;
    }
    else if(op == 2) fichas_add(balance);
}

int fichas_trade(int balance){ //trocar fichas WIP
    int op;
    system("cls");
    printf("\n");
    printf("ESTAMOS TRABALHANDO NOS PREMIOS!\n\n\n");
    printf("|0| Voltar\n\n");
    printf("-> ");
    scanf("%d",&op);
    return 0;
}

void casino_about(void){ //resumo do resumo
    int tmp;
    system("cls");
    printf("SOBRE O PROJETO\n\n");
    printf("Bem simples, feito em C puro, projeto pessoal.\n");
    printf("A ideia era fazer jogos de apostas que se encontra em sites de aposta e em casinos.\n");
    printf("Com o tempo vou adicionando novos jogos, assim que encontro um boa maneira de implementa-los.\n");
    printf("E isso.\n\n");
    printf("|0| Voltar\n\n");
    printf("-> ");
    scanf("%d",&tmp);
}

int profile(void){ // menu de perfis WIP
    int pf_id[20],pf_blc[20],id=0,i,op;
    char pf_name[20], pf_pass[20];
    char name[20][20], pass[20][20];

    FILE *profile; 
    profile = fopen("profiles.txt","r");

    while(fscanf(profile,"%d %s %d %s",&pf_id[id],pf_name,&pf_blc[id],pf_pass) != EOF){
        strcpy(name[id],pf_name);
        strcpy(pass[id],pf_pass);
        id++;
    }

    fclose(profile);

    system("cls");
    printf("BEM VINDO AO CASINO!\n\n\n");
    printf("|1| Ja tenho conta no casino.\n");
    printf("|2| Quero criar uma conta.\n\n");
    printf("-> ");
    scanf("%d",&op);

    if(op == 1){ // selecionar um perfil existente
        system("cls");
        printf("DIGITE O ID DA SUA CONTA\n\n\n");
        printf("ID: ");
        scanf("%d",&i);

        while(i < 0 || i >= id){
            system("cls");
            printf("ID invalido! Por favor tente novamente.\n\n");
            printf("DIGITE O ID DA SUA CONTA\n\n\n");
            printf("ID: ");
            scanf("%d",&i);
        }

        password(pass[i]);

        printf("ID: %d\n",pf_id[i]);
        printf("Nome: %s\n",name[i]);
        printf("Fichas: %d\n\n",pf_blc[i]);
        
        printf("Bem Vindo %s!\n\n",name[i]);
        printf("|0| Entrar no Casino\n\n");
        printf("-> ");
        
        scanf("%d",&op);
        
        return pf_blc[i];
    }

    else if(op == 2){ //criar um perfil WIP
    
    }

}

void password(char * cpass){ //senhas
    char trypass[20];
    int op;

    printf("Digite a senha da conta: ");
    scanf("%s",trypass);

    if(strcmp(cpass,trypass) != 0){
        system("cls");
        printf("Senha Incorreta!\n\n");
        printf("|0| Tentar Novamente\n\n");
        printf("-> ");
        scanf("%d",&op);
        system("cls");
        password(cpass);
    }
    system("cls");
}