#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

struct Endereco{
	char Rua[50];
	int numero;
	char Bairro[40];
	char Cidade[40];
	char Estado[40];
};

struct Cliente{
	int Cod;
	char Nome[50];
	int Tel;
	struct Endereco ende;
}C;

struct Agencia{
	int Cod;
	char Nome[50];
	struct Endereco ende;
	int Tel;
	float Ativos;
}Ag,Agi;

struct Conta{
	int CodCta;
	int CodAg;
	int CodCliente;
	float Saldo;
	float Limite;
	int E;
}Cta, Ctai;

FILE *fptrCliente, *fptrAgencia, *fptrConta, *fptrNovo, *fptrBack;

char op, op1, cont, nome[50];
int i, j, k, codigo, n;

void MenuPrincipal(void);

void MenuCliente(void);
void cadastroCliente(void);
void consultaCliente(void);
void alteracaoCliente(void);

void MenuAgencia(void);
void cadastroAgencia(void);
void consultaAgencia(void);
void alteracaoAgencia(void); 
void ordenarAgencia(void);

void MenuConta(void);
void cadastroConta(void);
void consultaConta(void);
void alterarConta(void);
void excluirLConta(void);
void excluirFConta(void);
void ordenarConta(void);
void buscarConta(void);
void restaurarBKContas(void);


void main(void) {
	printf("\n\n\n\n");   
    printf("               XXXXX     XXXXX   XX     XX     XXXX   XXXXX       \n");
    printf("               XX   XX  XX   XX  XXX    XX   XX      XX   XX      \n");
    printf("               XX   XX  XX   XX  XXXX   XX  XX       XX   XX      \n");
    printf("               XXXXX    XXXXXXX  XX XX  XX  XX       XX   XX      \n");
    printf("               XX   XX  XX   XX  XX  XX XX  XX       XX   XX      \n");
    printf("               XX   XX  XX   XX  XX   XXXX   XX      XX   XX      \n");
    printf("               XXXXX    XX   XX  XX     XX     XXXX   XXXXX      \n");
    printf("\n");    
    printf("                XXXXX   XX       XXXXX    XXXXX    XXXXXXXX           \n");
    printf("               XX   XX  XX       XX   XX  XX   X   XX           \n");
    printf("               XX   XX  XX       XX   XX  XX   X   XX           \n");
    printf("               XXXXXXX  XX       XXXXX    XXXX     XXXXXXX           \n");
    printf("               XX   XX  XX       XX   XX  XX XX    XX          \n");
    printf("               XX   XX  XX       XX   XX  XX  XX   XX          \n");
    printf("               XX   XX  XXXXXXX  XXXXX    XX   XX  XXXXXXXX          \n");
    printf("\n\n");
    printf("\n\n");
	getch();

	inicio:
	do{
	
		MenuPrincipal();
		
		switch(op){
			case'1': 
				do{
				
					MenuAgencia();
					switch(op){
							case '1': cadastroAgencia(); break;
							case '2': consultaAgencia(); break;
							case '3': alteracaoAgencia(); break;
							case '4': ordenarAgencia(); break;
							case '9': goto inicio;
							case '0': printf("\n\n\tSaindo...\n\t"); exit(1); break;
							default: printf("\n\tOpcao Invalida\n");
					}

				}while(op!='0');
				break;
			case'2': 
				do{
			
					MenuCliente();
					switch(op){
						case '1': cadastroCliente(); break;
						case '2': consultaCliente(); break;
						case '3': alteracaoCliente(); break;
						case '9': goto inicio;
						case '0': printf("\n\n\tSaindo...\n\t"); exit(1); break;
						default: printf("\n\tOpcao Invalida\n");
					}

				}while(op!='0');
				break;
			case'3': 
				do{
				
					MenuConta();
					switch(op){
							case '1': cadastroConta(); break;
							case '2': consultaConta(); break;
							case '3': alterarConta(); break;
							case '4': excluirLConta(); break;
							case '5': excluirFConta(); break;
							case '6': ordenarConta(); break;
							case '7': buscarConta(); break;
							case '8': restaurarBKContas(); break;
							case '9': goto inicio;
							case '0': printf("\n\n\tSaindo...\n\t"); exit(1); break;
							default: printf("\n\tOpcao Invalida\n");
					}

				}while(op!='0');
				
			case'0': printf("\n\n\tSaindo...\n\t"); break;
			default: printf("\n\tOpcao Invalida\n");
			break;
		}
		system("pause");
	}while(op!='0');
}

