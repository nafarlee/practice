#lang sicp

(define (average x y z)
  (/ (+ x y z) 3))

(define (smooth f dx)
  (lambda (x)
    (average (f (- x dx))
             (f x)
             (f (+ x dx)))))

(define (compose f g)
  (lambda (x)
    (f (g x))))

(define (repeated f n)
  (if (= n 1)
    f
    (repeated (compose f f)
              (dec n))))

(define (n-fold-smooth f n dx)
  ((repeated (lambda (fn) (smooth fn dx))
             n)
   f))
