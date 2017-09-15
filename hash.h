#define HASH_SIZE 256

typedef struct node {
  struct node * next;
  char *text;
  int type;
}HASH_NODE;

void hashInit(void);
int hashAddress(char *text);
HASH_NODE *hashInsert(int type, char *text);
void hashPrint(void);
