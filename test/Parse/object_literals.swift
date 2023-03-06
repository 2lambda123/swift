// RUN: %target-typecheck-verify-swift

let _ = #notAPound // expected-error {{no macro named 'notAPound'}}
let _ = #notAPound(1, 2) // expected-error {{no macro named 'notAPound'}}
let _ = #Color // expected-error {{no macro named 'Color'}}

let _ = [##] // expected-error 2 {{expected a macro identifier}} {{none}}
// expected-error @-1 {{consecutive statements on a line must be separated by ';'}}
