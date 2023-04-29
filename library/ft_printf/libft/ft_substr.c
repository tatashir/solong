/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:10:38 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 21:40:36 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*heap;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen == 0 || len == 0 || slen < start)
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	heap = (char *)malloc(sizeof(char) * (len + 1));
	if (heap == NULL)
		return (NULL);
	s += start;
	ft_strlcpy(heap, s, len + 1);
	return (heap);
}
