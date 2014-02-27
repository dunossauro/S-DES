/*Código feito e testado no Slackware 14.1
Escrito(e muito mal escrito) por Eduardo Mendes
É um passo a passo deenvolvido nos laboratórios da Fatec-AM
Durante as aulas de criptografia*/

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

//variaveis_globais
int chave[10];
int k1[8];
int k2[8];
int texto[8];

//função que cria as Ks
void chaves (){

system("clear");

//variaveis_locais
int j;
int p[10], le[5], ld[5];

printf("Digite os 10 numeros de chave:\n");

for(j=0;j<=9;j++){
	scanf("%i",&chave[j]);
	if(chave[j]!=1 && chave[j] !=0){
	printf("Digite só 0 ou 1!!!:\n");
	}
}

//Permutação10
p[0]=chave[2];
p[1]=chave[4];
p[2]=chave[1];
p[3]=chave[6];
p[4]=chave[3];
p[5]=chave[9];
p[6]=chave[0];
p[7]=chave[8];
p[8]=chave[7];
p[9]=chave[5];

//LS-1(le)

le[0]=p[1];
le[1]=p[2];
le[2]=p[3];
le[3]=p[4];
le[4]=p[0];

//LS-1(ld)
ld[0]=p[6];
ld[1]=p[7];
ld[2]=p[8];
ld[3]=p[9];
ld[4]=p[5];

//permutação 8

//junção dos caracteres
p[0]=le[0];
p[1]=le[1];
p[2]=le[2];
p[3]=le[3];
p[4]=le[4];
p[5]=ld[0];
p[6]=ld[1];
p[7]=ld[2];
p[8]=ld[3];
p[9]=ld[4];

//K1

k1[0]=p[5];
k1[1]=p[2];
k1[2]=p[6];
k1[3]=p[3];
k1[4]=p[7];
k1[5]=p[4];
k1[6]=p[9];
k1[7]=p[8];

printf("k1:    ");
for(j=0;j<8;j++){

	printf("%i",k1[j]);
}

printf("\n");

//LS-2 le
le[0]=p[3];
le[1]=p[3];
le[2]=p[4];
le[3]=p[0];
le[4]=p[1];

//LS-2 ld
ld[0]=p[7];
ld[1]=p[8];
ld[2]=p[9];
ld[3]=p[5];
ld[4]=p[6];

//p8(2)

p[0]=le[0];
p[1]=le[1];
p[2]=le[2];
p[3]=le[3];
p[4]=le[4];
p[5]=ld[0];
p[6]=ld[1];
p[7]=ld[2];
p[8]=ld[3];
p[9]=ld[4];

//K2

k2[0]=p[5];
k2[1]=p[2];
k2[2]=p[6];
k2[3]=p[3];
k2[4]=p[7];
k2[5]=p[4];
k2[6]=p[9];
k2[7]=p[8];

printf("k2:    ");

for(j=0;j<8;j++){

        printf("%i",k2[j]);
}

printf("\n");


printf("chave: ");

for(j=0;j<10;j++){

        printf("%i",chave[j]);
}

printf("\n");

}


