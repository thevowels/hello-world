/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_err.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:54:17 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/18 22:06:00 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int pid;

	pid = fork();
	if(pid == -1)
		return (1);
	if(pid == 0)
	{
		//Child Process
		execlp("ping", "ping", "-c", "3", "google.asdf", NULL);
	}
	else
	{	int wstatus;

		wait(&wstatus);
		if(WIFEXITED(wstatus))
		{
			// WEXITSTATUS = value >> 8 shifting right by 8.
			int statusCode = WEXITSTATUS(wstatus);
			if(statusCode == 0)
			{
				printf("Success\n");
			}
			else
				printf("Failure with status code %d\n", statusCode);
		}
		printf("Success on Child process\n");
		printf("Cleaning up \n");
	}
}