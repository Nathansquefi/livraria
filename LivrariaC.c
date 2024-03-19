#include <stdio.h>

typedef struct livro {
    int cod;
    char titulo[45];
    float preco;
    int np; // número de páginas
} LIVRO;

int menu(void);
LIVRO cadastraLivro(void);
void print_livro(LIVRO liv);
float calcMediaPreco(LIVRO livros[], int nlvs);
LIVRO procuraLivro(LIVRO livros[], int nlvs, int cod);

int main() {
    LIVRO biblioteca[3];
    int opcao, nlivros = 0;

    do {
        opcao = menu();

        switch (opcao) {
            case 1:
                if (nlivros < 3) {
                    biblioteca[nlivros] = cadastraLivro();
                    nlivros++;
                } else {
                    printf("A biblioteca está cheia. Não é possível cadastrar mais livros.\n");
                }
                break;
            case 2:
                printf("Informe o código do livro: ");
                int codigo;
                scanf("%d", &codigo);
                LIVRO livroEncontrado = procuraLivro(biblioteca, nlivros, codigo);
                if (livroEncontrado.cod != -1) {
                    print_livro(livroEncontrado);
                } else {
                    printf("Livro não existe!\n");
                }
                break;
            case 3:
                if (nlivros > 0) {
                    float mediaPreco = calcMediaPreco(biblioteca, nlivros);
                    printf("O preço médio dos livros é %.2f\n", mediaPreco);
                } else {
                    printf("Não há livros cadastrados para calcular a média de preço.\n");
                }
                break;
            case 4:
                printf("Imprime biblioteca\n");
                for (int i = 0; i < nlivros; i++) {
                    print_livro(biblioteca[i]);
                }
                break;
            case 5:
                printf("Fim do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    return 0;
}

int menu(void) {
    int opcao;
    printf("1 - Cadastro de livro\n");
    printf("2 - Consulta de livro\n");
    printf("3 - Preço médio dos livros\n");
    printf("4 - Imprime biblioteca\n");
    printf("5 - Fim\n");
    printf("Entre com sua opção: ");
    scanf("%d", &opcao);
    getchar(); // Limpar o buffer do teclado
    return opcao;
}

LIVRO cadastraLivro(void) {
    LIVRO novoLivro;
    printf("Cadastro de Livro\n");
    printf("Título: ");
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    printf("Código: ");
    scanf("%d", &novoLivro.cod);
    printf("Preço: ");
    scanf("%f", &novoLivro.preco);
    printf("Número de páginas: ");
    scanf("%d", &novoLivro.np);
    getchar(); // Limpar o buffer do teclado
    return novoLivro;
}

void print_livro(LIVRO liv) {
    printf("Código: %d\n", liv.cod);
    printf("Título: %s", liv.titulo);
    printf("Preço: %.2f\n", liv.preco);
    printf("Número de páginas: %d\n", liv.np);
}

float calcMediaPreco(LIVRO livros[], int nlvs) {
    float soma = 0;
    for (int i = 0; i < nlvs; i++) {
        soma += livros[i].preco;
    }
    return (nlvs > 0) ? (soma / nlvs) : 0;
}

LIVRO procuraLivro(LIVRO livros[], int nlvs, int cod) {
    LIVRO livroNaoEncontrado = {-1, "", 0.0, 0};
    for (int i = 0; i < nlvs; i++) {
        if (livros[i].cod == cod) {
            return livros[i];
        }
    }
    return livroNaoEncontrado;
}
