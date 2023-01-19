/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedrones <jpedrones@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:04:30 by jpedrones         #+#    #+#             */
/*   Updated: 2022/11/04 22:15:00 by jpedrones        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define ERR_SERVER_USR1		"Error sending \033[0;35mSIGUSR1 \033[0mto server"
# define ERR_SERVER_USR2		"Error sending \033[0;35mSIGUSR2 \033[0mto server"
# define ERR_SERVER_UNEXPECTED	"An unexpected error occurred on the server"
# define OK_SERVER				"\033[0;32mDone! \033[0mPrinted message"
# define ERR_CLIENT_USR1		"Error sending \033[0;35mSIGUSR1 \033[0mto client"

#endif //ERROR_MESSAGE_H