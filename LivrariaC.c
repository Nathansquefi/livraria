#include <stdio.h>

typedef struct livro {
    int cod;
    char titulo[45];
    float preco;
    int np; // n�mero de p�ginas
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
                    printf("A biblioteca est� cheia. N�o � poss�vel cadastrar mais livros.\n");
                }
                break;
            case 2:
                printf("Informe o c�digo do livro: ");
                int codigo;
                scanf("%d", &codigo);
                LIVRO livroEncontrado = procuraLivro(biblioteca, nlivros, codigo);
                if (livroEncontrado.cod != -1) {
                    print_livro(livroEncontrado);
                } else {
                    printf("Livro n�o existe!\n");
                }
                break;
            case 3:
                if (nlivros > 0) {
                    float mediaPreco = calcMediaPreco(biblioteca, nlivros);
                    printf("O pre�o m�dio dos livros � %.2f\n", mediaPreco);
                } else {
                    printf("N�o h� livros cadastrados para calcular a m�dia de pre�o.\n");
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
                printf("Op��o inv�lida.\n");
        }
    } while (opcao != 5);

    return 0;
}

int menu(void) {
    int opcao;
    printf("1 - Cadastro de livro\n");
    printf("2 - Consulta de livro\n");
    printf("3 - Pre�o m�dio dos livros\n");
    printf("4 - Imprime biblioteca\n");
    printf("5 - Fim\n");
    printf("Entre com sua op��o: ");
    scanf("%d", &opcao);
    getchar(); // Limpar o buffer do teclado
    return opcao;
}

LIVRO cadastraLivro(void) {
    LIVRO novoLivro;
    printf("Cadastro de Livro\n");
    printf("T�tulo: ");
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    printf("C�digo: ");
    scanf("%d", &novoLivro.cod);
    printf("Pre�o: ");
    scanf("%f", &novoLivro.preco);
    printf("N�mero de p�ginas: ");
    scanf("%d", &novoLivro.np);
    getchar(); // Limpar o buffer do teclado
    return novoLivro;
}

void print_livro(LIVRO liv) {
    printf("C�digo: %d\n", liv.cod);
    printf("T�tulo: %s", liv.titulo);
    printf("Pre�o: %.2f\n", liv.preco);
    printf("N�mero de p�ginas: %d\n", liv.np);
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
