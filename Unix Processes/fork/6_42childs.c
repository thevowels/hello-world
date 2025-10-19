/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_42childs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:23:27 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/20 01:30:08 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	pid_t child_pids[42];
	int i;

	i = 0;
	while(i < 42)
	{
		child_pids[i] = fork();
		if(child_pids[i] == 0)
		{
			usleep(i * 100000);
			printf("Child process %i\n", i);
			exit(EXIT_SUCCESS);
		}
		else if(child_pids[i] > 0)
		{
			//Success parent process but as the child process exit
			// the iterations will be done only by the parent.
			// printf("Parent Process %i\n", i);
		}
		else
		{
			printf("Failed while forking\n");
		}
		i++;
	}
	printf("Parent process");
	return (0);
}