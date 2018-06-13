#lang sicp

(define tolerance 0.00001)

(define (average x y) (/ (+ x y) 2))

(define (average-damp f)
  (lambda (x) 
    (average x (f x))))

(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) 
       tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try first-guess))

(define (compose f g)
  (lambda (x)
    (f (g x))))

(define (repeated f n)
  (if (= n 1)
    f
    (repeated (compose f f)
              (dec n))))
