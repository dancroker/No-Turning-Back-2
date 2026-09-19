cmake_minimum_required(VERSION 3.16)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("SBGJ-2026" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 4)
  set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
endif()

# DEPENDENCIES
add_subdirectory(external)

# GAME
add_executable(game 
	src/main.cpp
 "src/Map/LevelGen/LevelGen.cpp" "src/Map/LevelGen/Level.cpp"
	"src/main.cpp"

  "src/Game.cpp"
  "src/Game.hpp"
 "src/Map/GameMap.cpp" "src/Map/MapDraw/MapDraw.cpp")

target_link_directories(game PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(game PRIVATE
  "sfml-graphics"
  "sfml-window"
  "sfml-system"
)


# ASSETS
if(WIN32)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/data/" "$<TARGET_FILE_DIR:game>/data/"
  )
else()
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/data" "$<TARGET_FILE_DIR:game>/data"
  )
endif()

# -- im only gonna add this when needed --

# # INSTALL
# install(TARGETS game
#   RUNTIME DESTINATION bin
# )
# install(DIRECTORY data/
#   DESTINATION bin/data
# )
