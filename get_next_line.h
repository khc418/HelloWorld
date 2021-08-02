#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

/*
*	LIBRARIES
*/
# include <stdlib.h>
//# include <unistd.h>

/*
*	PROTOTYPES
*/

# define BUFFER_SIZE 1000

size_t	ft_strlen(const char* s);
void* ft_calloc(size_t nmemb, size_t size);
char* ft_strdup(const char* s);
char* ft_strjoin(char const* s1, char const* s2);
char* ft_substr(char const* s, unsigned int start, size_t len);
int		ft_strchr_pos(const char* s, int c);

char* get_next_line(int fd);

/*
*	DATA STRUCT
*/

typedef struct s_data
{
	char* buff;
	char* newline;
	int		r;
	int		i;
}	t_data;

#endif