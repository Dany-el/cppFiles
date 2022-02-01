#include <iostream>
#include "Date.h"

using std::cout;
using std::cin;

/**
 * @brief Getter of Day
 * 
 * @return unsigned int 
 */
inline unsigned int Date::getDay() const{
    return day;
}

/**
 * @brief Getter of Month
 * 
 * @return unsigned int 
 */
inline unsigned int Date::getMonth() const{
    return month;
}

/**
 * @brief Getter of Year
 * 
 * @return unsigned int 
 */
inline unsigned int Date::getYear() const{
    return year;
}

/**
 * @brief Setter of Day
 * 
 * @param p_day - user's day
 */
inline void Date::setDay(const unsigned int p_day){
    if (p_day > 0 && p_day <=31)    
    {
        day = p_day;
    }    
}
/**
 * @brief Setter of Month
 * 
 * @param p_month - user's month
 */
inline void Date::setMonth(const unsigned int p_month){
    if (p_month > 0 && p_month<=12)
    {
        month = p_month;
    }
}
/**
 * @brief Setter of Year
 * 
 * @param p_year - user's year
 */
inline void Date::setYear(const unsigned int p_year){
    if (p_year >= 1000)
    {
        year = p_year;
    }
}

/**
 * @brief Construct a new Date:: Date object
 * 
 */
Date::Date(){
    day = 0;
    month = 0;
    year = 0;
}

/**
 * @brief Construct a new Date:: Date object
 * 
 * @param p_day   - user's day
 * @param p_month - user's month
 * @param p_year  - user's year
 */
Date::Date(const unsigned int p_day,const unsigned int p_month, const unsigned int p_year){
    if (p_day > 0 && p_day <=31)    
    {
        day = p_day;
    } 
    if (p_month > 0 && p_month<=12)
    {
        month = p_month;
    }   
    if (p_year >= 1000)
    {
        year = p_year;
    }
}

/**
 * @brief Check if Month was right written
 * 
 */
void Date::CheckInputMonth(){
    while (month < 0 || month > 12)
    {
        system("clear");
        cout << "dd.[mm].yyyy\n";
        cout << "Wrong! There are only 12 months\n";
        cout << "Month: ";
        cin >> month;
    }
}   

/**
 * @brief Check if Month is 1 to 7 to input day
 * 
 */
void Date::CheckOneSevenMonth(){
    // If February
    if (month == 2)
    {
        while (day < 0 || day > 28)
        {
            system("clear");
            printf("[dd].%d.yyyy\n",month);
            cout << "Wrong! This Month has only 28 days\n";
            cout << "Day: ";
            cin >> day;
        } 
    }
    // If January to July(Except February, that's why it's above)
    if(month > 0 && month <= 7){
        if (month%2 == 0)
        {
            while (day < 0 || day > 30)
            {
                system("clear");
                printf("[dd].%d.yyyy\n",month);
                cout << "Wrong! This Month has only 30 days\n";
                cout << "Day: ";
                cin >> day;
            } 
        }
        else{
            while (day < 0 || day > 31)
            {
                system("clear");
                printf("[dd].%d.yyyy\n",month);
                cout << "Wrong! This Month has only 31 days\n";
                cout << "Day: ";
                cin >> day;
            } 
        }
    }
}

/**
 * @brief Check if Month is from 8 to 12 to input day
 * 
 */
void Date::CheckEightTwelveMonth(){
    if (month > 7 && month <=12 )
    {
        if (month%2 == 0)
        {
            while (day < 0 || day > 31)
            {
                system("clear");
                printf("[dd].%d.yyyy\n",month);
                cout << "Wrong! This Month has only 31 days\n";
                cout << "Day: ";
                cin >> day;
            } 
        }
        else{
            while (day < 0 || day > 30)
            {
                system("clear");
                printf("[dd].%d.yyyy\n",month);
                cout << "Wrong! This Month has only 30 days\n";
                cout << "Day: ";
                cin >> day;
            } 
        }
    }
}

/**
 * @brief Check if Day was right written
 * 
 */
void Date::CheckInputDay(){
    CheckOneSevenMonth();
    CheckEightTwelveMonth();
}
/**
 * @brief Check if Year was right written
 * 
 */
void Date::CheckInputYear(){
    while(year < 1000){
        system("clear");
        printf("%d.%d.[yyyy]",day,month);
        cout << "\nWrong! Year must have 4 numbers\n";
        cout << "Year: ";
        cin >> year;
    }
}


/**
 * @brief Input date.month.year
 * 
 */
void Date::Input(){
    // Input month
    cout << "\n----\nDate's format:\ndd.[mm].yyyy\n----\n";
    cout << "\nMonth: ";
    cin >> month;
    CheckInputMonth();

    // Input Day
    system("clear");
    printf("[dd].%d.yyyy",month);
    cout << "\nDay: ";
    cin >> day;
    CheckInputDay();
    
    // Input Year
    system("clear");
    printf("%d.%d.[yyyy]",day,month);
    cout << "\nYear: ";
    cin >> year;    
    CheckInputYear();

    system("clear");
}

