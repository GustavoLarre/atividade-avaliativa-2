#include <stdio.h>
#include <string.h>

/*1- Elabore um algoritimo para solicitar de cada funcionário a quantidade de peças fabricadas naquele mês e apresentar o seu salário.*/

//Protótipos
int retorno();
void calculaSal1(pecasProduzidas);
void calculaSal2(pecasProduzidas);
void calculaSal3(pecasProduzidas);

main()
{

    // Variáveis
    int opcao, pecasProduzidas, conta;

    do
    {
        // Entrada dos dados
        printf("\n Informe o numero de pecas que voce produziu esse mes:");
        scanf("%d", &pecasProduzidas);

        // Operações
        if (pecasProduzidas <= 50)
        {
            conta = 1;
        }
        else if (pecasProduzidas > 50 && pecasProduzidas <= 80)
        {
            conta = 2;
        }
        else if (pecasProduzidas > 80)
        {
            conta = 3;
        }

        switch (conta)
        {
        case 1:
            calculaSal1(pecasProduzidas);
            break;

        case 2:
            calculaSal2(pecasProduzidas);
            break;

        case 3:
            calculaSal3(pecasProduzidas);
        }

        opcao = retorno();

    } while (opcao != 0);
}

void calculaSal1(pecasProduzidas)
{
    printf("\n Infelizmente voce nao recebera um adicional de produtividade e o seu salario e de: R$ 600.00\n");
}

void calculaSal2(int pecasProduzidas)
{
    // Variáveis
    double sal = 600.00, adicional, salFinal;

    // Operaçãos e saída
    adicional = (pecasProduzidas - 50) * 0.50;
    salFinal = adicional + sal;
    printf("\n O seu adicional de produtividade foi de R$ %.2lf", adicional);
    printf("\n O seu salario nesse mes e de R$ %.2lf \n", salFinal);
}

void calculaSal3(pecasProduzidas)
{
    // Variáveis
    float sal = 600.00, num1 = 30, num2, adicional, salFinal;

    // Operações e saída
    num2 = pecasProduzidas - 80;
    adicional = (num1 * 0.50) + (num2 * 0.75);
    salFinal = adicional + sal;
    printf("\n O seu adicional de produtividade foi de R$ %.2lf", adicional);
    printf("\n O seu salario nesse mes e de R$ %.2lf", salFinal);
}

int retorno()
{
    int opcaoEscolhida;
    printf("\n\n");
    printf("\n Caso voce deseje calcular um novo salario digite 1.");
    printf("\n Para sair digite 0.\n");
    scanf("%d", &opcaoEscolhida);
    return opcaoEscolhida;
}