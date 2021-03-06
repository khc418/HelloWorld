#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

static void	new_line(char** arr, t_data* data, int fd)
{
	if (data->i >= 0)
	{
		data->newline = ft_substr(arr[fd], 0, data->i + 1);
		data->buff = ft_strdup(arr[fd] + data->i + 1);
		free(arr[fd]);
		arr[fd] = NULL;
		arr[fd] = ft_strdup(data->buff);
		free(data->buff);
		if (arr[fd][0] == '\0')
		{
			free(arr[fd]);
			arr[fd] = NULL;
		}
	}
	else
	{
		data->newline = ft_strdup(arr[fd]);
		free(arr[fd]);
		arr[fd] = NULL;
	}
}

static int	reader(char** arr, t_data* data, int fd)
{
	if (arr[fd] == NULL)
	{
		data->buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (data->buff == NULL)
			return (0);
		data->r = read(fd, data->buff, BUFFER_SIZE);
		if (data->r == -1 || data->r == 0)
		{
			free(data->buff);
			return (0);
		}
		data->buff[data->r] = '\0';
		arr[fd] = ft_strdup(data->buff);
		free(data->buff);
	}
	else
	{
		data->buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (data->buff == NULL)
			return (0);
		data->r = read(fd, data->buff, BUFFER_SIZE);
		if (data->r == -1 || data->r == 0)
		{
			free(data->buff);
			return (0);
		}
		data->buff[data->r] = '\0';
		data->newline = ft_strjoin(arr[fd], data->buff);
		free(data->buff);
		free(arr[fd]);
		arr[fd] = NULL;
		arr[fd] = ft_strdup(data->newline);
		free(data->newline);
	}
	return (1);
}

char* get_next_line(int fd)
{
	static char* arr[4096];
	t_data		data;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data.r = BUFFER_SIZE;
	if (arr[fd] == NULL)
	{
		if (!reader(arr, &data, fd))
			return (NULL);
	}
	data.i = ft_strchr_pos(arr[fd], '\n');
	if (data.i >= 0 || data.r < BUFFER_SIZE)
	{
		new_line(arr, &data, fd);
		return (data.newline);
	}
	while (data.r > 0)
	{
		if (!reader(arr, &data, fd) && arr[fd] == NULL)
			return (NULL);
		data.i = ft_strchr_pos(arr[fd], '\n');
		if (data.i >= 0)
		{
			new_line(arr, &data, fd);
			return (data.newline);
		}
		if (data.r == 0)
		{
			data.newline = ft_strdup(arr[fd]);
			free(arr[fd]);
			arr[fd] = NULL;
			return (data.newline);
		}
	}
	return (NULL);
}
