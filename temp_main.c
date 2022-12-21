#include <fcntl.h>
#include <stdio.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Open the file for reading
  int fd = open(argv[1], O_RDONLY);
  if (fd < 0) {
    perror("open failed");
    return 1;
  }

  // Read and print each line of the file
  char* line;
  while ((line = get_next_line(fd)) != NULL) {
    printf("%s\n", line);
    free(line);
  }

  // Close the file
  if (close(fd) < 0) {
    perror("close failed");
    return 1;
  }

  return 0;
}

