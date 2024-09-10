# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ListAnalyzer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ListAnalyzer_autogen.dir/ParseCache.txt"
  "ListAnalyzer_autogen"
  )
endif()
