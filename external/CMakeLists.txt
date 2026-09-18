if(NOT EXISTS "${CMAKE_SOURCE_DIR}/external/SFML/CMakeLists.txt")
  
  find_package(Git REQUIRED)
  
  execute_process(
    COMMAND "${GIT_EXECUTABLE} submodule update --init --recursive"
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    RESULT_VARIABLE "GIT_SUBMODULE_RESULT"
  )

  if(NOT GIT_SUBMODULE_RESULT EQUAL "0")
    message(FATAL_ERROR "failed to run 'git submodule update --init --recursive'")
  endif()

endif()

add_subdirectory(SFML)