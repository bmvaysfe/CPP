#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<cmath>
#include<cassert>  // for assert()
#include<set>
#include<cstdio>
using namespace std;

void parse_MM_DD_YYYY_STL(const string& date_2_parse, int* mm, int* dd, int* yyyy)
{
	string tmp_token = date_2_parse.substr(0,2);  // month
	(*mm) = atoi(tmp_token.data());
	
	tmp_token = date_2_parse.substr(3,2);  // day
	(*dd) = atoi(tmp_token.data());
	
	tmp_token = date_2_parse.substr(6,4);  // year
	(*yyyy) = atoi(tmp_token.data());
//	cout<<__FUNCTION__<<"() "<<*mm<<"/"<<*dd<<"/"<<*yyyy<<endl;
}

void parse_MM_DD_YYYY(const char *date, int* mm, int* dd, int* yyyy)
{
	char tmp_mm[3]={0}, tmp_dd[3]={0}, tmp_yyyy[5]={0};
	memcpy(tmp_mm, date,2); // month
	memcpy(tmp_dd, date+3,2); // day 
	memcpy(tmp_yyyy,date+strlen(date)-4,4);  // year
	(*mm) = atoi(tmp_mm);
	(*dd) = atoi(tmp_dd);
	(*yyyy) = atoi(tmp_yyyy);
}

// Date string is in format MM/DD/YYYY
bool is_same_month(const char* date1, const char* date2)
{
	char month1[3]={0}, month2[3] = {0};
	memcpy(month1, date1,2);
	memcpy(month2, date2,2);
	int m1 = atoi(month1);
	int m2 = atoi(month2);
//	cout<<__FUNCTION__<<"() m1="<<m1<<"\tm2="<<m2<<endl;	
	return m1 == m2;
}

//	Date string is in format MM/DD/YYYY
//	Return true if yes, false otherwise.
bool is_same_year(const char* date1, const char* date2)
{
	const char *pYear1 = date1+strlen(date1)-4; // Year is YYYY
	const char *pYear2 = date2+strlen(date2)-4; // Year is YYYY
//	cout<<__FUNCTION__<<"() pYear1="<<pYear1<<endl;
//	cout<<__FUNCTION__<<"() pYear2="<<pYear2<<endl;
	return strcmp(pYear1, pYear2) == 0;
}

//	Return 0 if dates are equal, 1 if date1>date2, 2 otherwise
//	Date format is MM/DD/YYYY as of 03.02.2026
int compare_dates(const char* date1, const char* date2)
{
	char temp_date1[256] = {0}, temp_date2[256]={0};	
	char* MM1=nullptr;
	char* DD1=nullptr;
	char* YY1=nullptr;
	char* MM2=nullptr;
	char* DD2=nullptr;
	char* YY2=nullptr;
	int mm1=0, dd1=0, yy1=0;
	int mm2=0, dd2=0, yy2=0;
	
	if(strcmp(date1,date2) == 0) return 0;
		
	parse_MM_DD_YYYY(date1, &mm1, &dd1, &yy1);
	parse_MM_DD_YYYY(date2, &mm2, &dd2, &yy2);
	
	// Compare Years
	if(yy1>yy2) return 1;
	else if(yy2>yy1)return 2; 
	else { // Years are the same
		if(mm1>mm2) return 1;
		else if(mm1<mm2) return 2;
		else { // Months are the same
			if(dd1>dd2) return 1;
			else return 2;
		}
	}
	return 0; // We should not be there.
}

bool isLeapYear(int year)   
{
    bool leap = true;
    
    if(year%4!=0) return false; // non-leap year 
    else {	
        if(year%400 == 0) return true; // leap year
        if(year%100 == 0) return false;
	}
    return leap;
}

int days_in_year(int year) 
{
	return isLeapYear(year)?366:365;
}


int days_in_month(int month, int year)
{
	int num_days=0;
	// January = 1, December =12
	switch(month) {
		case 1:	
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			num_days = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			num_days = 30;
			break;
		case 2: // February
			num_days = isLeapYear(year)?29:28;
			break;
		default:
			cout<<"Invalid month = "<<month<<endl;
			break;
	};
	return num_days;
}

