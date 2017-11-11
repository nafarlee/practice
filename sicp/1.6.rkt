#lang sicp

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))

(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
          guess
          (sqrt-iter (improve guess x)
                     x)))

; The problem with this new-if function is related to the order in which
; a forms will be evaluated. Regardless of the value of the predicate, both the
; then-clause, as well as the else-clause will be evaluated until they are a 
; primitive value. 
;
; In this case, it will recursive infinitely, never even evaluating the 
; predicate.
