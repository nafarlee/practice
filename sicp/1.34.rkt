#lang sicp

(define (square x) (* x x))

(define (f g) (g 2))

; (f f)
; (f 2)
; (2 2)
;
; This will error, as there is no way to `apply` the literal form 2.
