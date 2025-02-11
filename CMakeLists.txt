cmake_minimum_required(VERSION 3.22)

project(axolotl)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

add_compile_options(--coverage)
add_link_options(-lgcov --coverage)

#
# Third Party Libraries
#
find_package(Criterion)
include_directories(CRITERION_INCLUDE_DIR)

#
# Interfaces
#
add_library(axolotl-common INTERFACE)
target_sources(axolotl-common PUBLIC src/common/tsv.h src/common/tsv.c)

#
# Frontend Executable
#
add_executable(axolotl src/main.c)
target_link_libraries(axolotl axolotl-common)

#
# Fuzz
#
add_executable(axolotl-fuzz fuzz/main.c)
target_link_libraries(axolotl-fuzz axolotl-common)

#
# Tests
#
add_executable(axolotl-test tests/common/test_tsv.c)
include_directories(axolotl-test src)
target_link_libraries(axolotl-test axolotl-common ${CRITERION_LIBRARY})

#
# Custom Commands and Targets
#

# Run tests
add_custom_target(test ${CMAKE_BINARY_DIR}/axolotl-test)

# Build human written documentation
add_custom_target(docs mkdocs build -f "${CMAKE_SOURCE_DIR}/mkdocs.docs.yml")

# Build computer generated reports
add_custom_target(docs-reports mkdocs build -f
                               "${CMAKE_SOURCE_DIR}/mkdocs.reports.yml")
