#include <stdio.h> //Bilbioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //FUNÇÃO responsavel por cadastrar os usuários no sistema
{
     //Inicio criação de variáveis/string
     char arquivo[40];
	 char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];

     //Final criação de variáveis/string

     printf("Digite seu cpf: ");
     scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das trings

     FILE *file; //cria o aqrquivo
	 file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	 fprintf(file,cpf); //salvo o valor da variavel
	 fclose(file); //fecho o arquivo

	 file = fopen(arquivo, "a");
	 fprintf(file,",");
	 fclose(file);



	 printf("Digite o nome a ser cadastrado: ");
	 scanf("%s",nome);

	 file = fopen(arquivo, "a");
	 fprintf(file,nome);
	 fclose(file);

	  file = fopen(arquivo, "a");
	  fprintf(file,",");
	  fclose(file);


	 printf("Digite o sobrenome a ser cadastrado: ");
	 scanf("%s",sobrenome);

	 file = fopen(arquivo, "a");
	 fprintf(file,sobrenome);
	 fclose(file);

	  file = fopen(arquivo, "a");
	 fprintf(file,",");
	 fclose(file);


	 printf("Digite o cargo a ser cadastrado: ");
	 scanf("%s",cargo);

	 file = fopen(arquivo, "a");
	 fprintf(file,cargo);
	 fclose(file);

	 system("pause");






}

int consulta()
{

    setlocale(LC_ALL, "portuguese"); //Definindo a Liguagem

	char cpf[40];
	char conteudo[200];

	printf("Digite o cpf a ser consultado:\n");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL)
    {
        printf("CPF não localizado\n");
    }

     while(fgets(conteudo, 200, file)!= NULL)
     {
         printf("\tEssas são as informações do usuario:\n");
         printf("\t%s", conteudo);
         printf("\n\n");
     }
           system("pause");
}

int deletar()
{
   char cpf[40];

   printf("Digite o cpf do cadastro a ser excluido: ");
   scanf("%s", cpf);

   FILE *file;
   file = fopen(cpf, "r");

   if(file == NULL) {
    printf("CPF não encontrado\n");
    system("pause");
    return 0;
   }

    fclose(file);

    if(remove(cpf) == 0)
    {
        printf("CPF removido com sucesso.\n");
    }   else
        {
            printf("Erro ao remover o arquivo.\n");
        }

            system("pause");
            return 0;
}






int main()
{

	int opcao=0; //Definindo as variaveis
	int laco=1;

	for(laco=1;laco=1;)
	{

	    system("cls");


	    setlocale(LC_ALL, "portuguese"); //Definindo a Liguagem


		printf("## Cartório da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: "); //fim do menu

        scanf("%d" , &opcao); //aréa,armazenando a escolha do usuário

        system("cls"); //responsavel por limpar a tela




        switch(opcao) //inicio da seleção do menu
        {
         	 case 1:
  	        registro(); //chamada de funções
             break;

             case 2:
            consulta();
	         break;

	         case 3:
	        deletar();
   	        break;

   	         default:
   	         printf("Essa opção não está disponivel ");
   	         system ("pause");
			 break;

		}


    }
}
