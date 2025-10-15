/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_forwhile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:08:32 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/12 12:18:33 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int id = fork();
	int	n;

	if(id == 0)
		n  = 1;
	else
		n = 5;

	int i;
	for(i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
		// the computer are really fast now. If i don't use usleep it will
		// complete one of the process's loop before the other one start.
		usleep(10000);
	}
	return (0);
}