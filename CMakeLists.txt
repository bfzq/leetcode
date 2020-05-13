cmake_minimum_required(VERSION 3.13)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.
		    two\ sum)

add_executable(leetcode
               main.cc
	       base.cc
	       two\ sum/two_sum.cc)
