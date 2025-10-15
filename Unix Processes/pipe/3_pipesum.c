/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_pipesum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:26:33 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 22:06:34 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	int pid;
	int fd[2];
	int arr[] = {1, 2, 3, 4, 5, 6, 100};
	int arrSize;
	int sum;
	int start;
	int end;

	arrSize = sizeof(arr) / sizeof(int);
	sum = 0;
	if (pipe(fd) == -1)
	{
		printf("Error while piping.\n");
		return (1);
	}

	pid = fork();

	if (pid == -1)
	{
		printf("Error on forking");
		return (2);
	}

	if (pid == 0)
	{
		start = arrSize / 2;
		end = arrSize;
		while (start < end)
		{
			sum += arr[start];
			start++;
		}
		printf("Partial sum from children : %d\n", sum);
		close(fd[0]);
		write(fd[1], &sum, sizeof(int));
		close(fd[1]);
		sleep(2);

	}
	else
	{
		start = 0;
		end = arrSize / 2;
		while (start < end)
		{
			sum += arr[start];
			start++;
		}
		printf("Partial sum from parent : %d\n", sum);
		int tmp;
		close(fd[1]);
		if( read(fd[0], &tmp,sizeof(int)) <= 0)
		{
			printf("Error occured while reading.\n");
			return (3);
		}
		sum += tmp;
		printf("Total : %d\n", sum);
		close(fd[0]);
		wait(NULL);
	}
	return (0);
}