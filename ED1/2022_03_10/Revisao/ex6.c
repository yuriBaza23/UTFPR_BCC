#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Essa é a struct aluno
 * Nela estão o ra e 3 notas que 
 * são equivalentes a 3 provas de um
 * período letivo de uma determinada
 * disciplina.
*/
typedef struct aluno {
  int ra;
  float notas[3];
} Aluno;

// Função responsável por CADASTRAR os alunos.
bool cadastrarAluno(FILE *arquivo, Aluno aluno[], int tamanho) {
  if(!arquivo) return false;

  for(int i = 0; i < tamanho; i++) {
    fscanf(arquivo, "%d", &aluno[i].ra);
    // fscanf(arquivo, "%d", *(aluno+i).ra);
    fscanf(arquivo, "%f", &aluno[i].notas[0]);
    fscanf(arquivo, "%f", &aluno[i].notas[1]);
    fscanf(arquivo, "%f", &aluno[i].notas[2]);
  }

  fclose(arquivo);

  return true;
}

/* Função responsável por ENCONTRAR ALUNO COM 
 * MAIOR NOTA em determinada prova
*/
Aluno encontraAlunoMaiorNota(Aluno aluno[], int tamanho, int avaliacao) {
  int posicao = 0;
  float nota = 0;

  for(int i = 0; i < tamanho; i++) {
    if(aluno[i].notas[avaliacao] > nota) {
      posicao = i;
      nota = aluno[i].notas[avaliacao];
    }
  }

  return aluno[posicao];
}

//Função responsável por ENCONTRAR ALUNO COM MAIOR (1) OU MENOR (0) MÉDIA
Aluno encontraAlunoMedia(Aluno aluno[], int tamanho, int maiorOuMenor) {
  int posicao = 0;
  float media = (aluno[0].notas[0] + aluno[0].notas[1] + aluno[0].notas[2]) / 3;

  if(maiorOuMenor == 1) {
    for(int i = 0; i < tamanho; i++) {
      float mediaAluno = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3; 
      if(mediaAluno > media) {
        posicao = i;
        media = mediaAluno;
      }
    }
  } else {
    for(int i = 0; i < tamanho; i++) {
      float mediaAluno = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3; 
      if(mediaAluno < media) {
        posicao = i;
        media = mediaAluno;
      }
    }
  }

  return aluno[posicao];
}

Aluno encontraAlunoMedia(Aluno aluno[], int tamanho, int maior) {
  int posicao = 0;
  float media = (aluno[0].notas[0] + aluno[0].notas[1] + aluno[0].notas[2]) / 3;

  
  for(int i = 0; i < tamanho; i++) {
    float mediaAluno = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3; 

    int x =  (condicao ? 10 : 100);

    if( (maior ? mediaAluno>media :  mediaAluno<media) ) {
      posicao = i;
      media = mediaAluno;
    }
  }
  

  return aluno[posicao];
}

//Função responsável por IMPRIMIR STATUS DO ALUNO (Fim de período letivo)
void imprimeStatus(Aluno aluno[], int tamanho) {
  for(int i = 0; i < tamanho; i++) {
    float mediaAluno = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3; 
    if(mediaAluno >= 6.0) {
      printf("[Aluno %d] STATUS: APROVADO\n", aluno[i].ra);
      printf("Nota AV1: %.1f\n", aluno[i].notas[0]);
      printf("Nota AV2: %.1f\n", aluno[i].notas[1]);
      printf("Nota AV3: %.1f\n", aluno[i].notas[2]);
      printf("Média do aluno: %.1f\n\n", mediaAluno);
    } else {
      printf("[Aluno %d] STATUS: REPROVADO\n", aluno[i].ra);
      printf("Nota AV1: %.1f\n", aluno[i].notas[0]);
      printf("Nota AV2: %.1f\n", aluno[i].notas[1]);
      printf("Nota AV3: %.1f\n", aluno[i].notas[2]);
      printf("Média do aluno: %.1f\n\n", mediaAluno);
    }
  }
}

int main() {
  // ENTRADA
  Aluno alunos[5];
  FILE *arquivo = fopen("./ED1/2022_03_10/Revisao/arq_ex6.in", "r");
  int numeroAv = 0;
  int quantidadeAlunos; 
  fscanf(arquivo, "%d", &quantidadeAlunos);

  // PROCESSAMENTO
  bool cadastrado = cadastrarAluno(arquivo, alunos, quantidadeAlunos);
  Aluno alunoMaiorNotaAV1 = encontraAlunoMaiorNota(alunos, quantidadeAlunos, numeroAv);
  Aluno alunoMaiorMedia = encontraAlunoMedia(alunos, quantidadeAlunos, 1);
  Aluno alunoMenorMedia = encontraAlunoMedia(alunos, quantidadeAlunos, 0);

  // SAIDA
  if(cadastrado) {
    printf("\n[Info Alunos] ================================|\n");
    printf("Aluno com a maior nota na av%d: %d\n", numeroAv + 1, alunoMaiorNotaAV1.ra);
    printf("Aluno com a maior média:        %d\n", alunoMaiorMedia.ra);
    printf("Aluno com a menor média:        %d\n", alunoMenorMedia.ra);
    printf("================== BOLETIM ===================|\n");
    imprimeStatus(alunos, quantidadeAlunos);
  } else
    printf("Não foi possível realizar o cadastro dos alunos.\n");

  return 0;
}