#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1000 //constante com nome 'MAX' que armazena o número 1000
int linhas=0; // variável global que inicia com 0, pois irá armazenar as linhas que o programa irá escrever
struct variaveis{ // estrutura de dados para armazenar as variáveis e serão utilizadas entre as sub-rotinas
	int opcao, tipo, tamanho;
	char localizacao[MAX],nome[MAX],frase[MAX],comando[MAX],var[MAX];
};
int menu(int opcao){ // função que mostra o menu de opções
    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    printf("\n----------------[MENU]----------------\n|   0) Sair                          |\n|   1) Nomear variáveis.             |\n|   2) Colocar comandos de entrada.  |\n|   3) Colocar comandos de saída.    |\n|   4) Colocar condições.            |\n|   5) Colocar escolhas.             |\n--------------------------------------\n"); // imprime o menu de opções na tela do usuário
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%d",&opcao); // espera o usuário digitar a opção desejada
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	return opcao; // retorna o valor da opção que o usuário deseja utilizar
}
void variavel(struct variaveis var){ // procedimento que cria variáveis do tipo que o usuário desejar
	printf("\t[VARIÁVEIS]\n\n1- Tipo inteiro.\n2- Tipo real.\n3- Tipo caractér.\n4- String.\n"); // imprime na tela as opções
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%d",&var.tipo); // lê a opção que o usuário desejar utilizar
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	switch(var.tipo){ // o programa irá ver a opção que o usuário deseja utilizar e executar a mesma
		case 1:
	        usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Digite o(s) nome(s) da(s) variável(s) (separadas por vírgula):\n"); // pede para que o usuário nomeie suas variáveis
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
		    scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
	    	getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas    operacionais, como por exemplo Linux e OS X
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	    	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Nomeando variável do tipo inteiro...\n"); // diz ao usuário o que o programa irá fazer em seguida
	    	sprintf(var.var, "echo 'int %s;'>> %s", var.nome, var.localizacao); // o sprintf joga tudo à sua frente para dentro    de uma string(vetor de caracteres)
    		system(var.var); // executa como comando do sistema o que estiver dentro da variável
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Variável nomeada...\n"); // diz que a variável foi nomeada com sucesso
    		linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		case 2:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Digite o(s) nome(s) da(s) variável(s) (separadas por vírgula):\n"); // pede para que o usuário nomeie suas variáveis
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas    operacionais, como por exemplo Linux e OS X
		    scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
    		getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é    jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas    operacionais, como por exemplo Linux e OS X
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Nomeando variável do tipo real...\n"); // diz ao usuário o que o programa irá fazer em seguida
    		sprintf(var.var, "echo 'float %s;'>> %s", var.nome, var.localizacao); // o sprintf joga tudo à sua frente para    dentro de uma string(vetor de caracteres)
    		system(var.var); // executa como comando do sistema o que estiver dentro da variável
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Variável nomeada...\n"); // diz que a variável foi nomeada com sucesso
    		linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		case 3:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Digite o(s) nome(s) da(s) variável(s) (separadas por vírgula):\n"); // pede para que o usuário nomeie suas variáveis
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
    		scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
    		getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é    jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas    operacionais, como por exemplo Linux e OS X
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Nomeando variável do tipo caractér...\n"); // diz ao usuário o que o programa irá fazer em seguida
    		sprintf(var.var, "echo 'char %s;'>> %s", var.nome, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
    		system(var.var); // executa como comando do sistema o que estiver dentro da variável
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Variável nomeada...\n"); // diz que a variável foi nomeada com sucesso
    		linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		case 4:
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Digite o nome da variável:\n"); // pede para que o usuário nomeie sua variável
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só    funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas    operacionais, como por exemplo Linux e OS X
    		scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
    		getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é    jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo) // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo) // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Digite o tamanho da string:\n"); // pede para que o usuário dê o tamanho de seu vetor de caracteres
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
    		scanf("%d",&var.tamanho);
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo) // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo) // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Nomeando string...\n"); // diz ao usuário o que o programa irá fazer em seguida
    		sprintf(var.var, "echo 'char %s[%d];'>> %s", var.nome, var.tamanho, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
    		system(var.var); // executa como comando do sistema o que estiver dentro da variável
    		usleep(500000);
    		printf("String nomeada...\n"); // diz que a variável foi nomeada com sucesso
    		linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		default:
	    	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo) // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo) // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("[OPÇÃO INEXISTENTE]\n"); // caso o usuário digite uma opção inexistente, irá aparecer este aviso
	}
}
void entrada(struct variaveis var){ // procedimento que insere comandos de entrada no código que está sendo criado pelo programa
	printf("\t[ENTRADA]\n1- Tipo inteiro.\n2- Tipo real.\n3- Tipo caractér.\n4- String.\n"); // imprime na tela as opções
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%d",&var.tipo); // pede para que o usuário digite a opção desejada
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	switch(var.tipo){
		case 1:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo) // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Digite o nome da variável (caso haja mais de uma variável a fazer entrada, execute esta função novamente):\n"); // pede para que o usuário digite o nome da variável que deseja fazer entrada
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
    		scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
    		getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
	    	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
		    fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo) // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Inserindo comando de entrada do tipo inteiro...\n"); // diz ao usuário o que o programa irá fazer em seguida
	    	sprintf(var.var, "echo 'scanf(\"%%d\",&%s);'>> %s", var.nome, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
		    system(var.var); // executa como comando do sistema o que estiver dentro da variável
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo) // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Comando inserido...\n"); // diz que o comando foi inserido com sucesso
		    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		case 2:
	    	printf("Digite o nome da variável (caso haja mais de uma variável a fazer entrada, execute esta função novamente):\n"); // pede para que o usuário digite o nome da variável que deseja fazer entrada
		    fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
	    	getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
	    	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	    	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Inserindo comando de entrada do tipo real...\n"); // diz ao usuário o que o programa irá fazer em seguida
	    	sprintf(var.var, "echo 'scanf(\"%%f\",&%s);'>> %s", var.nome, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
		    system(var.var); // executa como comando do sistema o que estiver dentro da variável
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Comando inserido...\n"); // diz que o comando foi inserido com sucesso
	    	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		case 3:
    		printf("Digite o nome da variável (caso haja mais de uma variável a fazer entrada, execute esta função novamente):\n"); // pede para que o usuário digite o nome da variável que deseja fazer entrada
	    	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
	    	getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
	    	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
		    fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Inserindo comando de entrada do tipo caractér...\n"); // diz ao usuário o que o programa irá fazer em seguida
	    	sprintf(var.var, "echo 'scanf(\"%%c\",&%s);'>> %s", var.nome, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
		    system(var.var); // executa como comando do sistema o que estiver dentro da variável
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Comando inserido...\n"); // diz que o comando foi inserido com sucesso
	    	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		case 4:
	    	printf("Digite o nome da variável (caso haja mais de uma variável a fazer entrada, execute esta função novamente):\n"); // pede para que o usuário digite o nome da variável que deseja fazer entrada
		    fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	    	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
		    scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
	    	getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
		    setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Inserindo comando de entrada do tipo string...\n"); // diz ao usuário o que o programa irá fazer em seguida
	    	sprintf(var.var, "echo 'scanf(\"%%s\",&%s);'>> %s", var.nome, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
		    system(var.var); // executa como comando do sistema o que estiver dentro da variável
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Comando inserido...\n"); // diz que o comando foi inserido com sucesso
		    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		default:
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("[OPÇÃO INEXISTENTE]\n"); // caso o usuário digite uma opção inexistente, irá aparecer este aviso
    }
}
void saida(struct variaveis var){ // procedimento que insere comandos de saída no código que está sendo criado pelo programa
	printf("\t[SAÍDA]\n1- Incluindo variável(s) na saída.\n2- Apenas saída, sem inclusão de variável(s).\n"); // imprime na tela as opções
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%d",&var.tipo); // lê a opção que o usuário deseja utilizar
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	switch(var.tipo){
		case 1:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Digite a saída, incluindo também a(s) variável(s) com seus respectivos tipos, usando %%'letra_correspondente':\n"); // pede para que o usuário digite a saída que irá aparecer em seu programa
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
    		scanf("%[^\n]",&var.frase); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
    		getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Digite o nome da(s) variável(s) (separadas por vírgula):\n"); // pede para que o usuário digite os nomes das variáveis que irão ter seus valores substituindo na saída
		    fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	       	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
		    getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Inserindo comando de saída...\n"); // diz ao usuário o que o programa irá fazer em seguida
		    sprintf(var.var, "echo 'printf(\"%s\",%s);'>> %s", var.frase, var.nome, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
    		system(var.var); // executa como comando do sistema o que estiver dentro da variável
	    	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Saída inserida...\n"); // diz que a saída foi inserida com sucesso
	    	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		case 2:
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Digite a saída:\n"); // pede para que o usuário digite a saída que irá aparecer em seu programa
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	    	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	scanf("%[^\n]",&var.frase); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
		    getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Inserindo comando de saída...\n"); // diz ao usuário o que o programa irá fazer em seguida
	    	sprintf(var.var, "echo 'printf(\"%s\");'>> %s", var.frase, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
		    system(var.var); // executa como comando do sistema o que estiver dentro da variável
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Saída inserida...\n"); // diz que a saída foi inserida com sucesso
		    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		default:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("[OPÇÃO INEXISTENTE]\n"); // caso o usuário digite uma opção inexistente, irá aparecer este aviso
	}
}
void condicao(struct variaveis var){
	printf("\t[CONDIÇÃO]\nDigite a(s) condição(s):\n"); // pede para que o usuário digite a condição (ou as condições)
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
	getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	printf("Digite o(s) comando(s) (para colocar mais de um comando, separe-os com ponto e vírgula ';'):\n");
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%[^\n]",&var.comando); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
	getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	printf("Inserindo comando(s)...\n"); // diz ao usuário o que o programa irá fazer em seguida
	sprintf(var.var, "echo 'if(%s){'>> %s", var.nome, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	sprintf(var.var, "echo '%s'>> %s", var.comando, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	sprintf(var.var, "echo '}'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	printf("Comando(s) inserido(s)...\n"); // diz que o(s) comando(s) foram inseridos com sucesso
    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	printf("Deseja criar um caso contrario ?\n1- Sim.\n2- Não.\n"); // pergunta ao usuário se quer colocar um caso contrario em sua condição
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%d",&var.tipo); // lê a reposta do usuário em relação à pergunta
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	switch(var.tipo){
		case 1:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Digite o(s) comando(s) (para colocar mais de um comando, separe-os com ponto e vírgula ';'):\n"); // pede para que o usuário digite os comandos que deseja colocar em seu caso contrario
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	    	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	scanf("%[^\n]",&var.comando); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
		    getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
		    setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
		    fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Inserindo comando(s)...\n"); // diz ao usuário o que o programa irá fazer em seguida
		    sprintf(var.var, "echo 'else{'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
    		system(var.var); // executa como comando do sistema o que estiver dentro da variável
	    	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		    sprintf(var.var, "echo '%s'>> %s", var.comando, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
    		system(var.var); // executa como comando do sistema o que estiver dentro da variável
	    	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		    sprintf(var.var, "echo '}'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
    		system(var.var); // executa como comando do sistema o que estiver dentro da variável
	    	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Comando(s) inserido(s)...\n"); // diz que os comandos foram inseridos com sucesso
		    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		case 2:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Ok, Podemos continuar...\n"); // mensagem dizendo que o programa irá continuar normalmente
		break;
		default:
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("[OPÇÃO INEXISTENTE]\n"); // caso o usuário digite uma opção inexistente, irá aparecer este aviso
	}
}
void escolha(struct variaveis var){
	printf("\t[ESCOLHA]\nDigite a variável responsável pela escolha:\n"); // pede para que o usuário digite qual variável irá servir de condição para uma certa escolha
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%[^\n]",&var.nome); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
	getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	sprintf(var.var,"echo 'switch(%s){'>> %s", var.nome, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	printf("1- Adicionar caso contrário.\n2- Adicionar um caso.\n"); // pergunta ao usuário se ele quer criar um caso contrario ou um caso normal
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%d",&var.tipo); // lê a opção digitada pelo usuário
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	switch(var.tipo){
		case 1:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Digite o(s) comando(s) (para colocar mais de um comando, separe-os com ponto e vírgula ';'):\n"); // pede para que o usuário digite os comandos que deseja colocar em seu caso contrario
    		fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	scanf("%[^\n]",&var.comando); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
		    getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Inserindo caso contrário...\n"); // diz ao usuário o que o programa irá fazer em seguida
		    sprintf(var.var,"echo 'default:'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
    		system(var.var); // executa como comando do sistema o que estiver dentro da variável
	    	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		    sprintf(var.var, "echo '%s'>> %s", var.comando, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
		    system(var.var); // executa como comando do sistema o que estiver dentro da variável
		    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		    sprintf(var.var, "echo 'break;'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	    	system(var.var); // executa como comando do sistema o que estiver dentro da variável
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Caso contrário inserido...\n"); // diz que o caso contrario foi inserido com sucesso
		    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
		break;
		case 2:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("Digite o caso a ser verificado:\n"); // pede para o usuário um valor para verificar como caso entre as escolhas
		    fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
		    scanf("%[^\n]",&var.frase); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
		    getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
		    setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
		    fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Digite o(s) comando(s) (para colocar mais de um comando, separe-os com ponto e vírgula ';'):\n"); // pede para que o usuário digite os comandos a serem inseridos no caso
		    fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
		    scanf("%[^\n]",&var.comando); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
		    getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
    		setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	    	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
		    usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
    		printf("Inserindo caso...\n"); // diz ao usuário o que o programa irá fazer em seguida
	    	sprintf(var.var, "echo 'case %s:'>> %s", var.frase, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
		    system(var.var); // executa como comando do sistema o que estiver dentro da variável
		    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
    		sprintf(var.var, "echo '%s'>> %s", var.comando, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	    	system(var.var); // executa como comando do sistema o que estiver dentro da variável
		    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
    		sprintf(var.var, "echo 'break;'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	    	system(var.var); // executa como comando do sistema o que estiver dentro da variável
		    linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	    	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
		    printf("Caso inserido...\n"); // diz que o caso foi inserido com sucesso
		break;
		default:
    		usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	    	printf("[OPÇÃO INEXISTENTE]\n"); // caso o usuário digite uma opção inexistente, irá aparecer este aviso
	}
	sprintf(var.var,"echo '}'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
}
int main(){
	struct variaveis var;
	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	system("clear || cls"); // executa o comando 'clear' ou o 'cls', dependendo do comando que estiver disponível no sistema
	printf("\t\t++SOFTWARE PROGRAMMER++\n\nAviso: Para utilizar este programa, é necessário que o usuário tenha pelo menos conhecimento básico sobre lógica de programação.\n\nDigite o nome do programa que será criado (adicionando a extensão '.c' após o nome do arquivo):\n"); // imprime na tela o início do programa e um aviso
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	scanf("%[^\n]",&var.localizacao); // lê tudo o que for digitado até que a tecla enter (ou '\n') seja apertada
	getchar(); // o programa irá receber um \n para completar o scanf acima, mas este não será utilizado, por isso é jogado para o proximo comando de entrada, por isso utilizei o getchar para receber este enter.
	setbuf(stdin, NULL); // tambem limpa o buffer do teclado, mas geralmente funciona também em outros sistemas operacionais, como por exemplo Linux e OS X
	fflush(stdin); // limpa o buffer do teclado, para que não haja erros na entrada de dados, este geralmente só funciona em compiladores para o Sistema Operacional Windows
	sprintf(var.var, "echo '#include <stdio.h>'>%s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	sprintf(var.var, "echo '#include <stdlib.h>'>>%s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	sprintf(var.var, "echo 'int main(){'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	do{
		var.opcao=menu(0); // chama a função 'menu', enviando como parâmetro o número 0, e armazenando seu retorno na variável 'var.opcao'
		switch(var.opcao){ // verifica qual caso se adequa ao valor armazenado na variável e o executa
			case 0:
	    		printf("Saindo."); // imprime na tela que o programa está encerrando
		    	usleep(166666); // faz o programa fazer uma pausa por 166666 microsegundos
			    printf(".");
			    usleep(166666); // faz o programa fazer uma pausa por 166666 microsegundos
		    	printf(".\n");
		    	usleep(166666); // faz o programa fazer uma pausa por 166666 microsegundos
			break;
			case 1:
		    	variavel(var); // chama o procedimento de criação de variáveis
			break;
			    case 2:
		    	entrada(var); // chama o procedimento que insere comandos de entrada
			break;
		    case 3:
			    saida(var); // chama o procedimento que insere comandos de saída
			break;
		    case 4:
			    condicao(var); // chama o procedimento que verifica uma condição
			break;
			case 5:
			    escolha(var); // chama o procedimento de condição por escolha de casos(múltipla escolha)
			break;
			default:
	    		printf("[OPÇÃO INEXISTENTE]\n"); // caso o usuário digite uma opção inexistente, irá aparecer este aviso
		}
	}
	while(var.opcao!=0); // repete tudo o que está dentro do 'do' enquanto a condição for verdadeira
	sprintf(var.var, "echo 'return 0;'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	sprintf(var.var, "echo '}'>> %s", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	linhas++; // soma +1 à variável que armazena a quantidade de linhas escritas
	printf("Se nada ocorreu nenhum erro, o número de linhas 'programadas' devem ser: %d linhas.\nCompilando...\n", linhas); // mostra ao usuário a quantidade de linhas que o programa 'programou', e diz que logo em seguida irá compilar o programa criado
	sprintf(var.var, "gcc %s -o %s.o", var.localizacao, var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	printf("Executando o programa criado...\n------------------------------------------------------------\n\n"); // a partir daqui o programa criado é executado
	usleep(500000); // faz o programa fazer uma pausa por 500000 microsegundos (meio segundo)
	sprintf(var.var, "./%s.o", var.localizacao); // o sprintf joga tudo à sua frente para dentro de uma string(vetor de caracteres)
	system(var.var); // executa como comando do sistema o que estiver dentro da variável
	printf("\n------------------------------------------------------------\n"); // linha que define o fim do programa
	return 0;
}