file(REMOVE_RECURSE
  "DeviceBTest.cpp.exe"
  "DeviceBTest.cpp.exe.manifest"
  "DeviceBTest.cpp.pdb"
  "libDeviceBTest.cpp.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/DeviceBTest.cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
