//===--- ErrorObjectCommon.cpp - Recoverable error object -----------------===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2019 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
//
// This implements the parts of the standard Error protocol type which are
// shared between the ObjC-interoperable implementation and the native
// implementation. The parts specific to each implementation can be found in
// ErrorObject.mm (for the ObjC-interoperable parts) and ErrorObjectNative.cpp.
//
//===----------------------------------------------------------------------===//

#include "swift/Runtime/Concurrent.h"
#include "swift/Runtime/Config.h"
#include "ErrorObject.h"
#include "ErrorObjectTestSupport.h"

using namespace swift;

std::atomic<void (*)(SwiftError *error)> swift::_swift_willThrow;

void swift::_swift_setWillThrowHandler(void (* handler)(SwiftError *error)) {
  _swift_willThrow.store(handler, std::memory_order_release);
}

/// Breakpoint hook for debuggers, and calls _swift_willThrow if set.
SWIFT_CC(swift) void
swift::swift_willThrow(SWIFT_CONTEXT void *unused,
                       SWIFT_ERROR_RESULT SwiftError **error) {
  // Cheap check to bail out early, since we expect there to be no callbacks
  // the vast majority of the time.
  auto handler = _swift_willThrow.load(std::memory_order_acquire);
  if (SWIFT_UNLIKELY(handler)) {
    (* handler)(*error);
  }
}
