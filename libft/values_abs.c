/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:30:19 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/27 14:36:45 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	values_abs(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}