void cripto(){

int p[8],ld[4],le[4],j,s0[4][4],s1[4][4],xor[8],linha[2],coluna[2],i,bit[2];

//pos matriz
int pm[4];

//ip(final do codigo)
int ip[8];

//valores da matriz s0
s0[0][0]=1;
s0[0][1]=0;
s0[0][2]=3;
s0[0][3]=2;
s0[1][0]=3;
s0[1][1]=2;
s0[1][2]=1;
s0[1][3]=0;
s0[2][0]=0;
s0[2][1]=2;
s0[2][2]=1;
s0[2][3]=3;
s0[3][0]=3;
s0[3][1]=1;
s0[3][2]=3;
s0[3][3]=2;

//valores da matriz s1
s1[0][0]=0;
s1[0][1]=1;
s1[0][2]=2;
s1[0][3]=3;
s1[1][0]=2;
s1[1][1]=0;
s1[1][2]=1;
s1[1][3]=3;
s1[2][0]=3;
s1[2][1]=0;
s1[2][2]=1;
s1[2][3]=0;
s1[3][0]=2;
s1[3][1]=1;
s1[3][2]=0;
s1[3][3]=3;

printf("Digite o texto claro\n");

for(j=0;j<8;j++){

	scanf("%i",&texto[j]);
	if((texto[j]!=1) && (texto[j] !=0)){
        	printf("Digite só 0 ou 1!!!:\n");
        }

}

//IP
p[0]=texto[1];
p[1]=texto[5];
p[2]=texto[2];
p[3]=texto[0];
p[4]=texto[3];
p[5]=texto[7];
p[6]=texto[4];
p[7]=texto[6];

//L - R
le[0]=p[0];
le[1]=p[1];
le[2]=p[2];
le[3]=p[3];
ld[0]=p[4];
ld[1]=p[5];
ld[2]=p[6];
ld[3]=p[7];

//E/P
p[0]=ld[3];
p[1]=ld[0];
p[2]=ld[1];
p[3]=ld[2];
p[4]=ld[1];
p[5]=ld[2];
p[6]=ld[3];
p[7]=ld[0];

//XOR K1
xor[0]=(p[0]^k1[0]);
xor[1]=(p[1]^k1[1]);
xor[2]=(p[2]^k1[2]);
xor[3]=(p[3]^k1[3]);
xor[4]=(p[4]^k1[4]);
xor[5]=(p[5]^k1[5]);
xor[6]=(p[6]^k1[6]);
xor[7]=(p[7]^k1[7]);

//matriz s0 1-4

if( (xor[0]=0) && (xor[3]=0)){
	linha[0]=0;
}
if( (xor[0]=0) && (xor[3]=1)){
	linha[0]=1;
}
if( (xor[0]=1)  && (xor[3]=0)){
        linha[0]=2;
}
if( (xor[0]=1) && (xor[3]=1)){
        linha[0]=3;
}

//matriz s0 2-3

if((xor[1]=0)  && (xor[2]=0)){
        coluna[0]=0;
}
if((xor[1]=0) && (xor[2]=1)){
        coluna[0]=1;
}
if((xor[1]=1)  && (xor[2]=0)){
        coluna[0]=2;
}
if((xor[1]=1) && (xor[2]=1)){
        coluna[0]=3;
}

//busca na matriz S0

for(j=0;j>4;j++){
	if(linha[0]=j){
		for(i=0;i>4;i++){
			if(coluna[0]=i){
				bit[0]=s0[j][i];
			}
		}
	}
}

//converçao decimal -> binario
if(bit[0]=0){

	pm[0]=0;
	pm[1]=0;
}if(bit[0]=1){

	pm[0]=0;
	pm[1]=1;

}if(bit[0]=2){

	pm[0]=1;
	pm[1]=0;

}if(bit[0]=3){

	pm[0]=1;
	pm[1]=1;
}

//matriz s1 1-4

if((xor[4]=0)  && (xor[7]=0)){
        linha[1]=0;
}
if((xor[4]=0) && (xor[7]=1)){
        linha[1]=1;
}
if((xor[4]=1)  && (xor[7]=0)){
        linha[1]=2;
}
if((xor[4]=1) && (xor[7]=1)){
        linha[1]=3;
}

//matriz s1 2-3

if((xor[5]=0)  && (xor[6]=0)){
        coluna[1]=0;
}
if((xor[5]=0) && (xor[6]=1)){
        coluna[1]=1;
}
if((xor[5]=1)  && (xor[6]=0)){
        coluna[1]=2;
}
if((xor[5]=1) && (xor[6]=1)){
        coluna[1]=3;
}

//busca na matriz S1

for(j=0;j>4;j++){
        if(linha[1]=j){
                for(i=0;i>4;i++){
                        if(coluna[1]=i){
                                bit[1]=s1[j][i];
                        }
                }
        }
}

//converçao decimal -> binario S1
if(bit[1]=0){

        pm[2]=0;
        pm[3]=0;
}if(bit[1]=1){

        pm[2]=0;
        pm[3]=1;

}if(bit[1]=2){

        pm[2]=1;
        pm[3]=0;

}if(bit[1]=3){

        pm[2]=1;
        pm[3]=1;
}

//P4

p[0]=pm[1];
p[1]=pm[3];
p[2]=pm[2];
p[3]=pm[0];

//xor Le ^ p4

xor[0]=(le[0]^p[0]);
xor[1]=(le[1]^p[1]);
xor[2]=(le[2]^p[2]);
xor[3]=(le[3]^p[3]);

//junçao 8bits

p[0]=xor[0];
p[1]=xor[1];
p[2]=xor[2];
p[3]=xor[3];
p[4]=ld[0];
p[5]=ld[1];
p[6]=ld[2];
p[7]=ld[3];

//SW

le[0]=p[4];
le[1]=p[5];
le[2]=p[6];
le[3]=p[7];
ld[0]=p[0];
ld[1]=p[1];
ld[2]=p[2];
ld[3]=p[3];

//E/P

p[0]=ld[3];
p[1]=ld[0];
p[2]=ld[1];
p[3]=ld[2];
p[4]=ld[1];
p[5]=ld[2];
p[6]=ld[3];
p[7]=ld[0];

//XOR K2

xor[0]=(p[0]^k2[0]);
xor[1]=(p[1]^k2[1]);
xor[2]=(p[2]^k2[2]);
xor[3]=(p[3]^k2[3]);
xor[4]=(p[4]^k2[4]);
xor[5]=(p[5]^k2[5]);
xor[6]=(p[6]^k2[6]);
xor[7]=(p[7]^k2[7]);

//matriz s0 1-4

if((xor[0]=0)  && (xor[3]=0)){
        linha[1]=0;
}
if((xor[0]=0) && (xor[3]=1)){
        linha[1]=1;
}
if((xor[0]=1)  && (xor[3]=0)){
        linha[1]=2;
}
if((xor[0]=1) && (xor[3]=1)){
        linha[1]=3;
}

//matriz s0 2-3

if((xor[1]=0)  && (xor[2]=0)){
        coluna[1]=0;
}
if((xor[1]=0) && (xor[2]=1)){
        coluna[1]=1;
}
if((xor[1]=1)  && (xor[2]=0)){
        coluna[1]=2;
}
if((xor[1]=1) && (xor[2]=1)){
        coluna[1]=3;
}

//busca na matriz S0

for(j=0;j>4;j++){
        if(linha[1]=j){
                for(i=0;i>4;i++){
                        if(coluna[1]=i){
                                bit[0]=s0[j][i];
                        }
                }
        }
}

//converçao decimal -> binario
if(bit[0]=0){

        pm[0]=0;
        pm[1]=0;
}if(bit[0]=1){

        pm[0]=0;
        pm[1]=1;

}if(bit[0]=2){

        pm[0]=1;
        pm[1]=0;

}if(bit[0]=3){

        pm[0]=1;
        pm[1]=1;
}

//matriz s1 1-4

if((xor[4]=0)  && (xor[7]=0)){
        linha[1]=0;
}
if((xor[4]=0) && (xor[7]=1)){
        linha[1]=1;
}
if((xor[4]=1)  && (xor[7]=0)){
        linha[1]=2;
}
if((xor[4]=1) && (xor[7]=1)){
        linha[1]=3;
}

//matriz s1 2-3

if((xor[5]=0)  && (xor[6]=0)){
        coluna[1]=0;
}
if((xor[5]=0) && (xor[6]=1)){
        coluna[1]=1;
}
if((xor[5]=1)  && (xor[6]=0)){
        coluna[1]=2;
}
if((xor[5]=1) && (xor[6]=1)){
        coluna[1]=3;
}

//busca na matriz S1

for(j=0;j>4;j++){
        if(linha[1]=j){
                for(i=0;i>4;i++){
                        if(coluna[1]=i){
                                bit[1]=s1[j][i];
                        }
                }
    }
}

//converçao decimal -> binario S1
if(bit[1]=0){

        pm[2]=0;
        pm[3]=0;
}if(bit[1]=1){

        pm[2]=0;
        pm[3]=1;

}if(bit[1]=2){

        pm[2]=1;
        pm[3]=0;

}if(bit[1]=3){

        pm[2]=1;
        pm[3]=1;
}

//P4

p[0]=pm[1];
p[1]=pm[3];
p[2]=pm[2];
p[3]=pm[0];

//xor Le ^ p4

xor[0]=(le[0]^p[0]);
xor[1]=(le[1]^p[1]);
xor[2]=(le[2]^p[2]);
xor[3]=(le[3]^p[3]);

//junçao 8bits

p[0]=xor[0];
p[1]=xor[1];
p[2]=xor[2];
p[3]=xor[3];
p[4]=ld[0];
p[5]=ld[1];
p[6]=ld[2];
p[7]=ld[3];

//IP(reverso)

ip[0]=p[3];
ip[1]=p[0];
ip[2]=p[2];
ip[3]=p[4];
ip[4]=p[6];
ip[5]=p[1];
ip[6]=p[7];
ip[7]=p[5];

printf("Valor criptografado: ");
for(j=0;j<=7;j++){

	printf("%i",ip[j]);

}

printf("\nTexto puro: ");

for(j=0;j<=7;j++){

	printf("%d",texto[j]);

}
printf("\n");
}

