#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <iostream>
#include "listasstr.h"

struct reg {
	char nome  [50];   
	char tel   [20];
	char email [50];
	char cpf   [20];
	char cid   [50];
	char end   [50];
	char vei   [20];
	char placa [20];
	char dt_ent[20];
	char serv  [50];
	float vlr_orc;
	char status;
	int cod;
};

int tamanho(FILE *arq) {
	fseek(arq,0,SEEK_END);
	return ftell(arq)/sizeof(reg);
}

void linha() {
	printf("==========================================================================");
}

void cadastrar(FILE *arq) {
	reg contato;
	char confirma;
	printf("Cadastrando Novo Registro!\n");
	printf("N�mero do Registro.......:%d\n\n",tamanho(arq)+1);
	linha();
	printf("\n\n");
	fflush(stdin);
	
	printf("Nome / Raz�o Social......:");
	gets(contato.nome);
	
	printf("Telefone.................:");
	gets(contato.tel);
	
	printf("E-mail...................:");
	gets(contato.email);
	
	printf("CPF / CNPJ...............:");
	gets(contato.cpf);
	
	printf("Cidade...................:");
	gets(contato.cid);
	
	printf("Endere�o.................:");
	gets(contato.end);
	
	printf("Ve�culo..................:");
	gets(contato.vei);
	
	printf("Placa....................:");
	gets(contato.placa);
	
	printf("Data de Entrada..........:");
	gets(contato.dt_ent);
	
	printf("Descri��o do Servi�o.....:");
	gets(contato.serv);
	
	printf("Valor do Or�amento.......:");
	scanf("%f",&contato.vlr_orc);
	
	printf("\nConfirma <s/n>...........:");
	scanf(" %c",&confirma);
	if (toupper(confirma) == 'S') {
		
		printf("Gravando.....\n\n");
		fseek(arq,0,SEEK_END);
		contato.status='S';
		contato.cod=(tamanho(arq)+1);
		fwrite(&contato,sizeof(reg),1,arq);
	}
	else {
		printf("\n");
	}
	system("pause");
}

void consultar(FILE *arq) {
	reg contato;
	int nr;
	printf("Consulta pelo C�digo\n");
	printf("Informe o C�digo...:");
	scanf("%d",&nr);
	printf("\n");
	if ((nr <= tamanho(arq)) && (nr > 0)) {
		fseek(arq,(nr - 1) * sizeof(reg),SEEK_SET);
		fread(&contato,sizeof(reg),1,arq);
		linha();
		printf("\n\n");
		printf("C�digo do Cliente........:%d\n\n",contato.cod);
		printf("Nome / Raz�o Social......:%s\n",contato.nome);
		printf("Telefone.................:%s\n",contato.tel);
		printf("E-mail...................:%s\n",contato.email);
		printf("CPF / CNPJ...............:%s\n",contato.cpf);
		printf("Cidade...................:%s\n",contato.cid);
		printf("Endere�o.................:%s\n",contato.end);
		printf("Ve�culo..................:%s\n",contato.vei);
		printf("Placa....................:%s\n",contato.placa);
		printf("Data de Entrada..........:%s\n",contato.dt_ent);
		printf("Descri��o do Servi�o.....:%s\n",contato.serv);
		printf("Valor do Or�amento.......:%.2f\n",contato.vlr_orc);	
		printf("Status do Cliente........:%c\n\n",contato.status);
		linha();
		printf("\n\n");			
	}
	else {
		linha();
		printf("\n\nN�mero de Registro Inv�lido!\n\n");
	}
	system("pause");
}

void inativar(FILE *arq) {
	reg contato;
	char confirma;
	int nr;
	printf("Informe o c�digo do cadastro que deseja inativar:");
	scanf("%d",&nr);
	printf("\n");
	linha();
	printf("\n\n");
	if ((nr <= tamanho(arq)) && (nr > 0)) {
		fseek (arq,(nr-1)*sizeof(reg),SEEK_SET);
		fread(&contato,sizeof (reg),1,arq);
		if (contato.status == 'S') {
			printf("Nome / Raz�o Social......:%s\n",contato.nome);
			printf("Telefone.................:%s\n",contato.tel);
			printf("E-mail...................:%s\n",contato.email);
			printf("CPF / CNPJ...............:%s\n",contato.cpf);
			printf("Cidade...................:%s\n",contato.cid);
			printf("Endere�o.................:%s\n",contato.end);
			printf("Ve�culo..................:%s\n",contato.vei);
			printf("Placa....................:%s\n",contato.placa);
			printf("Data de Entrada..........:%s\n",contato.dt_ent);
			printf("Descri��o do Servi�o.....:%s\n",contato.serv);
			printf("Valor do Or�amento.......:%.2f\n",contato.vlr_orc);	
			getchar();
			printf("\n");
			linha();
			printf("\n\n");
			printf("Confirma <s/n>:");
			scanf("%c",&confirma);						
			if (toupper (confirma) == 'S') {
					printf("\nInativando.....\n\n");
					fseek(arq,(nr-1)*sizeof(reg),SEEK_SET);
					contato.status = 'N';
					fwrite(&contato,sizeof(reg),1,arq);
			}
			else {
				printf("\n");
			}
		}
		else {
			printf("Registro Inexistente!\n\n");
		}
	}
	else {
		printf("N�mero de Registro Inv�lido!\n\n");
	}
	system("pause");
}

