/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:19:08 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 21:38:13 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	unsigned const char	*p_src;

	if (dest == src)
		return (dest);
	p_dest = (unsigned char *)dest;
	p_src = (unsigned const char *)src;
	if (dest <= src)
	{
		while (n--)
			*p_dest++ = *p_src++;
	}
	else
	{
		p_dest += n;
		p_src += n;
		while (n--)
			*--p_dest = *--p_src;
	}
	return (dest);
}