/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:51:42 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 21:34:40 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_str(int *len, char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	ft_putstr_fd(s, 1);
	*len += ft_strlen(s);
}
