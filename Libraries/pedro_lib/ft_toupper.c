/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:14:48 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/07 18:43:02 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

int	ft_toupper(int x)
{
	if (x >= 'a' && x <= 'z')
		return (x - 32);
	else
		return (x);
}