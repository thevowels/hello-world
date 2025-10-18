/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:35:26 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/18 21:54:08 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int pid;

	pid = fork();
	if(pid == -1)
		return (-1);
	if(pid == 0)
	{
		//Child Process
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}
	else
	{	
		wait(NULL);
		printf("Success on Child process\n");
		printf("Cleaning up \n");
	}
	return (0);
}