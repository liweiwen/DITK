if(NOT ITK_BUILD_ALL_MODULES)
  message(FATAL_ERROR "BUILD_EXAMPLES requires ITK_BUILD_ALL_MODULES")
endif()

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

macro(itk_add_test)
endmacro()

set(ITK_TEST_DRIVER itkTestDriver)

add_subdirectory(Iterators)
add_subdirectory(DataRepresentation)
add_subdirectory(Filtering)
add_subdirectory(IO)
add_subdirectory(Numerics)
add_subdirectory(Registration)
add_subdirectory(Segmentation)
add_subdirectory(SpatialObjects)
add_subdirectory(Statistics)
