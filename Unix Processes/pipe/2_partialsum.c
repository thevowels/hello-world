/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_partialsum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:01:59 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 21:26:09 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	int arr[] = {1,2,3,4,5,6};
	int arrSize;
	int pid;
	int	start;
	int	end;
	int sum;

	sum = 0;
	arrSize = sizeof(arr) / sizeof(int);
	
	pid = fork();
	if(pid == -1)
	{
		return (1);
	}
	if(pid == 0)
	{
		start = arrSize / 2;
		end = arrSize;
	}
	else
	{
		start = 0;
		end = arrSize / 2;
	}
	
	while(start < end)
	{
		sum += arr[start];
		start++;
	}
	printf("Partial sum: %d\n", sum);
	wait(NULL);
	return (0);
}