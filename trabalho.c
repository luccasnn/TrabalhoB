#include <stdio.h>                  //Luccas Nantes 1904643
#include <string.h>                 //Andre Henrique Caseiro 1905342
#define MAX 100
int ordem=0;
//ordem do usuário
int cont;
int i,j,num,dif=0;
//for,for, tirar"enter", detectar dif. na função pesuisar
int nalunos;
//número de alunos, variável apontadora
int situ[MAX];
//situação do usuário
char lixo,nomepesq[MAX],nomeenter[MAX];

struct alunos {
  int ID;
  char nome[MAX];
  char CPF[MAX];
  char nasc[MAX];

};
typedef struct alunos Tip;

int Cadastrar(Tip alunos[], int nalunos ){
  nalunos++;
  i=nalunos;
  printf("cadastro\n");
  printf("Entre com o nome:\n");
  scanf("%c", &lixo);
  fgets(nomeenter, MAX-1, stdin);
  num=strlen(nomeenter);

  for(j=0;j<num;j++){
    alunos[i].nome[j]=nomeenter[j];
  }

  printf("Entre com a data:\n");
  gets(alunos[i].nasc);

  printf("Entre com CPF:\n");
  gets(alunos[i].CPF);

  printf("%s\n", alunos[i].nome);
  printf("%s\n\n", alunos[i].nasc);
  printf("%s\n\n", alunos[i].CPF);
  situ[i]=1;
  alunos[i].ID=i;
  printf("Seu ID é:%d\n",i);
  return nalunos;
}

void Listar(Tip alunos[],int nalunos){
  printf("listar\n");
  for(i=0;i<MAX;i++){
    if(situ[i]==1){
      printf("Nome:%s\n", alunos[i].nome);
      printf("CPF:%s\n", alunos[i].CPF);
      printf("Data de Nascimento%s\n", alunos[i].nasc);
    }
  }
}

void Pesquisar(Tip alunos[],int nalunos){
  printf("Pesquisar,Informe seu nome:\n");
  scanf("%c",&lixo);
  fgets(nomepesq,MAX-1,stdin);
  num=strlen(nomepesq);

  for(i=1;i<=nalunos;i++){
    for(j=0;j<num-1;j++){
      if(alunos[i].nome[j]!=nomepesq[j]){
      dif++;
      }
    }
  } 

  for(i=1;i<=nalunos;i++){
    if(situ[i]==1&&dif==0){
      printf("CPF:%s\n\n", alunos[i].CPF);
      printf("Data de Nascimento:%s\n\n", alunos[i].nasc);
    }
  }
}

void Atualizar(Tip alunos[],int nalunos){
  int ID;
  char nome[MAX],data[MAX],CPF[MAX];
  printf("Atualizar\n");
  printf("Digite seu ID:\n");
  scanf("%d",&ID);

  for(i=1;i<=nalunos;i++){
    if(alunos[i].ID==ID&&situ[i]==1){
      fgets(nome, 1, stdin);
      printf("Digite seu nome atualizado:\n ");
      scanf("%c", &lixo);
      fgets(nome, MAX-1, stdin);
      num=strlen(nome);

      printf("Sua data de nascimento atualizada:\n");
      scanf("%s", &data);

      printf("Digite seu CPF atualizado:\n");
      scanf("%s", &CPF);
      break;
    }
  }
  num++;
  printf("%d",num);

     for(i=1;i<=nalunos;i++){
        for(j=0;j<MAX-1;j++){
          if(j<num){
          alunos[ID].nome[j]=nome[j];
          }
         }
       }
     for(i=1;i<=nalunos;i++){
         for(j=0;j<num-1;j++){
          alunos[ID].CPF[j]=CPF[j];
              
        }
      }
      for(i=1;i<=nalunos;i++){
        for(j=0;j<num-1;j++){
          alunos[ID].nasc[j]=data[j];
            
        }
      }
}

void Remover(Tip alunos[]){
  printf("remover\n");
  printf("Qual o seu ID?\n");
  scanf("%d",&i);
  situ[i]=0;
}

int main(){
  Tip alunos[100];

  printf("Cadastro de pessoas\n");
  printf("1-Cadastrar\n");
  printf("2-Listar\n");
  printf("3-Pesquisar\n");
  printf("4-Atualizar\n");
  printf("5-Remover\n");
  printf("6-Sair\n");
  
  while(6==6){
    printf("O que o(a) senhor(a) deseja fazer?\n");
     scanf("%d",&ordem);
    if(ordem==1){
      nalunos=Cadastrar(alunos,nalunos);
    }

    if(ordem==2){
      Listar(alunos,nalunos);
    }

    if(ordem==3){
      Pesquisar(alunos, nalunos);
      dif=0;
    }

    if(ordem==4){
      Atualizar(alunos,nalunos);
    }

    if(ordem==5){
      Remover(alunos);
    }

    if(ordem==6){
      printf("Adeus :( \n");
    return 0;  
    }
  }
}
