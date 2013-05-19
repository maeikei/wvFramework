include_directories(.)
link_directories(${CMAKE_BINARY_DIR}/3rdpart/boost/lib)
link_directories(${CMAKE_BINARY_DIR}/3rdpart/cpp-netlib/lib)

aux_source_directory(. framework_SRCS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-backtrace-limit=0 ")

add_executable(watorvapor 
  ${framework_SRCS}
)
target_link_libraries( watorvapor leveldb)

if(NOT WIN32)
  target_link_libraries( watorvapor
    boost_iostreams
    boost_system
    boost_filesystem
    boost_regex
    cppnetlib
  )
endif(NOT WIN32)

if(APPLE)
  target_link_libraries( watorvapor
    c++
    c++abi
  )
endif(APPLE)

install(TARGETS watorvapor DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
