#lang sicp

(define (even? n)
  (= 0 (remainder n 2)))

(define (expt-iter b n)
  (expt-iter-rec b n 1))

(define (expt-iter-rec b n a)
  (cond ((= n 0) a)
        ((even? n) (expt-iter-rec (* b b) (/ n 2) a))
        (else (expt-iter-rec b (dec n) (* b a)))))
