/*
 * Project_One_Clock.h
 * Author: Sean Jette
 * Date: 17SEP2023
 */

#ifndef PROJECT_ONE_CLOCK_H             // Check if the header file has already been included
#define PROJECT_ONE_CLOCK_H             // If not, define it so it can be included
#define _CRT_SECURE_NO_WARNINGS         /* Define _CRT_SECURE_NO_WARNINGS to disable warnings 
                                         about using unsafe functions from the C Runtime Library */

// Class to represent a clock time
class ClockTime {
private:
    // Private member variables to store the hour, minute, and second
    int hour;
    int minute;
    int second;
public:
    // Constructor with default values of 0 for hour, minute, and second
    ClockTime(int hr = 0, int min = 0, int sec = 0) : hour(hr), minute(min), second(sec) {}
    // Getter function for the second
    int getSecond() {
        return this->second;
    }
    // Setter function for the second with validation
    void setSecond(int sec) {
        if (sec >= 0 && sec < 60) {
            this->second = sec;
        }
    }
    // Function to add one second to the current time
    void addOneSecond() {
        int currentSecond = getSecond();
        if (currentSecond >= 0 && currentSecond < 59) {
            // If the current second is between 0 and 58, add 1
            setSecond(currentSecond + 1);
        }
        else if (currentSecond == 59) {
            // If the current second is 59, set the second to 0 and add one minute
            setSecond(0);
            addOneMinute();
        }
    }
    // Getter function for the minute
    int getMinute() {
        return this->minute;
    }
    // Setter function for the minute with validation
    void setMinute(int min) {
        if (min >= 0 && min < 60) {
            this->minute = min;
        }
    }
    // Function to add one minute to the current time
    void addOneMinute() {
        int currentMinute = getMinute();
        if (currentMinute >= 0 && currentMinute < 59) {
            // If the current minute is between 0 and 58, add 1
            setMinute(currentMinute + 1);
        }
        else if (currentMinute == 59) {
            // If the current minute is 59, set the minute to 0 and add one hour
            setMinute(0);
            addOneHour();
        }
    }
    // Getter function for the hour
    int getHour() {
        return this->hour;
    }
    // Setter function for the hour with validation
    void setHour(int hr) {
        if (hr >= 0 && hr < 24) {
            this->hour = hr;
        }
    }
    // Function to add one hour to the current time
    void addOneHour() {
        int currentHour = getHour();
        if (currentHour >= 0 && currentHour < 23) {
            // If the current hour is between 0 and 22, add 1
            setHour(currentHour + 1);
        }
        else if (currentHour == 23) {
            // If the current hour is 23, set the hour to 0
            setHour(0);
        }
    }
};
#endif /* PROJECT_ONE_CLOCK_H */