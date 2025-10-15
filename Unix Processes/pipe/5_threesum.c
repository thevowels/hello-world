/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_threesum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:07:17 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 23:55:14 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int arrSize;
	
	arrSize = sizeof(arr) / sizeof(int);
	if(arrSize < 3)
	{
		printf("The array size doesn't fit for threesum\n");
		return (42);
	}
	int chunks = arrSize / 3;
	printf("Arrsize: %d\n", arrSize);
	printf("Chunk size; %d\n", chunks);
	int pid1;
	int pipe1[2];

	if(pipe(pipe1) == -1)
	{
		printf("Error while creating pipe\n");
		return (1);
	}
	pid1 = fork();
	if(pid1 == -1)
	{
		printf("Error while forking\n");
		return (2);
	}
	if(pid1 == 0)
	{
		// This is child process
		close(pipe1[0]);
		int start1 = 0;
		int end1 = chunks;

		int sum;
		sum = 0;
		while(start1 < end1)
		{
			sum += arr[start1];
			start1++;
		}
		printf("First chunk starts at %d and ends at %d  with partial sum:	 %d\n", 0, end1, sum);

		if(write(pipe1[1], &sum, sizeof(sum)) <= 0)
		{
			printf("Error while writing into pipe\n");
			return (3);
		}
		// closing write end of pipe
		close(pipe1[1]);
		
	}
	else
	{
		// This is parent process
		int pipe2[2];

		if(pipe(pipe2) == -1)
		{
			printf("Error while creating pipe\n");
			return (1);	
		}

		int pid2 = fork();
		if(pid2 == -1)
		{
			printf("Error while forking\n");
			return (2);
		}
		if(pid2 == 0)
		{
			//Another child

			//close read end of pipe
			close(pipe2[0]);
			int start2 = chunks;
			int end2 = chunks * 2;
			int sum = 0;

			while(start2 < end2)
			{
				sum += arr[start2];
				start2++;
			}
			printf("Second chunk starts at %d and ends at %d with partial sum:	 %d \n", chunks *2, end2, sum);

			if(write(pipe2[1], &sum, sizeof(sum)) <= 0)
			{
				printf("Error while writing into pipe\n");
				return (3);	
			}
			//closing the read end of pipe
			close(pipe2[1]);
		}
		else
		{
			int start3 = chunks *2;
			int end3 = arrSize;
			int sum = 0;
			int sum1;
			int sum2;

			//closing  write end of pipes
			close(pipe1[1]);
			close(pipe2[1]);
			while(start3 < end3)
			{
				sum += arr[start3];
				start3++;
			}
			printf("Third chunk starts at %d and ends at %d with partial sum: 	%d\n", chunks *3, end3, sum);

			if(read(pipe1[0], &sum1, sizeof(int)) <= 0 ||
				read(pipe2[0], &sum2, sizeof(int)) <= 0)
			{
				printf("Error while Reading from pipes pipe\n");
				return (4);	
			}
			sum += sum1;
			sum += sum2;

			printf("Total sum : %d\n", sum);
			close(pipe1[0]);
			close(pipe2[0]);
			while(wait(NULL) != -1)
			{
				
			}
		}
	}
	
	return (0);





}