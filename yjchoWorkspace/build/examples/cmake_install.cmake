# Install script for directory: /home/pi/Downloads/NFC Reader Library for Linux V.4.0/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx1_BasicDiscoveryLoop/cmake_install.cmake")
  include("/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx2_AdvancedDiscoveryLoop/cmake_install.cmake")
  include("/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx3_NFCForum/cmake_install.cmake")
  include("/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx4_MIFAREClassic/cmake_install.cmake")
  include("/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx5_ISO15693/cmake_install.cmake")
  include("/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx6_EMVCo_Loopback/cmake_install.cmake")
  include("/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx7_EMVCo_Polling/cmake_install.cmake")
  include("/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx8_HCE_T4T/cmake_install.cmake")
  include("/home/pi/Downloads/NFC Reader Library for Linux V.4.0/build/examples/NfcrdlibEx9_NTagI2C/cmake_install.cmake")

endif()