/**
 * @brief Print date.month.year
 * 
 */
void Date::Print(){
    //system("clear");
    cout << "Date:\n" << day << '.' << month << '.' << year << '\n';
}

/**
 * @brief Convert date into days
 * 
 * @param p_date - user's date
 * @return unsigned int (days)
 */
unsigned int Date::ConvertDateIntoDays(const Date p_date){
    unsigned int sum = 0;
    // + Days
    sum += p_date.day;
    // + Months
    // -1 'cause it's not even ended
    for (size_t i = 1; i <= p_date.month - 1; i++)
    {
        // To 7
        if (i <= 7)
        {
            // February
            if (i == 2)
            {
                sum+=28;
            }
            else if (i % 2 == 0 && i !=2)
            {
                sum+=30;
            }
            else{
                sum+=31;
            }
        }
        // From 8
        else{
            if (i % 2 != 0)
            {
                sum+=30;
            }
            else{
                sum+=31;
            }
        }
    }
    // + Year
    sum += (p_date.year * 365);
    return sum;
}

/**
 * @brief Check the right writing of the date
 * 
 */
void Date::RightDatePlusPlus(Date& tmp){
    if (month == 2)
    {
        if (day > 28)
        {
            day -= 28;
        }
        else if (day == 28)
        {
            day = 1;
        }
        ++month;
    }
    else if (month <= 7) 
    {
        if (month % 2 == 0)
        {
            if (day > 30)
            {
                day -= 30;                
            }
            else if (day == 30)
            {
                day = 1;
            }
            ++month;
        }
        else{
            if (day > 31)
            {
                day -= 31;                
            }
            else if (day == 31)
            {
                day = 1;
            }
            ++month;
        }        
    }
    else if (month >=8)
    {
        if (month % 2 != 0 )
        {
            if (day >30)
            {
                day -= 30;
            }
            else if (day == 30)
            {
                day = 1;
            }
            ++month;
        }
        else{
            if (day > 31)
            {
                day = day - 31;                
            }
            else if (day == 31)
            {
                day = 1;
            }
            ++month;
        }    
    }  
}

/**
 * @brief Convert days into date 
 * 
 * @param full_days - sum of days (date and days) 
 * @return Date 
 */
Date Date::ConvertDaysIntoDate(unsigned int full_days){
    Date tmp;
    tmp.setYear(full_days/365);
    full_days -= tmp.getYear()*365;
    tmp.setMonth(1 + (full_days*0.032855));
    // I use max 31 instead of 30 or 28
    full_days -=(tmp.getMonth() - 1) * 31;
    tmp.setDay(full_days);
    // Sadly, but date has
    // to 6 days - not exact result  
    RightDatePlusPlus(tmp);
    return tmp;
}

/**
 * @brief Difference of two dates
 * 
 * @param second_date - second date 
 * @return unsigned int (days)
 */
unsigned int Date::operator - (const Date second_date){
    Date tmp;
    tmp.setDay(day);
    tmp.setMonth(month);
    tmp.setYear(year);
    // First date days
    unsigned int first_days = ConvertDateIntoDays(tmp);
    // Second date days
    unsigned int second_days = ConvertDateIntoDays(second_date);
    // Minus two dates
    if (first_days > second_days)
    {
        return first_days - second_days;
    }
    else{
        return second_days - first_days;
    }
}

/**
 * @brief Sum of date and days
 * 
 * @param p_days - days to sum with date
 * @return unsigned int (date)
 */
Date Date::operator + (const unsigned int p_days){
    Date tmp;
    tmp.setDay(day);
    tmp.setMonth(month);
    tmp.setYear(year);
    tmp = ConvertDaysIntoDate(ConvertDateIntoDays(tmp) + p_days);
    return tmp;
}

/**
 * @brief Plus 
 * 
 * @return Date 
 */
Date Date::operator ++(){
    // Copy date to new object
    Date tmp;
    tmp.setDay(day);
    tmp.setMonth(month);
    tmp.setYear(year);
    // Tmp
    unsigned int days = ConvertDateIntoDays(tmp);
    tmp = ConvertDaysIntoDate(++days);
    return tmp; 
}

/**
 * @brief 
 * 
 * @return Date 
 */
Date Date::operator --(){
    // Copy date to new object
    Date tmp;
    tmp.setDay(day);
    tmp.setMonth(month);
    tmp.setYear(year);
    // Tmp
    unsigned int days = ConvertDateIntoDays(tmp);
    tmp = ConvertDaysIntoDate(--days);
    return tmp; 
}

/**
 * @brief Destroy the Date:: Date object
 * 
 */
Date::~Date(){}