#include <stdio.h>
#include <stdbool.h>
  bool ERRO_arquivo(char *arquivo){
  char escolha = '\0';
  printf("\n%s", arquivo);
  printf("arquivo não encontrado");
  printf("\nGostaria de tentar novamente? (s/n)");
  printf("\n>>");
  scanf("%c", &escolha);
  if(escolha == 'N' || escolha == 'n') return true;
  return false;
}
  bool AbreArquivo1(FILE **fp1){
    char arquivo[] = "Primeiro";
    do{
      *fp1 = fopen("arquivo1.txt", "a+");

      if(*fp1 == NULL){
         if(ERRO_arquivo(arquivo)) return true;
      }
    }while(*fp1 == NULL);
    return false;
  }
  bool AbreArquivo2(FILE **fp2){
    char arquivo[] = "Segundo";
    do{
      *fp2 = fopen("arquivo2.txt", "a+");
      if(*fp2 == NULL){
         if(ERRO_arquivo(arquivo)) return true;
      }
    }while(*fp2 == NULL);
    return false;
  }
  bool LeituraBlocos(){
    char opcao = '\0';
    do{
    printf("Gostaria que a leitura aconteça por blocos? (s/n)\n>>");
    scanf("%c", &opcao);
    if(opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N') printf("Escolha uma opção adequada.\n");
  }while(opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N');
    if(opcao == 's' || opcao == 'S') return true;
    if(opcao == 'n' || opcao == 'N') return false;
  }
int main(){
  bool QuerSair = false, leituraBlocos = true;
  char LeituraArquivo1[10000] = "\0";
  char LeituraArquivo2[10000] = "\0";
  char c;
  int Tamanho = 1, i;
  long lSize1 = 0, lSize2 = 0;
  FILE* fp1 = NULL;
  FILE* fp2 = NULL;
  printf("Bem vindo!\nO programa aceita arquivos de até 9.999 carácteres.\n");
  QuerSair = AbreArquivo1(&fp1);
  if(QuerSair) return 0;
  QuerSair = AbreArquivo2(&fp2);
  if(QuerSair) return 0;
  leituraBlocos = LeituraBlocos();
  if(leituraBlocos) Tamanho = lSize2 - 1;
  /*trecho retirado do site: http://www.cplusplus.com/reference/cstdio/fread/*/
  fseek (fp1 , 0 , SEEK_END);
  lSize1 = ftell (fp1);
  rewind (fp1);
  fread(LeituraArquivo1,Tamanho,lSize1,fp1);
  fseek (fp2 , 0 , SEEK_END);
  lSize2 = ftell (fp2);
  rewind (fp2);
  fread(LeituraArquivo2, Tamanho, lSize2, fp2);
  i=lSize2/Tamanho;
  fwrite(LeituraArquivo2, Tamanho, i, fp1);
  for(i = 0; LeituraArquivo1[i] != '\0'; i++) printf("%c",LeituraArquivo1[i]);
  for(i = 0; LeituraArquivo2[i] != '\0'; i++) printf("%c",LeituraArquivo2[i]);
  printf("\n");
  fclose(fp1);
  fclose(fp2);
return 0;
}
