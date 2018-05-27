#lang sicp


(define (filtered-accumulate combiner predicate null-value term a next b)
  (define (iter a result)
    (define val (if (predicate a) (term a) null-value))
    (if (> a b)
        result
        (iter (next a) (combiner val result))))
  (iter a null-value))


(define (square a) (* a a))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) 
         n)
        ((divides? test-divisor n) 
         test-divisor)
        (else (find-divisor 
               n 
               (+ test-divisor 1)))))

(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (sum-square-primes a b)
  (filtered-accumulate + prime? 0 square a inc b))


(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define (product-coprime-integers n)
  (define (relatively-prime? i)
    (= 1 (gcd i n)))
  (filtered-accumulate * relatively-prime? 1 identity 1 inc n))
