#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void imprime();
void menu();
struct TIPO_CLIENTE{
  int cod;                     
  char nome[50];       
  char tel[20];        
  char email[100];     
};
struct TIPO_CLIENTE clientes[5];
int cont;
int main(){
  int op;
  cont = 1;
  setlocale(LC_ALL,"Portuguese");
  do{
    menu();
    scanf("%d", &op);
    fflush(stdin);
    switch(op){
      case 1:
        system("cls");
        if(cont < 5){
          clientes[cont].cod = cont;
          printf("\nInsira o nome do cliente: \n");
          gets(clientes[cont].nome);
          fflush(stdin);
          printf("\nInsira o telefone do cliente: \n");
          gets(clientes[cont].tel);
          fflush(stdin);
          printf("\nInsira o e-mail do cliente: \n");
          gets(clientes[cont].email);
          fflush(stdin);
          cont++;
        }
        else{
          printf("Agenda lotada!\n");
        }
        system("pause");
        break;
      case 2:
        system("cls");
        if(cont == 0){
          printf("Agenda vazia!\n");
        }else{
          imprime();
        }
        system("pause");
        break;
      default:
        if(op != 0){
          system("cls");
          printf("Opção inválida [%d]!\n", op);
          system("pause");
        }
        break;
    }
  }while(op != 0);
}
void imprime(){
  for(int i=1; i<cont; i++){
    printf("*** Código do cliente: %d \n", clientes[i].cod);
    printf("Nome: %s \n", clientes[i].nome);
    printf("Tel.: %s \n", clientes[i].tel);
    printf("E-mail: %s \n----------\n", clientes[i].email);
  }
}
void menu(){
  system("cls");
  printf("----------- AGENDA - VERSÃO BETA -----------\n");
  printf("1 - Digite 1 para inserir novo cadastro;\n");
  printf("2 - Digite 2 para mostrar clientes cadastrados;\n");
  printf("0 - Digite 0 para encerrar.\n");
}

