#lang sicp

(define (f-recursive n)
  (cond ((< n 3) n)
        (else (+ (f-recursive (- n 1))
                 (* 2 (f-recursive (- n 2)))
                 (* 3 (f-recursive (- n 3)))))))

(define (f-iter n)
  (f-inner 0 1 2 n))

(define (f-inner old mid fresh n)
  (cond ((= n 0) old)
        (else (f-inner mid
                       fresh
                       (+ fresh
                          (* 2 mid)
                          (* 3 old))
                       (- n 1)))))
