#lang planet neil/sicp

(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

; Given two values, a and b, this function will first determine if b is greater
; than 0. 
;
; If it is, the return value will be equal to the sum of a and b, a positive 
; number. 
;
; If b is negative, the return value will be equal to the difference between a 
; and b. 
;
; As a result, the return value will always be equal to the value of a added to 
; the absolute value of the value of b.
