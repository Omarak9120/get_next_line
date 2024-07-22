/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:52:34 by oabdelka          #+#    #+#             */
/*   Updated: 2024/06/26 18:47:35 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **buffer)
{
	size_t	length;
	char	*line;

	length = find_newline(*buffer);
	line = copy_line(*buffer, length);
	if (!line)
		return (NULL);
	*buffer = update_buffer(*buffer, length);
	return (line);
}

char	*read_and_buffer(int fd, char *buffer)
{
	char	temp_buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*temp;

	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		temp = ft_strjoin(buffer, temp_buffer);
		free(buffer);
		if (!temp)
			return (NULL);
		buffer = temp;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	buffer = read_and_buffer(fd, buffer);
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = get_line(&buffer);
	return (line);
}

char	*copy_line(const char *buffer, size_t length)
{
	char	*line;
	size_t	i;

	line = (char *)malloc(length + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < length)
	{
		line[i] = buffer[i];
		i++;
	}
	line[length] = '\0';
	return (line);
}

char	*update_buffer(char *buffer, size_t start)
{
	char	*new_buffer;

	if (start >= ft_strlen(buffer))
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(buffer + start);
	free(buffer);
	return (new_buffer);
}
//  #include "get_next_line.h"
//  #include <fcntl.h>
//  #include <stdio.h>
//  int main(void)
//  {
//      int fd = open("text.txt", O_RDONLY);
//      char *line;
//      if (fd == -1)
//      {
//          perror("Error opening file");
//          return (1);
//      }
//      while ((line = get_next_line(fd)) != NULL)
//      {
//          printf("%s", line);
//          free(line);
//      }
//      close(fd);
//      return (0);
//  }
//  % valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes 
// ./a.out 
