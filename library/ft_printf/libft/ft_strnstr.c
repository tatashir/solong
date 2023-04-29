/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 07:19:28 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 21:40:17 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	slen;

	slen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len > 0)
	{
		while (*haystack != '\0' && slen <= len)
		{
			if (ft_strncmp(haystack, needle, slen) == 0)
				return ((char *)haystack);
			haystack++;
			len--;
		}
	}
	return (NULL);
}
