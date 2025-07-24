#include <fcntl.h>    // open
#include <stdio.h>    // printf, perror
#include <stdlib.h>   // free
#include <unistd.h>   // close

#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Dosya açilamadi");
        return 1;
    }

    char *line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);  // genellikle satır sonunda \n var, fazladan ekleme gerekmez
    }
    close(fd);
    return 0;
}
