/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_receive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:11:20 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/18 20:26:45 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(void)
{
	int arr[5];
	int i;
	int fd = open("sum", O_RDONLY);
	if(fd == -1)
		return (1);

	i = 0;
	while(i < 5)
	{
		if(read(fd, &arr[i], sizeof(int)) == -1)
			return (2);
		printf("Received: %d\n", arr[i]);
		i++;
	}

	return (0);
	
}