#lang sicp

(define (iterative-improve good-enough? reducer)
  (define (iter guess)
    (if (good-enough? guess)
      guess
      (iter (reducer guess))
      ))
  iter)

(define (average x y) 
  (/ (+ x y) 2))

(define (square x) (* x x))

(define (sqrt- x)
  (define (good-enough? guess)
    (< (abs (- (square guess) x)) 0.001))
  (define (improve guess)
    (average guess (/ x guess)))
  ((iterative-improve good-enough? improve) 1.0))

(define (fixed-point- f first-guess)
  ((iterative-improve
    (lambda (guess)
      (< (abs (- guess (f guess))) .00001))
    f)
   first-guess))
