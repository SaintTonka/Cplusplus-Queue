file(REMOVE_RECURSE
  "ParserTest.cpp.exe"
  "ParserTest.cpp.exe.manifest"
  "ParserTest.cpp.pdb"
  "libParserTest.cpp.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/ParserTest.cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
