find_library(DeathLib REQUIRED)

set(ACTIVE_TESTS	TextureLoading_Test.h
	)
	
add_executable(test Game_Suite.cpp Test.cpp Suite.cpp ${ACTIVE_TESTS})
target_link_libraries(test DeathLib ${SFML_LIBRARIES})