file(REMOVE_RECURSE
  "EventsTest.cpp.exe"
  "EventsTest.cpp.exe.manifest"
  "EventsTest.cpp.pdb"
  "libEventsTest.cpp.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/EventsTest.cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
