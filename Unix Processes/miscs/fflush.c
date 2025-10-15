/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fflush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:42:10 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/12 11:49:36 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


int main(void)
{
	/*
		Write systemcall print out immediately.
		Printf use a buffer before printing out for efficiency.
		You might notice in "ft_printf" project they said we don't need to
		implement original printf()’s buffer management.
		What I noticed is that until it finds a newline character, it doesn't
		printout to the stdout.
		Thast why when i go to infinate loop, asdf won't printed unless I 
		explicitely call fflush to stdout.
	*/
	printf("asdfas\n");
	write(1,"xyz\n",4);
	//this will go to underlying buffer but not to the stdout until flush.
	printf("asdf");
	fflush(stdout);
	while(1);
	return (0);
}