void ativar(FILE *arq) {
	reg contato;
	char confirma;
	int nr;
	printf("Informe o c�digo do cadastro que deseja ativar:");
	scanf("%d",&nr);
	printf("\n");
	linha();
	printf("\n\n");
	if ((nr <= tamanho(arq)) && (nr > 0))
	{
		fseek (arq,(nr-1)*sizeof(reg),SEEK_SET);
		fread(&contato,sizeof (reg),1,arq);
		if (contato.status == 'N') {
			printf("Nome / Raz�o Social......:%s\n",contato.nome);
			printf("Telefone.................:%s\n",contato.tel);
			printf("E-mail...................:%s\n",contato.email);
			printf("CPF / CNPJ...............:%s\n",contato.cpf);
			printf("Cidade...................:%s\n",contato.cid);
			printf("Endere�o.................:%s\n",contato.end);
			printf("Ve�culo..................:%s\n",contato.vei);
			printf("Placa....................:%s\n",contato.placa);
			printf("Data de Entrada..........:%s\n",contato.dt_ent);
			printf("Descri��o do Servi�o.....:%s\n",contato.serv);
			printf("Valor do Or�amento.......:%.2f\n",contato.vlr_orc);	
			getchar();
			printf("\n");
			linha();
			printf("\n\n");
			printf("Confirma <s/n>:");
			scanf(" %c",&confirma);
			if (toupper(confirma) == 'S') {
					printf("\nAtivando.....\n\n");
					fseek(arq,(nr-1)*sizeof(reg),SEEK_SET);
					contato.status ='S';
					fwrite(&contato,sizeof(reg),1,arq);
			}
			else {
				printf("\n");
			}
		}
		else {
			printf("Este Cliente j� est� Ativo, Tente Outro!\n\n");
		}
	}
	else {
		printf("N�mero de Registro Inv�lido!\n\n");
	}
	system("pause");
}

void gerararqtxt(FILE *arq) {
	char nomearq[20];
	printf("Nome do Arquivo Texto:");
	scanf("%s",nomearq);
	strcat(nomearq,".txt");
	FILE *arqtxt = fopen(nomearq,"w");
	if (!arqtxt) {
		printf("\nN�o foi poss�vel criar esse arquivo!\n\n");
		system("pause");
	}
	fprintf(arqtxt,"			  ___ __ _ _ __ ___ \n");
	fprintf(arqtxt,"			 / __/ _` | '__/ __| \n");
	fprintf(arqtxt,"			| (_| (_| | |  \\__ \\ \n");
	fprintf(arqtxt,"			 \\___\\__,_|_|  |___/ \n");
	fprintf(arqtxt,"\n			       CLIENTES\n\n");
	fprintf(arqtxt,"===================================================================================\n");				
	int nr;
	reg contato;
	for (nr=0;nr<tamanho(arq);nr++) {
		fseek(arq,nr * sizeof(reg),SEEK_SET);
		fread(&contato,sizeof(reg),1,arq);
		fprintf(arqtxt,"\n");
		
		fprintf(arqtxt,"C�digo...................: %d\n\n",contato.cod);
		fprintf(arqtxt,"Nome / Raz�o Social......: %s\n",contato.nome);
		fprintf(arqtxt,"Telefone.................: %s\n",contato.tel);
		fprintf(arqtxt,"E-mail...................: %s\n",contato.email);
		fprintf(arqtxt,"CPF / CNPJ...............: %s\n",contato.cpf);
		fprintf(arqtxt,"Cidade...................: %s\n",contato.cid);
		fprintf(arqtxt,"Endere�o.................: %s\n",contato.end);
		fprintf(arqtxt,"Ve�culo..................: %s\n",contato.vei);
		fprintf(arqtxt,"Placa....................: %s\n",contato.placa);
		fprintf(arqtxt,"Data de Entrada..........: %s\n",contato.dt_ent);
		fprintf(arqtxt,"Descri��o do Servi�o.....: %s\n",contato.serv);
		fprintf(arqtxt,"Valor do Or�amento.......: %.2f\n",contato.vlr_orc);
		fprintf(arqtxt,"Status do Cliente........: %c\n",contato.status);
		fprintf(arqtxt,"===================================================================================\n");
	}
		fclose(arqtxt);
		printf("Relat�rio gerado com sucesso!\n\n");
		system("pause");
}

