/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_stdout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:11:17 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/18 22:19:10 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	int pid = fork();
	if(pid == -1)
		return (1);
		
	if(pid == 0)
	{
		// Child process
		int file = open("pingResult.txt", O_WRONLY | O_CREAT , 0777);
		if(file == -1)
			return (2);
		dup2(file, STDOUT_FILENO);
		close(file);
		
		execlp("ping", "ping", "-c", "3", "google.com", NULL);

	}
	else
	{
		wait(NULL);
		printf("Cleaning up from parent\n");
		// Parent process
	}
}