file(REMOVE_RECURSE
  "DeviceATest.cpp.exe"
  "DeviceATest.cpp.exe.manifest"
  "DeviceATest.cpp.pdb"
  "libDeviceATest.cpp.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/DeviceATest.cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
