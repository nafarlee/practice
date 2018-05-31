#lang sicp

(define (fixed-point f first-guess)
  (define tolerance 0.00001)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) 
       tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try first-guess))

; x = 1 + 1/x
; Multiply x on both sides...
; x^2 = x + 1
; This matches the equation specified in Section 1.2.2

(define (golden-ratio x)
  (+ 1 (/ 1 x)))

(fixed-point golden-ratio 2.0) ; 1.6180327868852458