void descripto(){

int p[8],ld[4],le[4],j,s0[4][4],s1[4][4],xor[8],linha[2],coluna[2],i,bit[2];

//pos matriz
int pm[4];

//ip(final do codigo)
int ip[8];

//valores da matriz s0
s0[0][0]=1;
s0[0][1]=0;
s0[0][2]=3;
s0[0][3]=2;
s0[1][0]=3;
s0[1][1]=2;
s0[1][2]=1;
s0[1][3]=0;
s0[2][0]=0;
s0[2][1]=2;
s0[2][2]=1;
s0[2][3]=3;
s0[3][0]=3;
s0[3][1]=1;
s0[3][2]=3;
s0[3][3]=2;

//valores da matriz s1
s1[0][0]=0;
s1[0][1]=1;
s1[0][2]=2;
s1[0][3]=3;
s1[1][0]=2;
s1[1][1]=0;
s1[1][2]=1;
s1[1][3]=3;
s1[2][0]=3;
s1[2][1]=0;
s1[2][2]=1;
s1[2][3]=0;
s1[3][0]=2;
s1[3][1]=1;
s1[3][2]=0;
s1[3][3]=3;

printf("Digite o texto criptografado\n");

for(j=0;j<8;j++){

	scanf("%i",&texto[j]);
	if((texto[j]!=1) && (texto[j] !=0)){
        	printf("Digite só 0 ou 1!!!:\n");
        }

}

//IP
p[0]=texto[1];
p[1]=texto[5];
p[2]=texto[2];
p[3]=texto[0];
p[4]=texto[3];
p[5]=texto[7];
p[6]=texto[4];
p[7]=texto[6];

//L - R
le[0]=p[0];
le[1]=p[1];
le[2]=p[2];
le[3]=p[3];
ld[0]=p[4];
ld[1]=p[5];
ld[2]=p[6];
ld[3]=p[7];

//E/P
p[0]=ld[3];
p[1]=ld[0];
p[2]=ld[1];
p[3]=ld[2];
p[4]=ld[1];
p[5]=ld[2];
p[6]=ld[3];
p[7]=ld[0];

//XOR K2
xor[0]=(p[0]^k2[0]);
xor[1]=(p[1]^k2[1]);
xor[2]=(p[2]^k2[2]);
xor[3]=(p[3]^k2[3]);
xor[4]=(p[4]^k2[4]);
xor[5]=(p[5]^k2[5]);
xor[6]=(p[6]^k2[6]);
xor[7]=(p[7]^k2[7]);

//matriz s0 1-4

if( (xor[1]=0) && (xor[4]=0)){
	linha[0]=0;
}
if( (xor[1]=0) && (xor[4]=1)){
	linha[0]=1;
}
if( (xor[1]=1)  && (xor[4]=0)){
        linha[0]=2;
}
if( (xor[1]=1) && (xor[4]=1)){
        linha[0]=3;
}

//matriz s0 2-3

if((xor[2]=0)  && (xor[3]=0)){
        coluna[0]=0;
}
if((xor[2]=0) && (xor[3]=1)){
        coluna[0]=1;
}
if((xor[2]=1)  && (xor[3]=0)){
        coluna[0]=2;
}
if((xor[2]=1) && (xor[3]=1)){
        coluna[0]=3;
}

//busca na matriz S0

for(j=0;j>4;j++){
	if(linha[0]=j){
		for(i=0;i>4;i++){
			if(coluna[0]=i){
				bit[0]=s0[j][i];
			}
		}
	}
}

//converçao decimal -> binario
if(bit[0]=0){

	pm[0]=0;
	pm[1]=0;
}if(bit[0]=1){

	pm[0]=0;
	pm[1]=1;

}if(bit[0]=2){

	pm[0]=1;
	pm[1]=0;

}if(bit[0]=3){

	pm[0]=1;
	pm[1]=1;
}

//matriz s1 1-4

if((xor[1]=0)  && (xor[4]=0)){
        linha[1]=0;
}
if((xor[1]=0) && (xor[4]=1)){
        linha[1]=1;
}
if((xor[1]=1)  && (xor[4]=0)){
        linha[1]=2;
}
if((xor[1]=1) && (xor[4]=1)){
        linha[1]=3;
}

//matriz s1 2-3

if((xor[2]=0)  && (xor[3]=0)){
        coluna[1]=0;
}
if((xor[2]=0) && (xor[3]=1)){
        coluna[1]=1;
}
if((xor[2]=1)  && (xor[3]=0)){
        coluna[1]=2;
}
if((xor[2]=1) && (xor[3]=1)){
        coluna[1]=3;
}

//busca na matriz S1

for(j=0;j>4;j++){
        if(linha[1]=j){
                for(i=0;i>4;i++){
                        if(coluna[1]=i){
                                bit[1]=s1[j][i];
                        }
                }
        }
}

//converçao decimal -> binario S1
if(bit[1]=0){

        pm[2]=0;
        pm[3]=0;
}if(bit[1]=1){

        pm[2]=0;
        pm[3]=1;

}if(bit[1]=2){

        pm[2]=1;
        pm[3]=0;

}if(bit[1]=3){

        pm[2]=1;
        pm[3]=1;
}

//P4

p[0]=pm[1];
p[1]=pm[3];
p[2]=pm[2];
p[3]=pm[0];

//xor Le ^ p4

xor[0]=(le[0]^p[0]);
xor[1]=(le[1]^p[1]);
xor[2]=(le[2]^p[2]);
xor[3]=(le[3]^p[3]);

//junçao 8bits

p[0]=xor[0];
p[1]=xor[1];
p[2]=xor[2];
p[3]=xor[3];
p[4]=ld[0];
p[5]=ld[1];
p[6]=ld[2];
p[7]=ld[3];

//SW

le[0]=p[4];
le[1]=p[5];
le[2]=p[6];
le[3]=p[7];
ld[0]=p[0];
ld[1]=p[1];
ld[2]=p[2];
ld[3]=p[3];

//E/P

p[0]=ld[3];
p[1]=ld[0];
p[2]=ld[1];
p[3]=ld[2];
p[4]=ld[1];
p[5]=ld[2];
p[6]=ld[3];
p[7]=ld[0];

//XOR K1

xor[0]=(p[0]^k1[0]);
xor[1]=(p[1]^k1[1]);
xor[2]=(p[2]^k1[2]);
xor[3]=(p[3]^k1[3]);
xor[4]=(p[4]^k1[4]);
xor[5]=(p[5]^k1[5]);
xor[6]=(p[6]^k1[6]);
xor[7]=(p[7]^k1[7]);

//matriz s0 1-4

if((xor[1]=0)  && (xor[4]=0)){
        linha[0]=0;
}
if((xor[1]=0) && (xor[4]=1)){
        linha[0]=1;
}
if((xor[1]=1)  && (xor[4]=0)){
        linha[0]=2;
}
if((xor[1]=1) && (xor[4]=1)){
        linha[0]=3;
}

//matriz s0 2-3

if((xor[2]=0)  && (xor[3]=0)){
        coluna[0]=0;
}
if((xor[2]=0) && (xor[3]=1)){
        coluna[0]=1;
}
if((xor[2]=1)  && (xor[3]=0)){
        coluna[0]=2;
}
if((xor[2]=1) && (xor[3]=1)){
        coluna[0]=3;
}

//busca na matriz S0

for(j=0;j>4;j++){
        if(linha[0]=j){
                for(i=0;i>4;i++){
                        if(coluna[0]=i){
                                bit[0]=s0[j][i];
                        }
                }
        }
}

//converçao decimal -> binario
if(bit[0]=0){

        pm[0]=0;
        pm[1]=0;
}if(bit[0]=1){

        pm[0]=0;
        pm[1]=1;

}if(bit[0]=2){

        pm[0]=1;
        pm[1]=0;

}if(bit[0]=3){

        pm[0]=1;
        pm[1]=1;
}

//P4

p[0]=pm[1];
p[1]=pm[3];
p[2]=pm[2];
p[3]=pm[0];

//xor Le ^ p4

xor[0]=(le[0]^p[0]);
xor[1]=(le[1]^p[1]);
xor[2]=(le[2]^p[2]);
xor[3]=(le[3]^p[3]);

//junçao 8bits

p[0]=xor[0];
p[1]=xor[1];
p[2]=xor[2];
p[3]=xor[3];
p[4]=ld[0];
p[5]=ld[1];
p[6]=ld[2];
p[7]=ld[3];

//IP(reverso)

ip[0]=p[3];
ip[1]=p[0];
ip[2]=p[2];
ip[3]=p[4];
ip[4]=p[6];
ip[5]=p[1];
ip[6]=p[7];
ip[7]=p[5];

printf("Valor puro: ");
for(j=0;j<=7;j++){

	printf("%i",ip[j]);

}

printf("\nTexto criptografado: ");

for(j=0;j<=7;j++){

	printf("%d",texto[j]);

}
printf("\n");

}

main(){
//inicia chaves
	chaves();

//inicia o processo de cripto
	cripto();

//inicia descripto
	descripto();

}
