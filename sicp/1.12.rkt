#lang sicp

(define (pascal row column)
  (cond ((= column 1) 1)
        ((= column row) 1)
        (else (+ (pascal (- row 1) column)
                 (pascal (- row 1) (- column 1))))))
