/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:15:20 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/17 16:15:21 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*void freeList(t_list *head)
{
	if (head)
		freeList((t_list *)head->next);
	free(head);
}

int	main(void)
{
	t_list *new = NULL;
	ft_lstadd_front(&new, ft_lstnew((void *)1));
	ft_lstadd_front(&new, ft_lstnew((void *)2));
	printf("%d\n", ft_lstsize(new));
	freeList(new);
}*/
