/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_int.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:56:41 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/28 16:29:59 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_int.h"

/*
   Originally written by
   컴퓨터공학부
   정진경

   Modified by
   소프트웨어학부
   이규성, 이병구, 조영호
   in 23/10/28
 */

inf_int::inf_int()
{
	this->digits = new char[2];	// 동적할당

	this->digits[0] = '0';		// default 값 0 설정
	this->digits[1] = '\0';
	this->length = 1;
	this->thesign = true;
}

inf_int::inf_int(int n){
	char	buf[100];

	if(n<0){		// 음수 처리
		this->thesign=false;
		n=-n;
	}
	else
		this->thesign=true;

	int i=0;
	while (n > 0){
		buf[i] = n % 10 + '0';

		n/=10;
		i++;
	}
	if (i == 0)
		new (this) inf_int(); 
	else
	{
		buf[i]='\0';

		this->digits=new char[i+1];
		this->length=i;
		strcpy(this->digits, buf);
	}
}

inf_int::inf_int(const char* str) {
	if (str[0] == '-') {
		this->thesign = false;
		++str;
	}
	else
		this->thesign = true;


	this->length = strlen(str);
	this->digits = new char[this->length + 1];

	for (unsigned int i = 0; i < this->length; i++) {
		this->digits[i] = str[this->length - i - 1];
	}
	this->digits[this->length] = '\0';
}

inf_int::inf_int(const inf_int& a){
	this->digits=new char[a.length+1];

	strcpy(this->digits, a.digits);
	this->length=a.length;
	this->thesign=a.thesign;
}

inf_int::~inf_int(){
	delete digits;		// 메모리 할당 해제
}

inf_int& inf_int::operator=(const inf_int& a)
{
	if(this->digits) {
		delete this->digits;		// 이미 문자열이 있을 경우 제거.
	}
	this->digits=new char[a.length+1];

	strcpy(this->digits, a.digits);
	this->length=a.length;
	this->thesign=a.thesign;

	return *this; 
}

bool operator==(const inf_int& a, const inf_int& b)
{
	// we assume 0 is always positive.
	if ( (strcmp(a.digits , b.digits)==0) && a.thesign==b.thesign )	// 부호가 같고, 절댓값이 일치해야함.
		return true;
	return false;
}

bool operator!=(const inf_int& a, const inf_int& b)
{
	return !operator==(a, b);
}

bool operator>(const inf_int& a, const inf_int& b) {
    if (a.thesign && !b.thesign) return (true);
    if (!a.thesign && b.thesign) return (false);

    if (a.length > b.length) return a.thesign;
    if (a.length < b.length) return !a.thesign;

    // Compare character by character
    for (int i = a.length - 1; i >= 0; i--) {
        if (a.digits[i] > b.digits[i]) return (a.thesign);
        if (a.digits[i] < b.digits[i]) return (!a.thesign);
    }
    return (false);
}

bool operator<(const inf_int& a, const inf_int& b)
{
	if(operator>(a, b) || operator==(a, b)) {
		return false;
	}else{
		return true;
	}
}

inf_int operator+(const inf_int& a, const inf_int& b)
{
	inf_int c;
	unsigned int i;

	if(a.thesign==b.thesign){	// 이항의 부호가 같을 경우 + 연산자로 연산
		for(i=0; i<a.length; i++){
			c.Add(a.digits[i], i+1);
		}	
		for(i=0; i<b.length; i++){
			c.Add(b.digits[i], i+1);
		}

		c.thesign=a.thesign;	

		return c;
	}else{	// 이항의 부호가 다를 경우 - 연산자로 연산
		c=b;
		c.thesign=a.thesign;

		return a-c;
	}
}

inf_int operator-(const inf_int& a, const inf_int& b)
{
	// to be filled
}

inf_int operator*(const inf_int& a, const inf_int& b)
{
	// to be filled
}


ostream& operator<<(ostream& out, const inf_int& a)
{
	int i;

	if(a.thesign == false){
		out<<'-';
	}
	for(i=a.length - 1; i>=0; i--){
		out<<a.digits[i];
	}
	return out;
}

void inf_int::Add(const char num, const unsigned int index)	// a의 index 자리수에 n을 더한다. 0<=n<=9, ex) a가 391일때, Add(a, 2, 2)의 결과는 411
{
	if(this->length<index){
		this->digits=(char *)realloc(this->digits, index+1);

		if(this->digits == NULL){		// 할당 실패 예외처리
			cout << "Memory reallocation failed, the program will terminate.\n";

			exit(0);
		}

		this->length=index;					// 길이 지정
		this->digits[this->length]='\0';	// 널문자 삽입
	}

	if(this->digits[index-1] < '0'){	// 연산 전에 '0'보다 작은 아스키값인 경우 0으로 채움. 쓰여지지 않았던 새로운 자리수일 경우 발생
		this->digits[index-1] = '0';
	}

	this->digits[index-1] += num-'0';	// 값 연산


	if(this->digits[index-1] > '9'){	// 자리올림이 발생할 경우
		this->digits[index-1] -= 10;	// 현재 자릿수에서 (아스키값) 10을 빼고
		Add('1', index+1);			// 윗자리에 1을 더한다
	}
}

