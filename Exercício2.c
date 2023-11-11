#include<stdio.h>
#include<string.h>

/*2- Elaborar uma análise para o ministerio da fazenda sobre o recebimento de sálario regular através do registro de carteira proficional dos funcionários do país. */

int validarSexo(char sexo)
{
    return sexo == 'M' || 'F';
}

int validarSalario(float salario)
{
    return salario > 1.00;
}

char classificarSalario(float salario)
{
    if(salario > 1400.00){
        return 'A';
    }else if(salario == 1400.00){
        return 'l';
    }else{
        return 'B';
    }
}

void mostraClassificacao(char nome[], char sexo, float salario)
{
    char classificacao = classificarSalario(salario);
    char sexoPorExtenso = (sexo == 'M')? 'Masculino' : 'Feminino';

    printf("\n Nome: %s \n", nome);
    printf("\n Sexo: %s \n", (sexo == 'M')? "Masculino" : "Feminino");
    printf("\n Salario: R$ %.2f", salario);
    printf("\nClassificacao em relacao ao salario minimo:");

    switch(classificacao){
        case 'A':
        printf("\n Acima");
        break;

        case 'l':
        printf("\n Igual");
        break;

        case 'B':
        printf("\n Abaixo");
    }
}

int main()
{
    int quantidadeAssalariados, totalAbaixo = 0, totaAcima = 0, totalIgual = 0;
    char nome[100], sexo;
    float salario;

    printf("\n Informe a quantidade de assalariados:");
    scanf("%d", &quantidadeAssalariados);

    for(int i = 0; i <= quantidadeAssalariados; i++){
        do{
            printf("\n Informe o nome do assalariado %d:",i);
            scanf("%s", nome);
        }while(nome[0]=='\0');

        do{
            printf("\n Informe o seu sexo %d (M/F):", i);
            scanf("%s", &sexo);
        }while(!validarSexo(sexo));

        do{
            printf("\n Informe o seu salario %d:", i);
            scanf("%f", &salario);
        }while(!validarSalario(salario));

        mostraClassificacao(nome, sexo, salario);

        if(classificarSalario(salario) == 'B'){
            totalAbaixo++;
        }else if(classificarSalario(salario) == 'A'){
            totaAcima++;
        }else if(classificarSalario(salario) =='l'){
            totalIgual++;
        }
    }

    printf("\n Assalariados com salario abaixo do minimo: %d", totalAbaixo);
    printf("\n Assalariados com salario acima do minimo: %d", totaAcima);
    printf("\n Assalariados com salario igual ao minimo: %d", totalIgual);
}
