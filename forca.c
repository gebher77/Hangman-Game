#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>


	//variaveis globais
	char palavrasecreta[TAMANHO_PALAVRA];
	char chutes[26];
	int chutesdados = 0;




void abertura() {
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta() {
	char chute;
	printf("Qual letra? ");
	scanf(" %c", &chute);

	chutes[chutesdados] = chute;
	chutesdados++;
}


void desenhaforca() {
	int erros = chuteserrados();




printf("  _______       \n");
printf(" |/      |      \n");
printf(" |      %c%c%c  \n", (erros >= 1 ?'(':' '), 
    (erros >= 1 ?'_':' '), (erros >= 1 ?')':' '));
printf(" |      %c%c%c  \n", (erros >= 3 ?'\\':' '), 
    (erros >= 2 ?'|':' '), (erros >= 3 ?'/': ' '));
printf(" |       %c     \n", (erros >= 2 ?'|':' '));
printf(" |      %c %c   \n", (erros >= 4 ?'/':' '), 
    (erros >= 4 ?'\\':' '));
printf(" |              \n");
printf("_|___           \n");
printf("\n\n");

	printf("Voce ja deu %d chutes\n", chutesdados);

	for(int i = 0; i < strlen(palavrasecreta); i++) {

		if(jachutou(palavrasecreta[i])) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}

	}
	printf("\n");

}

void adiciona(){
	char quer;
	printf("Voce deseja adicionar uma nova palavra(S/N)\n");
	scanf(" %c", &quer);

if(quer == 'S') {
	char novapalavra[TAMANHO_PALAVRA];
	printf("qual a nova palavra\n");
	scanf("%s", novapalavra);

	FILE* f;

	f = fopen("palavras.txt", "r+");
	if(f == 0){
		printf("Desculpe, banco de dados nao disponivel\n\n");
		exit(1);
	}

	int qtd;
	fscanf(f, "%d", &qtd);
	qtd++;

	fseek(f, 0, SEEK_SET);
	fprintf(f, "%d",qtd);


	fseek(f, 0, SEEK_END);
	fprintf(f, "\n%s",novapalavra);

	fclose(f);
}


}

void escolhepalavra() {
	FILE* f;

	f = fopen("palavras.txt", "r");
	

	int qtddepalavras;
	fscanf(f, "%d", &qtddepalavras);



	srand(time(0));
	int randon = rand() % qtddepalavras;

	for (int i = 0; i <= randon; i++)
	{
		fscanf(f, "%s", palavrasecreta);
	}







	fclose(f);


}

int acertou(){
for (int i = 0; i < strlen(palavrasecreta); ++i)
{
	if(!jachutou(palavrasecreta[i])) {
		return 0;
	}
}


return 1;


}

int chuteserrados(){
	int erros = 0;
for (int i = 0; i < chutesdados; ++i)
{

	int existe = 0;
	for (int j = 0; j < strlen(palavrasecreta); ++j)
	{
		if (chutes[i] == palavrasecreta[j])
		{
			existe = 1;
			break;

		}
	}
	if(!existe) erros++;
	
}

return erros;



}
int enforcou(){


	return chuteserrados() >= 5;


}

int jachutou(char letra) {
	int achou = 0;
	for(int j = 0; j < chutesdados; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}

	return achou;
}


