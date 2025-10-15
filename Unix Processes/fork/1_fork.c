/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:32:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/12 11:56:03 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int	id;
	int tmp;

	tmp = 42;

	id = fork();
	
	/*
		Next lines of codes will be executed twice as we've duplicated
		and now there is two process running.
	*/
	printf("Hello World\n");
	/*
		Both Process share the same data.
	*/
	printf("TMP : %i\n", tmp);

	if(id == 0)
		printf("This is from child process : ID: %i\n", id);
	else
		printf("This is from parent process : ID: %i\n", id);

	return(0);
}