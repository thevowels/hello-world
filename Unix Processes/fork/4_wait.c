/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_wait.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:16:02 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 15:01:22 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(void)
{
	int id = fork();
	int	n;

	if(id == 0)
		n  = 1;
	else
		n = 5;

	int i;
	i = n;
	wait(NULL);
	while(i < n + 5)
	{
		printf("%d ", i);
		fflush(stdout);
		// the computer are really fast now. If i don't use usleep it will
		// complete one of the process's loop before the other one start.
		usleep(10000);
		i++;
	}
	return (0);
}