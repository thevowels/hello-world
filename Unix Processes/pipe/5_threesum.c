/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_threesum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:07:17 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 23:26:59 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int main(void)
{
	int arr[] = {1,2,3,4,5,2,323,4,23,423,4,32,423,4,23,4,234,23,4,234,23,4,234,3,423,4,23,423,4,23,4};
	int arrSize;

	arrSize = sizeof(arr) / sizeof(int);
	printf("Arrsize: %d\n", arrSize);

	int chunks = arrSize / 3;

	int start1 = 0;
	int end1 = chunks;

	int start2 = chunks;
	int end2 = chunks * 2;

	int start3 = chunks *2;
	int end3 = arrSize;

	printf("First chunk starts at %d and ends at %d \n", start1, end1);
	printf("Second chunk starts at %d and ends at %d\n", start2, end2);
	printf("Third chunk starts at %d and ends at %d \n", start3, end3);


}