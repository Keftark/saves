/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:31:09 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/21 14:31:11 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

void	free_matrix(unsigned short **matrix, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nbr_lines)
	{
		free(matrix[i]);
		i++;
	}
	if (data->len_lines != 0)
		free(matrix);
}

unsigned short	**free_matrix_i(unsigned short **matrix, int i)
{
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
	return (NULL);
}
