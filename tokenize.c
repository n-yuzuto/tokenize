#include <string.h>

char *tokenize(char *init) {
  char *p, *ret;
  static char *head = NULL;

  if (head == NULL && init == NULL) return NULL;
  if (init != NULL) head = init;
  if (*head == '\0') return NULL;

  p = head; ret = head;
  while (*p != '\0' && *p != ' ' && *p != '.' && *p != ',' && *p != ';') {p++;}
  if (*p == '\0') {
    head = p;
  }
   else {
    *p = '\0';
    head = p + 1;
    while (*head == ' ' || *head == ',' || *head == '.' || *head == ';' || *head == '\'') { head++; }
  }

  return ret;
}


int main(void) {
  char s[] = "This is a pen.  ,;abc  de";
  char *p;
  
  p = tokenize(s);
  while (p != NULL) {
    puts(p);
    p = tokenize(NULL);
  }
  
}
