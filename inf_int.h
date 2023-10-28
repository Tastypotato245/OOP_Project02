/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:56:27 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/28 16:24:04 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INF_INT_H_
# define _INF_INT_H_
# include <iostream>
# include <cstring>
# include <algorithm>

class inf_int
{
	private :
		char* digits;
		unsigned int length;
		bool thesign;

	public :
		inf_int();					//default constructor	: set 0 
		inf_int(int);				//int to inf_int
		inf_int(const char* );		//str(char *) to inf_int
		inf_int(const inf_int&);	//copy constructor		: copy from inf_int
		~inf_int();					//destructor			: del digits

		inf_int& operator=(const inf_int&); // assignment operator

		friend bool operator==(const inf_int& , const inf_int&);
		friend bool operator!=(const inf_int& , const inf_int&);
		friend bool operator>(const inf_int& , const inf_int&);
		friend bool operator<(const inf_int& , const inf_int&);

		friend inf_int operator+(const inf_int& , const inf_int&);
		friend inf_int operator-(const inf_int& , const inf_int&);
		friend inf_int operator*(const inf_int& , const inf_int&);

		friend ostream& operator<<(ostream& , const inf_int&);
};

#endif
