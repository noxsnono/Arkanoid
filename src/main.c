/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:41:29 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/01 23:41:39 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

int	main(int ac, char **av)
{
	t_data	*d;

	if (init_start(&d, ac, av) < 0)
		return(error("main:: Initialization error"));
	return(0);
}
