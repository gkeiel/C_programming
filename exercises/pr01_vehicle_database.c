#include <stdio.h>
#include <stdlib.h> // para usar atoi e atof
#include <string.h> // para usar strstr

typedef enum
{
    gasolina = 1,
    etanol,
    diesel,
    gnv,
    eletricidade,
} comb;

typedef struct
{
    int numero;
    char descricao[100];
    float custo;
} reparo;

typedef struct
{
    char nome[15];
    char marca[15];
    char modelo[15];
    int ano;
    int km;
    comb combustivel;
    char placa[15];
    float preco;
    reparo R[3];
} veiculo;

// declara variáveis globais
int n = 10;    // número de structs (registros)
veiculo V[10]; // vetor da struct veiculo
int total;

// declara funções secundárias
void registro_inicializa()
{
    for (int i = 0; i < n; i++)
    {
        strcpy(V[i].marca, "");
        strcpy(V[i].modelo, "");
        V[i].ano = 0;
        V[i].km = 0;
        strcpy(V[i].placa, "");
        V[i].preco = 0;
        for (int j = 0; j < 10; j++)
        {
            V[i].R[j].numero = 0;
            strcpy(V[i].R[j].descricao, "");
            V[i].R[j].custo = 0;
        }
    }
}

void registro_cadastro()
{
    // REGISTRA até n veiculos
    printf("Registro de veiculos:\n");
    for (int i = 0; i < 1; i++)
    {
        printf("Insira o nome do dono: ");
        scanf("%[^\n]", V[i].nome);

        printf("Insira a marca: ");
        scanf("%s", V[i].marca);

        getchar();
        printf("Insira o modelo: ");
        scanf("%[^\n]", V[i].modelo);

        printf("Insira o ano: ");
        scanf("%d", &V[i].ano);

        printf("Insira a quilometragem: ");
        scanf("%d", &V[i].km);

        // printf("Selecione o tipo de combustivel: ");
        // scanf("%d", &V[i].comb);

        printf("Insira a placa: ");
        scanf("%s", V[i].placa);

        printf("Insira o preco: ");
        scanf("%f", &V[i].preco);

        printf("Insira o total de reparos: ");
        scanf("%d", &total);

        for (int j = 0; j < total; j++)
        {
            printf("Insira o numero do reparo: ");
            scanf("%d", &V[i].R[j].numero);

            getchar();
            printf("Insira o descricao do reparo: ");
            scanf("%[^\n]", V[i].R[j].descricao);

            printf("Insira o custo do reparo: ");
            scanf("%f", &V[i].R[j].custo);
        }
        printf("\n");
        getchar();
    }
}

void registro_escreve()
{
    // ESCREVE no arquivo
    FILE *arquivo;
    arquivo = fopen("vehicle_database.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(arquivo, "%s", "Nome: ");
        fprintf(arquivo, "%s", V[i].nome);
        fprintf(arquivo, "%s", ", Marca: ");
        fprintf(arquivo, "%s", V[i].marca);
        fprintf(arquivo, "%s", ", Modelo: ");
        fprintf(arquivo, "%s", V[i].modelo);
        fprintf(arquivo, "%s", ", Ano: ");
        fprintf(arquivo, "%d", V[i].ano);
        fprintf(arquivo, "%s", ", Quilometragem: ");
        fprintf(arquivo, "%d", V[i].km);
        fprintf(arquivo, "%s", ", Placa: ");
        fprintf(arquivo, "%s", V[i].placa);
        fprintf(arquivo, "%s", ", Preco: ");
        fprintf(arquivo, "%.2f", V[i].preco);
        for (int j = 0; j < 10; j++)
        {
            fprintf(arquivo, "%s", ", Reparo: ");
            fprintf(arquivo, "%d", V[i].R[j].numero);
            fprintf(arquivo, "%s", ", Descricao: ");
            fprintf(arquivo, "%s", V[i].R[j].descricao);
            fprintf(arquivo, "%s", ", Custo: ");
            fprintf(arquivo, "%.2f", V[i].R[j].custo);
        }
        fprintf(arquivo, "%s", "\n");
    }
    fclose(arquivo);
}

void registro_le()
{
    // LÊ do arquivo
    char aux[10];
    FILE *arquivo;
    arquivo = fopen("vehicle_database.txt", "r");
    while (fscanf(arquivo, "%s ", aux) == 1)
    {
        printf("%s", aux);
    }
    fclose(arquivo);
}

void registro_mostra()
{
    // MOSTRA registro de até n veículos
    for (int i = 0; i < n; i++)
    {
        /*switch (i){
            case gasolina:
                str[15] = "etanol";
            case etanol:
                str = "etanol";
            case diesel:
                str = "diesel";
            case GNV:
                str = "gnv";
            case eletricidade:
                str = "eletricidade";
        }*/
        printf("Nome: %s, Marca: %s, Modelo: %s, Ano: %d, Quilometragem: %d, Combustível: %d, Placa: %s, Preco: %.2f", V[i].nome, V[i].marca, V[i].modelo, V[i].ano, V[i].km, 1, V[i].placa, V[i].preco);
        for (int j = 0; j < 10; j++)
        {
            printf(", Reparo: %d, Descricao: %s, Custo: %.2f", V[i].R[j].numero, V[i].R[j].descricao, V[i].R[j].custo);
        }
        printf("\n\n");
    }
}

void registro_busca()
{
    // BUSCA registro de veículo por campo específico informado
    char campo[15]; // string campo
    char busca[15]; // string busca
    int x = -1;
    printf("\nInforme o campo para procura do veiculo: ");
    scanf("%s", campo);
    printf("Informe o dado para exibir a ficha do respectivo veiculo: ");
    scanf("%s", busca);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(campo, "nome") == 0)
        {
            if (strstr(V[i].nome, busca))
                x = i;
        }
        if (strcmp(campo, "marca") == 0)
        {
            if (strstr(V[i].marca, busca))
                x = i;
        }
        if (strcmp(campo, "modelo") == 0)
        {
            if (strstr(V[i].modelo, busca))
                x = i;
        }
        if (strcmp(campo, "ano") == 0)
        {
            if (V[i].ano == atoi(busca))
                x = i;
        }
        if (strcmp(campo, "km") == 0)
        {
            if (V[i].km == atoi(busca))
                x = i;
        }
        if (strcmp(campo, "placa") == 0)
        {
            if (strstr(V[i].placa, busca))
                x = i;
        }
        if (strcmp(campo, "preco") == 0)
        {
            if (V[i].preco == atof(busca))
                x = i;
        }
    }

    // MOSTRA registro de veículo buscado
    if (x >= 0)
    {
        printf("Nome: %s, Marca: %s, Modelo: %s, Ano: %d, Quilometragem: %d, Combustível: %d, Placa: %s, Preco: %.2f\n", V[x].nome, V[x].marca, V[x].modelo, V[x].ano, V[x].km, V[x].combustivel, V[x].placa, V[x].preco);
    }
    else
    {
        printf("Não fora encontrado nenhum veiculo.");
    }
}

int main()
{
    while(1)
    {
        // INICIALIZA registros
        registro_inicializa();
        registro_cadastro();
        registro_escreve();
        registro_le();
        // registro_mostra();
        // registro_busca();
    }
}