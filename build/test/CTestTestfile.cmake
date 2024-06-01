# CMake generated Testfile for 
# Source directory: C:/Users/danii/Desktop/Cplusplus-Queue/test
# Build directory: C:/Users/danii/Desktop/Cplusplus-Queue/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test_Devices "C:/Users/danii/Desktop/Cplusplus-Queue/build/test/Test_Devices.exe")
set_tests_properties(Test_Devices PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/danii/Desktop/Cplusplus-Queue/test/CMakeLists.txt;30;add_test;C:/Users/danii/Desktop/Cplusplus-Queue/test/CMakeLists.txt;0;")
add_test(Test_EventQueue "C:/Users/danii/Desktop/Cplusplus-Queue/build/test/Test_EventQueue.exe")
set_tests_properties(Test_EventQueue PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/danii/Desktop/Cplusplus-Queue/test/CMakeLists.txt;31;add_test;C:/Users/danii/Desktop/Cplusplus-Queue/test/CMakeLists.txt;0;")
add_test(Test_Events "C:/Users/danii/Desktop/Cplusplus-Queue/build/test/Test_Events.exe")
set_tests_properties(Test_Events PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/danii/Desktop/Cplusplus-Queue/test/CMakeLists.txt;32;add_test;C:/Users/danii/Desktop/Cplusplus-Queue/test/CMakeLists.txt;0;")
add_test(Test_Parser "C:/Users/danii/Desktop/Cplusplus-Queue/build/test/Test_Parser.exe")
set_tests_properties(Test_Parser PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/danii/Desktop/Cplusplus-Queue/test/CMakeLists.txt;33;add_test;C:/Users/danii/Desktop/Cplusplus-Queue/test/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