void MenuPrincipal(void){
	fflush(stdin);
	system("color 1f");
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t\t MENU ");
	printf("\n\n\n\t\t\t\t1-Agencia ");
	printf("\n\t\t\t\t2-Cliente");
	printf("\n\t\t\t\t3-Conta");
	printf("\n\t\t\t\t0-Sair");
	printf("\n\t\t\t\tOpcao:");
	op=getche();
}

void MenuCliente(void){

	system("color 81");
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t MENU CLIENTE");
	printf("\n\n\n\t\t\t\t1-Cadastro ");
	printf("\n\t\t\t\t2-Consulta");
	printf("\n\t\t\t\t3-Alteracao");
	printf("\n\t\t\t\t9-Retornar para o menu anterior");
	printf("\n\t\t\t\t0-Sair");
	printf("\n\t\t\t\tOpcao:");
	op=getche();
}

void MenuAgencia(void){
	
	system("color 4f");
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t MENU AGENCIA");
	printf("\n\n\n\t\t\t\t1-Cadastro ");
	printf("\n\t\t\t\t2-Consulta");
	printf("\n\t\t\t\t3-Alteracao");
	printf("\n\t\t\t\t4-Ordenacao");
	printf("\n\t\t\t\t9-Retornar para o menu anterior");
	printf("\n\t\t\t\t0-Sair");
	printf("\n\t\t\t\tOpcao:");
	op=getche();
}

void MenuConta(void){
	
	system("color 3f");
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t MENU CONTA");
	printf("\n\n\n\t\t\t\t1-Cadastro ");
	printf("\n\t\t\t\t2-Consulta");
	printf("\n\t\t\t\t3-Alteracao");
	printf("\n\t\t\t\t4-Excluisao Logica");
	printf("\n\t\t\t\t5-Exlusao Fisica");
	printf("\n\t\t\t\t6-Ordenacao");
	printf("\n\t\t\t\t7-Buscar");
	printf("\n\t\t\t\t8-Restaurar Backup");
	printf("\n\t\t\t\t9-Retornar para o menu anterior");
	printf("\n\t\t\t\t0-Sair");
	printf("\n\t\t\t\tOpcao:");
	op=getche();
}
void cadastroCliente(void){
	if((fptrCliente=fopen("Cliente.dat","rb+"))==NULL)
		if((fptrCliente=fopen("Cliente.dat","wb"))==NULL){
			printf("\n Erro na abertura do Arquivo\n\t");
			system("pause");
			exit(1);
		}
	do{
	
		system("cls");
		printf("\nCadastro de Clientes:");
		fflush(stdin);
		printf("\n\n\tNome: ");
		gets(C.Nome);
		for(i=0;i<strlen(C.Nome);i++)
		C.Nome[i]=toupper(C.Nome[i]);
		fflush(stdin);
		printf("\tEndereco");
		printf("\n\tRua: ");
		gets(C.ende.Rua);
		fflush(stdin);
		printf("\tNumero: ");
		scanf("%d",&C.ende.numero);
		fflush(stdin);
		printf("\tBairro: ");
		gets(C.ende.Bairro);
		printf("\tCidade: ");
		gets(C.ende.Cidade);
		printf("\tEstado: ");
		gets(C.ende.Estado);
		printf("\tTelefone: ");
		scanf("%d",&C.Tel);
		fseek(fptrCliente, 0, 2);
		C.Cod=ftell(fptrCliente)/sizeof(C);
		fwrite(&C, sizeof(C), 1, fptrCliente);
		printf("\n\n\t Deseja continuar a cadastrar S/N: ");
		cont=getche();
		system("cls");
		
	}while((cont=='s')||(cont=='S'));
	
	fclose(fptrCliente);
}

void consultaCliente(void){
	
	if((fptrCliente=fopen("Cliente.dat","rb"))==NULL){
		printf("\n Erro na leitura do Arquivo Cliente\n\t");
		system("pause");
		exit(1);
	}
	system("cls");
	printf("\n\nLista de Clientes");
	while(fread(&C,sizeof(C),1,fptrCliente)){
		printf("\nCodigo: %d",C.Cod);
		printf("\nNome: %s",C.Nome);
		printf("\nEndereco: %s, %d,%s",C.ende.Rua,C.ende.numero,C.ende.Bairro);
		printf("\nTelefone: %d\n",C.Tel);
		system("pause");		
	}
	fclose(fptrCliente);
	system("cls");
}

