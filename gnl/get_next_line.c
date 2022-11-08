#include "get_next_line.h"

int get_next_line(char **line)
{
	int byte;
	int i = 0;
	char ch;
	char *buf = malloc(100000);

	*line = buf;
	while ((byte = read(0, &ch, 1) > 0))
		buf[i++] = ch;
	buf[i] = '\0';
	return (byte);
}
