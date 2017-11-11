#lang sicp

(define (p) (p))

(define (test x y)
  (if (= x 0)
      0
      y))

(test 0 (p))

; Under normal-order evaluation, the expression will terminate successfully, as
; the argument y ((p) in this case) will never be evaluated, as the conditional
; would yield true.
;
; Under applicative-order evaluation, it will never make it to the body of the
; test function, as the argument evaluation will repeatedly supplant the 
; expression with another. It will infinitely attempt to evaluate (p).
