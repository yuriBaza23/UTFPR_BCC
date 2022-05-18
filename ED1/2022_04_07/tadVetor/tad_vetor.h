// DADOS
typedef struct vetor Vetor;

// FUNÇÕES
// - Criar um vetor
// - Destruir um vetor
// - Inserir um elemento no vetor
// - Imprimir um vetor

Vetor* vector_create(int tam);

void vector_toIndex(Vetor* array, int element);

void vector_print(Vetor* array);

void vector_destroy(Vetor** endArray);