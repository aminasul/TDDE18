// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "linked_list.h"
#include <random>

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) {
    Sorted_List l{};

    SECTION("Testing if list is empty and size is 0")
    {
	REQUIRE( l.is_empty() == true );
	REQUIRE( l.size() == 0 );
    }

    SECTION("Testing insert, remove, is_empty and size in right order")
    {
    	REQUIRE(l.size() == 0);
    	l.insert(3);
    	l.insert(4);
    	l.insert(5);
    	l.insert(2);
    	l.remove(4);
    	l.remove(5);
    	l.remove(2);
    	CHECK_FALSE( l.is_empty());
    	CHECK_FALSE( l.size() == 0 );
	CHECK(l.size() == 1);


    }

    SECTION("Testing insert, remove, is_empty and size in left order")
    {
    	REQUIRE(l.size() == 0);
    	l.insert(3);
    	l.insert(4);
    	l.insert(5);
    	l.insert(2);
    	l.remove(2);
        l.remove(5);
    	l.remove(3);
    	l.remove(4);
    	CHECK( l.size() == 0 );
    	CHECK( l.is_empty() == true );

    }

    SECTION("Testing printlist")
    {
    	l.insert(1);
    	l.insert(0);
    	l.insert(4);
    	l.insert(10);
    	l.insert(7);
    	l.insert(8);
    	l.insert(6);
    	l.printlist();
    }

    SECTION("Testing if operator = and copy works")
    {

    	l.insert(1);
    	l.insert(0);
    	l.insert(4);
    	l.insert(10);
    	l.insert(7);
    	l.insert(8);
    	l.insert(6);
    	l.printlist();
    	Sorted_List l2 {};
    	l2 = l;
    	l2.printlist();
    	l2.insert(7);
    	l2.printlist();
    	l.printlist();
    	Sorted_List l3{};
    	l3 = l2;
    	l3.printlist();
    	l3.insert(9);
    	l2.printlist();
    	l3.printlist();

      }
    SECTION("Testing if at works as expected")
    {
	CHECK_FALSE(l.at(3) == 1);
	l.insert(1);
	CHECK(l.at(1) == 1);
	l.insert(4);
    	l.insert(10);
    	l.insert(7);
    	l.insert(8);
	CHECK(l.at(8) == 4);
    }

    SECTION("Testing if our copy constructure works :)")
    {
    	l.insert(3);
    	l.insert(4);
    	l.insert(5);
    	l.insert(2);
	Sorted_List l2{l};
	l2.printlist();
	l.insert(7);
	l2.printlist();
	l.printlist();


    }

// TODO Complementary work needed: missing tests for move assignment, please add this :)

  SECTION("Testing if our move constructure works :)"
  {
  	l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(2);
    Sorted_List l3(std::move(l));
  	l.printlist();
  	l3.printlist();
  }

    SECTION("Testing if our move assignment works <3")
    {
      Sorted_List l4{};
      l.insert(4);
      l.insert(7);
      l.insert(2);
      Sorted_List l5{};
      l5 = std::move(l4);
      l4.printlist();
      l5.printlist();
    }

    SECTION("Testing with random generation")
    {
	l.insert(rand());
	l.insert(rand());
	l.insert(rand());
	l.printlist();
    }

}

// It is your job to create new test cases and fully test your Sorted_List class
