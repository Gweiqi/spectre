# Distributed under the MIT License.
# See LICENSE.txt for details.

spectre_target_headers(
  Evolution
  INCLUDE_DIRECTORY ${CMAKE_SOURCE_DIR}/src
  HEADERS
  DgElementArray.hpp
  )

add_subdirectory(Limiters)
