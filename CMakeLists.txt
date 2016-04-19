cmake_minimum_required(VERSION 3.5)
project(QuickShoppr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GroceryItem.cpp GroceryItem.h GroceryStore.cpp GroceryStore.h GroceryAisle.cpp GroceryAisle.h GroceryList.cpp GroceryList.h)
add_executable(QuickShoppr ${SOURCE_FILES})