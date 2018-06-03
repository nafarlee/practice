#lang sicp

(define (cont-frac n d k)
  (define (recur c) 
    (if (> c k)
      0
      (/ (n c)
         (+ (d c)
            (recur (inc c))))))
  (recur 1))

(define (square x) (* x x))

(define (tan-cf x k)
  (define (n i)
    (if (= 1 i)
      x
      (- 0 (square x))))
  (define (d i)
    (- (* 2 i) 1))
  (cont-frac n d k))