void relatorioord(FILE *arq) {
	lista l;
	linit(&l);
	int nr;
	reg contato;
	elem x;
	for (nr=0;nr<tamanho(arq);nr++) {
		fseek(arq,nr*sizeof(reg),SEEK_SET);
		fread(&contato,sizeof(reg),1,arq);
		strcpy(x.nome,contato.nome);
		x.nr = nr;
		lins(&l,x);
	}
	FILE *arqtxt = fopen("Relat�rio Ordenado.txt","w");
	fprintf(arqtxt,"			  ___ __ _ _ __ ___ \n");
	fprintf(arqtxt,"			 / __/ _` | '__/ __| \n");
	fprintf(arqtxt,"			| (_| (_| | |  \\__ \\ \n");
	fprintf(arqtxt,"			 \\___\\__,_|_|  |___/ \n");
	fprintf(arqtxt,"\n			       CLIENTES\n\n");
	fprintf(arqtxt,"===================================================================================\n");		
	
	int c;
	for (c=0;c<l.fim;c++) {
		nr = l.m[c].nr;
		fseek(arq,nr*sizeof(reg),SEEK_SET);
		fread(&contato,sizeof(reg),1,arq);
		if(contato.status == 'S') {		
			fprintf(arqtxt,"C�digo...................: %d\n\n",contato.cod);
			fprintf(arqtxt,"Nome / Raz�o Social......: %s\n",contato.nome);
			fprintf(arqtxt,"Telefone.................: %s\n",contato.tel);
			fprintf(arqtxt,"E-mail...................: %s\n",contato.email);
			fprintf(arqtxt,"CPF / CNPJ...............: %s\n",contato.cpf);
			fprintf(arqtxt,"Cidade...................: %s\n",contato.cid);
			fprintf(arqtxt,"Endere�o.................: %s\n",contato.end);
			fprintf(arqtxt,"Ve�culo..................: %s\n",contato.vei);
			fprintf(arqtxt,"Placa....................: %s\n",contato.placa);
			fprintf(arqtxt,"Data de Entrada..........: %s\n",contato.dt_ent);
			fprintf(arqtxt,"Descri��o do Servi�o.....: %s\n",contato.serv);
			fprintf(arqtxt,"Valor do Or�amento.......: %.2f\n",contato.vlr_orc);
			fprintf(arqtxt,"Status do Cliente........: %c\n",contato.status);
			fprintf(arqtxt,"===================================================================================\n");
		}	
	}
	fclose(arqtxt);
	printf("Relat�rio gerado com sucesso!\n\n");
	system("pause");	
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	int op;
	FILE *arq;
	
	if ((arq = fopen("dados.dat","rb+")) == NULL)
		if ((arq = fopen("dados.dat","wb+")) == NULL) {
			printf("Falha ao abrir o arquivo!\n\n");
			system("pause");
		}
	
	do {
		system("cls");
		linha();
		printf("\n\n");
		printf("			  ___ __ _ _ __ ___ \n");
		printf("			 / __/ _` | '__/ __| \n");
		printf("			| (_| (_| | |  \\__ \\ \n");
		printf("			 \\___\\__,_|_|  |___/ \n");
		printf("\n			    AUTO MEC�NICA\n\n");
		linha();
		printf("\n\n");
		printf("                        ____________________\n");
		printf("                     //|          |         \\ \n");
		printf("                   //  |          |          \\ \n");
		printf("      ___________//____|__________|___________\\__________________\n");
		printf("    /__________________|_=________|_=__________|_________________{}\n");
		printf("    [           ______ |          | .          | ==  ______      { }\n");
		printf("   _[___       /##  ##\\|          |            |    /##  ##\\    _{# }_\n");
		printf("  {_____)_____|##    ##|__________|____________|___|##    ##|__(______}\n");
		printf("             /  ##__##                            /  ##__##        \ \n");
		linha();
		printf("\n\n");
		linha();
		printf("\n\n");
		printf("CLIENTES CADASTRADOS: %d\n\n",tamanho(arq));
		printf("1.Cadastrar\n");
		printf("2.Consultar\n");
		printf("3.Gerar Arquivo\n");
		printf("4.Inativar Cadastro\n");
		printf("5.Ativar Cadastro\n");
		printf("6.Relat�rio Ordenado\n");
		printf("7.Sair\n\n");
		linha();
		printf("\n\n");
		printf("Op��o:");
		scanf("%d",&op);
		printf("\n");
		switch (op) {
			case 1:
				cadastrar(arq);
				break;
			case 2:
				consultar(arq);
				break;
			case 3:
				gerararqtxt(arq);
				break;
			case 4:
				inativar(arq);
				break;
			case 5:
				ativar(arq);
				break;
			case 6:
				relatorioord(arq);
				break;
			case 7:
				fclose(arq);
		}
	} while (op != 7);
	system("pause");
	return 0;
}
