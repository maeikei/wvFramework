include_directories(.)
link_directories(${CMAKE_BINARY_DIR}/3rdpart/boost/lib)

aux_source_directory(. framework_SRCS)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-backtrace-limit=0 ")

add_definitions(
  -DASIO_HAS_MOVE -DASIO_HAS_VARIADIC_TEMPLATES -DASIO_HAS_STD_SYSTEM_ERROR
  -DASIO_ERROR_CATEGORY_NOEXCEPT=noexcept -DASIO_HAS_STD_ARRAY
  -DASIO_HAS_STD_SHARED_PTR -DASIO_HAS_STD_ATOMIC -DASIO_HAS_STD_CHRONO
  -DASIO_HAS_STD_ADDRESSOFF -DASIO_HAS_STD_FUNCTION -DASIO_HAS_STD_TYPE_TRAITS
)


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
  )
endif(NOT WIN32)

if(APPLE)
  target_link_libraries( watorvapor
    c++
    c++abi
  )
endif(APPLE)

install(TARGETS watorvapor DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
