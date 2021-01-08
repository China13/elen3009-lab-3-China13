#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// COMMENT OUT THIS TEST AFTER INSPECTING THE OUTPUT
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
//TEST_CASE("Date has uninitialised state") {
//    // make a prior memory allocations - which will be the case in a typical program
//	auto str = "hello"s;
//
//    Date today;	// rather use: auto today = Date{}; not used here to illustrate the issue
//    std::cout << "Today is: " << endl;
//    printDate(today);
//}

// Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	auto heritage_day = Date{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an exception is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.
TEST_CASE("Date for invalid day, throws an exception"){
CHECK_THROWS_AS(Date(-4, Month::January, 2000), invalidDate_Day);
CHECK_THROWS_AS(Date(32, Month::January, 2000), invalidDate_Day);
}

TEST_CASE("Date for invalid month, throws an exception"){
Month ChinaMonth1 = static_cast<Month>(-1);
Month ChinaMonth2 = static_cast<Month>(13);
CHECK_THROWS_AS(Date(4, ChinaMonth1, 2000), invalidDate_Month );
CHECK_THROWS_AS(Date(4, ChinaMonth2, 2000), invalidDate_Month );
}

TEST_CASE("Date for invalid year, throws an exception"){
CHECK_THROWS_AS(Date(4, Month::January, -2000), invalidDate_Year);
}

TEST_CASE("Date is leap year"){
    CHECK_NOTHROW(Date(29, Month::February,2020));
    CHECK_THROWS_AS(Date(29, Month::February, 2009), invalidDate_Day);
}
// Exercise 2.3
TEST_CASE("Identical Dates are Equal") {
    auto date_1 = Date{1, Month::January, 2000};
    auto date_2 = Date{1, Month::January, 2000};

    CHECK(date_1 == date_2);
}

// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.
TEST_CASE("Identical days, different years and months, are not equal dates"){
    auto date_1 = Date{1, Month::February, 2001};
    auto date_2 = Date{1, Month::January, 2000};


    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Identical months, different days and years, are not equal dates"){
    auto date_1 = Date{2, Month::January, 2001};
    auto date_2 = Date{1, Month::January, 2000};

    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Identical years, different days and months, are not equal dates"){
    auto date_1 = Date{2, Month::August, 2000};
    auto date_2 = Date{1, Month::January, 2000};

    CHECK_FALSE(date_1 == date_2);
}
// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.
TEST_CASE("A date increase by day"){
    auto date_1 = Date{2, Month::August, 2000};
    date_1.nextDay();
    auto date_2 = Date{3, Month::August, 2000};

    CHECK(date_1 == date_2);
}

TEST_CASE("Last day of the month, the next day is the begining of the new month"){
    auto date_1 = Date{31, Month::August, 2000};
    date_1.nextDay();
    auto date_2 = Date{1, Month::September, 2000};

    CHECK(date_1 == date_2);
}

TEST_CASE("Last day of the year, the next day is the begining of the new year"){
    auto date_1 = Date{31, Month::December, 2000};
    date_1.nextDay();
    auto date_2 = Date{1, Month::January, 2001};

    CHECK(date_1 == date_2);
}

TEST_CASE("A leap year, and the day is the 28th of February, the next day is the 29th of February."){
    auto date_1 = Date{28, Month::February, 2020};
    date_1.nextDay();
    auto date_2 = Date{29, Month::February, 2020};

    CHECK(date_1 == date_2);
}

TEST_CASE("A leap year, and the day is the 29th of February, the next day is the 1st of March 2020."){
    auto date_1 = Date{28, Month::February, 2021};
    date_1.nextDay();
    auto date_2 = Date{1, Month::March, 2021};

    CHECK(date_1 == date_2);
}

TEST_CASE("The day is the 28th of February 2021, the next day is the 1st of March 2021."){
    auto date_1 = Date{28, Month::February, 2021};
    date_1.nextDay();
    auto date_2 = Date{1, Month::March, 2021};

    CHECK(date_1 == date_2);
}


// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
