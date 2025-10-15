/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_waitmore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:18:58 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 18:12:09 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	int	pid1;
	int pid2;
	int n = 1;

	pid1= fork();
	pid2 = fork();

	while(n < 5)
	{
		printf("PID1: %d  && PID2: %d\n", pid1, pid2);
		usleep(50);
		n++;
	}

	while(wait(NULL) != -1)
	{
		printf("Waiting for child \n");
	}


}