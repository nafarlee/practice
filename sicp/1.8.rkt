#lang sicp

(define (square x) (* x x))

(define (low-enough-delta? prev-guess guess)
  (< (abs (- guess prev-guess))
     (* guess 0.000001)))

(define (improve y x)
  (/ (+ (/ x
           (square y))
        (* 2 y))
     3))

(define (cube-root-approx x) (cube-root-recur x 1 x))

(define (cube-root-recur prev-guess guess x)
  (if (low-enough-delta? prev-guess guess)
      guess
      (cube-root-recur guess
                       (improve guess x)
                       x)))

(cube-root-approx 345345.0)