int dates_difference_in_days(const char* date1, const char* date2)
{
	int total_days = 0;
	char *pDate1 = nullptr;	// Pointer to earlier date
	char *pDate2 = nullptr; // Pointer to later date
	int areDatesSame = compare_dates(date1, date2);
	if(areDatesSame == 0) return 0; // Dates are the same
	if(areDatesSame ==1) {
		pDate2 = const_cast<char *>(date1); 
		pDate1 = const_cast<char *>(date2); 
	}
	else {
		pDate1 = const_cast<char *>(date1);
		pDate2 = const_cast<char *>(date2); 
	}

	int mm1=0, dd1=0, yyyy1=0, mm2=0, dd2=0, yyyy2=0;
	parse_MM_DD_YYYY(date1, &mm1, &dd1, &yyyy1);
	parse_MM_DD_YYYY(date2, &mm2, &dd2, &yyyy2);
	int start_month=0, next_full_month=0, last_full_month=0, 
		num_days_in_month=0, current_month=0, days_to_month_end=0, current_year=0;;
	if(yyyy2 - yyyy1==0 ) { // Same years
		if(mm1!=mm2) {
			num_days_in_month = days_in_month(mm1, yyyy1);
			total_days+=num_days_in_month - dd1;  // Number of days elapsed of starting months of earlier date
			next_full_month = mm1+1;
			last_full_month = mm2-1;
			for(current_month=next_full_month;current_month<mm2;current_month++) {
					num_days_in_month = days_in_month(current_month, yyyy1);
					total_days+=num_days_in_month;
			}
			total_days+= dd2;
		}
		else if(mm1==mm2) { // Same month
			total_days+= dd2-dd1;
		}
	}
	else if(yyyy2-yyyy1 == 1) // Difference is 1 year but no more than 2 years
	{
		days_to_month_end = days_in_month(mm1, yyyy1);
		total_days+= days_to_month_end-dd1;
		current_month = mm1+1; // Start next month after month in earlier date
		current_year = yyyy1; // Starting year
	
		while( current_month != mm2 && current_year!= yyyy2)
		{
			for(; current_month<=12; current_month++)
				total_days+=days_in_month(current_month, current_year);
			++current_year; // Start year is over, new year starts
			current_month = 1; // January
		}				
		total_days+=dd2; // Days elapsed from beginning of month of latest date
	}
	else { // 2+ years difference

	//	1. Count number of days from day of earlier date till the end of month
		days_to_month_end = days_in_month(mm1, yyyy1);
		total_days+= days_to_month_end-dd1;
		
	//	2. Update years, count days in years in between yyyy1+1 and yyyy2
		current_month = mm1+1; // Start next month after month in earlier date
		current_year = yyyy1; // Starting year
		
		while( current_month != mm2 && current_year!= yyyy2)
		{
			for(; current_month<=12; current_month++)
				total_days+=days_in_month(current_month, current_year);
			++current_year; // Start year is over, new year starts
			current_month = 1; // January
		}				
		
	//	3. Count number of days from the beginning of later year
		current_month =1; // January
		while(current_month!=mm2) {
			total_days+= days_in_month(current_month, yyyy2);
			++current_month;
		}
		
		total_days+=dd2; // Add number of days in later date at given month mm2

	}
	return total_days;
}


int main(int argc, char**argv)
{
   
    int year=1900;
    cout<<"Year "<<year<<" is ";
	if(!isLeapYear(year)) 
		cout<<"non-";
	cout<<"leap."<<endl;
	
	const char *date1 = "01/11/1976";
	const char *date1A = "01/27/1976";
	const char *date1B = "03/26/1976";
	const char *date1C = "02/11/1976";
	const char *date1D = "02/01/1976";
	const char *date1E = "01/12/1977";
	const char *date1F = "01/10/1977";
	const char *date2 = "06/23/1993";
	int test_date=compare_dates(date1,date2);
	
	cout<<"test_date="<<test_date<<endl;
	cout<<is_same_year(date1,date2)<<endl;
	cout<<is_same_month(date1,date2)<<endl;
	int mm=0, dd=0, yyyy=0;
	parse_MM_DD_YYYY(date1, &mm, &dd, &yyyy);
	cout<<"mm = "<<mm<<"\tdd = "<<dd<<"\tyyyy = "<<yyyy<<endl;

	int numdays = dates_difference_in_days(date1, date1A);
	cout<<"Difference between "<<date1<<" and " <<date1A<<" is "<<numdays<<" days."<<endl;
	
	numdays = dates_difference_in_days(date1, date1B);
	cout<<"Difference between "<<date1<<" and " <<date1B<<" is "<<numdays<<" days."<<endl;
	
	numdays = dates_difference_in_days(date1, date1C);
	cout<<"Difference between "<<date1<<" and " <<date1C<<" is "<<numdays<<" days."<<endl;
	
	numdays = dates_difference_in_days(date1, date1D);
	cout<<"Difference between "<<date1<<" and " <<date1D<<" is "<<numdays<<" days."<<endl;
	
	numdays = dates_difference_in_days(date1, date1E);
	cout<<"Difference between "<<date1<<" and " <<date1E<<" is "<<numdays<<" days."<<endl;
	
	numdays = dates_difference_in_days(date1, date1F);
	cout<<"Difference between "<<date1<<" and " <<date1F<<" is "<<numdays<<" days."<<endl;
	
	cout<<"1976 is leap year? "<<isLeapYear(1976)<<" February has "<<days_in_month(2,1976)<<" days."<<endl;

	const char* start_ww2= "06/22/1941";
	const char* may9 = "05/09/1945";
	numdays = dates_difference_in_days(start_ww2, may9);
	cout<<"Difference between "<<start_ww2<<" and " <<may9<<" is "<<numdays<<" days."<<endl;

    return 0;
}
