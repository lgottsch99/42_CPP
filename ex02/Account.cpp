/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:08:30 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/24 17:43:25 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>


//Constructor (incl init list)
/*
int	const	amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };


[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] index:2;amount:957;created
[19920104_091532] index:3;amount:432;created
[19920104_091532] index:4;amount:1234;created
[19920104_091532] index:5;amount:0;created
[19920104_091532] index:6;amount:754;created
[19920104_091532] index:7;amount:16576;created

*/
//only for one account/ line
Account::Account(int initial_deposit):
	_nbAccounts(), _totalAmount(), _totalNbDeposits(), _totalNbWithdrawals(),
	_accountIndex(), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{


	
	//display timestamp
	_displayTimestamp();
	//index //amount //created
	std::cout << "index:" << _accountIndex << "amount:" << _amount << ";created\n";

}

// [19920104_091532] 
//yyyy mm dd _ hh mm ss
void Account::_displayTimestamp(void)
{
	time_t timer;
	struct tm *timeinfo;

	//get currrent time
	time(&timer);
	timeinfo = localtime(&timer);

	//print timestamp
	std::cout << "[" << timeinfo->tm_year << timeinfo->tm_mon 
				<< timeinfo->tm_mday << "_" 
				<< timeinfo->tm_hour << timeinfo->tm_min
				<< timeinfo->tm_sec << "] ";
}


//Destructor
/*
[19920104_091532] index:0;amount:47;closed
[19920104_091532] index:1;amount:785;closed
[19920104_091532] index:2;amount:864;closed
[19920104_091532] index:3;amount:430;closed
[19920104_091532] index:4;amount:1245;closed
[19920104_091532] index:5;amount:23;closed
[19920104_091532] index:6;amount:106;closed
[19920104_091532] index:7;amount:8942;closed

*/
Account::~Account( void )
{
	//remove any alloc mem

	//display timestamp
	_displayTimestamp();
	//index //amount //created
	std::cout << "index:" << _accountIndex << "amount:" << _amount << ";closed\n";

}



//display accountsInfos:
// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0



//for each, displayStatus
/*
[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
[19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
[19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
[19920104_091532] index:3;amount:432;deposits:0;withdrawals:0
[19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
[19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
[19920104_091532] index:6;amount:754;deposits:0;withdrawals:0
[19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0

*/
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << "amount:" << _amount 
			<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
			<< "\n";
}


//make deposit
/*
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
[19920104_091532] index:2;p_amount:957;deposit:564;amount:1521;nb_deposits:1
[19920104_091532] index:3;p_amount:432;deposit:2;amount:434;nb_deposits:1
[19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1
[19920104_091532] index:5;p_amount:0;deposit:23;amount:23;nb_deposits:1
[19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1
[19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1

*/


//make withdrawal
/*
[19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
[19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
[19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
[19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
[19920104_091532] index:5;p_amount:23;withdrawal:refused
[19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
[19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1
*/