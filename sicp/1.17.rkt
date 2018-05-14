#lang sicp

(define (even? n)
  (= (remainder n 2) 0))

(define (double n)
  (* n 2))

(define (halve n)
  (/ n 2))

(define (fast-mult a b)
    (cond ((= b 1) 
           a)
          ((even? b) 
           (double (fast-mult a (halve b))))
          (else 
           (+ a (fast-mult a (dec b))))))