void alteracaoCliente(void){
	if((fptrCliente=fopen("Cliente.dat","rb+"))==NULL){
		printf("\n Erro na leitura do Arquivo Cliente\n\t");
		system("pause");
		exit(1);
	}
	k=0;
	system("cls");
	fflush(stdin);
	printf("\n\tDigite o Nome do Cliente que deseja alterar ");
	gets(nome);
	for(i=0;i<strlen(nome);i++)
		nome[i]=toupper(nome[i]);
	fseek(fptrCliente,0,0);
	while(fread(&C,sizeof(C),1,fptrCliente)){
	
		if((strcmp(nome,C.Nome))==0){
			fseek(fptrCliente,ftell(fptrCliente)-sizeof(C),0);
			printf("\nCodigo: %d",C.Cod);
			printf("\nNome: %s",C.Nome);
			printf("\nEndereco: %s, %d, %s, %s, %s",C.ende.Rua,C.ende.numero,C.ende.Bairro,C.ende.Cidade, C.ende.Estado);
			printf("\nTelefone: %d\n",C.Tel);
			system("pause");		
			fflush(stdin);
			k=1;
			printf("\n\tDeseja Alterar o Endereco (S/N)? ");
			op=getche();
			if((op=='s')||(op=='S')){
				printf("\n\tNovo Endereco");
				printf("\n\tRua: ");
				gets(C.ende.Rua);
				fflush(stdin);
				printf("\tNumero: ");
				scanf("%d",&C.ende.numero);
				fflush(stdin);
				printf("\tBairro: ");
				gets(C.ende.Bairro);
				printf("\tCidade: ");
				gets(C.ende.Cidade);
				printf("\tEstado: ");
				gets(C.ende.Estado);
				fseek(fptrCliente,ftell(fptrCliente)-sizeof(C),0);
				fwrite(&C, sizeof(C),1,fptrCliente);
			}
			printf("\n\tDeseja alterar o telefone (S/N)? ");
			op=getche();
			
			if((op=='s')||(op=='S')){
				fflush(stdin);
				printf("\n\tNovo numero de Telefone:");
				printf("\n\tTelefone: ");
				scanf("%d",&C.Tel);
				fseek(fptrCliente,ftell(fptrCliente)-sizeof(C),0);
				fwrite(&C, sizeof(C),1,fptrCliente);
			}
			fseek(fptrCliente,0,2);
		}
		
	}
	if(k==0) printf("\n\t Cliente nao localizado\n");
	else printf("\n\t Cadastro atualizado com sucesso\n");
	fclose(fptrCliente);
	system("pause");
}

void cadastroAgencia(void){
	if((fptrAgencia=fopen("Agencia.dat","rb+"))==NULL)
		if((fptrAgencia=fopen("Agencia.dat","wb"))==NULL){
			printf("\n Erro na abertura do Arquivo\n\t");
			system("pause");
			exit(1);
		}
	do{
	
		system("cls");
		printf("\nCadastro de Agencias:");
		printf("\n\n\tAgencia Numero: ");
		scanf("%d",&Ag.Cod);
		fflush(stdin);
		printf("\tNome: ");
		gets(Ag.Nome);
		fflush(stdin);
		printf("\tEndereco");
		printf("\n\tRua: ");
		gets(Ag.ende.Rua);
		fflush(stdin);
		printf("\tNumero: ");
		scanf("%d",&Ag.ende.numero);
		fflush(stdin);
		printf("\tBairro: ");
		gets(Ag.ende.Bairro);
		printf("\tCidade: ");
		gets(Ag.ende.Cidade);
		printf("\tEstado: ");
		gets(Ag.ende.Estado);
		printf("\tTelefone: ");
		scanf("%d",&Ag.Tel);
		fseek(fptrAgencia, 0, 2);
		Ag.Ativos=0;
		fwrite(&Ag, sizeof(Ag), 1, fptrAgencia);
		printf("\n\n\t Deseja continuar a cadastrar S/N: ");
		cont=getche();
		system("cls");	
		
	}while((cont=='s')||(cont=='S'));
	fclose(fptrAgencia);	
}

