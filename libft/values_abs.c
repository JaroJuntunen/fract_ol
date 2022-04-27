/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:30:19 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/27 18:48:44 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	values_abs(double i)
{
	if (i < 0)
		i *= -1.0;
	return (i);
}