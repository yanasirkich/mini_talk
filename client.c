/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:55:49 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/08 14:15:52 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_putstr_fd("Error. Not enough or too many arguments.", 2);
	else
	{	
		pid = ft_atoi(argv[1]); //test if it works as intended
		send_signal(pid, argv[2]);
	}
	return (0);
}