void consultaAgencia(void){
	
	if((fptrAgencia=fopen("Agencia.dat","rb"))==NULL){
		printf("\n\tErro na Leitura do Arquivo\n\t");
		system("pause");
		exit(1);
	}
	
	system("cls");
	printf("\n\nLista de Agencias");
	while(fread(&Ag,sizeof(Ag),1,fptrAgencia)){
		k=0;
		printf("\nCodigo: %d",Ag.Cod);
		printf("\nNome: %s",Ag.Nome);
		printf("\nEndereco: %s, %d,%s",Ag.ende.Rua,Ag.ende.numero,Ag.ende.Bairro);
		printf("\nTelefone: %d",Ag.Tel);
		printf("\nAtivos= %.2f",Ag.Ativos);
		printf("\n\tContas:");
		if((fptrConta=fopen("Conta.dat","rb"))==NULL){
			printf("\n\tErro na Leitura do Arquivo de Contas\n\t");
			system("pause");
		}
		else
			if((fptrCliente=fopen("Cliente.dat","rb"))==NULL){
				printf("\n\tErro na Leitura do Arquivo de Cliente\n\t");
				system("pause");
			}
			else{
				while(fread(&Cta,sizeof(Cta),1,fptrConta)){
					if(Cta.E==0){
						if(Ag.Cod==Cta.CodAg){
							k=1;
							printf("\n\tConta N.: %d", Cta.CodCta);
							fseek(fptrCliente,0,0);
							while(fread(&C,sizeof(C),1,fptrCliente)){
								if(Cta.CodCliente==C.Cod){
									printf("\n\tCliente: %s",C.Nome);
									fseek(fptrCliente,0,2);
								}
							}
							printf("\n\tSaldo Atual: %.2f", Cta.Saldo);
							printf("\n\tLimite Disponivel: %.2f",Cta.Limite);
							printf("\n\tSaldo Total Disponivel(Saldo + Limite): %.2f\n", Cta.Saldo+Cta.Limite);
						}
					}
				}
				if(k!=0)
					system("pause");
			}
	}
	if(k==0){
		printf("\n\tNao existem contas cadastrada nessa agencia\n");
		system("pause");	
	}
	
	fclose(fptrAgencia);
	fclose(fptrCliente);
	fclose(fptrConta);
	system("cls");
}

void alteracaoAgencia(void){
	if((fptrAgencia=fopen("Agencia.dat","rb+"))==NULL){
		printf("\n\tErro na Leitura do Arquivo\n\t");
		system("pause");
	}
	k=0;
	system("cls");
	printf("\n\tDigite o Codigo da Agencia que deseja alterar ");
	scanf("%d",&n);
	while(fread(&Ag,sizeof(Ag),1,fptrAgencia)){
		if(n==Ag.Cod){
			printf("\nCodigo: %d",Ag.Cod);
			printf("\nNome: %s",Ag.Nome);
			printf("\nEndereco: %s, %d, %s, %s, %s",Ag.ende.Rua,Ag.ende.numero,Ag.ende.Bairro,Ag.ende.Cidade,Ag.ende.Estado);
			printf("\nTelefone: %d",Ag.Tel);
			printf("\nAtivos= %.2f\n",Ag.Ativos);
			system("pause");		
			k=1;
			fflush(stdin);
			printf("\n\tDeseja Alterar o Endereco (S/N)? ");
			op=getche();
			if((op=='s')||(op=='S')){
				fflush(stdin);
				printf("\n\tNovo Endereco");
				printf("\n\tRua: ");
				gets(Ag.ende.Rua);
				fflush(stdin);
				printf("\tNumero: ");
				scanf("%d",&Ag.ende.numero);
				fflush(stdin);
				printf("\tBairro: ");
				gets(Ag.ende.Bairro);
				printf("\tCidade: ");
				gets(Ag.ende.Cidade);
				printf("\tEstado: ");
				gets(Ag.ende.Estado);
				fseek(fptrAgencia,ftell(fptrAgencia)-sizeof(Ag),0);
				fwrite(&Ag, sizeof(Ag),1,fptrAgencia);
				
			}
			printf("\n\tDeseja alterar o telefone (S/N)? ");
			op=getche();
			if((op=='s')||(op=='S')){
				printf("\n\tNovo numero de Telefone:");
				printf("\n\tTelefone: ");
				scanf("%d",&Ag.Tel);
				fseek(fptrAgencia,ftell(fptrAgencia)-sizeof(Ag),0);
				fwrite(&Ag, sizeof(Ag),1,fptrAgencia);				
			}
			fseek(fptrAgencia,0,2);
		}
	}
	if(k==0) printf("\n\t Agencia nao localizada\n");
	else printf("\n\t Cadastro atualizado com sucesso\n");
	fclose(fptrAgencia);
	system("pause");
}

