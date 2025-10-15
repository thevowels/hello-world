/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_waitmore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:18:58 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/12 12:24:32 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	int	id;
	int	n;
	
	id = fork();

	if(id == 0)
	{
		//This is child process
		n = 1;
		printf("Child starts now\n");
	}
	else
	{
		n = 6;
		wait(NULL);
		printf("Parent start now\n");

	}

	int	i;
	i = n;
	while(i < n + 5)
	{
		printf("%d ", i);
		fflush(stdout);
		i++;
		usleep(10000);
	}
	write(1,"\n",1);
	
}