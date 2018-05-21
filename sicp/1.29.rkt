#lang sicp

(define (simpson f a b n)
  (define h (/ (- b a) n))
  (define (y k) (f (+ a (* k h))))
  (define (term k)
    (* (y k)
       (cond
         ((or (= k 0) (= k n)) 1)
         ((even? k)            2)
         (else                 4))))
  (define (recur k)
    (if (= k n)
      (term k)
      (+ (term k) (recur (inc k)))))
  (* h (/ 1 3) (recur 0)))

(define (cube x) (* x x x))

(simpson cube 0 1 10) ; 1/4
(simpson cube 0 1 100) ; 1/4
(simpson cube 0 1 1000) ; 1/4

; The simpson method appears to arrive at accurate results much more quickly
; than the previous method
