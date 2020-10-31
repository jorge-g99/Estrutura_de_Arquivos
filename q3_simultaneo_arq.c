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

  FILE *arq_entrada_one, *arq_entrada_two;
  long tam_arq, qtd_reg;
  // Stores the amount of records read
  long registros_lidos = 0;
  // Registry instances
  struct Registro registro_arq_um;
  struct Registro registro_arq_dois;
  struct Registro registro_exibido;
 
  // verifica se o argumento foi passada de maneira correta
  if(argc != 3) {
    fprintf(stderr, "uso: <nome do arquivo de entrada 1> <nome do arquivo de entrada 2>");
    return 1;
  }
 
  // Reading the file number one
  arq_entrada_one = fopen(argv[1], "r");
  // Checks the existence of the file
  if(arq_entrada_one == NULL) {
    fprintf(stderr, "Arquivo de entrada um inexistente");
    return 1;
  }
  // Get the file size
  fseek(arq_entrada_one, 0L, SEEK_END);
  // Stores the size in bytes
  long tam_arq = ftell(arq_entrada_one);
  // Reset the file position indicator
  fseek(arq_entrada_one, 0L, SEEK_SET);
 

  // Reading the file number two
  arq_entrada_two = fopen(argv[2], "r");
  // Checks the existence of the file
  if(arq_entrada_two == NULL) {
    fprintf(stderr, "Arquivo de entrada dois inexistente");
    return 1;
  }
 
  // checks if file one has been read successfully
  int codigo_leitura_um = fread(&registro_arq_um, sizeof(struct Registro), 1, arq_entrada_one);
  // checks if file two was successfully read
  int codigo_leitura_dois = fread(&registro_arq_dois, sizeof(struct Registro), 1, arq_entrada_two);
 
  // Comparison logic
  while(codigo_leitura_um && codigo_leitura_dois){
 
    if(strncmp(registro_arq_um.cpf, registro_arq_dois.cpf, 15) == 0 &&
      strncmp(registro_arq_um.cpf, registro_exibido.cpf, 15) != 0) 
    {
      printf("%.4s\n", registro_arq_um.email);
      registro_exibido = registro_arq_um;
    }
    
    if(strncmp(registro_arq_um.cpf, registro_arq_dois.cpf, 15) < 0) {
      codigo_leitura_um = fread(&registro_arq_um, sizeof(struct Registro), 1, arq_entrada_one);
    } else {
      codigo_leitura_dois = fread(&registro_arq_dois, sizeof(struct Registro), 1, arq_entrada_two);
    }
  };

  fclose(arq_entrada_one);
  fclose(arq_entrada_two);
  return 0;
}
