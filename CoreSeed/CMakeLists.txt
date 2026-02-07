cmake_minimum_required(VERSION 3.16)
project(CoreSeed LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Suche die installierten Qt6-Pakete auf OpenBSD
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(CoreSeed src/main.cpp)

# Verknüpfe CoreSeed mit den Qt6-Bibliotheken
target_link_libraries(CoreSeed PRIVATE Qt6::Widgets)
