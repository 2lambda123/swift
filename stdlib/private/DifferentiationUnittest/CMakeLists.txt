add_swift_target_library(swiftDifferentiationUnittest ${SWIFT_STDLIB_LIBRARY_BUILD_TYPES} IS_STDLIB
  # This file should be listed first. Module name is inferred from the filename.
  GYB_SOURCES DifferentiationUnittest.swift.gyb

  SWIFT_MODULE_DEPENDS _Differentiation StdlibUnittest
  INSTALL_IN_COMPONENT stdlib-experimental
  DARWIN_INSTALL_NAME_DIR "${SWIFT_DARWIN_STDLIB_PRIVATE_INSTALL_NAME_DIR}"
  MACCATALYST_BUILD_FLAVOR "zippered")
