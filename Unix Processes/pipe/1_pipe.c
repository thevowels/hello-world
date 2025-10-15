/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:14:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 19:01:47 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int fd[2];
	int pid;
	
	if(pipe(fd) == -1)
	{
		printf("Error occured during creating pipe.\n");
		return (1);
	}
	pid = fork();
	if(pid == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a Number: ");
		scanf("%d", &x);
		if(write(fd[1],&x,sizeof(int)) == -1)
		{
			printf("An error occured with writing the pipe.\n");
			return (2);
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		if(read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("Error occured during reading from pipe.\n");
			return (3);
		}
		close(fd[0]);
		printf("From child proces %d\n", y);
	}

	return (0);
}