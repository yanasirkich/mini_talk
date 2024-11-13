/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:55:49 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/13 13:00:37 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(pid_t pid, char *text);
static void	send_character_bits(pid_t pid, char c);
static int 	safe_kill(pid_t pid, int signal);

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error. Not enough or too many arguments.", 2);
		exit(EXIT_FAILURE);

	}
	else
	{	
		pid = ft_atoi(argv[1]); //test if it works as intended
		send_signal(pid, argv[2]);
	}
	return (0);
}

static void	send_signal(pid_t pid, char *text)
{
	while (*text)
	{
		send_character_bits(pid, *text);
		text++;
	}
	send_character_bits(pid, '\n');
}

static void	send_character_bits(pid_t pid, char c)
{
	int	bit_position;
	int	bit;
	
	bit_position = 7;
	while (bit_position >= 0)
	{
		bit = (c >> bit_position) & 1;
		if (bit == 0)
			safe_kill(pid, SIGUSR1);
		else
			safe_kill(pid, SIGUSR2);
		usleep(200); //100-microsecond delay between signals
		bit_position--;
	}
}

static int safe_kill(pid_t pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_putstr_fd("Error. Failed to send a signal.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
