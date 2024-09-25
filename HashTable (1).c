
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10

// Estrutura para representar um filme
typedef struct {
	int id;               // ID C:nico do filme
	char genero[50];          // Genero do filme
	char data [50];       // Data de lancamento do Filme
	char temp_vis[20];      // Tempo de visualizacao do filme
	char av_user [5];        // Avaliacao de usuario
	char nome[50];        // Nome do filme
} Filme;

// Estrutura da Tabela Hash
typedef struct {
	Filme *tabela[TAMANHO_HASH];  // Array de ponteiros para armazenar filmes
} TabelaHash;

// Funcao Hash: Retorna o indice baseado no ID do File
int funcao_hash(int id) {
	return id % TAMANHO_HASH;  // Usa modulo para determinar a posicao na tabela
}

// Funcao para inserir um filme na tabela hash
void inserir(TabelaHash *tabela, Filme *filme) {
	int indice = funcao_hash(filme->id);  // Calcula o indice baseado no ID
	tabela->tabela[indice] = filme;  // Insere o filme na tabela
}

// Função para remover um filme da tabela hash pelo ID
void remover(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice baseado no ID

    // Verifica se há um filme no índice correspondente
    if (tabela->tabela[indice] != NULL && tabela->tabela[indice]->id == id) {
        printf("Removendo filme: ID: %d, Nome: %s\n", tabela->tabela[indice]->id, tabela->tabela[indice]->nome);
        tabela->tabela[indice] = NULL;  // Remove o filme, configurando a posição como NULL
    } else {
        printf("Filme com ID %d não encontrado para remoção.\n", id);
    }
}


// Funcao para buscar um filme na tabela hash pelo ID
Filme *buscar(TabelaHash *tabela, int id) {
	int indice = funcao_hash(id);  // Calcula o C-ndice para busca
	return tabela->tabela[indice];  // Retorna o Filme encontrado
}

// Funcao para exibir filmes com maior nota
void exibirMelhoresFilmes(TabelaHash *tabela) {
	for (int i = 0; i < TAMANHO_HASH; i++) {
		if ((tabela->tabela[i] != NULL) && (strcmp(tabela->tabela[i]->av_user, "5.0") == 0)) {
			printf(" ID: %d, genero: %s, data de lancamento: %s, tempo de visualização: %s, avaliação do usuario: %s, nome do filme: %s\n",
			       tabela->tabela[i]->id,
			       tabela->tabela[i]->genero,
			       tabela->tabela[i]->data,
			       tabela->tabela[i]->temp_vis,
			       tabela->tabela[i]->av_user,
			       tabela->tabela[i]->nome);

		}
	}
}

// Funcao principal para demonstrar o uso da tabela hash com filmes
int main() {
	// Inicializa a tabela hash
	TabelaHash tabela = {NULL};

	// Criacao de alguns filmes
	Filme filme1 = {101, "romance", "19/09/2024","2:00", "3.5", "Sobre o Mesmo ceu"};
	Filme filme2 = {102, "açao", "19/09/1998","2:00", "5.0", "Duro de matar"};
	Filme filme3 = {103, "comedia", "29/11/1974","2:00", "5.0", "Click"};
	Filme filme4 = {104, "drama", "09/10/2013","2:00", "4.5", "Brilho Eterno de uma Mente sem Lembranças"};
	Filme filme5 = {105, "ação", "13/11/2024","2:00", "4.0", "Jhon Wick"};
	Filme filme6 = {106, "ação", "22/02/2000","2:00", "4.0", "Velozes e furiosos"};
	Filme filme7 = {107, "ação", "24/09/2024","2:00", "4.3", "Duro de matar 2"};
	Filme filme8 = {108, "ação", "11/04/2025","2:00", "4.9", "Duro de matar 3"};
	Filme filme9 = {109, "ação", "05/09/2012","2:00", "4.5", "Duro de matar 4"};
	Filme filme10 = {110, "ação", "19/09/2011","2:00", "4.8", "Duro de matar 5"};
    
	

	// Insere os filmes na tabela hash
	inserir(&tabela, &filme1);
    inserir(&tabela, &filme2);
    inserir(&tabela, &filme3);
    inserir(&tabela, &filme4);
    inserir(&tabela, &filme5);
    inserir(&tabela, &filme6);
    inserir(&tabela, &filme7);
    inserir(&tabela, &filme8);
    inserir(&tabela, &filme9);
    inserir(&tabela, &filme10);

	// Busca por um filme especC-fico
	Filme*t = buscar(&tabela, 104);
	if (t != NULL) {
		printf("Filme encontrado: ID: %d, genero: %s, data de lancamento: %s, tempo de visualização: %s, avaliação do usuario: %s, nome do filme: %s\n\n",
		       t->id, t->genero, t->data, t->temp_vis, t->av_user, t->nome);
	} else {
		printf("Filme nao encontrado.\n");
	}

	// Exibir todos os melhores filmes
    printf("Melhores filmes");
	exibirMelhoresFilmes(&tabela);
	printf("\n");
	// Remover um filme
	remover(&tabela, 104); // Removendo o filme com ID 104

    // Tentar buscar o filme removido
    t = buscar(&tabela, 104);
    if (t != NULL) {
        printf("Filme encontrado: ID: %d, genero: %s, data de lancamento: %s, tempo de visualizacao: %s, avaliacao do usuario: %s, nome do filme: %s\n\n",
               t->id, t->genero, t->data, t->temp_vis, t->av_user, t->nome);
    } else {
        printf("Filme não encontrado após remoção.\n");
    }

    return 0;
}