void ordenarAgencia(void){
	if((fptrAgencia=fopen("Agencia.dat","rb+"))==NULL){
		printf("\n\tErro na Leitura do Arquivo\n\t");
		system("pause");
		exit(1);
	}
	fseek(fptrAgencia,0,2);
	n=ftell(fptrAgencia)/sizeof(Ag);
	
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			fseek(fptrAgencia,i*sizeof(Ag),0);
			fread(&Agi,sizeof(Agi),1,fptrAgencia);
			fseek(fptrAgencia,j*sizeof(Ag),0);
			fread(&Ag,sizeof(Ag),1,fptrAgencia);
			if(Agi.Cod>Ag.Cod){
				fseek(fptrAgencia,i*sizeof(Ag),0);
				fwrite(&Ag,sizeof(Ag),1,fptrAgencia);
				fseek(fptrAgencia,j*sizeof(Agi),0);
				fwrite(&Agi,sizeof(Agi),1,fptrAgencia);
			}
		}
	}
	fclose(fptrAgencia);
	printf("\n\tOrdenacao realizada com sucesso\n\t");
	system("pause");
}

void cadastroConta(void){
	if((fptrConta=fopen("Conta.dat","rb+"))==NULL)
		if((fptrConta=fopen("Conta.dat","wb"))==NULL)	{
			printf("\n\tErro na criacao do arquivo\n");
			system("pause");
			exit(1);
		}
	if((fptrAgencia=fopen("Agencia.dat","rb+"))==NULL)	{
		printf("\n\tNao existe Agencia cadastrada\n");
		system("pause");
		
	}
	if((fptrCliente=fopen("Cliente.dat","rb"))==NULL)	{
		printf("\n\tNao existe Cliente cadastrada\n");
		system("pause");
		
	}
	system("cls");
	printf("\nCadastro de Conta");
	printf("\n\n\tNumero da Conta:");
	scanf("%d",&Cta.CodCta);
	fseek(fptrAgencia,0,0);
	while(fread(&Ag,sizeof(Ag),1,fptrAgencia)){
		printf("\nCodigo: %d",Ag.Cod);
		printf("\nNome: %s\n",Ag.Nome);
		system("pause");
		printf("\n\tDeseja selecionar essa agencia (S/N)?");
		op=getche();
		if((op=='s')||(op=='S')){
			Cta.CodAg=Ag.Cod;
			fseek(fptrAgencia,0,2);
		}
	}
	while(fread(&C,sizeof(C),1,fptrCliente)){
		printf("\nCodigo: %d",C.Cod);
		printf("\nNome: %s\n",C.Nome);
		system("pause");
		printf("\n\tDeseja selecionar esse Cliente (S/N)?");
		op=getche();
		if((op=='s')||(op=='S')){
			Cta.CodCliente=C.Cod;
			fseek(fptrCliente,0,2);
		}
	}
	printf("\n\tSaldo: ");
	scanf("%f",&Cta.Saldo);
	fseek(fptrAgencia,0,0);
	while(fread(&Ag,sizeof(Ag),1,fptrAgencia)){
		if(Cta.CodAg==Ag.Cod){
			Ag.Ativos=Ag.Ativos+Cta.Saldo;
			fseek(fptrAgencia,ftell(fptrAgencia)-sizeof(Ag),0);
			fwrite(&Ag,sizeof(Ag),1,fptrAgencia);
			fseek(fptrAgencia,0,2);
		}
	}
	Cta.E=0;
	printf("\tLimite: ");
	scanf("%f",&Cta.Limite);
	fseek(fptrConta,0,2);
	fwrite(&Cta,sizeof(Cta),1,fptrConta);
	fclose(fptrAgencia);
	fclose(fptrConta);
	fclose(fptrCliente);
}
void consultaConta(void){
	if((fptrAgencia=fopen("Agencia.dat","rb"))==NULL){
		printf("\n\tErro na leitura do arquivo\n");
		system("pause");
	}
	if((fptrConta=fopen("Conta.dat","rb"))==NULL){
		printf("\n\tErro na leitura do arquivo\n");
		system("pause");
	}
	if((fptrCliente=fopen("Cliente.dat","rb"))==NULL){
		printf("\n\tErro na leitura do arquivo\n");
		system("pause");
	}
	system("cls");
	fseek(fptrConta,0,0);
	while(fread(&Cta,sizeof(Cta),1,fptrConta)){
		if(Cta.E==0){
			printf("\n\tConta Numero: %d", Cta.CodCta);
			fseek(fptrAgencia,0,0);
			while(fread(&Ag,sizeof(Ag),1,fptrAgencia)){
				if(Cta.CodAg==Ag.Cod){
					printf("\n\tCodigo da Agencia: %d", Ag.Cod);
					printf("\n\tNome da Agencia: %s", Ag.Nome);
					fseek(fptrAgencia,0,2);
				}
			}
			fseek(fptrCliente,0,0);
			while(fread(&C,sizeof(C),1,fptrCliente)){
				if(Cta.CodCliente==C.Cod){
					printf("\n\tNome do Cliente: %s", C.Nome);
					fseek(fptrAgencia,0,2);
				}
			}
			printf("\n\tSaldo: %.2f",Cta.Saldo);
			printf("\n\tLimite: %.2f",Cta.Limite);
			printf("\n\tSaldo Total Disponivel: %.2f\n",Cta.Saldo+Cta.Limite);
			system("pause");
		}
	}
	fclose(fptrAgencia);
	fclose(fptrCliente);
	fclose(fptrConta);
}
void alterarConta(void){
	if((fptrConta=fopen("Conta.dat","rb+"))==NULL){
		printf("\n\tErro na leitura do arquivo\n");
		system("pause");
	}
	system("cls");
	fflush(stdin);
	printf("\n\tDigite o Codigo da Conta que deseja alterar\n\t");
	scanf("%d",&codigo);
	while(fread(&Cta,sizeof(Cta),1,fptrConta)){
		if(codigo==Cta.CodCta){
			if(Cta.E==0){
				printf("\n\tDigite o novo Limite: ");
				scanf("%f",&Cta.Limite);
				fseek(fptrConta,ftell(fptrConta)-sizeof(Cta),0);
				fwrite(&Cta,sizeof(Cta),1,fptrConta);
				fseek(fptrConta,0,2);
			}
		}
	}
	printf("\n\tAlteracao realizada com sucesso\n");
	system("pause");
	fclose(fptrConta);
}
void excluirLConta(void){
	if((fptrConta=fopen("Conta.dat","rb+"))==NULL){
		printf("\n\tErro na leitura do Arquivo\n");
		exit(1);
	}	
	system("cls");
	printf("\n\tDigite o numero da conta que deseja excluir");
	scanf("%d", & codigo);
	while(fread(&Cta,sizeof(Cta),1,fptrConta)){
		if(codigo==Cta.CodCta){
			Cta.E=1;
			fseek(fptrConta,ftell(fptrConta)-sizeof(Cta),0);
			fwrite(&Cta,sizeof(Cta),1,fptrConta);
		 	fseek(fptrConta,0,2);
		 
		}
		
	} 
	printf("\n\tExclusao realizada com sucesso\n");
	system("pause");
	fclose(fptrConta);
}      
void excluirFConta(void){
	if((fptrConta=fopen("Conta.dat","rb"))==NULL){
		printf("\n\tErro na Leitura do arquivo\n");
		system("pause");
		exit(1);
	}
	if((fptrNovo=fopen("Novo.dat","wb"))==NULL){
		printf("\n\tErro na Leitura do arquivo\n");
		system("pause");
		exit(1);
	}
	if((fptrBack=fopen("BackupConta.dat","rb+"))==NULL)
		if((fptrBack=fopen("BackupConta.dat","wb"))==NULL){
			printf("\n\tErro na Leitura do arquivo\n");
			system("pause");
			exit(1);
		}
	
	while(fread(&Cta,sizeof(Cta),1,fptrConta)){
		if(Cta.E==1){
			fseek(fptrBack,0,2);
			fwrite(&Cta,sizeof(Cta),1,fptrBack);
		}
		else{
			fseek(fptrNovo,0,2);
			fwrite(&Cta,sizeof(Cta),1,fptrNovo);
		}
	}
	fclose(fptrBack);
	fclose(fptrConta);
	fclose(fptrNovo);
	remove("Conta.dat");
	rename("Novo.dat","Conta.dat");
	printf("\n\tExclusao realizada com sucesso\n");
}
void ordenarConta(void){
	if((fptrConta=fopen("Conta.dat","rb+"))==NULL){
		printf("\n\tErro na Leitura do Arquivo\n\t");
		system("pause");
		exit(1);
	}
	fseek(fptrConta,0,2);
	n=ftell(fptrConta)/sizeof(Cta);
	
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			fseek(fptrConta,i*sizeof(Cta),0);
			fread(&Ctai,sizeof(Ctai),1,fptrConta);
			fseek(fptrConta,j*sizeof(Cta),0);
			fread(&Cta,sizeof(Cta),1,fptrConta);
			if(Ctai.CodCta>Cta.CodCta){
				fseek(fptrConta,i*sizeof(Cta),0);
				fwrite(&Cta,sizeof(Cta),1,fptrConta);
				fseek(fptrConta,j*sizeof(Ctai),0);
				fwrite(&Ctai,sizeof(Ctai),1,fptrConta);
			}
		}
	}
	fclose(fptrConta);
	printf("\n\tOrdenacao realizada com sucesso\n\t");
	system("pause");		
}
void buscarConta(void){

	if((fptrAgencia=fopen("Agencia.dat","rb"))==NULL){
		printf("\n\tErro na leitura do arquivo\n");
		system("pause");
	}
	if((fptrConta=fopen("Conta.dat","rb"))==NULL){
		printf("\n\tErro na leitura do arquivo\n");
		system("pause");
	}
	if((fptrCliente=fopen("Cliente.dat","rb"))==NULL){
		printf("\n\tErro na leitura do arquivo\n");
		system("pause");
	}
	k=0;
	printf("\n\tEntre com o Codigo da Conta que deseja Consultar:");
	scanf("%d",&codigo);
	while(fread(&Cta,sizeof(Cta),1,fptrConta)){
		if(codigo==Cta.CodCta){
			if(Cta.E==0){
				k=1;
				printf("\n\tConta Numero: %d", Cta.CodCta);
				while(fread(&Ag,sizeof(Ag),1,fptrAgencia)){
					if(Cta.CodAg==Ag.Cod){
						printf("\n\tCodigo da Agencia: %d", Ag.Cod);
						printf("\n\tNome da Agencia: %s", Ag.Nome);
						fseek(fptrAgencia,0,2);
					}
				}
				while(fread(&C,sizeof(C),1,fptrCliente)){
					if(Cta.CodCliente==C.Cod){
						printf("\n\tNome do Cliente: %s", C.Nome);
						fseek(fptrAgencia,0,2);
					}
				}
				printf("\n\tSaldo: %.2f",Cta.Saldo);
				printf("\n\tLimite: %.2f",Cta.Limite);
				printf("\n\tSaldo Total Disponivel: %.2f\n\t",Cta.Saldo+Cta.Limite);
			}
			fseek(fptrConta,0,2);
		}
			
	}
	if(k==0) printf("\n\tConta nao localizada\n\t");
	system("pause");
	fclose(fptrAgencia);
	fclose(fptrCliente);
	fclose(fptrConta);
}
void restaurarBKContas(void){
	if((fptrBack=fopen("BackupConta.dat","rb"))==NULL){
		printf("\n\tErro na Leitura do arquivo\n");
		system("pause");
		exit(1);
	}
	if((fptrConta=fopen("Conta.dat","rb+"))==NULL){
		printf("\n\tErro na leitura do arquivo\n");
		system("pause");
	}
	
	fseek(fptrBack,0,0);
	while(fread(&Cta,sizeof(Cta),1,fptrBack)){
		Cta.E=0;
		fseek(fptrConta,0,2);
		fwrite(&Cta,sizeof(Cta),1,fptrConta);
	}
	fclose(fptrBack);
	fclose(fptrConta);
	remove("BackupConta.dat");
	printf("\n\tRestauracao efetuada com sucesso\n\t");
	system("pause");
	system("cls");
}
