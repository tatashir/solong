/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:19:20 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 21:39:39 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	cnt;
	size_t	dst_size;
	size_t	src_size;

	if (src == NULL && size == 0)
		return (0);
	src_size = ft_strlen(src);
	if (dest == NULL && size == 0)
		return (src_size);
	dst_size = ft_strlen(dest);
	if (dst_size >= size)
		return (size + src_size);
	cnt = size - dst_size;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && --cnt > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (dst_size + src_size);
}
