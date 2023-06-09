// RUN: %empty-directory(%t)
// RUN: %target-build-swift %s -module-name Basic -emit-module -emit-module-path %t/
// RUN: %target-swift-symbolgraph-extract -module-name Basic -I %t -pretty-print -output-dir %t
// RUN: %FileCheck %s --input-file %t/Basic.symbols.json

public class Base {}
public class Derived: Base {}

// CHECK: "kind": "inheritsFrom"
// CHECK-NEXT: "source": "s:5Basic7DerivedC"
// CHECK-NEXT: "target": "s:5Basic4BaseC"
