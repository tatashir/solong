/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:20:00 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 21:40:02 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*heap;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	heap = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (heap == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		heap[i] = f(i, *s);
		i++;
		s++;
	}
	heap[i] = '\0';
	return (heap);
}
