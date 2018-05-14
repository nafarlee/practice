#lang sicp

(define (even? n)
  (= 0 (remainder n 2)))

(define (double n)
  (* n 2))

(define (halve n)
  (/ n 2))

(define (mult-iter a b)
  (mult-iter-rec a b 0))

(define (mult-iter-rec a b c)
  (cond ((= b 0) c)
        ((even? b) (mult-iter-rec (double a) (halve b) c))
        (else (mult-iter-rec a (dec b) (+ a c)))))
