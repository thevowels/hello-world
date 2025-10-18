/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_send.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:11:23 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/18 20:35:36 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char ** argv)
{
	if(mkfifo("sum", 0777) == -1)
	{
		if(errno != EEXIST)
		{
			printf("Problem create fifo file");
			return (1);
		}
	}


	int arr[5];
	srand(time(NULL));
	int i;
	i = 0;
	while(i < 5)
	{
		arr[i] = rand() % 100;
		i++;
	}
	int fd = open("sum", O_WRONLY);
	
	if(fd == -1)
		return (2);
	
	if (  write(fd,arr, sizeof(arr)) == -1)
	{
		printf("Error while writing into fifo file");
		return (3);
	}
	i = 0;
	while(i < 5)
	{
		printf("Wrote %d\n", arr[i]);
		i++;
	
	}

return (0);
}