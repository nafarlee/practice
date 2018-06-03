#lang sicp

(define (cont-frac n d k)
  (define (recur c) 
    (if (> c k)
      0
      (/ (n c)
         (+ (d c)
            (recur (inc c))))))
  (recur 1))

(define (multiple-3 x)
  (= 0 (remainder x 3)))

(define (n i) 1.0)

(define (d i)
  (if (multiple-3 (inc i))
    (- i (floor (/ i 3)))
    1))
