#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma pack(1)

struct Registro {
  int id_inscricao;
  char curso[20];
  char cpf[15];
  char dataNacimento[11];
  char sexo;
  char email[40];
  char opcaoQuadro;
};

int main(int argc, char* argv[]) {

  FILE *arq_entrada, *arq_saida;
  long tam_arq, qtd_reg;
  // Stores the amount of records read
  long registros_lidos = 0;
  // Registry instances
  struct Registro registro;
  struct Registro registro_valido;
  

  // Checks if the argument was passed correctly
  if(argc != 3) {
    fprintf(stderr, "uso: <nome do arquivo de entrada> <nome do arquivo de saida>");
    return 1;
  }

  // Reading the file
  arq_entrada = fopen(argv[1], "r");

  // Checks the existence of the file
  if(arq_entrada == NULL) {
    fprintf(stderr, "Arquivo de entrada inexistente");
    return 1;
  }

  // Get the file size
  fseek(arq_entrada, 0L, SEEK_END);

  // Stores the size in bytes
  tam_arq = ftell(arq_entrada);
 
  // Stores the number of records
  qtd_reg = tam_arq / sizeof(struct Registro);
 
  fseek(arq_entrada, 0L, SEEK_SET);

  // Opens file for writing
  arq_saida = fopen(argv[2], "w");
 
  if(arq_saida == NULL) {
    fprintf(stderr, "Erro ao criar arquivo de escrita.");
    return 1;
  }
 
  // Read the first record
  fread(&registro, sizeof(struct Registro), 1, arq_entrada);
  registros_lidos++;
 
  // Path logic in the records
  while(registros_lidos < qtd_reg) {
    fread(&registro, sizeof(struct Registro), 1, arq_entrada);
    registros_lidos ++;
    
    if(strncmp(registro.cpf, registro_valido.cpf, 15) == 0) {
      if(registro.id_inscricao > registro_valido.id_inscricao) {
        registro_valido = registro;
      }
      if(registros_lidos == numero_registros) {
        fwrite(&registro_valido, sizeof(struct Registro), 1, arq_saida);
      }
    } else {
      fwrite(&registro_valido, sizeof(struct Registro), 1, arq_saida);
      registro_valido = registro;
    }
  }

  fclose(arq_entrada);
	fclose(arq_saida);
	return 0;
}
