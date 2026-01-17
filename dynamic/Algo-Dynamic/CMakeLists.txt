cmake_minimum_required(VERSION 3.5)

project(Algo-Dynamic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Algo-Dynamic max_sum_inc_subseq.cc)

include(GNUInstallDirs)
install(TARGETS Algo-Dynamic
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
