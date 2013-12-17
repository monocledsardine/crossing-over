# Minimum required for SFML
cmake_minimum_required(VERSION 2.8)

project(Death)

# Set the SFML_DIR cache variable
set(SFML_DIR "${PROJECT_BINARY_DIR}/SFML" CACHE FILEPATH "Root directory for SFML install")

# CMake needs these values to find SFML
set(CMAKE_MODULE_PATH "${SFML_DIR}/cmake/Modules")
set(CMAKE_PREFIX_PATH "${SFML_DIR}")

# Find SFML
find_package(SFML COMPONENTS system window graphics main)

# Handy error message for those unsavvy people
if (SFML_FOUND)
	message(STATUS "SFML Found!")
else(SFML_FOUND)
	set(SFML_LIBRARIES "")
	message(FATAL_ERROR "SFML was not found. Try setting SFML_DIR in the graphical interface.")
endif(SFML_FOUND)

# Include SFML header files
include_directories(${SFML_INCLUDE_DIR})

# Raw list of Death game source files
set(DEATH_SRC 
	Action.h
	Actor.h
	Actor.cpp
	Animation.h
	Animation.cpp
	Cameraman.h
	Cameraman.cpp
	Director.h
	Director.cpp
	Enemy.h
	Enemy.cpp
	ImageRef.h
	InputReactor.h
	InputReactor.cpp
	Kirby.h
	Kirby.cpp
	Motion.h
	Motion.cpp
	RoomLoader.h
	RoomLoader.cpp
	Shadow.h
	Shooter.h
	Shooter.cpp
	Soul.h
	Soul.cpp
	Targetable.h
	Targetable.cpp
	TextureStore.h
	TextureStore.cpp
	ThrowawayRoom.h
	Thrower.h
	TiledImage.h	
	TiledImage.cpp
	Thrower.cpp
	ZSprite.h
)

add_library(DeathLib ${DEATH_SRC})

add_executable(Death Main.cpp)
target_link_libraries(Death DeathLib ${SFML_LIBRARIES})

# Make sure the install prefix is in the graphical prompt
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/../bin" CACHE FILEPATH "Install location of the project")

# To install the game, we need 1. The .exe, 2. SFML dlls, ...
install(TARGETS Death DESTINATION .)
install(FILES ${SFML_DIR}/bin/sfml-system-2.dll
				${SFML_DIR}/bin/sfml-window-2.dll
				${SFML_DIR}/bin/sfml-graphics-2.dll
				DESTINATION .)

# ...and 3. Images
install(DIRECTORY images DESTINATION .)
#
add_subdirectory(TestSuite)