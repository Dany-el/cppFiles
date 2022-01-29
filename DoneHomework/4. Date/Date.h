#pragma once

class Date{
    // Day
    unsigned int day;
    // Month
    unsigned int month;
    // Year
    unsigned int year;
    // Methods for checking
    // for Day
    void CheckInputDay();
    void CheckOneSevenMonth();
    void CheckEightTwelveMonth();
    // for Month
    void CheckInputMonth();
    // for Year
    void CheckInputYear();
    // Converter of date -> days
    unsigned int ConvertDateIntoDays(const Date p_date);
    // Converter of days -> date
    Date ConvertDaysIntoDate(unsigned int full_days);
    // Operators
    unsigned int operator - (const Date second_date);
    Date operator + (const unsigned int p_days);
public:
    inline unsigned int getDay() const;
    inline unsigned int getMonth() const;
    inline unsigned int getYear() const;

    inline void setDay(const unsigned int p_day);
    inline void setMonth(const unsigned int p_month);
    inline void setYear(const unsigned int p_year);

    Date();
    Date(const unsigned int p_day,const unsigned int p_month, const unsigned int p_year);

    void Input();
    void Print();

    ~Date();
};