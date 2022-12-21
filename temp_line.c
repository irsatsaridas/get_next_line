#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char* get_next_line(int fd) {
  char* buffer = malloc(BUFFER_SIZE);
  if (buffer == NULL) {
    return NULL;
  }

  ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
  if (bytes_read < 0) {
    free(buffer);
    return NULL;
  } else if (bytes_read == 0) {
    free(buffer);
    return NULL;
  }

  // Search for the newline character within the block of data
  for (size_t i = 0; i < bytes_read; i++) {
    if (buffer[i] == '\n') {
      buffer[i] = '\0';
      return buffer;
    }
  }

  // Newline character not found, so return the entire block of data
  buffer[bytes_read] = '\0';
  return buffer;
}

