#lang sicp

(define (square x)
  (* x x))

(define (sum-squares x y)
  (+ (square x)
     (square y)))

(define (main x y z)
  (cond ((= x (min x y z)) (sum-squares y z))
        ((= y (min x y z)) (sum-squares x z))
        ((= z (min x y z)) (sum-squares x y))))
