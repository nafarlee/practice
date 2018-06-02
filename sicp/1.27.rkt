#lang sicp


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

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp) (remainder (square (expmod base (/ exp 2) m)) m))
        (else (remainder (* base (expmod base (- exp 1) m)) m))))

(define (carmichael? n)
  (define (recur a)
    (cond ((= a n) true)
          ((= a (expmod a n n)) (recur (inc a)))
          (else false)))
  (if (prime? n) false (recur 0)))


(carmichael? 561) ; #t
(carmichael? 1105) ; #t
(carmichael? 1729) ; #t
(carmichael? 2465) ; #t
(carmichael? 2821) ; #t
(carmichael? 6601) ; #t