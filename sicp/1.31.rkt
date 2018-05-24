#lang sicp

(define (product-recur term a next b)
  (if (> a b)
      1
      (* (term a)
         (product-recur term (next a) next b))))

(define (product term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (* (term a) result))))
  (iter a 1))

(define (factorial n)
  (product identity 1 inc n))

(define (pi-term n)
  (if (even? n)
    (/ (+ n 2) (+ n 1))
    (/ (+ n 1) (+ n 2))))

(define (pi-approx n)
  (* 4 (product pi-term 1 inc n)))
