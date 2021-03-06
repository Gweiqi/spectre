# Distributed under the MIT License.
# See LICENSE.txt for details.

set(LIBRARY ParallelSchwarz)

add_spectre_library(${LIBRARY})

spectre_target_sources(
  ${LIBRARY}
  PRIVATE
  OverlapHelpers.cpp
  )

spectre_target_headers(
  ${LIBRARY}
  INCLUDE_DIRECTORY ${CMAKE_SOURCE_DIR}/src
  HEADERS
  OverlapHelpers.hpp
  Schwarz.hpp
  )

target_link_libraries(
  ${LIBRARY}
  PUBLIC
  Boost::boost
  DataStructures
  DomainStructure
  PRIVATE
  ErrorHandling
  Utilities
  )
