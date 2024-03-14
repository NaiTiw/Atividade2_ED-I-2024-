#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Pessoa
{
char nome[30], cargo[10];
float salbase, benef, desconto;
};
void cadastrar(struct Pessoa p[3]);
void imprimir (struct Pessoa p[3], float *somav, float *somag, float *somac);
int main()
{
struct Pessoa p[3];
int i;
float somav=0, somag=0, somac=0;
cadastrar(p);
imprimir(p, &somav, &somag, &somac);
printf("Total salarios gerente: %f\n", somag);
printf("Total salarios vendedor: %f\n", somav);
printf("Total salarios caixa: %f\n", somac);
system("pause");
}
void cadastrar (struct Pessoa p[3])
{
int i;
for(i=0;i<3;i++)
{
printf("Informe o nome: ");
scanf("%s", &p[i].nome);
printf("Informe o cargo: ");
scanf("%s", &p[i].cargo);
printf("Informe o salario: ");
scanf("%f", &p[i].salbase);
printf("Informe o beneficio: ");
scanf("%f", &p[i].benef);
printf("Informe o desconto: ");
scanf("%f", &p[i].desconto);
}
}
void imprimir (struct Pessoa p[3], float *somav, float *somag, float *somac)
{
int i;
float liquido=0, soma=0;
for(i=0;i<3;i++)
{
printf("\nNome: %s\n", p[i].nome);
printf("Cargo: %s\n", p[i].cargo);
printf("Salario base:%f\n", p[i].salbase);
printf("Beneficios: %f\n", p[i].benef);
printf("Desconto: %f\n", p[i].desconto);
liquido=p[i].salbase+p[i].benef-p[i].desconto;
printf("Salario Liquido: %f", liquido);
if(strcmp(p[i].cargo, "vendedor")==0)
*somav=*somav+liquido;
else
if(strcmp(p[i].cargo, "gerente")==0)
*somag=*somac+liquido;
else
*somac=*somac+liquido;
soma=soma+liquido;
liquido=0;
}
printf("Media salarial: %f", soma/3);
}
