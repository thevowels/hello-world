/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_fifo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:54:15 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/18 20:12:41 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char **argvv)
{
	if(mkfifo("myfifo", 0777) == -1)
	{
		if(errno != EEXIST)
		{
			printf("Couldn't create fifo file\n");
			return 1;
		}
	}

	int fd = open("myfifo", O_WRONLY);
	int x= 42;

	while(1)
	{
		if(write(fd, &x,sizeof(x)) == -1)
		{
			printf("Something happened");
			return (2);
		}
	
	}
	close(fd);

	return (0);
	
}