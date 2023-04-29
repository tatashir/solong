/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 07:19:31 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 21:40:23 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*return_p;

	cc = (char)c;
	return_p = NULL;
	while (*s != '\0')
	{
		if (*s == cc)
			return_p = (char *)s;
		s++;
	}
	if (cc == 0)
		return ((char *)s);
	if (return_p != NULL)
		return (return_p);
	else
		return (NULL);
}
