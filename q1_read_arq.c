#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	FILE *entrada;
	char *buffer = NULL;
	int qtd;
	long tmn_arq, qtd_linhas = 1, qtd_palavras = 0;

	// Argument check
	if (argc != 3) {
		fprintf(stderr,"Erro na chamada do comando.\n");
		return 1;
	}

	// Opening the file for reading
	entrada = fopen(argv[1],"r");

	// Checking for file existence
	if (!entrada) {
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

	// Get file size
	fseek(f,0,SEEK_END);

	// Stores size in bytes
	tmn_arq = ftell(entrada);

	// Definition of exact buffer memory
	buffer = (char*)malloc(sizeof(char) * tmn_arq + 1);

	// Checking memory allocation
	if (buffer == NULL) {
		fprintf(stderr, "Erro no alocamento de memoria");
		return 1;
	}

	// Stores the last position
	size_t tmn_bfr = fread(buffer, sizeof(char), tmn_arq, entrada);

	buffer[tmn_bfr + 1] = '\0';

	long posicao;
	char caractere;
	short estado = 0;

	for (posicao = 0; buffer[posicao]; posicao++) {
		
		caractere = conteudo[posicao];

		if (caractere == ' ' || caractere == '\n' || caractere == '\t') {

			estado = 0;
			if (caractere == '\n')
				qtd_linhas++;
		} else if (estado == 0) {

			estado = 1;
			qtd_palavras++;

		}
	}

	// Release the memory
	free(conteudo);

	// Print result
	printf("\nNumero de Linhas: %d\nNumero de Palavras: %d\n\n", qtd_linhas, qtd_palavras);

	// Close file
	fclose(entrada);
	return 0;
}