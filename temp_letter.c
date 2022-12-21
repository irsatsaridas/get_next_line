#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/*
 * Reads a line from the file descriptor `fd` and returns it as a null-terminated string.
 * Returns NULL if an error occurs or there is nothing else to read.
 */
char* get_next_line(int fd) {
  // Allocate initial buffer
  char* buffer = malloc(BUFFER_SIZE);
  if (buffer == NULL) {
    // malloc failed, return NULL
    return NULL;
  }

  size_t i = 0;
  while (1) {
    // Read a single character from the file descriptor
    ssize_t bytes_read = read(fd, buffer + i, 1);
    if (bytes_read < 0) {
      // read failed, free the buffer and return NULL
      free(buffer);
      return NULL;
    } else if (bytes_read == 0) {
      // End of file reached
      if (i == 0) {
        // No data was read, so free the buffer and return NULL
        free(buffer);
        return NULL;
      } else {
        // Data was read, so return it
        buffer[i] = '\0';
        return buffer;
      }
    }

    if (buffer[i] == '\n') {
      // End of line reached, so return the line
      buffer[i] = '\0';
      return buffer;
    }

    i++;

    if (i == BUFFER_SIZE) {
      // Buffer is full, so allocate a new buffer and copy the data
      char* new_buffer = malloc(BUFFER_SIZE * 2);
      if (new_buffer == NULL) {
        // malloc failed, free the old buffer and return NULL
        free(buffer);
        return NULL;
      }
      for (size_t j = 0; j < BUFFER_SIZE; j++) {
        new_buffer[j] = buffer[j];
      }
      free(buffer);
      buffer = new_buffer;
    }
  }
}

