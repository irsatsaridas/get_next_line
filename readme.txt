This function reads a line from the file descriptor fd and 
returns it as a null-terminated string. It does this by reading
one character at a time from the file descriptor using read, 
and appending it to a buffer that is initially allocated using malloc. 
If the end of the line is reached (indicated by a newline character '\n'),
the function returns the line. If the end of the file is reached 
(indicated by read returning 0), the function returns the line 
if there is data in the buffer, or NULL if the buffer is empty. 
If an error occurs while reading from the file descriptor 
(indicated by read returning a negative value), 
the function returns NULL and frees the buffer using free.

The function also includes a simple mechanism for resizing the buffer 
if it becomes full. If the buffer is full, it allocates a new buffier 
using malloc, copies the data from the old buffer to the new buffer 
using a loop, and then frees the old buffer using free.

 To use the function, you can open the file using the open system call,
 then pass the file descriptor to get_next_line to read a line from the file. 
 You can then repeat this process until the end of the file is reached, 
 at which point get_next_line will return NULL. Here is an example of how 
 you might use the get_next_line function to read a text file line by line:
 temp_main.c

 This program opens the file specified as a command-line argument using open,
 then uses get_next_line to read and print each line of the file until the 
 end of the file is reached. It then closes the file using close.
 
 Surfi89-
new line görene kadar BUFFER_SIZE kadar okuyup bi stringe ekliyor, 
new line gördüğünde eklemeyi bırakıyor. Sonra elde ettiği stringin newline den sonrasını siliyor.

Yaten-
Yine aynı mantık buffersize arttıra arttıra okumuş, bufferi string array olarak tanımlayıp fd. stringe yazmış büyük ihtimal stdo için
nihai stringin içinde sadece bir \0 var strjoin ile okuduğu stringin son elemanını da /0 yapttıktan sonra onunla nihai stringi birleştiriyor.
ve gereksiz stringleri free ile yok ediyor ve tekrar içinde \n var mı kontrol ediyor

\n den öncesini almak için de substr kullanılmış