int main() {


	abertura();
	escolhepalavra();

	do {

		desenhaforca();
		chuta();

	} while (!acertou() && !enforcou());
	if (acertou())
	{
		printf("Parabens, voce ganhou!\n\n");

		
printf("              .-=========-. 	\n");        
printf("              \'-=======-'/		\n");		
printf("              _|   .=.   |_ 	\n");
printf("             ((|  {{1}}  |))	\n");
printf("              \\|   /|\\   |/	\n");		
printf("               \\__ '`' __/		\n");
printf("                 _`) (`_ 		\n");
printf("               _/_______\\_  	\n");
printf("              /___________\\  	\n");

	} else{
		printf("\nPuxa, voce foi enforcado!\n");
		printf("A palavra era **%s**\n\n",palavrasecreta);







printf("						                        _gxXXXXXXXXXXXXXXXXXXXXXXXX!x_ 					\n");
printf("						                   __x!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!x_ 			\n");
printf("						                ,gXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx_ 			\n");
printf("						              ,gXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!_  		\n");
printf("						            _!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!.  	\n");
printf("						          gXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXs 	\n");
printf("						        ,!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!. 	\n");
printf("						       g!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX! 	\n");
printf("						      iXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX! 	\n");
printf("						     ,XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx \n");
printf("						     !XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx \n");
printf("						   ,XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx \n");
printf("						   !XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXi\n");
printf("						  dXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						  !XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						   XXXXXXXXXXXXXXXXXXXf~~~VXXXXXXXXXXXXXXXXXXXXXXXXXXvvvvvvvvXXXXXXXXXXXXXX!\n");
printf("						   !XXXXXXXXXXXXXXXf`       'XXXXXXXXXXXXXXXXXXXXXf`          '~XXXXXXXXXXP\n");
printf("						    vXXXXXXXXXXXX!            !XXXXXXXXXXXXXXXXXX!              !XXXXXXXXX\n");
printf("						     XXXXXXXXXXv`              'VXXXXXXXXXXXXXXX                !XXXXXXXX!\n");
printf("						     !XXXXXXXXX.                 YXXXXXXXXXXXXX!                XXXXXXXXX\n");
printf("						      XXXXXXXXX!                 ,XXXXXXXXXXXXXX                VXXXXXXX!\n");
printf("						      'XXXXXXXX!                ,!XXXX ~~XXXXXXX               iXXXXXX~\n");
printf("						       'XXXXXXXX               ,XXXXXX   XXXXXXXX!             xXXXXXX!\n");
printf("						        !XXXXXXX!xxxxxxs______xXXXXXXX   'YXXXXXX!          ,xXXXXXXXX\n");
printf("						         YXXXXXXXXXXXXXXXXXXXXXXXXXXX`    VXXXXXXX!s. __gxx!XXXXXXXXXP\n");
printf("						          XXXXXXXXXXXXXXXXXXXXXXXXXX!      'XXXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						          XXXXXXXXXXXXXXXXXXXXXXXXXP        'YXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						          XXXXXXXXXXXXXXXXXXXXXXXX!     i    !XXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						          XXXXXXXXXXXXXXXXXXXXXXXX!     XX   !XXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						          XXXXXXXXXXXXXXXXXXXXXXXXx_   iXX_,_dXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("						          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXP\n");
printf("						          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						           ~vXvvvvXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXf\n");
printf("						                    'VXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXvvvvvv~\n");
printf("						                      'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~\n");
printf("						                  _    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXv`\n");
printf("						                 -XX!  !XXXXXXX~XXXXXXXXXXXXXXXXXXXXXX~   Xxi\n");
printf("						                  YXX  '~ XXXXX XXXXXXXXXXXXXXXXXXXX`     iXX`\n");
printf("						                  !XX!    !XXX` XXXXXXXXXXXXXXXXXXXX      !XX\n");
printf("						                  !XXX    '~Vf  YXXXXXXXXXXXXXP YXXX     !XXX\n");
printf("						                  !XXX  ,_      !XXP YXXXfXXXX!  XXX     XXXV\n");
printf("						                  !XXX !XX           'XXP 'YXX!       ,.!XXX!\n");
printf("						                  !XXXi!XP  XX.                  ,_  !XXXXXX!\n");
printf("						                  iXXXx X!  XX! !Xx.  ,.     xs.,XXi !XXXXXXf\n");
printf("						                   XXXXXXXXXXXXXXXXX! _!XXx  dXXXXXXX.iXXXXXX\n");
printf("						                   VXXXXXXXXXXXXXXXXXXXXXXXxxXXXXXXXXXXXXXXX!\n");
printf("						                   YXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXV\n");
printf("						                    'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX!\n");
printf("						                    'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXf\n");
printf("						                       VXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXf\n");
printf("						                         VXXXXXXXXXXXXXXXXXXXXXXXXXXXXv`\n");
printf("						                          ~vXXXXXXXXXXXXXXXXXXXXXXXf`\n");
printf("						                              ~vXXXXXXXXXXXXXXXXv~\n");
printf("						                                 '~VvXXXXXXXV~~\n");
printf("						                                       ~~\n");






	}
	adiciona();
}